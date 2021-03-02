#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]){
 
      if(argc > 2){
            char *ip;
            int fd, numbytes,puerto;
            char buf[100];
            puerto = atoi(argv[2]);
            ip = argv[1];

            struct hostent *he;
            struct sockaddr_in server;

            if ((he = gethostbyname(ip)) == NULL){
                  printf("gethostbyname() error\n");
                  exit(0);
            }

            if ((fd=socket(AF_INET, SOCK_STREAM, 0)) == -1){
                  printf("socket() error\n");
                  exit(0);
            }

            server.sin_family = AF_INET;
            server.sin_port = htons(puerto);
            server.sin_addr = *((struct in_addr *)he->h_addr);
            bzero(&(server.sin_zero),8);

            if(connect(fd, (struct sockaddr *)&server,sizeof(struct sockaddr)) == -1){
                  printf("Connect() error\n");
                  exit(0);
            }
            send (fd,"34",2,0);
            send (fd,"Un mensaje desde el cliente en C \n",34,0);
            
            if ((numbytes=recv(fd,buf,100,0)) == -1){
                  printf("Error en recv() \n");
                  exit(0);
            }

            buf[numbytes] = '\0';

            printf("Mensaje del Servidor: %s\n",buf);

            close(fd);
      }else{
            printf("No se ingreso el IP y Puerto por parametro\n");
      }
 
}