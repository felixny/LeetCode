import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
public class Solution49 {

    public static void main(String[] args) {        
        Solution49 main = new Solution49();
        String[] anagrams = new String[] {"eat","tea","tan","ate","nat","bat"};
        List<List<String>> result = main.groupAnagrams(anagrams);
        for(List<String> list : result) {
            for(String str : list) {
                System.out.print(str + ", ");
            }
            System.out.println();
        }
    }

    /* Solution */
    public List<List<String>> groupAnagrams(String[] strs) {

        String temp;
        char[] array;
        List<String> list;
        Map<String, List<String>> map = new HashMap<>();

        for (String str : strs) {
            array = str.toCharArray();
            System.out.print(array);
            System.out.print( '\n' );

            Arrays.sort(array);
            
            temp = String.valueOf(array);

            if (map.containsKey(temp)) {
                map.get(temp).add(str);
            } else {
                list = new ArrayList<>();
                list.add(str);
                map.put(temp, list);
            }
        }

        List<List<String>> result = new ArrayList<>();
        for (List<String> value : map.values()) {
            result.add(value);
        }
        return result;
    }

    

   
}