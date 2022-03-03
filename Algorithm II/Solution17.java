import java.util.ArrayList;
import java.util.List;
// import java.util.Arrays;

public class Solution17 {
    final char[][] letters = { {}, {}, { 'a', 'b', 'c' }, { 'd', 'e', 'f' }, { 'g', 'h', 'i' }, { 'j', 'k', 'l' },
            { 'm', 'n', 'o' }, { 'p', 'q', 'r', 's' }, { 't', 'u', 'v' }, { 'w', 'x', 'y', 'z' } };

    public List<String> letterCombinations(String digits) {
        List<String> result = new ArrayList<>();
        int len = digits.length();
        // empty array
        if (len == 0)
            return result;
        dfs(0, len, new StringBuilder(), result, digits);
        return result;
    }

    public void dfs(int pos, int len, StringBuilder sb, List<String> result, String digits) {
        if (pos == len) {
            result.add(sb.toString());
            return;
        }
        char[] L = letters[Character.getNumericValue(digits.charAt(pos))];
        for (int i = 0; i < L.length; i++) {
            dfs(pos + 1, len, new StringBuilder(sb).append(L[i]), result, digits);
        }
    }

    public static void main(String[] args) {
        Solution17 leetcode = new Solution17();
        List<String> result = leetcode.letterCombinations("23");
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result.get(i).length(); j++) {
                System.out.print(result.get(i).charAt(j));
            }
            System.out.println();
        }
    }

}

/* https://cscircles.cemc.uwaterloo.ca/java_visualize/#code=import+java.util.ArrayList%3B%0Aimport+java.util.List%3B%0Aimport+java.util.Arrays%3B%0A%0Apublic+class+Solution17+%7B%0A++++final+char%5B%5D%5B%5D+letters+%3D+%7B+%7B%7D,+%7B%7D,+%7B+'a',+'b',+'c'+%7D,+%7B+'d',+'e',+'f'+%7D,+%7B+'g',+'h',+'i'+%7D,+%7B+'j',+'k',+'l'+%7D,%0A++++++++++++%7B+'m',+'n',+'o'+%7D,+%7B+'p',+'q',+'r',+'s'+%7D,+%7B+'t',+'u',+'v'+%7D,+%7B+'w',+'x',+'y',+'z'+%7D+%7D%3B%0A%0A++++public+List%3CString%3E+letterCombinations(String+digits)+%7B%0A++++++++List%3CString%3E+result+%3D+new+ArrayList%3C%3E()%3B%0A++++++++int+len+%3D+digits.length()%3B%0A++++++++//+empty+array%0A++++++++if+(len+%3D%3D+0)%0A++++++++++++return+result%3B%0A++++++++dfs(0,+len,+new+StringBuilder(),+result,+digits)%3B%0A++++++++return+result%3B%0A++++%7D%0A%0A++++public+void+dfs(int+pos,+int+len,+StringBuilder+sb,+List%3CString%3E+result,+String+digits)+%7B%0A++++++++if+(pos+%3D%3D+len)+%7B%0A++++++++++++result.add(sb.toString())%3B%0A++++++++++++return%3B%0A++++++++%7D%0A++++++++char%5B%5D+L+%3D+letters%5BCharacter.getNumericValue(digits.charAt(pos))%5D%3B%0A++++++++for+(int+i+%3D+0%3B+i+%3C+L.length%3B+i%2B%2B)+%7B%0A++++++++++++dfs(pos+%2B+1,+len,+new+StringBuilder(sb).append(L%5Bi%5D),+result,+digits)%3B%0A++++++++%7D%0A++++%7D%0A%0A++++public+static+void+main(String%5B%5D+args)+%7B%0A++++++++Solution17+leetcode+%3D+new+Solution17()%3B%0A++++++++List%3CString%3E+result+%3D+leetcode.letterCombinations(%2223%22)%3B%0A++++++++for+(int+i+%3D+0%3B+i+%3C+result.size()%3B+i%2B%2B)+%7B%0A++++++++++++for+(int+j+%3D+0%3B+j+%3C+result.get(i).length()%3B+j%2B%2B)+%7B%0A++++++++++++++++System.out.print(result.get(i).charAt(j))%3B%0A++++++++++++%7D%0A++++++++++++System.out.println()%3B%0A++++++++%7D%0A++++%7D%0A%0A%7D%0A&mode=display&curInstr=57 */