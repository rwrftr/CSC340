import java.util.*;

public class app {
  private static final Set<String> POS = new HashSet<String>();
  static {
    POS.add("noun");
    POS.add("verb");
    POS.add("adjective");
    POS.add("adverb");
    POS.add("conjunction");
    POS.add("interjection");
    POS.add("preposition");
    POS.add("pronoun");
  }

  public static void main(String[] args) {
    dictionary dict = new dictionary();

    System.out.println("! Loading data...");
    dict.loadData();
    System.out.println("! Loading completed...\n");

    helpers.printHeader(dict.getKeywordCount(), dict.getDefinitionCount());

    // MAIN LOOP !!
    Scanner sc = new Scanner(System.in);
    int queryNum = 1;

    while (true) {
      System.out.print("Search [" + queryNum + "]: ");
      String line = sc.nextLine().trim();

      if (line.equals("!q")) {
        helpers.printThankYou();
        break;
      }
      if (line.equals("!help")) {
        helpers.printHowTo();
        queryNum++;
        continue;
      }
      if (line.equals("!words")) {
        helpers.printAllKeywords(dict.getAllKeywordsSorted());
        queryNum++;
        continue;
      }

      if (line.isEmpty()) {
        helpers.printHowTo();
        queryNum++;
        continue;
      }

      // split up for [keyword] [pos] [distinct] [reverse]
      // distinct/reverse dont care for order and part of speech is optional
      String[] tokens = line.split(" ");
      String rawKeyword = tokens[0];
      String posFilter = null;
      boolean useDistinct = false;
      boolean useReverse = false;

      for (int i = 1; i < tokens.length; i++) {
        String t = tokens[i].toLowerCase();
        if (t.equals("distinct")) {
          useDistinct = true;
        } else if (t.equals("reverse")) {
          useReverse = true;
        } else if (POS.contains(t)) {
          posFilter = t;
        } else {
          if(i == 1 ){ helpers.printWarn2nd(t); }
          if(i == 2 ){ helpers.printWarn3rd(t); }
          if(i == 3 ){ helpers.printWarn4th(t); }
        }
      }

      // Lookup entries
      List<dictionary.PosEntry> groups = dict.getEntriesFor(rawKeyword);

      if (groups.isEmpty()) {
        helpers.printNotFound(rawKeyword);
        queryNum++;
        continue;
      }

      // Apply optional filters in the assignment’s typical order:
      // 1) part-of-speech, 2) distinct, 3) reverse
      if (posFilter != null) {
        groups = filterByPos(groups, posFilter);
      }
      if (useDistinct) {
        groups = applyDistinct(groups);
      }
      if (useReverse) {
        groups = applyReverse(groups);
      }

      helpers.printEntries(rawKeyword, groups);
      queryNum++;
    }

    sc.close();
  }

  // ============ extra helpers !

  // filter the result list by part of speech
  private static List<dictionary.PosEntry> filterByPos(List<dictionary.PosEntry> input, String wantPos) {
    if (input == null || input.isEmpty() || wantPos == null) { return input; }

    List<dictionary.PosEntry> filteredList = new ArrayList<dictionary.PosEntry>();

    for (dictionary.PosEntry g : input) {
      if (g.getPos().equalsIgnoreCase(wantPos)) {
        filteredList.add(new dictionary.PosEntry(g.getPos(), g.getDefinitions()));
      }
    }
    return filteredList;
  }

  // remove duplicates
  private static List<dictionary.PosEntry> applyDistinct(List<dictionary.PosEntry> input) {
    if (input == null || input.isEmpty()) { return input; }

    HashSet<String> seen = new HashSet<String>();
    List<dictionary.PosEntry> filteredList = new ArrayList<dictionary.PosEntry>();

    for (dictionary.PosEntry g : input) {
      List<String> defs = g.getDefinitions(); // copy returned by dictionary
      List<String> uniqeList = new ArrayList<String>();
      for (String d : defs) {
        if (!seen.contains(d)) {
          seen.add(d);
          uniqeList.add(d);
        }
      }
      if (!uniqeList.isEmpty()) {
        filteredList.add(new dictionary.PosEntry(g.getPos(), uniqeList));
      }
    }
    return filteredList;
  }

  // Reverse group order AND reverse definitions within each group.  
  private static List<dictionary.PosEntry> applyReverse(List<dictionary.PosEntry> input) {
    if (input == null || input.isEmpty())
      return input;

    List<dictionary.PosEntry> reversedList = new ArrayList<dictionary.PosEntry>();
    for (int i = input.size() - 1; i >= 0; i--) {
      dictionary.PosEntry g = input.get(i);
      List<String> defs = g.getDefinitions(); // copy
      Collections.reverse(defs);
      reversedList.add(new dictionary.PosEntry(g.getPos(), defs));
    }
    return reversedList;
  }
}
