class Solution238 {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int output[] = new int[nums.length];
        
        output[0] = 1;
        
        int product = 1;
        
        for (int i = 0; i < n; i++){
            output[i] = product;
            product *= nums[i];
        }
        
        product = 1;
        for (int i = n - 1; i >= 0; i--){
            output[i] *= product;
            product *= nums[i];
        }
        return output;
    }
}