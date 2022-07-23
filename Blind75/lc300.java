import java.util.*;

public class lc300 {
    public int lengthOfLIS(int[] nums){
        if (nums == null || nums.length == 0) return 0;

        int[] max = new int[nums.length];
        Arrays.fill(max,1);

        int res = 1;
        for (int i = 0; i < nums.length; i++){
            for (int j = 0; j < i; j++){
                System.out.println("i: " + i);
                System.out.println("j: " + j);
                System.out.println("nums[i]: " + nums[i]);
                System.out.println("nums[j]: " + nums[j]);
                if (nums[i] > nums[j]){
                    max[i] = Math.max(max[i],max[j]+1);
                }
            }
            res = Math.max(max[i],res);
        }
        return res;
    }

    public static void main(String[] args) {
        lc300 leetcode = new lc300();
        int[] nums = {9,1,3,7,5,6,20};

        System.out.println(leetcode.lengthOfLIS(nums));
    }
}
