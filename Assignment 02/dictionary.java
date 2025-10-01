import java.util.*;

public final class dictionary {

  // class for holding definitions by part of speech
  public static final class PosEntry {
    private final String pos; // for this program pos = part of speach!!! not point of sale or the one with cuss words 
    private final List<String> definitions;

    public PosEntry(String pos, List<String> defs) {
      this.pos = pos;
      this.definitions = new ArrayList<String>(defs);
    }

    public String getPos() {
      return pos;
    }

    public List<String> getDefinitions() {
      return new ArrayList<String>(definitions);
    }
  }

  private final Map<String, List<PosEntry>> dictionaryMap = new HashMap<String, List<PosEntry>>();

  public dictionary() {
  }

  // get data from exampleData enum, load it into dictionary
  public void loadData() {
    dictionaryMap.clear();

    for (exampleData data : exampleData.values()) {
      String word = data.getWord();
      Map<String, List<String>> byPos = data.getEntries();

      List<PosEntry> groups = new ArrayList<PosEntry>();
      for (String pos : byPos.keySet()) {
        List<String> defs = byPos.get(pos);
        groups.add(new PosEntry(pos, defs));
      }
      dictionaryMap.put(word, groups);
    }
  }

  public int getKeywordCount() {
    return dictionaryMap.size();
  }

  public int getDefinitionCount() {
    int total = 0;
    for (List<PosEntry> groups : dictionaryMap.values()) {
      for (PosEntry g : groups) {
        total += g.getDefinitions().size();
      }
    }
    return total;
  }

  public List<String> getAllKeywordsSorted() {
    List<String> sortedList = new ArrayList<String>(dictionaryMap.keySet());
    Collections.sort(sortedList);
    return sortedList;
  }

  // search by keyword, returns deep copy
  public List<PosEntry> getEntriesFor(String raw) {
    if (raw == null || raw.isEmpty()){ return new ArrayList<PosEntry>(); }

    String key = normalize(raw);
    List<PosEntry> groups = dictionaryMap.get(key);

    if (groups == null){ return new ArrayList<PosEntry>(); }

    List<PosEntry> copy = new ArrayList<PosEntry>();

    for (PosEntry g : groups) { copy.add(new PosEntry(g.getPos(), g.getDefinitions())); }

    return copy;
  }

  private static String normalize(String s) {
    if (s.length() == 0) { return s; }
    if (s.length() == 1) { return s.substring(0, 1).toUpperCase(); }

    return s.substring(0, 1).toUpperCase() + s.substring(1).toLowerCase();
  }
}
