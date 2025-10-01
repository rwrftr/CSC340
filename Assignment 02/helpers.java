import java.util.List;

public final class helpers {

  private helpers() {
  }

  public static void printHeader(int keywordCount, int definitionCount) {
    System.out.println("===== DICTIONARY 340 JAVA =====");
    System.out.println("----- Keywords: " + keywordCount);
    System.out.println("----- Definitions: " + definitionCount);
    System.out.println();
  }

  public static void printHowTo() {
    System.out.println(" |");
    System.out.println("  PARAMETER HOW-TO, please enter:");
    System.out.println("  1. A search key -then 2. An optional part of speech -then");
    System.out.println("  3. An optional 'distinct' -then 4. An optional 'reverse'");
    System.out.println(" |");
  }

  public static void printNotFound(String keyword) {
    System.out.println(" |");
    System.out.println(  "  <NOT FOUND> To be considered for the next release. Thank you.");
    System.out.println(" |");
    printHowTo();
  }

  public static void printAllKeywords(List<String> words) {
    System.out.println(" |");
    for (String w : words) {
      System.out.println(" " + w);
    }
    System.out.println(" |");
  }

  public static void printEntries(String keyword, List<dictionary.PosEntry> entries) {
    if (entries.isEmpty()) {
      printNotFound(keyword);
      return;
    }

    // make word appear with leading capital
    String displayWord = keyword.substring(0, 1).toUpperCase() +
        keyword.substring(1).toLowerCase();

    System.out.println(" |");
    for (dictionary.PosEntry group : entries) {
      for (String def : group.getDefinitions()) {
        System.out.println("  " + displayWord + " [" + group.getPos() + "] : " + def);
      }
    }
    System.out.println(" |");
  }

  public static void printThankYou() {
    System.out.println("\n----- THANK YOU -----");
  }

  public static void printWarn2nd(String t){
    System.out.println(" |");
    System.out.println("  <The entered 2nd parameter '" + t + "' is NOT a part of speech.>");
    System.out.println("  <The entered 2nd parameter '" + t + "' is NOT 'distinct'.>");
    System.out.println("  <The entered 2nd parameter '" + t + "' is NOT 'reverse'.>");
    System.out.println("  <The entered 2nd parameter '" + t + "' was disregarded.>");
    System.out.println("  <The 2nd parameter should be a part of speech or 'distinct' or 'reverse'.>");
    System.out.println(" |");
  }



  public static void printWarn3rd(String t){
    System.out.println(" |");
    System.out.println("  <The entered 3rd parameter '" + t + "' is NOT 'distinct'.>");
    System.out.println("  <The entered 3rd parameter '" + t + "' is NOT 'reverse'.>");
    System.out.println("  <The entered 3rd parameter '" + t + "' was disregarded.>");
    System.out.println("  <The 3rd parameter should be 'distinct' or 'reverse'.>");
    System.out.println(" |"); 
  }

  public static void printWarn4th(String t){
    System.out.println(" |");
    System.out.println("  <The entered 4th parameter '" + t + "' is NOT 'reverse'.>");
    System.out.println("  <The entered 4th parameter '" + t + "' was disregarded.>");
    System.out.println("  <The 4th parameter should be 'reverse'.>");
    System.out.println(" |"); 
  }

}