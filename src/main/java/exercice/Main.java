package exercice;

import java.util.*;

public class    Main {
    public static void main(String[] args) {
        String texte = "Il fait beau aujourd’hui comme en aout";
        List<Character> ordre = List.of('f', 'I', 'z', 'u', 'k', 'a', 'b', 'o');
        long startTime = System.nanoTime();
        String out = simple_pire.solution(texte,ordre).toString();
        long endTime = System.nanoTime();

        long duration = (endTime - startTime);
        System.out.println("Execution time: " + duration + "ns");
        System.out.println(out);

    }
}
