import java.util.*;

public enum exampleData {
  ARROW("Arrow", map(new String[][] {
      { "noun",
          "Here is one arrow: <IMG> -=>> </IMG>" }
  })),

  BOOK("Book", map(new String[][] {
      { "noun",
          "A set of pages.",
          "A written work published in printed or electronic form." },
      { "verb",
          "To arrange for someone to have a seat on a plane.",
          "To arrange something on a particular date." }
  })),

  DISTINCT("Distinct", map(new String[][] {
      { "adjective",
          "Familiar. Worked in Java.",
          "Unique. No duplicates. Clearly different or of a different kind." },
      { "adverb",
          "Uniquely. Written \"distinctly\"." },
      { "noun",
          "A keyword in this assignment.",
          "A keyword in this assignment.",
          "A keyword in this assignment.",
          "An advanced search option.",
          "Distinct is a parameter in this assignment." }
  })),

  REVERSE("Reverse", map(new String[][] {
      { "adjective",
          "On back side.",
          "Opposite to usual or previous arrangement." },
      { "noun",
          "A dictionary program's parameter.",
          "Change to opposite direction.",
          "The opposite." },
      { "verb",
          "Go back",
          "Revoke ruling.",
          "To be updated...",
          "To be updated...",
          "Turn something inside out." }
  })),

  PLACEHOLDER("Placeholder", map(new String[][] {
      { "adjective", 
          "To be updated...", 
          "To be updated..." },
      { "adverb", 
          "To be updated..." },
      { "conjunction", 
          "To be updated..." },
      { "interjection", 
          "To be updated..." },
      { "noun", 
          "To be updated...", "To be updated...", "To be updated..." },
      { "preposition", 
          "To be updated..." },
      { "pronoun", 
          "To be updated..." },
      { "verb", 
          "To be updated..." }
  })),

  CAT("Cat", map(new String[][] {
      { "noun",
          "A small domesticated feline.",
          "A popular household pet." },
      { "verb",
          "To raise an anchor to the ship's cathead." }
  })),

  DOG("Dog", map(new String[][] {
      { "noun",
          "A loyal domesticated canine.",
          "A common household pet." },
      { "verb",
          "To follow persistently.",
          "To track with close attention." }
  })),

  BIRD("Bird", map(new String[][] {
      { "noun",
          "A creature with feathers and wings.",
          "An animal that lays eggs." },
      { "verb",
          "To watch birds as a hobby." }
  })),

  FISH("Fish", map(new String[][] {
      { "noun",
          "An aquatic animal that breathes through gills.",
          "A cold-blooded vertebrate living in water." },
      { "verb",
          "To try to catch fish.",
          "To search for something hidden." }
  })),

  HORSE("Horse", map(new String[][] {
      { "noun",
          "A large four-legged mammal used for riding.",
          "A strong domesticated animal with hooves." },
      { "verb",
          "To provide with a horse.",
          "To move something with great effort." }
  })),

  MOUSE("Mouse", map(new String[][] {
      { "noun",
          "A small rodent with a pointed snout.",
          "A timid or shy person." },
      { "verb",
          "To move a computer cursor using a mouse.",
          "To hunt or search like a cat after mice." }
  }));

  private final String word;
  private final Map<String, List<String>> entries; // POS -> definitions

  exampleData(String word, Map<String, List<String>> entries) {
    this.word = word;
    this.entries = entries;
  }

  public String getWord() {
    return word;
  }

  public Map<String, List<String>> getEntries() {
    return entries;
  }

  // method that lets me define my enums easier ! it converts 2d array into a map
private static Map<String, List<String>> map(String[][] rows) {
    Map<String, List<String>> m = new LinkedHashMap<String, List<String>>();  // used to be HashMap
    for (String[] row : rows) {
        String pos = row[0];
        String[] defsArr = Arrays.copyOfRange(row, 1, row.length);
        m.put(pos, Arrays.asList(defsArr));
    }
    return m;
}

}
