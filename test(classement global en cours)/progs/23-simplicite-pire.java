package exercice;
import java.util.List;
import java.util.Map;
import java.util.ArrayList;
import java.util.HashMap;
public class simplicite {
	public static String trierMots(String phrase, List<Character> alphabet) {
        Map<Character, List<String>> motsParLettre = new HashMap<>();
        for (char lettre : alphabet) {
            motsParLettre.put(lettre, new ArrayList<>());
        }
        String[] mots = phrase.toLowerCase().split("\\W+");
        for (String mot : mots) {
            if (!mot.isEmpty()) {
                char premiereLettre = mot.charAt(0);
                if (motsParLettre.containsKey(premiereLettre)) {
                    motsParLettre.get(premiereLettre).add(mot);
                }
            }
        }
        StringBuilder phraseTrie = new StringBuilder();
        for (char lettre : alphabet) {
            List<String> motsDeLaLettre = motsParLettre.get(lettre);
            for (String mot : motsDeLaLettre) {
                phraseTrie.append(mot).append(" ");
            }
        }
        return phraseTrie.toString().trim();
    }
}
