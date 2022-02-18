
public class Solution334 {
    public boolean increasingTriplet(int[] nums) {
        if (nums.length == 0 || nums.length < 3) {
            return false;
        }

        int min1 = Integer.MAX_VALUE;
        int min2 = Integer.MAX_VALUE;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] < min1) {
                min1 = nums[i];
            }

            if (nums[i] > min1) {
                min2 = Math.min(nums[i], min2);
            }

            if (nums[i] > min2) {
                return true;
            }

        }
        return false;
    }
}
