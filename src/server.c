/*
 * server.c - Socket setup and main connection loop
 *
 * Key concepts to learn here:
 *  - socket()     : Create a TCP socket (AF_INET, SOCK_STREAM)
 *  - setsockopt() : Set SO_REUSEADDR so port is freed on restart
 *  - bind()       : Attach socket to an address/port
 *  - listen()     : Mark socket as passive (waiting for connections)
 *  - accept()     : Block until a client connects; returns new fd
 *  - close()      : Release the file descriptor when done
 *
 * Flow:
 *   socket() -> bind() -> listen() -> loop{ accept() -> handle -> close client }
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "../include/server.h"
#include "../include/request.h"
#include "../include/response.h"

int server_init(server_t *server, int port, const char *webroot) {
    server->port    = port;
    server->webroot = webroot;

    /* TODO: listen() with backlog MAX_CONNECTIONS */

    // Info about the socket function can be found here https://man7.org/linux/man-pages/man2/socket.2.html
    server->socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    // Info about the setsockopt can be found here https://man7.org/linux/man-pages/man3/setsockopt.3p.html
    int enable = 1;
    if (setsockopt(server->socket_fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0){
      return -1;
    }

    // Define the address struct
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    if (bind(server->socket_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        return -1;
    }



    return 0; /* placeholder */
}

void server_run(server_t *server) {
    char buffer[BUFFER_SIZE];
    http_request_t req;

    while (1) {
        /* TODO: accept() new connection -> client_fd */
        int client_fd = -1; /* placeholder */
        (void)client_fd;

        /* TODO: read() raw HTTP request into buffer */
        /* TODO: request_parse(buffer, &req) */
        /* TODO: response_send(client_fd, &req, server->webroot) */
        /* TODO: close(client_fd) */

        memset(buffer, 0, BUFFER_SIZE);
        memset(&req, 0, sizeof(req));
        break; /* remove once loop is implemented */
    }
}

void server_cleanup(server_t *server) {
    if (server->socket_fd > 0)
        close(server->socket_fd);
}
