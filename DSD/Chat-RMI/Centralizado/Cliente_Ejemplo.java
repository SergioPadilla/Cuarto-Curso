import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.lang.Thread;

import java.util.List;
import java.util.ArrayList;

public class Cliente_Ejemplo implements Cliente_Ejemplo_I {
	public static List<String> mensajes = new ArrayList<>();
	public static String nombre_cliente;

    public static void main(String args[]) {
    	/**
    	* Registro un objeto para el cliente
    	*/
    	if (System.getSecurityManager() == null) {
            System.setSecurityManager(new SecurityManager());
        }
        try {
            nombre_cliente = args[1];
            Cliente_Ejemplo_I prueba = new Cliente_Ejemplo();
            Cliente_Ejemplo_I stub =
                (Cliente_Ejemplo_I) UnicastRemoteObject.exportObject(prueba, 0);
            Registry registry = LocateRegistry.getRegistry();
            registry.rebind(nombre_cliente, stub);
            System.out.println("Registrado cliente remoto"+nombre_cliente);
        } catch (Exception e) {
            System.err.println("cliente exception:");
            e.printStackTrace();
        }

        /**
        * Registro al cliente en el servidor remoto
        */
        try {
        	nombre_cliente = args[1];
            String nombre_objeto_remoto = "servidor";
            System.out.println("Buscando servidor remoto");
            Registry registry = LocateRegistry.getRegistry(args[0]);
            Ejemplo_I instancia_local = (Ejemplo_I) registry.lookup(nombre_objeto_remoto);
            System.out.println("Invocando servidor remoto para registrar al cliente");
            instancia_local.registrar(nombre_cliente); // Registro al cliente en el servidor para que reciba los mensajes del chat
        } catch (Exception e) {
            System.err.println("Cliente exception:");
            e.printStackTrace();
        }

        /**
        * Menu para opciones
        */
        while(true){
        	System.out.println("Elige una de las siguientes opciones:");
        	System.out.println("1 -> enviar mensaje");
        	System.out.println("2 -> mostrar mensajes");
        	System.out.println("3 -> desconectar");
        	System.out.println();

        	String opcion = System.console().readLine();

        	if(opcion.equals("1")){
        		System.out.println("Escriba el mensaje: ");
        		String mensaje = System.console().readLine();

        		try {
		            String nombre_objeto_remoto = "servidor";
		            System.out.println("Buscando servidor remoto");
		            Registry registry = LocateRegistry.getRegistry(args[0]);
		            Ejemplo_I instancia_local = (Ejemplo_I) registry.lookup(nombre_objeto_remoto);
		            System.out.println("Invocando servidor remoto para mostrar mensaje");
		            instancia_local.difundir_mensaje(mensaje);
		        } catch (Exception e) {
		            System.err.println("Cliente exception:");
		            e.printStackTrace();
		        }
        	}
        	else if(opcion.equals("2")){
        		for(String mensaje : mensajes)
        			System.out.println(nombre_cliente + ": " + mensaje);
        		System.out.println();
        	}
        	else if(opcion.equals("3")){
        		try {
		            String nombre_objeto_remoto = "servidor";
		            System.out.println("Buscando servidor remoto");
		            Registry registry = LocateRegistry.getRegistry(args[0]);
		            Ejemplo_I instancia_local = (Ejemplo_I) registry.lookup(nombre_objeto_remoto);
		            System.out.println("Invocando servidor remoto para desconectar");
		            instancia_local.desconectar(nombre_cliente);
		            System.exit(0);
		        } catch (Exception e) {
		            System.err.println("Cliente exception:");
		            e.printStackTrace();
		        }
        	}
        	else
        		System.out.println("Opcion no válida");
        }
    }

    public void mostrar_mensaje (String mensaje) throws RemoteException{
    	mensajes.add(mensaje);
    }
}
