// NS3 Formative Exercise 1 - hello_client.c
// Worked Answer
// 
// Copyright (c) 2009-2017 University of Glasgow
// All rights reserved.

#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>

#define BUFLEN 1500

int
main(int argc, char *argv[])
{
  int                      i; 
  char                     ipstring[INET6_ADDRSTRLEN];
  struct addrinfo          hints, *ai, *ai0;

  if (argc != 2) {
    printf("Usage: %s <hostname>\n", argv[0]);
    return 1;
  }

  // Look up the IP address of the hostname specified on the command line
  memset(&hints, 0, sizeof(hints));
  hints.ai_family    = PF_UNSPEC;
  hints.ai_socktype  = SOCK_STREAM;
  if ((i = getaddrinfo(argv[1], "5000", &hints, &ai0)) != 0) {
    printf("Unable to look up IP address: %s", gai_strerror(i));
    return 2;
  }

  // Try to connect to each address in turn
  for (ai = ai0; ai != NULL; ai = ai->ai_next) {
    void *addr;
    char *ipversion;

    if (ai->ai_family == AF_INET){
      struct sockaddr_in *ipv4 = (struct sockaddr_in *)ai->ai_addr;
      addr = &(ipv4->sin_addr);
      ipversion = "IPv4";
    }
    else{
      struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)ai->ai_addr;
      addr = &(ipv6->sin6_addr);
      ipversion = "IPv6";
    } 
    inet_ntop(ai->ai_family, addr, ipstring, sizeof(ipstring));
    printf("%s %s %s\n", argv[1], ipversion, ipstring);

  }
  freeaddrinfo(ai0); 
  return 0;
}
