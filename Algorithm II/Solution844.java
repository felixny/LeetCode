public class Solution844 {
    public boolean backspaceCompare(String S, String T) {
        int sIdx = S.length() - 1; // S's index
        int tIdx = T.length() - 1; // T's index

        while(sIdx >= 0 || tIdx >= 0){
            sIdx = getValidIdx(S,sIdx);
            tIdx = getValidIdx(T,tIdx);
            if (S.charAt(sIdx) != T.charAt(tIdx)){
                return false;
            }
            sIdx--;
            tIdx--;
            
        }

        return sIdx == tIdx;
        
    }
    public int getValidIdx(String s, int index){
        int count = 0;
        while (index >=0){
            char c = s.charAt(index);
            if (c != '#' && count == 0){
                return index;
            }
            if (c != '#' && count > 0){
                count--;
            }
            if (c == '#'){
                count++;
            }
            index--;
        }
        return index;
    }
}
