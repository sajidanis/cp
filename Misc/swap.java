import java.util.*;
  
public class Main {
    
    // Disjoint Set Union (Union-Find) class
    static class DSU {
        int[] parent;
        
        public DSU(int n) {
            parent = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
        
        public int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]); // path compression
            }
            return parent[x];
        }
        
        public void union(int a, int b) {
            int rootA = find(a);
            int rootB = find(b);
            if (rootA != rootB) {
                parent[rootB] = rootA;
            }
        }
    }
    
    // Function to compute gcd of two numbers
    static int gcd(int a, int b) {
        while (b != 0) {
            int tmp = a % b;
            a = b;
            b = tmp;
        }
        return a;
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt(); // number of groups
        while (T-- > 0) {
            int n = sc.nextInt();
            int[] health = new int[n];
            for (int i = 0; i < n; i++) {
                health[i] = sc.nextInt();
            }
            
            // Create a sorted copy of the health values (target order)
            int[] sorted = health.clone();
            Arrays.sort(sorted);
            
            // DSU to group indices that can be swapped (i.e. gcd(health[i], health[j]) > 1)
            DSU dsu = new DSU(n);
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (gcd(health[i], health[j]) > 1) {
                        dsu.union(i, j);
                    }
                }
            }
            
            // Group indices by their DSU representative
            Map<Integer, List<Integer>> groups = new HashMap<>();
            for (int i = 0; i < n; i++) {
                int root = dsu.find(i);
                groups.computeIfAbsent(root, k -> new ArrayList<>()).add(i);
            }
            
            boolean possible = true;
            // For each connected component, check if the available numbers can be rearranged
            // to match the sorted order at those positions.
            for (List<Integer> indices : groups.values()) {
                List<Integer> currentValues = new ArrayList<>();
                List<Integer> targetValues = new ArrayList<>();
                for (int idx : indices) {
                    currentValues.add(health[idx]);
                    targetValues.add(sorted[idx]);
                }
                Collections.sort(currentValues);
                Collections.sort(targetValues);
                if (!currentValues.equals(targetValues)) {
                    possible = false;
                    break;
                }
            }
            
            System.out.println(possible ? "Yes" : "No");
        }
        sc.close();
    }
}
