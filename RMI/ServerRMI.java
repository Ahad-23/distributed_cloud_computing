import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class ServerRMI {
    public static void main(String[] args) {
        try {
            // Create an instance of Calculator
            CalculatorImpl calc = new CalculatorImpl();

            // Start RMI registry at port 1099
            Registry registry = LocateRegistry.createRegistry(1099);

            // Bind the object in the registry
            registry.rebind("CalculatorService", calc);

            System.out.println("Calculator RMI Server is ready...");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
