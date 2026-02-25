#ifndef SERVER_H
#define SERVER_H

#define MAX_CONNECTIONS 10
#define BUFFER_SIZE 4096

typedef struct
{
  int socket_fd;       /* Listening socket file descriptor */
  int port;            /* Port number to bind to */
  const char *webroot; /* Root directory for serving files */
} server_t;

/*
 * server_init - Create socket, bind to port, start listening
 * Returns 0 on success, -1 on failure
 */
int server_init(server_t *server, int port, const char *webroot);

/*
 * server_run - Main accept() loop; blocks until server stops
 * For each connection, reads request and sends response
 */
void server_run(server_t *server);

/*
 * server_cleanup - Close socket and free resources
 */
void server_cleanup(server_t *server);

#endif /* SERVER_H */
