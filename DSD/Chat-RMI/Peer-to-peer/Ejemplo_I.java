import java.rmi.Remote;
import java.rmi.RemoteException;

import java.util.List;

public interface Ejemplo_I extends Remote {
  public void registrar (String cliente) throws RemoteException;
  public void desconectar (String cliente) throws RemoteException;
  public List<String> clientes_registrados () throws RemoteException;
}
