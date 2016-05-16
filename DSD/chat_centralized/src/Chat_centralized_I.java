import java.rmi.Remote;
import java.rmi.RemoteException;

/**
 * Created by SergioPadilla on 7/5/16.
 */

public interface Chat_centralized_I extends Remote {
    public void sign_up (String id_user) throws RemoteException;
    public void send_message (String message, String server) throws RemoteException;
    public void sign_out (String id_user) throws RemoteException;
}
