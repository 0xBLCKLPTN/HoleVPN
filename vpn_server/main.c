#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "../cryptography/cryptography.h"

#define PORT 12345
#define BUFFER_SIZE 1024


int main() {
    int server_fd;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_DGRAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket to the port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    printf("VPN Server is running...\n");

    while (1) {
        // Receiving data from the client
        int len = recvfrom(server_fd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&address, (socklen_t*)&addrlen);
        if (len < 0) {
            perror("recvfrom");
            exit(EXIT_FAILURE);
        }

        // Decrypting the received data
        encrypt(buffer, len, KEY);
        printf("Decrypted message from client: %s\n", buffer);

        // Encrypting the response
        encrypt(buffer, len, KEY);

        // Sending the response back to the client
        sendto(server_fd, buffer, len, 0, (struct sockaddr *)&address, addrlen);
        printf("Encrypted response sent\n");
    }

    // Closing the socket
    close(server_fd);

    return 0;
}
