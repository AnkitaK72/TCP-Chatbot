
#include <windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <winsock2.h>      

#define DEFAULT_BUFLEN 1024
#define PORT 3000
#define SA struct sockaddr

extern void init_server();
extern void server_handler();

extern void init_client();
extern void client_handler();
