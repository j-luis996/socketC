import java.io.*;
import java.net.*;

public class cliente {

    public static void main(String[] args) throws IOException {

        String nombreHost = "127.0.0.1";
        int numeroPuerto = 8080;
        String mensaje = "Hola desde el cliente en Java\n";
        int longMensaje = mensaje.length();

        try (
                Socket socketEco = new Socket(nombreHost, numeroPuerto);
                PrintWriter escritor = new PrintWriter(socketEco.getOutputStream(),true);
                BufferedReader lector = new BufferedReader(new InputStreamReader(socketEco.getInputStream()));
                ) {
                    escritor.println(Integer.toString(longMensaje));
                    escritor.println(mensaje);
                    System.out.println("Mensaje del servidor: "+lector.readLine());

        } catch (UnknownHostException e) {
            System.err.println("No conozco al host " + nombreHost);
            System.exit(1);
        } catch (IOException e) {
            System.err.println("no se pudo obtener E/S para la conexion " + nombreHost);
            System.exit(1);
        }
    }
}
