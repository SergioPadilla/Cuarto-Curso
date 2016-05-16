import GUI.Cliente_chat_centralized_I;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by SergioPadilla on 7/5/16.
 */
public class Chat_centralized implements Chat_centralized_I {

    private List<String> users_connected = new ArrayList<>();

    public Chat_centralized() {
        super();
    }

    public void sign_up (String id_user) {
        /**
         * Registrar usuario en el array de usuarios conectados 'users_connected'
         *
         *  in:
         *      identificador: identificar de usuario
         */
        users_connected.add(id_user);
    }


    public void send_message (String message, String server) {
        /**
         * Comunicarme con cada cliente para enviarle el mensaje
         *
         *  in:
         *      Message: mensaje para difundir a los usuarios
         *
         *  out:
         *      Usuarios: todos los registrados en 'users_connected'
         */
        for(String name : users_connected){
            System.out.println("Buscando el objeto remoto");
            try {
                Registry registry = LocateRegistry.getRegistry(server);
                Cliente_chat_centralized_I instancia_local = (Cliente_chat_centralized_I) registry.lookup(name);
                System.out.println("Invocando el objeto remoto");
                instancia_local.mostrar_mensaje(message);
            } catch (Exception e) {
                System.err.println("Chat_centralized exception:");
                e.printStackTrace();
            }
        }
    }


    public void sign_out (String id_user) {
        /**
         * Eliminar usuario en el array de usuarios conectados 'users_connected'
         *
         *  in:
         *      identificador: identificar de usuario
         */
        users_connected.remove(id_user);
    }


    public static void main(String[] args) {
        if (System.getSecurityManager() == null) {
            System.setSecurityManager(new SecurityManager());
        }
        try {
            String nombre_objeto_remoto = "chat_I";
            Chat_centralized_I chat = new Chat_centralized();
            Chat_centralized_I stub = (Chat_centralized_I) UnicastRemoteObject.exportObject(chat, 0);
            Registry registry = LocateRegistry.getRegistry();
            registry.rebind(nombre_objeto_remoto, stub);
            System.out.println("Finish registry");
        } catch (Exception e) {
            System.err.println("Exception server:");
            e.printStackTrace();
        }
    }
}
