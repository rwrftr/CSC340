import java.util.*;

public class MyFavoriteProgram {
    public static void main(String[] args) {
        Random rand = new Random();

        System.out.println("Please type an animal name (e.g., cat, dog, fish).");
        Scanner animalScanner = new Scanner(System.in);
        String animal = animalScanner.nextLine().toLowerCase();

        switch (animal) {
            case "cat":
                String[] cats = {
                    "  |\\---/|\n  | o_o |\n   \\_^_/",
                    "     /\\_/\\\n    ( o.o )\n     > ^ <"
                };
                System.out.println(cats[rand.nextInt(cats.length)]);
                break;

            case "dog":
                String[] dogs = {
                    "  /\\_/\\\n ( o.o )\n  > ^ <",
                    "  /^ ^\\\n / 0 0 \\\n V\\ Y /V\n   / - \\\n  |    \\\n  || (__V"
                };
                System.out.println(dogs[rand.nextInt(dogs.length)]);
                break;

            case "fish":
                String[] fish = {
                    "   ><(((º>",
                    "   ><>"
                };
                System.out.println(fish[rand.nextInt(fish.length)]);
                break;

            default:
                System.out.println("Sorry, I don't have ASCII art for that animal yet.");
        }
        animalScanner.close();
    }
}

