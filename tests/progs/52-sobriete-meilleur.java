package main.java.exercice;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Exercice {
	 public static List<String> solution(String texte, List<Character> ordre) {
	        List<String> mots = new ArrayList<>();
	        StringBuilder sb = new StringBuilder();
	        int n = texte.length();

	        for (int i = 0; i < n; i++) {
	            char c = texte.charAt(i);

	            if (Character.isLetter(c)) {
	                sb.append(c);
	            } else {
	                if (sb.length() > 0) {
	                    mots.add(sb.toString());
	                    sb.setLength(0);
	                }
	            }
	        }

	        if (sb.length() > 0) {
	            mots.add(sb.toString());
	        }

	        customSort(mots, ordre);
	        return mots;
	    }

	    private static void customSort(List<String> mots, List<Character> ordre) {
	        int[] orderIndex = new int[26];
	        Arrays.fill(orderIndex, ordre.size());

	        for (int i = 0; i < ordre.size(); i++) {
	            char c = ordre.get(i);
	            int index = c - 'a';
	            orderIndex[index] = i;
	        }

	        mots.sort((a, b) -> {
	            int minLength = Math.min(a.length(), b.length());

	            for (int i = 0; i < minLength; i++) {
	                char charA = a.charAt(i);
	                char charB = b.charAt(i);

	                if (charA != charB) {
	                    int indexA = charA - 'a';
	                    int indexB = charB - 'a';

	                    return Integer.compare(orderIndex[indexA], orderIndex[indexB]);
	                }
	            }

	            return Integer.compare(a.length(), b.length());
	        });
	    }
    
}
