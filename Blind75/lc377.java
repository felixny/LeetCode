public class lc377 {
    public int combinationSum4(int[] nums, int target) {
        // memoization
        int[] memo = new int[target+1];
        memo[0] = 1;
        for (int i = 1; i <= target; i++){
            for (int num : nums){
                if (num <= i){
                    memo[i] += memo[i-num];
                }
            }
        }
        return memo[target];
    }
}
