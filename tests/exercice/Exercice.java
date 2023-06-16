package exercice;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Exercice {
    public static List<String> solution(String str, List<Character> ordre) {
        List<String> words = Arrays.asList(str.split("[^a-zA-Z0-9]"));
        List<String> sortedWords = new ArrayList<>();

        for (char c : ordre) {
            for (String word : words) {
                if (!sortedWords.contains(word) && word.charAt(0) == c) {
                    sortedWords.add(word);
                }
            }
        }
        
        for (String word : words) {
            
            if (!sortedWords.contains(word)) {
                sortedWords.add(word);
            }
        }

        return sortedWords;
    }
    
}
