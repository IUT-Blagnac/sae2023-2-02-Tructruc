package Simplicite_meilleur;

import java.util.*;

public class Exercice {
	
    public static List<String> solution(String str, List<Character> ordre) {
    	
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < ordre.size(); i++) {
            map.put(ordre.get(i), i);
        }

        String[] motsClasse = str.split(" ");

        Arrays.sort(motsClasse, (m1, m2) -> {
            int tailleMin = Math.min(m1.length(), m2.length());
            for (int i = 0; i < tailleMin; i++) {
                char c1 = m1.charAt(i);
                char c2 = m2.charAt(i);
                int order1 = map.containsKey(c1) ? map.get(c1) : Integer.MAX_VALUE;
                int order2 = map.containsKey(c2) ? map.get(c2) : Integer.MAX_VALUE;
                if (order1 != order2) {
                    return order1 - order2;
                }
            }
            return m1.length() - m2.length();
        });

        return Arrays.asList(motsClasse);
    }
}