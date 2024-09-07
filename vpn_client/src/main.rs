use tokio::net::TcpStream;
use tokio::io::{AsyncReadExt, AsyncWriteExt};
use aes::Aes256;
use block_modes::{BlockMode, Cbc};
use block_modes::block_padding::Pkcs7;
use hex;

type Aes256Cbc = Cbc<Aes256, Pkcs7>;

const KEY: &[u8; 32] = b"an example very very secret key!";
const IV: &[u8; 16] = b"an example iv456";

async fn send_message(stream: &mut TcpStream, message: &str) {
    let cipher = Aes256Cbc::new_from_slices(KEY, IV).unwrap();
    let encrypted_data = cipher.encrypt_vec(message.as_bytes());

    stream.write_all(&encrypted_data).await.unwrap();
}

#[tokio::main]
async fn main() {
    let mut stream = TcpStream::connect("127.0.0.1:12345").await.unwrap();
    println!("Connected to VPN Server on 127.0.0.1:12345");

    loop {
        let mut message = String::new();
        std::io::stdin().read_line(&mut message).unwrap();
        send_message(&mut stream, &message).await;
    }
}
