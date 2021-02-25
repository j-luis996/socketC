import java.io.*;
import java.net.*;

public class cliente {

    public static void main(String[] args) throws IOException {

        String nombreHost = "192.168.100.20";
        int numeroPuerto = 8080;

        try (
                Socket socketEco = new Socket(nombreHost, numeroPuerto);
                PrintWriter escritor = new PrintWriter(socketEco.getOutputStream(),true);
                BufferedReader lector = new BufferedReader(new InputStreamReader(socketEco.getInputStream()));
                ) {
                    escritor.println("Hola desde el cliente en Java\0");
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
