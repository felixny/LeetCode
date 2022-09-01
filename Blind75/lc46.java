
import java.util.*;

public class lc46 {

    List<List<Integer>> res = new ArrayList<>();
    private int[] vis;

    public List<List<Integer>> permute(int[] nums) {
        vis = new int[nums.length];
        dfs(new ArrayList<>(), nums, 0);
        return res;
    }

    private void dfs(List<Integer> list, int[] nums, int index) {
        if (index == nums.length) {
            res.add(new ArrayList<>(list));
            System.out.println(Arrays.toString(res.toArray()));
        }

        for (int i = 0; i < nums.length; i++) {
            if (vis[i] != 1) {
                vis[i] = 1;
                list.add(nums[i]);
                dfs(list, nums, index + 1);
                list.remove(list.size() - 1);
                vis[i] = 0;
            }
        }
    }

    public static void main(String[] args) {
        lc46 lc46 = new lc46();
        int nums[] = {1,2,3};
        System.out.println(lc46.permute(nums));
    }

}
