package GUI;

import java.rmi.Remote;

/**
 * Created by SergioPadilla on 17/5/16.
 */
public interface Cliente_chat_centralized_I extends Remote {
    public void mostrar_mensaje(String message);
}
