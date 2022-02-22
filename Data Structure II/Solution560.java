import java.util.*;

public class Solution560 {
    public static int subarraySum(int[] nums, int k) {
        int answer = 0, prefixSum = 0;
        Map<Integer, Integer> prefixSumsFrequency = new HashMap<>();
        prefixSumsFrequency.put(0, 1);
        for (int i = 0; i < nums.length; i++) {
            prefixSum += nums[i];
            answer += prefixSumsFrequency.getOrDefault(prefixSum - k, 0);
            prefixSumsFrequency.put(prefixSum, prefixSumsFrequency.getOrDefault(prefixSum, 0) + 1);
        }
        return answer;
    }
    public static void main(String[] args) {
        int[] nums = { 1, 2, 3 };
        int k = 3;
        System.out.println(subarraySum(nums, k));
    }
}
