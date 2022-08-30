
import java.util.*;

public class lc207 {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        // This problem can be converted to finding if a graph contains a cycle.
        ArrayList<Integer>[] adj = new ArrayList[numCourses];
        for (int i = 0; i < numCourses; i++) {
            adj[i] = new ArrayList();
        }

        for (int[] pre : prerequisites) {
            adj[pre[0]].add(pre[1]);

            System.out.println(Arrays.toString(pre));
        }

        System.out.println(Arrays.toString(adj));

        int[] visited = new int[numCourses];
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0 && !dfs(adj, visited, i))
                return false;
        }

        return true;
    }

    private boolean dfs(ArrayList<Integer>[] adj, int[] visited, int v) {
        if (visited[v] == 1)
            return false; // being visited
        if (visited[v] == 2)
            return true;
        
        visited[v] = 1;
        System.out.println("pre visited: "+ visited[v]);

        for (int ad : adj[v]) {
            System.out.println(ad);
            // !False => true -> returns false
            if (!dfs(adj, visited, ad))
                return false;
        }
       
        visited[v] = 2;

        System.out.println("post visited: "+ visited[v]);

        return true;
    }

    public static void main(String[] args) {
        lc207 leetcode = new lc207();
        int[][] pre = { { 0, 1 }, { 2, 1 }, { 2, 3 } };
        int num = 4;
        System.out.println(leetcode.canFinish(num, pre));
    }
}
