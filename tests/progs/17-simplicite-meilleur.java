package exercice;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Exercice {
    public static List<String> solution(String str, List<Character> ordre) {

        int i, j;
        List<String> listeMots = new ArrayList<>();
        String[] mots = str.split("[^a-zA-Z0-9]+");

        if (str.isEmpty()) {
            return listeMots;
        } else {
            listeMots = new ArrayList<>(Arrays.asList(mots));
        }

        for (i = 0; i < listeMots.size()-1; i++) {
            for (j = 0; j < listeMots.size()-1-i ; j++) {
                if (compareWithOrder(listeMots.get(j), listeMots.get(j+1), ordre) > 0) {
                    String temp = listeMots.get(j);
                    listeMots.set(j, listeMots.get(j+1));
                    listeMots.set(j+1, temp);
                }
            }
        }

        return listeMots;
    }

    public static int compareWithOrder(String mot1, String mot2, List<Character> ordre) {
        int longueurMotMin = Math.min(mot1.length(), mot2.length());
        
        for (int i = 0; i < longueurMotMin; i++) {
            char char1 = mot1.charAt(i);
            char char2 = mot2.charAt(i);
            
            if (char1 != char2) {
                int index1 = ordre.indexOf(char1);
                int index2 = ordre.indexOf(char2);
                
                if (index1 != -1 && index2 != -1) {
                    return Integer.compare(index1, index2);
                } else if (index1 != -1) {
                    return -1;
                } else if (index2 != -1) {
                    return 1;
                } else {
                    return -1;
                }
            }
        }
        
        return Integer.compare(mot1.length(), mot2.length());
    }  

}