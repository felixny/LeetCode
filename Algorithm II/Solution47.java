import java.util.ArrayList;
import java.util.List;
// import java.util.Arrays;

public class Solution47 {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();

        dfs(result, nums, 0);
        return result;
    }

    private void dfs(List<List<Integer>> result, int[] nums, int start) {
      if (start == nums.length){
        result.add(toList(nums));
      } else {
        for (int i = start; i < nums.length; i++){
            if (i != start & !canPermutate(start, i, nums)) continue;
            swap(start, i, nums);
            dfs(result, nums, start+1);
            swap(start, i, nums);

        }
      }
        
    }

    public List<Integer> toList(int[] nums){
        List<Integer> l = new ArrayList<>();
        for (int i : nums){
            l.add(i);
        }

        return l;
    }

    public void swap(int i, int j, int[] nums){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    public boolean canPermutate(int start, int curr, int[] nums){
        for (int i = start; i < curr; i++){
            if (nums[i] == nums[curr]){
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        Solution47 leetcode = new Solution47();
        List<List<Integer>> result = leetcode.permuteUnique(new int[] { 1, 1, 2 });
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result.get(i).size(); j++) {
                System.out.print(result.get(i).get(j));
            }
            System.out.println();
        }
    }

}

/* https://cscircles.cemc.uwaterloo.ca/java_visualize/#code=import+java.util.ArrayList%3B%0Aimport+java.util.List%3B%0Aimport+java.util.Arrays%3B%0A%0Apublic+class+Solution90+%7B%0A++++public+List%3CList%3CInteger%3E%3E+subsetsWithDup(int%5B%5D+nums)+%7B%0A++++++++List%3CList%3CInteger%3E%3E+result+%3D+new+ArrayList%3C%3E()%3B%0A%0A++++++++if+(nums+%3D%3D+null+%7C%7C+nums.length+%3D%3D+0)+%7B%0A++++++++++++return+result%3B%0A++++++++%7D%0A%0A++++++++Arrays.sort(nums)%3B%0A%0A++++++++List%3CInteger%3E+subset+%3D+new+ArrayList%3C%3E()%3B%0A%0A++++++++dfs(nums,+result,+subset,+0)%3B%0A%0A++++++++return+result%3B%0A%0A++++%7D%0A%0A++++private+void+dfs(int%5B%5D+nums,+List%3CList%3CInteger%3E%3E+result,+List%3CInteger%3E+subset,+int+start)+%7B%0A++++++++result.add(new+ArrayList%3C%3E(subset))%3B%0A%0A++++++++for+(int+i+%3D+start%3B+i+%3C+nums.length%3B+i%2B%2B)%7B%0A++++++++++++//+to+avoid+duplicate%0A++++++++++++if+(i+!%3D+start+%26%26+nums%5Bi%5D+%3D%3D+nums%5Bi-1%5D)%7B%0A++++++++++++++++continue%3B%0A++++++++++++%7D%0A%0A++++++++++++subset.add(nums%5Bi%5D)%3B%0A++++++++++++dfs(nums,result,subset,i%2B1)%3B%0A++++++++++++subset.remove(subset.size()-1)%3B%0A++++++++%7D%0A++++%7D%0A%0A++++public+static+void+main(String%5B%5D+args)+%7B%0A++++++++Solution90+leetcode+%3D+new+Solution90()%3B%0A++++++++List%3CList%3CInteger%3E%3E+result+%3D+leetcode.subsetsWithDup(new+int%5B%5D+%7B+1,+2,+2+%7D)%3B%0A++++++++for+(int+i+%3D+0%3B+i+%3C+result.size()%3B+i%2B%2B)+%7B%0A++++++++++++for+(int+j+%3D+0%3B+j+%3C+result.get(i).size()%3B+j%2B%2B)+%7B%0A++++++++++++++++System.out.print(result.get(i).get(j))%3B%0A++++++++++++%7D%0A++++++++++++System.out.println()%3B%0A++++++++%7D%0A++++%7D%0A%0A%7D%0A&mode=display&curInstr=87 */
