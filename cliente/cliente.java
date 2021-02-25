package cliente;

import java.io.*;
import java.net.*;

public class cliente {

    public static void main(String[] args) throws IOException {

        String nombreHost = "192.168.100.20";
        int numeroPuerto = 8080;

        try (
                Socket socketEco = new Socket(nombreHost, numeroPuerto);
                BufferedReader lector = new BufferedReader(new InputStreamReader(socketEco.getInputStream()));
                ) {
            System.out.println("mensaje del servidor: "+lector.readLine());

        } catch (UnknownHostException e) {
            System.err.println("No conozco al host " + nombreHost);
            System.exit(1);
        } catch (IOException e) {
            System.err.println("no se pudo obtener E/S para la conexion "
                    + nombreHost);
            System.exit(1);
        }
    }
}
