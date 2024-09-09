use actix_web::{get,post,web, App, HttpServer, HttpResponse, Responder};

#[get("/health")]
async fn health() -> impl Responder
{
    HttpResponse::Ok().body("Hello World!")
}

#[post("/add-server")]
async fn add_server() -> impl Responder
{
    HttpResponse::Ok().body("VPN server connected.")
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
async fn get_servers() -> impl Responder
{
    HttpResponse::Ok().body("{...}")
}

#[actix_web::main]
async fn main() -> std::io::Result<()> {
    HttpServer::new(|| {
        App::new()
            .service(health)
    })
    .bind(("127.0.0.1", 8080))?
    .run()
    .await
}
