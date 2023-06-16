package exercice;

import java.util.ArrayList;
import java.util.List;

public class Simplicite {
    public static List<String> solution(String str, List<Character> ordre) {

        if (str.length() == 0) return List.of("");

        String[] mots = str.split("[ .,'\"]+");
        List<String>  result = new ArrayList<>();

        for (Character lettre : ordre) {
            for (int i = 0; i < mots.length; i++) {
                if(mots[i].length() == 0) continue;
                if (mots[i].charAt(0) == lettre) {
                    result.add(mots[i]);
                }
            }
        }

        for (int i = 0; i < mots.length; i++) {
            if (!result.contains(mots[i])) {
                result.add(mots[i]);
            }
        }

        return result;
    }
}
