package exercice;

import java.util.ArrayList;
import java.util.List;

public class Exercice {
    public static List<String> solution(String str, List<Character> ordre) {
        // Contient le texte splité en mots
        String[] splited = str.split("[^a-zA-Z0-9]+");

        // Liste qui va contenir le résultat
        List<String> result = new ArrayList<>();

        // Tableau d’array list de string qui va permettre de stocker les mots dans le bon ordre
        ArrayList<String>[] tab = new ArrayList[ordre.size()+1];
        // Initialise les array lists
        for (int i = 0; i < tab.length; i++) {
            tab[i] = new ArrayList<>();
        }

        // Liste des mots qui ne commencent pas par un caractère de l’ordre
        List<String> notfound = new ArrayList<>();
        for (String s : splited) {
            // vérifie si la première lettre du mot est dans l’ordre, si oui, on l’ajoute a la liste correspondante
            // Si il n’y est pas, on l’ajoute a la liste des mots qui ne sont pas ordonné
            if (ordre.contains(s.charAt(0))){
                tab[ordre.indexOf(s.charAt(0))].add(s);
            }else{
                notfound.add(s);
            }
        }

        // Ajoute le contenu des listes a la liste de sortie
        for (ArrayList<String> list : tab) {
            result.addAll(list);
        }

        // ajoute la liste des mots inconnu a la liste de sortie
        result.addAll(notfound);

        // retourne la liste de sortie
        return result;
    }
}
