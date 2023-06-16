package exercice;

import java.util.ArrayList;
import java.util.List;

public class Exercice {
	public static List<String> solution(String texte, List<Character> ordre) {
		List<String> motsEnOrdre = new ArrayList<>();
		List<String> motsRestants = new ArrayList<>();

		StringBuilder constructMots = new StringBuilder();
		for (int i = 0; i < texte.length(); i++) {
			char c = texte.charAt(i);
			if (Character.isLetter(c)) {
				constructMots.append(c);
			} else if (constructMots.length() > 0) {
				motsRestants.add(constructMots.toString());
				constructMots.setLength(0);
			}
		}
		
		if (constructMots.length() > 0) {
			motsRestants.add(constructMots.toString()); //Ajouter les mots sans lettres dans ordre
		}

		List<String> motsASupprimer = new ArrayList<>(); 

		for (char ch : ordre) {
			for (String mot : motsRestants) {
				if (Character.toLowerCase(mot.charAt(0)) == Character.toLowerCase(ch)) {
					motsEnOrdre.add(mot);
					motsASupprimer.add(mot);
				}
			}
		}

		motsRestants.removeAll(motsASupprimer);
		motsEnOrdre.addAll(motsRestants);
		return motsEnOrdre;
	}
}
