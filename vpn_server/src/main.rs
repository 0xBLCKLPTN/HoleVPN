use tokio::net::TcpListener;
use tokio::io::{AsyncReadExt, AsyncWriteExt};
use aes::Aes256;
use block_modes::{BlockMode, Cbc};
use block_modes::block_padding::Pkcs7;
use hex;

type Aes256Cbc = Cbc<Aes256, Pkcs7>;

const KEY: &[u8; 32] = b"an example very very secret key!";
const IV: &[u8; 16] = b"an example iv456";

async fn handle_client(mut stream: tokio::net::tcp::OwnedReadHalf) {
    let mut buffer = [0; 1024];
    let mut decrypted_data = Vec::new();

    while let Ok(n) = stream.read(&mut buffer).await {
        if n == 0 {
            break;
        }

        let cipher = Aes256Cbc::new_from_slices(KEY, IV).unwrap();
        let decrypted_block = cipher.decrypt_vec(&buffer[..n]).unwrap();
        decrypted_data.extend_from_slice(&decrypted_block);

        println!("Received: {}", String::from_utf8_lossy(&decrypted_data));
        decrypted_data.clear();
    }
}

#[tokio::main]
async fn main() {
    let listener = TcpListener::bind("127.0.0.1:12345").await.unwrap();
    println!("VPN Server started on 127.0.0.1:12345");

    while let Ok((stream, _)) = listener.accept().await {
        let (reader, writer) = stream.into_split();
        tokio::spawn(async move {
            handle_client(reader).await;
        });
    }
}
