public class lc75 {
    public void sortColors(int[] nums) {
	
        int i = 0;
        int j = 0;
        int k = nums.length-1;
        
        while(j<=k){
            if(nums[j] == 0){
                swap(nums,i,j);
                i++;
                j++;
            }else if(nums[j] == 1){
                j++;
            }else if(nums[j] == 2){
                swap(nums, j,k);
                k--;
            }           
        }
}
    
    public void swap(int [] nums, int i ,int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j]= temp;
    }

    public static void main(String[] args) {
        
    }
}
