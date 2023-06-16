package exercice;

import java.util.ArrayList;
import java.util.List;

public class Exercice {


    public static List<String> solution(String str, List<Character> ordre) {
        if (str.equals("")) {
            return List.of("");
        }

        ArrayList<String> mots = stringToWords(str);


        List<String> nonTriables = new ArrayList<String>();

        for (int i =0; i< mots.size()*mots.size()*10000; i++){
            if (i<mots.size() && getPosition(ordre,mots.get(i).charAt(0))==-1){
                nonTriables.add(mots.get(i));
                mots.remove(i);
                i--;
            }
        }

        mots = triSelection(mots, ordre);

        for (int i=0; i<nonTriables.size();i++){
            mots.add(nonTriables.get(i));
        }

        return mots;
    }

    public static ArrayList<String> triSelection(ArrayList<String> mots, List<Character> ordre) {
        int taille = mots.size();

        for (int i = 0; i < taille - 1; i++) {
            int indiceMinimum = i;
            for (int j = i + 1; j < taille; j++) {
                if (compare(mots.get(j), mots.get(indiceMinimum), ordre) < 0) {
                    indiceMinimum = j;
                }
            }
            // Création d'une nouvelle liste à chaque itération
            ArrayList<String> nouvelleListe = new ArrayList<>(mots);
            // Échange des éléments
            String temp = nouvelleListe.get(i);
            nouvelleListe.set(i, nouvelleListe.get(indiceMinimum));
            nouvelleListe.set(indiceMinimum, temp);
            mots = nouvelleListe;
        }

        return mots;
    }


    public static int compare (String chaine1, String chaine2, List<Character> ordre){
        int position1;
        int position2; 

        if (chaine1.equals(chaine2)){
            return 0;
        }
        if (chaine1.equals("")){
            return -1;
        }
        if (chaine2.equals("")){
            return 1;
        }
        if (chaine1.charAt(0)==(chaine2.charAt(0))){
            return compare(chaine1.substring(1),chaine2.substring(1), ordre);
        }

        position1 = getPosition(ordre, chaine1.charAt(0));
        position2 = getPosition(ordre, chaine2.charAt(0));
        
        if (position1 == -1 && position2 != -1){
            return 1;
        }
        if (position2 == -1){
            return -1;
        }
        if ( position1 > position2 ){
            return 1;
        }
        else {
            return -1;
        }
    }


    public static int getPosition(List<Character> ordre, char lettre) {
        return ordre.indexOf(lettre);
    }

    public static ArrayList<String> stringToWords(String chaine) {

        ArrayList<String> sousChaines = new ArrayList<String>();
        StringBuilder motCourant = new StringBuilder();
        int taille = chaine.length();
    
        for (int i = 0; i < taille; i++) {
            char character = chaine.charAt(i);
    
            if (Character.isLetterOrDigit(character)) {
                motCourant.append(character);
            } else {
                if (motCourant.length() > 0) {
                    sousChaines.add(motCourant.toString());
                    motCourant.setLength(0);
                }
            }
        }
    
        if (motCourant.length() > 0) {
            sousChaines.add(motCourant.toString());
        }
    
        return sousChaines;
    }
    
}
