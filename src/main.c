/*
 * main.c - Entry point for the web server
 *
 * Responsibilities:
 *  - Parse command-line arguments (port, web root, etc.)
 *  - Initialize the server (call server_init)
 *  - Start the main accept loop (call server_run)
 *  - Handle graceful shutdown on SIGINT/SIGTERM
 */

#include <stdio.h>
#include <stdio.h>
#include "../include/server.h"

#define DEFAULT_PORT 8080
#define DEFAULT_WEBROOT "./www/html"

int main(int argc, char *argv[])
{
  int port = DEFAULT_PORT;
  const char *webroot = DEFAULT_WEBROOT;

  /* TODO: Parse argc/argv for -- port and --webroot flags*/

  server_t server;

  if (server_init(&server, port, webroot) < 0)
  {
    fprintf(stderr, "Failed to initialize server\n");
    return EXIT_FAILURE;
  }

  printf("Server runnign on port %d, serving: %s\n", port, webroot);
  server_run(&server);

  server_cleanup(&server);
  return EXIT_SUCCESS;
}
