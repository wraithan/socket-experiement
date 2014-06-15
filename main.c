#include <sys/socket.h>
#include <strings.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>

int my_send(int socket, char* message) {
    if (send(socket, message, strlen(message), 0) < 0) {
        puts("failure");
        return -1;
    }
    return 0;
}

int main() {
    struct sockaddr_in server;
    int sockfd;
    char* message = "{\"name\": \"a thing\"}";
    char content_length [25];
    sprintf(content_length, "Content-Length: %lu", strlen(message));

    // zero out the struct
    bzero((char *) &server, sizeof(server));

    // set server address
    server.sin_family = AF_INET;
    server.sin_port = htons(8000);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    // create tcp socket
    sockfd = socket(PF_INET, SOCK_STREAM, 0);

    if (connect(sockfd , (struct sockaddr *)&server , sizeof(server)) < 0)
    {
        // If the connection fails return 1
        return 1;
    }

    my_send(sockfd, "POST / HTTP/1.1\r\n");
    my_send(sockfd, content_length);
    my_send(sockfd, "\r\n");
    my_send(sockfd, "Content-Type: application/json\r\n");
    my_send(sockfd, "\r\n");
    my_send(sockfd, message);
    my_send(sockfd, "\r\n");

    close(sockfd);

    return 0;
}