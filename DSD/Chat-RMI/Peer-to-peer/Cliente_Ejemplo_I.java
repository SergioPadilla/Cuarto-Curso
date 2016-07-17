import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Cliente_Ejemplo_I extends Remote {
  public void mostrar_mensaje (String mensaje) throws RemoteException;
}