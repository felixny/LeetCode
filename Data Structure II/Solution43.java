

public class Solution43 {

    public static void main(String[] args){
        String num1 = "123";
        String num2 = "456";

        Solution43 main = new Solution43();
        String result = main.multiply(num1,num2);
        System.out.println(result);
        // testing out
      }
    

    public String multiply(String nums1, String nums2){
        if (nums1.equals("0") || nums2.equals("0")) return "0";
        if (nums1.equals("1")) return nums2;
        if (nums2.equals("1")) return nums1;

        int arr[]=new int[nums1.length()+nums2.length()];

        for (int i = nums1.length()-1; i>= 0; i--){
            for (int j = nums2.length()-1; j>=0;j--){
                arr[i+j+1] += (nums1.charAt(i) - '0') * (nums2.charAt(j) - '0');
                arr[i+j] += arr[i+j+1]/10;
                arr[i+j+1] %= 10;
            }
        }

        StringBuilder ans  = new StringBuilder();
        for (int i = 0; i < arr.length; i++){
            if (ans.length() == 0 && arr[i] == 0) continue;
            ans.append(arr[i]);
        }

        return ans.toString();

    }

 
}
