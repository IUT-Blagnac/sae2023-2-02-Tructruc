package exercice;

import java.util.ArrayList;
import java.util.List;

public class Exercice {
    public static List<String> solution(String str, List<Character> ordre) {
        String[] splited = str.split("\\s+|'|’");

        List<String> result = new ArrayList<>();

        ArrayList<String>[] tab = new ArrayList[ordre.size()+1];
        for (int i = 0; i < tab.length; i++){
            tab[i] = new ArrayList<>();
        }

        boolean found;
        List<String> notfound = new ArrayList<>();
        for (String s : splited){
            tab[(ordre.contains(s.charAt(0)) ? ordre.indexOf(s.charAt(0)) : tab.length-1 )].add(s);
        }

        for (ArrayList<String> list : tab){
            result.addAll(list);
        }
        result.addAll(notfound);
        return result;
    }
}
