import java.util.*;

public class lc78 {
    public List<List<Integer>> subsets(int[] nums){
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> subset = new ArrayList<>();

        dfs(res,subset, nums,0);

        return res;
    }

    private void dfs(List<List<Integer>> res, List<Integer> subset, int[] nums, int start){
        res.add(new ArrayList<>(subset));

        for (int i = start; i < nums.length; i++){
            subset.add(nums[i]);
            System.out.println(subset);
            dfs(res,subset,nums,i+1);
            subset.remove(subset.size()-1);
        }

    }

    public static void main(String[] args) {
        lc78 leetcode = new lc78();
        int[] nums = {1,2,3};
        System.out.println(leetcode.subsets(nums));
    }
}
