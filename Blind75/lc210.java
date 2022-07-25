import java.util.*;;

public class lc210 {
    private ArrayList[] graph;
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        // topo sort
        graph = new ArrayList[numCourses];
        
        int[] visit = new int[numCourses];
        Queue<Integer> q = new LinkedList<>();
        
        for (int i = 0; i < numCourses; i++){
            graph[i] = new ArrayList<>();
        }
        
        // adj list
        for (int[] p : prerequisites){
            graph[p[0]].add(p[1]);
        }
        
        for (int i = 0; i < numCourses; i++){
            if (dfs(i,visit,q)) return new int[0];
        }
        
        int i = 0;
        int[] res = new int[numCourses];
        while(!q.isEmpty()){
            res[i] = q.poll();
            i++;
        }
        
        return res;
    }
    
    private boolean dfs(int cur, int[] v, Queue<Integer> queue) {
        if (v[cur] == 1) return true;
        if (v[cur] == 2) return false;
        v[cur] = 1;
        for (int i = 0; i < graph[cur].size(); i++) {
            if (dfs((int) graph[cur].get(i), v, queue)) return true;
        }
        v[cur] = 2;
        queue.offer(cur);
        return false;
    }
}
