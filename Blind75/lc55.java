public class lc55{
    public boolean canJump(int[] nums) {
        int canJump = 0;
        int n = nums.length;
        for (int i = 0; i < n ; i++){
            // if initial value is 0 then its impossible
            if(canJump < i) return false;
            canJump = Math.max(canJump, i + nums[i]);
        }
        
        return true;
    }
}