import java.util.*;
class Solution {

    List<String> words;

    void go (String now) {
        if(now.length() > 5) return;
        if(words.contains(now)) return;
        words.add(now);
        go(now + "A");
        go(now + "E");
        go(now + "I");
        go(now + "O");
        go(now + "U");
    }
    public int solution(String word) {
        this.words = new ArrayList();
        go("");
        for(int i=1; i<words.size();i++){
            if(words.get(i).equals(word)) return i;
        }
        return 0;
    }
}
