#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
void strreverse(char* begin, char* end){  
    char aux;  
    while(end>begin)   
        aux=*end, *end--=*begin, *begin++=aux; 
}
void itoa_(int value, char *str){
    char* wstr=str;
    int sign;  
    div_t res;
   
    if ((sign=value) < 0) value = -value;
   
    do {   
      *wstr++ = (value%10)+'0';
    }while(value=value/10);
   
    if(sign<0) *wstr++='-';
    *wstr='\0';

    strreverse(str,wstr-1);
}
int main(int argc, char *argv[]){
 
      if(argc > 2){
            char *ip;
            int fd, numbytes,puerto, longMen;
            char buf[100];
            char *cLongMen=(char*)malloc ( 4*sizeof(char) );
            puerto = atoi(argv[2]);
            ip = argv[1];
            char *mensajeEnviar = "otro mensaje desde el cliente en C \n";

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
            longMen = strlen(mensajeEnviar);
            itoa_(longMen,cLongMen);

            send (fd,cLongMen,4,0);
            send (fd,mensajeEnviar,longMen,0);
            
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