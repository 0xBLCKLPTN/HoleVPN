use actix_web::{get,post,web, App, HttpServer, HttpResponse, Responder};
use redis::AsyncCommands;
use serde::Deserialize;
use std::sync::{Mutex, Arc};

use actix_web::error;
use actix_web::middleware::Logger;
use env_logger::Env;

#[derive(Deserialize)]
struct KeyValue
{
    country: String,
    ip: String,
}

#[get("/health")]
async fn health() -> impl Responder
{
    HttpResponse::Ok().body("Hello World!")
}

#[post("/add-server")]
async fn add_server(data: web::Json<KeyValue>, redis_client: web::Data<redis::Client>) -> actix_web::Result<impl Responder>
{
    let mut conn = redis_client.get_connection_manager().await.map_err(error::ErrorInternalServerError)?;
    let res = redis::Cmd::mset(&[
        (&data.country, data.ip.clone()),
    ])
    //println!("{:?}", res);
    .query_async::<String>(&mut conn).await.map_err(error::ErrorInternalServerError)?;
    if res == "OK" {
        Ok(HttpResponse::Ok().body("successfully cached values"))
    } else {
        Ok(HttpResponse::InternalServerError().finish())
    }
}

#[post("/delete-server")]
async fn delete_server() -> impl Responder
{
    HttpResponse::Ok().body("VPN server has been deleted.")
}

#[post("/ping-server")]
async fn ping_server() -> impl Responder
{
    HttpResponse::Ok().body("Server OK.")
}


#[get("/get-servers")]
async fn get_servers(redis_client: web::Data<RedisClient>) -> impl Responder
{
    let mut conn = redis_client.get().await.unwrap();
    let value: String = conn.keys().await.unwrap_or_else(|_| "Key not found".to_string());
    println!("KEYS {:?}", value);
    format!("Value for key!")
}

#[actix_web::main]
async fn main() -> std::io::Result<()> {
    env_logger::init_from_env(Env::default().default_filter_or("info"));
    println!("Starting Red Dot API server at http://localhost:8080");
    let redis_client = redis::Client::open("redis://127.0.0.1/").unwrap();
        
    HttpServer::new(move || {
        App::new()
            .app_data(web::Data::new(redis_client.clone()))
            .wrap(Logger::default())
            .wrap(Logger::new("%a %{User-Agent}i"))
            .service(health)
            .service(add_server)
            .service(delete_server)
            .service(ping_server)
            //.service(get_servers)
    })
    .bind(("127.0.0.1", 8080))?
    .run()
    .await
}
