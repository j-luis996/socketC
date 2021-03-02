

import java.net.*; // paquete que contienen clases de red , todo lo necesario para comunicarme en red
import java.io.*; // paquete que contienen clases para E/S teclado y monitor

public class Servidor {
    
    public static void main(String[] args) {
        
        if (args.length != 1) {
            System.err.println("Uso desde consola:  <numero puerto>");

            System.exit(1);
        }
        
        int numeroPuerto = Integer.parseInt(args[0]);// convertimos el numero de puerto
        
        try {
            ServerSocket socketdelServidor = new ServerSocket(numeroPuerto);//escuchando peticiones
            PrintWriter escritor=null;
            BufferedReader lector=null;
            
           
            
            while(true){
                Socket socketdelCliente=socketdelServidor.accept();
                escritor = new PrintWriter(socketdelCliente.getOutputStream(), true);                   
                lector = new BufferedReader( new InputStreamReader(socketdelCliente.getInputStream()));

                System.out.println("Longitud del mensaje: "+lector.readLine());
                System.out.println("Mensaje del cliente: "+lector.readLine());

                escritor.println("Hola desde el server en java");

                socketdelCliente.close();
                escritor.close();
                lector.close();
            }
            
           
        } catch (IOException e) {
            System.out.println(" ocurrio una excepcion cuando intentamos escuchar " + numeroPuerto + " o esperando por una conexicon");
            System.out.println(e.getMessage());
        }
    }
}
