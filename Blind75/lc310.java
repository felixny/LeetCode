import java.util.*;

public class lc310 {

    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        List<Integer> res = new ArrayList<>();
        
        if (n <= 0) return res;
        
        if (n == 1) {
            res.add(0);
            return res;
        }
        
        int degree[] = new int[n];
        List<List<Integer>> adj = new ArrayList<>();
        
        for (int i = 0; i < n; i++){
            adj.add(new ArrayList<>());
        }
        System.out.println("empty list : " + adj);


        for (int[] e : edges){
            //System.out.println(Arrays.toString(e));
           // System.out.println("e[0]: " + e[0]);
            degree[e[0]]++;
            //System.out.println(degree[e[0]]);
            //System.out.println("e[1]: " + e[1]);
            degree[e[1]]++;
            //System.out.println("e1 : " + degree[e[1]]);

            //System.out.println("e[0] " + e[0] + " e[1] " + e[1]);
            adj.get(e[0]).add(e[1]);
            adj.get(e[1]).add(e[0]);
        }

        System.out.println(adj);
        System.out.println(Arrays.toString(degree));
        
        Queue<Integer> q = new LinkedList<>();
        
        for (int i = 0; i < n; i++){
            if (degree[i] == 1){
                q.add(i);
            }
        }

        System.out.println("q: " + q);
        
        // bfs on a tree
        while(n > 2){
            int size = q.size();
            n -= size;

            // 4-3 = 1;
            System.out.println(n);
            
            while (size-->0){
                int v = q.poll();
                System.out.println("v: " + v);
                for(int i : adj.get(v)){
                    System.out.println("i : " + i);
                    degree[i]--;
                    if (degree[i] == 1){
                        //System.out.println(degree[i]);
                        q.add(i);
                    }
                }
                System.out.println("after q: " + q);
            }
        }
        res.addAll(q);
        return res;
    }

    public static void main(String[] args) {
        lc310 lc310 = new lc310();
        int n = 4;
        int[][] edges = {{1,0},{1,2},{1,3}};
        System.out.println(lc310.findMinHeightTrees(n, edges));


    }
}

