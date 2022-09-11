import java.util.*;

public class lc828 {
    public int uniqueLetterString(String s) {
        HashMap<Character, List<Integer>> map = new HashMap<>();
        int n = s.length();
        
        // store character's position
        for (int i = 0; i < n; i++){
            char ch = s.charAt(i);
         
            map.putIfAbsent(ch, new ArrayList<>());
            map.get(ch).add(i);
        }
        
        int result = 0;
        for (List<Integer> index : map.values()){
            for (int i = 0; i < index.size(); i++){
                int left, right;
                System.out.println(index.get(i));
                if (i == 0){
                    left = index.get(i)+1;
                } else {
                    left = index.get(i)-index.get(i-1);
                }
                
                if (i == index.size()-1){
                    right = n-index.get(i);
                } else {
                    right = index.get(i+1) - index.get(i);
                }
                // int left = i == 0 ? index.get(i)+1 : index.get(i)-index.get(i-1);
                // int right = i == index.size()-1 ? n-index.get(i) : index.get(i+1) - index.get(i);
                result += left*right;
            }
        }
        
        return result;
    }

    public static void main(String[] args) {
        lc828 lc828 = new lc828();
        String s = "ABC";
        lc828.uniqueLetterString(s);
    }
}
