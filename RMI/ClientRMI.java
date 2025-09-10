import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class ClientRMI {
    public static void main(String[] args) {
        try {
            // Get reference to the RMI registry
            Registry registry = LocateRegistry.getRegistry("localhost", 1099);
            Calculator stub = (Calculator) registry.lookup("CalculatorService");
            double a = 20, b = 5;
            System.out.println("Addition: " + stub.add(a, b));
            System.out.println("Subtraction: " + stub.subtract(a, b));
            System.out.println("Multiplication: " + stub.multiply(a, b));
            System.out.println("Division: " + stub.divide(a, b));
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
