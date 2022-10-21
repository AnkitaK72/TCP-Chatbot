#include "include.h"

SOCKET Listensocket = INVALID_SOCKET;
SOCKET Clientsocket = INVALID_SOCKET;
struct sockaddr_in servaddr, cli;
int sockfd, connfd, len;

void init_server(){
    //int sockfd, connfd, len;
    struct sockaddr_in servaddr, cli;

    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == INVALID_SOCKET){
        printf("server socket creation failed...\n");
        exit(0);
    }
    else
        printf("server socket successfully created..\n");

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("192.168.40.96");
    servaddr.sin_port = htons(PORT);
    SO_REUSEADDR;
    // Binding newly created socket to given IP and verification
    if(bind(sockfd,(SA*)&servaddr, sizeof(servaddr))== SOCKET_ERROR)
    {
        printf("bind failed with error: %d\n", WSAGetLastError());
        exit(0);
    }
    else
        printf("Socket successfully binded..\n");

    // Now server is ready to listen and verification
    if ((listen(sockfd, 5)) == SOCKET_ERROR) {
        printf("Listen failed...\n");
        exit(0);
    }
    else
        printf("Server listening..\n");
}  
    
void server_handler(){
   len = sizeof(cli);

    // Accept the data packet from client and verification
    connfd = accept(sockfd, (SA*)&cli, &len);
    if (connfd == INVALID_SOCKET) {
         printf("server accept failed...\n");
        exit(0);
    }
    else{
        printf("server accept the client...\n");
    
     // Function for chatting between client and server
    // int result =connect(sockfd, (SA*)&servaddr, sizeof(servaddr));
    //if(result == 0)

        char buff[100];
        int n;
            
        // read the message from client and copy it in buffer
        while(1){
            if(send > 0)
            {

                if(recv(connfd, buff, sizeof(buff),0)>0)
                {
                    printf("From client: %s\t  To client : ", buff);
                }
                n = 0;
                // copy server message in the buffer
                while((buff[n++] = getchar()) != '\n');

                // and send that buffer to client
                send(connfd, buff, sizeof(buff),0);

                // if msg contains "Exit" then server exit and chat ended.
                if(strncmp("exit", buff, 4) == 0){
                    printf("Server Exit...\n");
                }
            }
            
        }   
        
    }
}

    

    