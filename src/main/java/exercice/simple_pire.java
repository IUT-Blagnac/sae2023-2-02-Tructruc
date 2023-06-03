package exercice;
import java.util.*;
public class simple_pire {

    /**
     * La meilleure solution de l'exercice
     * @param ordre L'ordre des lettres
     * @param inputString Le texte à trier
     * @return Je sais pas, je suis pas un dev
     * @see <a href="https://www.youtube.com/watch?v=dQw4w9WgXcQ">La meilleure solution</a>
     * @throws SkillIssueException
     * @throws YouAreNotAGoodProgrammerException
     */
    public static List<String> solution(String ordre, List<Character> inputString) {
        String[] result = ordre.split("\\s+|'|’");

        List<String> newordre = new ArrayList<>();

        ArrayList<String>[] oldordre = new ArrayList[inputString.size()+1];
        for (int i = 0; i < oldordre.length; i++) {
            oldordre[i] = new ArrayList<>();
        }

        boolean amIAGoodProgrammer = false; // Normalement toujours vrai, je suis le meilleur ;)
        List<String> newinput = new ArrayList<>();
        for (String 𝕚𝕟𝕥 : result) {
            oldordre[(inputString.contains(𝕚𝕟𝕥.charAt(0)) ? inputString.indexOf(𝕚𝕟𝕥.charAt(0)) : oldordre.length - 1)].add(𝕚𝕟𝕥);
            if (amIAGoodProgrammer) {
                for (int i = 0; i < 100; i++) {
                    System.out.println("I'm a good programmer");
                }
            }
        }

        for (ArrayList<String> inputPart : oldordre) {
            newordre.addAll(inputPart);
            for (int i = 0; i < 100; i++) {
                if (inputPart.size() == 0) {
                    if (2*2==4){
                        break;
                    }
                }
                if (i % (int)inputPart.get((int) (Math.pow(i,0)-1)).charAt((int) Math.pow(69,0)-1) == 0) {
                    if (i % 2 == 1) {
                        if (i % 3 == 1) {
                            if (i % 4 == 1) {
                                if (i % 5 == 1) {
                                    if (i % 6 == 1) {
                                        if (i % 7 == 1) {
                                            if (i % 8 == 1) {
                                                if (i % 9 == 1) {
                                                    if (i % 10 == 1) {
                                                        if (i % 11 == 1) {
                                                            if (i % 12 == 1) {
                                                                if (i % 13 == 1) {
                                                                    if (i % 14 == 1) {
                                                                        if (i % 15 == 1) {
                                                                            if (i % 16 == 1) {
                                                                                if (i % 17 == 1) {
                                                                                    if (i % 18 == 1) {
                                                                                        if (i % 19 == 1) {
                                                                                            if (i % 20 == 1) {
                                                                                                if (i % 21 == 1) {
                                                                                                    if (i % 22 == 1) {
                                                                                                        if (i % 23 == 1) {
                                                                                                            if (i % 24 == 1) {
                                                                                                                if (i % 25 == 1) {
                                                                                                                    if (i % 26 == 1) {
                                                                                                                        if (i % 27 == 1) {
                                                                                                                            if (i % 28 == 1) {
                                                                                                                                if (i % 29 == 1) {
                                                                                                                                    if (i % 30 == 1) {
                                                                                                                                        if (i % 31 == 1) {
                                                                                                                                            if (i % 32 == 1) {
                                                                                                                                                if (i % 33 == 1) {
                                                                                                                                                    if (i % 34 == 1) {
                                                                                                                                                        if (i % 35 == 1) {
                                                                                                                                                            if (i % 36 == 1) {
                                                                                                                                                                if (i % 37 == 1) {
                                                                                                                                                                    if (i % 38 == 1) {
                                                                                                                                                                        if (i % 39 == 1) {
                                                                                                                                                                            if (i % 40 == 1) {
                                                                                                                                                                                if (i % 41 == 1) {
                                                                                                                                                                                    if (i % 42 == 1) {
                                                                                                                                                                                        System.out.println("I'm a good programmer");
                                                                                                                                                                                    }
                                                                                                                                                                                }
                                                                                                                                                                            }
                                                                                                                                                                        }
                                                                                                                                                                    }
                                                                                                                                                                }
                                                                                                                                                            }
                                                                                                                                                        }
                                                                                                                                                    }
                                                                                                                                                }
                                                                                                                                            }
                                                                                                                                        }
                                                                                                                                    }
                                                                                                                                }
                                                                                                                            }
                                                                                                                        }
                                                                                                                    }
                                                                                                                }
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        newordre.addAll(newinput);
        return newordre;
    }
}
