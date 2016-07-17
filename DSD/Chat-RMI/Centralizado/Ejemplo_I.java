import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Ejemplo_I extends Remote {
  public void registrar (String cliente) throws RemoteException;
  public void difundir_mensaje (String mensaje) throws RemoteException;
  public void desconectar (String cliente) throws RemoteException;
}
