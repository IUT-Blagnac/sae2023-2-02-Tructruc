package exercice;

import java.util.*;

public class Main {
    public static void main(String[] args) {
	
        var gcBeans = ManagementFactory.getGarbageCollectorMXBeans();

        gcBeans.stream().forEach(gc -> {

            out.println(format("GC Name : %s", gc.getName()));
            var poolNames = gc.getMemoryPoolNames();
            if (poolNames != null) {
                List.of(poolNames).forEach(pool ->
                        out.println(format("Pool name %s", pool)));
            } else {
                out.println("No memory pools for " + gc.getName());
            }

        };

        List<String> expected1 = List.of("666", "the", "the", "number", "of", "beast");
        try {
            List<String> result1 = Exercice.solution("666, the number of the beast", List.of('6', 't', 'n', 'o', 'b'));
            if (expected1.equals(result1)) {
                System.out.println("OK");
            } else {
                System.out.println("NOK");
            }
        } catch (Exception e){
            System.out.println("NOK");
        }

        List<String> expected2 = List.of("OK");

        try{
            List<String> result2 = Exercice.solution("OK", List.of('a', 'b', 'c', 'd', 'e'));
            if (expected2.equals(result2)) {
                System.out.println("OK");
            } else {
                System.out.println("NOK");
            }
        } catch (Exception e){
            System.out.println("NOK");
        }

        List<String> expected3 = List.of("");
        try {
            List<String> result3 = Exercice.solution("", List.of('6', 't', 'n', 'o', 'b'));
            if (expected3.equals(result3)) {
                System.out.println("OK");
            } else {
                System.out.println("NOK");
            }
        } catch (Exception e){
            System.out.println("NOK");
        }


        List<String> expected4 = List.of("fait", "Il", "aujourd", "aout", "beau", "hui", "comme", "en");
        try{
            List<String> result4 = Exercice.solution("Il fait beau aujourd'hui comme en aout", List.of('f', 'I', 'z', 'u', 'k', 'a', 'b', 'o'));
            if (expected4.equals(result4)) {
                System.out.println("OK");
            } else {
                System.out.println("NOK");
            }
        } catch (Exception e){
            System.out.println("NOK");
        }


        String texte = "Il fait beau aout aujourd’hui comme en ";
        List<Character> ordre = List.of('f', 'I', 'z', 'u', 'k', 'a', 'b', 'o');
        long startTime = System.nanoTime();
        String out = Exercice.solution(texte,ordre).toString();
        long endTime = System.nanoTime();

        long duration = (endTime - startTime);
        System.out.println(duration);


    }
}
