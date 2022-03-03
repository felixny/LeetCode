import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;

public class Solution40 {
    List<List<Integer>> ans = new ArrayList<>();

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {

        List<Integer> list = new ArrayList<>();
        Arrays.sort(candidates);
        dfs(candidates, 0, list, 0, target);

        return ans;
    }

    private void dfs(int[] num, int start, List<Integer> result, int sum, int target) {
        if (sum == target) {
            ans.add(new ArrayList<Integer>(result));
            return;
        }
        for (int i = start; i < num.length; i++) {
            if (i > start && num[i] == num[i - 1])
                continue; // if the set doesn't contains duplicates, then this line won't be needed.
            if (num[i] + sum <= target) {
                result.add(num[i]);
                dfs(num, i + 1, result, sum + num[i], target);
                result.remove(result.size() - 1);
            }

        }
    }

    public static void main(String[] args) {
        Solution40 leetcode = new Solution40();
        List<List<Integer>> result = leetcode.combinationSum2(new int[] { 10, 1, 2, 7, 6, 1, 5 }, 8);
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result.get(i).size(); j++) {
                System.out.print(result.get(i).get(j));
            }
            System.out.println();
        }
    }
}
