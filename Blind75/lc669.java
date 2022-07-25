import java.util.*;
import javax.lang.model.util.*;

class lc669 {
    public int widthOfBinaryTree(TreeNode root) {
        int max = 0;
        Queue<Pair<TreeNode, Integer>> q = new LinkedList<>();
        
        q.offer(new Pair(root,0));
        
        while(!q.isEmpty()){
            int size = q.size();
            
            int start = 0, end = 0;
            for (int i = 0; i < size; i++){
                Pair<TreeNode, Integer> p = q.poll();
                TreeNode current = p.getKey();
                Integer idx = p.getValue();
                if (i == 0) start = idx;
                if (i == size -1) end = idx;
                
                if (current.left != null){
                    q.offer(new Pair(current.left, 2idx+1));
                }
                
                if (current.right != null){
                    q.offer(new Pair(current.right, 2idx+2));
                }
            }
            max = Math.max(max, end-start+1);
            
            
        }
        
        return max;
    }
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode() {}
        TreeNode(int val) { this.val = val; }
        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
}