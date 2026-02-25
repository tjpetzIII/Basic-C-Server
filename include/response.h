#ifndef RESPONSE_H
#define RESPONSE_H

#include "request.h"

/*
 * response_send - Build and send HTTP response for a given request
 *   client_fd: connected client socket
 *   req:       parsed request
 *   webroot:   root directory for file serving
 */
void response_send(int client_fd, const http_request_t *req, const char *webroot);

/*
 * response_send_error - Send a simple HTTP error response (e.g. 404, 500)
 */
void response_send_error(int client_fd, int status_code, const char *message);

#endif /* RESPONSE_H */
