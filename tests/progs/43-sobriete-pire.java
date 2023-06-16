package exercice;
import java.util.ArrayList;
import java.util.List;
public class Exercicesobrietepire {
    public static List<String> solution(String str, List<Character> ordre) {
            List<String> motsTries = new ArrayList<>();
            String[] motsNonTries = str.split("[^a-zA-Z0-9]+");
            List<String> motsTrouves = new ArrayList<>();
            List<String> motsNonTrouves = new ArrayList<>();


            if(str==""){
                return motsTries;
            }
            
            for (int i = 0; i < ordre.size(); i++) {
                char lettre = ordre.get(i);
                for (int j = 0; j < motsNonTries.length; j++) {
                    String mot = motsNonTries[j];
                    if (!mot.isEmpty() && mot.charAt(0) == lettre) {
                        motsTrouves.add(mot);
                    }
                }
            }
        
            for (int i = 0; i < motsNonTries.length; i++) {
                String mot = motsNonTries[i];
                if (!motsTrouves.contains(mot)) {
                    motsNonTrouves.add(mot);
                }
            }
        
            for (String mot : motsNonTrouves) {
                motsTrouves.add(mot);
            }
        
            return motsTrouves;
        
    }
}
