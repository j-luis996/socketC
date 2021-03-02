#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

int main (int argc, char **argv){
      if(argc > 1){
            int fd, fd2, longitud_cliente, puerto;
            puerto = atoi(argv[1]);
            struct sockaddr_in server;
            struct sockaddr_in client;

            int numbytes;
            char *buf,*bufLongMen=(char*)malloc ( 4*sizeof(char) );
            int longMensaje;

            server.sin_family = AF_INET;
            server.sin_port = htons(puerto);
            server.sin_addr.s_addr = INADDR_ANY;
            bzero(&(server.sin_zero),8);

            if((fd = socket(AF_INET, SOCK_STREAM,0)) < 0){
                  perror("Error al crear el socket\n");
                  exit(-1);
            }else{
                  printf("Socket inicializado\n");
            }

            if(bind(fd,(struct sockaddr *)&server, sizeof(struct sockaddr))==-1){
                  printf("Error en bind\n");
                  exit(-1);
            }else{
                  printf("Socket creado\n");
            }

            if(listen(fd,SOMAXCONN)==-1){//el segundo valor es el numero de conexiones permitidas, en este caso es el maximo posible
                  printf("Error en el listen\n");
                  exit(-1);
            }else{
                  printf("Socket escuchando en %d\n", puerto);
            }

            while (1){
                  longitud_cliente = sizeof(struct sockaddr_in);

                  if((fd2 = accept(fd,(struct sockaddr *)&client,&longitud_cliente))==-1){
                        printf("Error al aceptar conexion");
                        exit(-1);
                  }else{
                        printf("cliente conectado\n");
                        
                  }

                  if ((numbytes=recv(fd2,bufLongMen,4,0)) == -1){
                        printf("Error en recv() \n");
                  }else{
                        longMensaje = atoi(bufLongMen);
                        printf("Longitud del mensaje %d \n",longMensaje);
                        numbytes = 0;
                        buf= NULL;
                  }


                  buf = (char*)malloc ( longMensaje*sizeof(char) );
                  
                  if ((numbytes=recv(fd2,buf,longMensaje,0)) == -1){
                        printf("Error en recv() \n");
                  }else{
                        printf("Mensaje del Cliente: %s\n",buf);
                  }

                  send(fd2,"Un mensaje desde el server en c\n",34,0);

                  free(buf);
                  free(bufLongMen);
                  close(fd2);
            }
           close(fd);
            
      }else{
            printf("ocurrio un error, revise que los parametros sean correctos\n");
      }
}