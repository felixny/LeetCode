import java.util.ArrayList;
import java.util.List;
// import java.util.Arrays;

public class Solution22 {
    public List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<>();
        dfs(result, "", 0, 0, n);

        return result;

    }

    private void dfs(List<String> result, String cur, int open, int close, int n) {
        if (cur.length() == n * 2) {
            result.add(cur);
            return;
        }

        if (open < n)
            dfs(result, cur + "(", open + 1, close, n);
        if (close < open)
            dfs(result, cur + ")", open, close + 1, n);
    }

    public static void main(String[] args){
        Solution22 gp = new Solution22();
        List<String> result = gp.generateParenthesis(3);
        List<String> result1 = gp.generateParenthesis(4);
        System.out.println(result);
        System.out.println(result1);

    }
}
