import java.util.ArrayList;
import java.util.List;


public class Solution986 {
    public int[][] intervalIntersection(int[][] firstList, int[][] secondList) {
        List<int[]> result = new ArrayList<>();
        int a = 0;
        int b = 0;
        while (a < firstList.length && b < secondList.length){
            int maxStart = Math.max(firstList[a][0], secondList[b][0]);
            int minEnd = Math.min(firstList[a][1], secondList[b][1]);
            if (maxStart <= minEnd){
                result.add(new int[]{maxStart, minEnd});
            }

            if (firstList[a][1] < secondList[b][1]){
                a++;
            } else {
                b++;
            }
        }

        int [][] ans = new int[result.size()][2];
        for (int i = 0; i < result.size(); i++){
            ans[i] = result.get(i);
        }

        return ans;


    }
}
