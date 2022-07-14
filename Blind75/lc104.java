import java.util.*;

public class lc104 {
    public int maxDepth(TreeNode root) {
        if (root == null) return 0;
        int right = 1 + maxDepth(root.right);
        int left = 1 + maxDepth(root.left);
        
        return Math.max(left,right);
    }

    // level order travesal
    public int maxDepth1(TreeNode root) {
        if (root == null)
                return 0;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        int height = 0;
        while (!q.isEmpty()) {
            int size = q.size();
            while (size-- > 0) {
                TreeNode temp = q.remove();
                if (temp.left != null)
                    q.add(temp.left);
                if (temp.right != null)
                    q.add(temp.right);
            }
            height++;
        }
        return height;
    }

    public class TreeNode{
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode() {}
        TreeNode(int val) {this.val = val;}
        TreeNode(int val, TreeNode left, TreeNode right){
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
}
