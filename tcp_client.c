#include "include.h"

void init_client(){
    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;

    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == INVALID_SOCKET) {
        printf("Client socket creation failed...\n");
        exit(0);
    }
    else
        printf("Client socket successfully created..\n");


    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("192.168.40.96");
    servaddr.sin_port = htons(PORT); 
} 

void client_handler(){

     int sockfd, connfd;
     struct sockaddr_in servaddr, cli;

    //assign IP, PORT
    //servaddr.sin_family = AF_INET;
    //servaddr.sin_addr.s_addr = inet_addr("192.168.40.96");
    //servaddr.sin_port = htons(PORT);

    //connect the client socket to server socket
    if(connect(sockfd, (SA*)&servaddr, sizeof(servaddr))==SOCKET_ERROR)
    {
        printf("connection with the server failed...%d\n",WSAGetLastError());
        exit(0);
    }
    else
        printf("connected to the server..\n");  

    if(connfd == 0){    
        char buff[100];
        int n;
        while(1)
        {
            printf("\n Enter the string : ");
            if(send>0)
            {
                n = 0;
                while ((buff[n++] = getchar()) != '\n');
                send(sockfd, buff, sizeof(buff), 0);
                if(recv(sockfd, buff, sizeof(buff), 0) >0){
                        printf("From server : %s\t  To server : ", buff);
                }
                if ((strncmp(buff, "exit", 4)) == 0){
                        printf("Client Exit...\n");
                }
            }       
        }
    }


}

