#ifndef REQUEST_H
#define REQUEST_H

#define MAX_PATH_LEN 256
#define MAX_METHOD_LEN 8

typedef struct
{
  char method[MAX_METHOD_LEN]; /* e.g. "GET", "POST" */
  char path[MAX_PATH_LEN];     /* e.g. "/index.html" */
  char version[16];            /* e.g. "HTTP/1.1" */
                               /* TODO: Add headers array if needed */
} http_request_t;

/*
 * request_parse - Parse raw HTTP request string into http_request_t
 * Returns 0 on success, -1 on malformed request
 */
int request_parse(const char *raw, http_request_t *req);

#endif /* REQUEST_H */
