import java.util.*;

class Server {
    int weight;
    char name;
    int currentWeight;
    
    public Server(char name, int weight) {
        this.name = name;
        this.weight = weight;
        this.currentWeight = 0;
    }
}

public class WeightedRoundRobin {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of servers");
        int num = sc.nextInt();
        List<Server> servers = new ArrayList<>();
        for (int i = 0; i < num; i++) {
            System.out.println("Enter name for server " + (i + 1) + "");
            char name = sc.next().charAt(0);
            System.out.println("Enter weight for server " + name + ":");
            int weight = sc.nextInt();
            servers.add(new Server(name, weight));
        }
        
        
        int totalWeight = 0;
        for (Server s : servers) {
            totalWeight += s.weight;
        }
        
        int request = 1;
        while (request == 1) {
            
            Server selected = null;
            int maxWeight = Integer.MIN_VALUE;
            
            for (Server s : servers) {
                s.currentWeight += s.weight;
                if (s.currentWeight > maxWeight) {
                    maxWeight = s.currentWeight;
                    selected = s;
                }
            }
                if (selected != null) {
                System.out.println("Request sent to Server " + selected.name);
                selected.currentWeight -= totalWeight;
            }
            
            System.out.println("Do you want to send a request?(0/1)");
            request = sc.nextInt();
        }
        
        sc.close();
    }
}