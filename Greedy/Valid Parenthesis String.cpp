Short Approach
      Use two counters:
      leftMin: minimum possible open brackets.
      leftMax: maximum possible open brackets.
      Traverse string:
      If '(' → increment both leftMin & leftMax.
      If ')' → decrement both.
      If '*' → it can be '(' or ')' or empty →
      → decrement leftMin (treat * as )),
      → increment leftMax (treat * as ().
      If at any point leftMax < 0 → too many ) → invalid.
      If leftMin < 0, reset to 0 (because * can balance it).
      At the end, if leftMin == 0, string is valid.


bool checkValidString(string s) {
    int leftMin = 0, leftMax = 0;          // range of possible '(' count

    for (char c : s) {
        if (c == '(') {
            leftMin++; leftMax++;          // '(' increases both
        } 
        else if (c == ')') {
            leftMin--; leftMax--;          // ')' decreases both
        } 
        else { // '*'
            leftMin--;                     // assume '*' as ')'
            leftMax++;                     // or assume '*' as '('
        }

        if (leftMax < 0) return false;     // too many ')'
        if (leftMin < 0) leftMin = 0;      // adjust: '*' can act as '('
    }
    return leftMin == 0;                   // all '(' matched
}
