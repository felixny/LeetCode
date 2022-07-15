public class lc11 {
    public int maxArea(int[] height){
        int left = 0;
        int right = height.length - 1;
        int max = 0;
        while (left < right){
            int h = Math.min(height[right],height[left]);
            max = Math.max(max,(right-left)*h);
            if (height[left] < height[right]){
                left++;
            } else {
                right--;
            }
        }

        return max;
    }

    public static void main(String[] args) {
        lc11 leetcode = new lc11();
        int[] height = {1,8,6,2,5,4,8,3,7};
        System.out.println(leetcode.maxArea(height));
    }
}
