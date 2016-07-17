import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.lang.Thread;

import java.util.List;
import java.util.ArrayList;

public class Ejemplo implements Ejemplo_I {

	List<String> clientes = new ArrayList<>();

    public Ejemplo() {
        super();
    }

    public void registrar (String cliente) throws RemoteException {
    	System.out.println("Registrando al cliente: "+cliente);
    	if(!clientes.contains(cliente)) {
    		clientes.add(cliente);
   			System.out.println("Cliente "+cliente+" registrado");
    	}
    	else // para evitar clientes con el mismo nombre
    		System.out.println("El cliente "+cliente+" ya esta registrado");
    }

  	public void difundir_mensaje (String mensaje) throws RemoteException{
  		try {            
            System.out.println("Buscando clientes remotos");
            Registry registry = LocateRegistry.getRegistry();

            /**
            * busco los clientes remotos
            */
            List<Cliente_Ejemplo_I> clientes_remotos = new ArrayList<>();
            for(String cliente : clientes)
            	clientes_remotos.add((Cliente_Ejemplo_I) registry.lookup(cliente));

            /**
            * Invoco los metodos para almacenar los mensajes en cada cliente
            */
            System.out.println("Invocando clientes remotos para almacenar el mensaje");
            for(Cliente_Ejemplo_I instancia_local : clientes_remotos)
            	instancia_local.mostrar_mensaje(mensaje);
        } catch (Exception e) {
            System.err.println("Ejemplo_I exception:");
            e.printStackTrace();
        }
  	}

  	public void desconectar (String cliente) throws RemoteException {
  		System.out.println("Borrando al cliente: "+cliente);
    	clientes.remove(cliente);
  	}

    public static void main(String[] args) {
        if (System.getSecurityManager() == null) {
            System.setSecurityManager(new SecurityManager());
        }
        try {
            String nombre_objeto_remoto = "servidor";
            Ejemplo_I prueba = new Ejemplo();
            Ejemplo_I stub =
                (Ejemplo_I) UnicastRemoteObject.exportObject(prueba, 0);
            Registry registry = LocateRegistry.getRegistry();
            registry.rebind(nombre_objeto_remoto, stub);
            System.out.println("Registrado servidor");
        } catch (Exception e) {
            System.err.println("Ejemplo exception:");
            e.printStackTrace();
        }
    }
}
