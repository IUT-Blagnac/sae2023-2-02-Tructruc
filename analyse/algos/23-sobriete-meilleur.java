package exercice;

import java.util.*;


public class sobriete {
	public static String trierMots(String phrase, List<Character> alphabet) {
        // Créer un tableau de listes de mots pour chaque lettre de l'alphabet donné (prend moins de place car limité a 26)
        List<String>[] motsParLettre = new List[26];
        for (int i = 0; i < 26; i++) {
            motsParLettre[i] = new ArrayList<>();
        }

        // Diviser la phrase en mots
        String[] mots = phrase.toLowerCase().split("\\W+");

        // Parcourir chaque mot et l'ajouter à la liste correspondante dans le tableau
        for (String mot : mots) {
            if (!mot.isEmpty()) {
                char premiereLettre = mot.charAt(0);
                if (Character.isLetter(premiereLettre)) {
                    int index = Character.toLowerCase(premiereLettre) - 'a';
                    motsParLettre[index].add(mot);
                }
            }
        }

        // Créer une liste de mots triés en parcourant le tableau et concaténant les listes de mots
        StringBuilder phraseTrie = new StringBuilder();
        for (char lettre : alphabet) {
            int index = Character.toLowerCase(lettre) - 'a';
            List<String> motsDeLaLettre = motsParLettre[index];
            for (String mot : motsDeLaLettre) {
                phraseTrie.append(mot).append(" ");
            }
        }

        return phraseTrie.toString().trim();
    }
}
