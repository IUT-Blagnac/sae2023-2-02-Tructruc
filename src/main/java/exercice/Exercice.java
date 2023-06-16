package exercice;

import java.util.ArrayList;
import java.util.List;

public class Exercice {
    public static List<String> solution(String texte, List<Character> ordre) {
        List<String> motsTries = new ArrayList<>();
        List<String> motsSansOrdre = new ArrayList<>();
        String[] mots = texte.split(" ");

        for (String mot : mots) {
            if (aOrdre(mot, ordre)) {
                ajouterMot(motsTries, mot, ordre);
            } else {
                motsSansOrdre.add(mot);
            }
        }

        motsTries.addAll(motsSansOrdre);
        trierMots(motsTries, ordre);
        return motsTries;
    }

    private static boolean aOrdre(String mot, List<Character> ordre) {
        for (char c : mot.toCharArray()) {
            if (!ordre.contains(c)) {
                return false;
            }
        }
        return true;
    }

    private static void ajouterMot(List<String> motsTries, String mot, List<Character> ordre) {
        int index = 0;
        for (int i = 0; i < motsTries.size(); i++) {
            if (comparerMots(mot, motsTries.get(i), ordre) < 0) {
                index = i;
                break;
            }
        }
        motsTries.add(index, mot);
    }

    private static int comparerMots(String mot1, String mot2, List<Character> ordre) {
        int longueur1 = mot1.length();
        int longueur2 = mot2.length();
        int longueurMin = Math.min(longueur1, longueur2);

        for (int i = 0; i < longueurMin; i++) {
            char char1 = mot1.charAt(i);
            char char2 = mot2.charAt(i);
            int index1 = getIndex(ordre, char1);
            int index2 = getIndex(ordre, char2);

            if (index1 != -1 && index2 != -1) {
                if (index1 != index2) {
                    return index1 - index2;
                }
            } else if (index1 == -1 && index2 == -1) {
                continue;
            } else if (index1 == -1) {
                return 1;
            } else if (index2 == -1) {
                return -1;
            }
        }

        return longueur1 - longueur2;
    }

    private static int getIndex(List<Character> liste, char c) {
        for (int i = 0; i < liste.size(); i++) {
            if (liste.get(i).equals(c)) {
                return i;
            }
        }
        return -1;
    }

    private static void trierMots(List<String> motsTries, List<Character> ordre) {
        for (int i = 1; i < motsTries.size(); i++) {
            String mot = motsTries.get(i);
            int j = i - 1;
            while (j >= 0 && comparerMots(motsTries.get(j), mot, ordre) > 0) {
                motsTries.set(j + 1, motsTries.get(j));
                j--;
            }
            motsTries.set(j + 1, mot);
        }
    }
}
