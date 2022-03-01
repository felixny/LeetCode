import java.util.ArrayList;
import java.util.List;

public class Solution438 {
    public List<Integer> findAnagrams(String s, String p) {
        
        List<Integer> res = new ArrayList<>();

        if (s == null || s.length() == 0 || s.length() < p.length()) return res;

        int[] phash = new int[26];
        int[] shash = new int[26];

        for (int i = 0; i < p.length(); i++){
            phash[p.charAt(i) - 'a']++;
            shash[s.charAt(i) - 'a']++;
        }

        if (phash.equals(shash)) res.add(0);

        for (int i = p.length(); i < s.length(); i++){
            shash[s.charAt(i)-'a']++;
            shash[s.charAt(i-p.length())-'a']--;
            if(compare(phash, shash)) res.add(i+1-p.length());
        }
        return res;
    }

    private boolean compare(int[] window, int[] count){
        for (int i = 0; i < 26; i++){
            if (window[i] != count[i]) return false;
        }
        return true;
    }
}
