import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;

public class Solution39 {
    List<List<Integer>> ans = new ArrayList<>();

    public List<List<Integer>> combinationSum(int[] candidates, int target) {

        List<Integer> list = new ArrayList<>();
        Arrays.sort(candidates);
        dfs(candidates, 0, list, 0, target);

        return ans;
    }

    private void dfs(int[] num, int start, List<Integer> result, int sum, int target) {
        if (sum == target) {
            ans.add(new ArrayList<Integer>(result));
            return;
        }
        for (int i = start; i < num.length; i++) {
            if (i > start && num[i] == num[i - 1])
                continue; // if the set doesn't contains duplicates, then this line won't be needed.
            if (num[i] + sum > target)
                break;

            result.add(num[i]);
            dfs(num, i, result, sum + num[i], target);
            result.remove(result.size() - 1);
        }
    }

    public static void main(String[] args) {
        Solution39 leetcode = new Solution39();
        List<List<Integer>> result = leetcode.combinationSum(new int[] { 2, 3, 6, 7 }, 7);
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result.get(i).size(); j++) {
                System.out.print(result.get(i).get(j));
            }
            System.out.println();
        }
    }
}

/* https://cscircles.cemc.uwaterloo.ca/java_visualize/#code=import+java.util.ArrayList%3B%0Aimport+java.util.List%3B%0Aimport+java.util.Arrays%3B%0A%0Apublic+class+Solution39+%7B%0A++++List%3CList%3CInteger%3E%3E+ans+%3D+new+ArrayList%3C%3E()%3B%0A%0A++++public+List%3CList%3CInteger%3E%3E+combinationSum(int%5B%5D+candidates,+int+target)+%7B%0A%0A++++++++List%3CInteger%3E+list+%3D+new+ArrayList%3C%3E()%3B%0A++++++++Arrays.sort(candidates)%3B%0A++++++++dfs(candidates,+0,+list,+0,+target)%3B%0A%0A++++++++return+ans%3B%0A++++%7D%0A%0A++++private+void+dfs(int%5B%5D+num,+int+start,+List%3CInteger%3E+result,+int+sum,+int+target)+%7B%0A++++++++if+(sum+%3D%3D+target)+%7B%0A++++++++++++ans.add(new+ArrayList%3CInteger%3E(result))%3B%0A++++++++++++return%3B%0A++++++++%7D%0A++++++++for+(int+i+%3D+start%3B+i+%3C+num.length%3B+i%2B%2B)+%7B%0A++++++++++++if+(i+%3E+start+%26%26+num%5Bi%5D+%3D%3D+num%5Bi+-+1%5D)%0A++++++++++++++++continue%3B+//+if+the+set+doesn't+contains+duplicates,+then+this+line+won't+be+needed.%0A++++++++++++if+(num%5Bi%5D+%2B+sum+%3E+target)%0A++++++++++++++++break%3B%0A%0A++++++++++++result.add(num%5Bi%5D)%3B%0A++++++++++++dfs(num,+i,+result,+sum+%2B+num%5Bi%5D,+target)%3B%0A++++++++++++result.remove(result.size()+-+1)%3B%0A++++++++%7D%0A++++%7D%0A%0A++++public+static+void+main(String%5B%5D+args)+%7B%0A++++++++Solution39+leetcode+%3D+new+Solution39()%3B%0A++++++++List%3CList%3CInteger%3E%3E+result+%3D+leetcode.combinationSum(new+int%5B%5D+%7B+2,+3,+6,+7+%7D,+7)%3B%0A++++++++for+(int+i+%3D+0%3B+i+%3C+result.size()%3B+i%2B%2B)+%7B%0A++++++++++++for+(int+j+%3D+0%3B+j+%3C+result.get(i).size()%3B+j%2B%2B)+%7B%0A++++++++++++++++System.out.print(result.get(i).get(j))%3B%0A++++++++++++%7D%0A++++++++++++System.out.println()%3B%0A++++++++%7D%0A++++%7D%0A%7D%0A&mode=display&curInstr=59
 */