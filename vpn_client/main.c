#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "../cryptography/cryptography.h"

#define BUFFER_SIZE 1024


int main(int argc, char* argv[]) {
    int PORT;
    char *ADDRESS;
    if ( argc >= 2 )
    {
        ADDRESS = argv[1];
        PORT = atoi(argv[2]);
    } else {
        perror("No address or port specified. ./red_dot_vpn 127.0.01 12345");
        return -1;
    }
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
    char message[BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation error");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Converting IPv4 addresses from text to binary form
    if (inet_pton(AF_INET, ADDRESS, &serv_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        close(sock);
        return -1;
    }

    printf("VPN Client is running...\n");
    while (1) {
        // Reading the message from the user
        printf("Enter message to send to server (or 'exit' to quit): ");
        if (fgets(message, BUFFER_SIZE, stdin) == NULL) {
            perror("fgets");
            close(sock);
            return -1;
        }

        // Removing the newline character
        message[strcspn(message, "\n")] = 0;

        // Checking for exit command
        if (strcmp(message, "exit") == 0) {
            break;
        }

        // Encrypting the message
        encrypt(message, strlen(message), KEY);

        // Sending the message to the server
        if (sendto(sock, message, strlen(message), 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
            perror("sendto");
            close(sock);
            return -1;
        }
        printf("Encrypted message sent\n");

        // Receiving the response from the server
        int len = recvfrom(sock, buffer, BUFFER_SIZE, 0, NULL, NULL);
        if (len < 0) {
            perror("recvfrom");
            close(sock);
            return -1;
        }

        // Decrypting the received response
        encrypt(buffer, len, KEY);
        printf("Decrypted response from server: %s\n", buffer);
    }

    // Closing the socket
    close(sock);

    return 0;
}
