import GUI.Cliente_chat_centralized_I;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;

/**
 * Created by SergioPadilla on 7/5/16.
 */
public class Cliente_chat_centralized implements Cliente_chat_centralized_I {

    public static String nombre_server_remoto = "chat_I";
    public static String server;
    public static String name;

    public static Registry registry;

    public Cliente_chat_centralized(String server) {
        //Almacenamos el nombre del host servidor
        this.server = server;
        try {
            registry = LocateRegistry.getRegistry(server);
        } catch (RemoteException e) {
            e.printStackTrace();
        }
    }

    public static void registro() {
        System.out.println("Buscando el objeto remoto");
        try {
            Chat_centralized_I instancia_local = (Chat_centralized_I) registry.lookup(nombre_server_remoto);
            System.out.println("Invocando el objeto remoto");
            name = Thread.currentThread().getName();
            instancia_local.sign_up(name);
        } catch (Exception e) {
            System.err.println("Chat_centralized exception:");
            e.printStackTrace();
        }
    }

    public static void main(String args[]) {

        registro();
        if (System.getSecurityManager() == null) {
            System.setSecurityManager(new SecurityManager());
        }
        try {
            String nombre_objeto_remoto = "chat_I";
            Cliente_chat_centralized chat = new Cliente_chat_centralized(server);
            Cliente_chat_centralized_I stub = (Cliente_chat_centralized_I) UnicastRemoteObject.exportObject(chat, 0);
            Registry registry = LocateRegistry.getRegistry();
            registry.rebind(name, stub);
            System.out.println("Finish registry");
        } catch (Exception e) {
            System.err.println("Exception server:");
            e.printStackTrace();
        }
    }

    public static void difunde_mensaje(String message){
        System.out.println("Buscando el objeto remoto");
        try {
            Registry registry = LocateRegistry.getRegistry(server);
            Chat_centralized_I instancia_local = (Chat_centralized_I) registry.lookup(nombre_server_remoto);
            System.out.println("Invocando el objeto remoto");
            instancia_local.send_message(message, server);
        } catch (Exception e) {
            System.err.println("Chat_centralized exception:");
            e.printStackTrace();
        }
    }

    public static void logout(){
        System.out.println("Buscando el objeto remoto");
        try {
            Registry registry = LocateRegistry.getRegistry(server);
            Chat_centralized_I instancia_local = (Chat_centralized_I) registry.lookup(nombre_server_remoto);
            instancia_local.sign_out(name);
        } catch (Exception e) {
            System.err.println("Chat_centralized exception:");
            e.printStackTrace();
        }
    }

    @Override
    public void mostrar_mensaje(String message) {
        System.out.print(message);
    }
}
