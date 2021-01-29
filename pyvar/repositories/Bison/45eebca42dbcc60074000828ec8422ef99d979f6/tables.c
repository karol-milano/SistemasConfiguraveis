@@ -35,7 +35,7 @@
 #include "tables.h"
 
 /* Several tables are indexed both by state and nonterminal numbers.
-   We call such an index a `vector'; i.e., a vector is either a state
+   We call such an index a 'vector'; i.e., a vector is either a state
    or a nonterminal number.
 
    Of course vector_number_t ought to be wide enough to contain
@@ -90,18 +90,18 @@ static base_number *width;
 
 /* For a given state, N = ACTROW[SYMBOL]:
 
-   If N = 0, stands for `run the default action'.
-   If N = MIN, stands for `raise a syntax error'.
-   If N > 0, stands for `shift SYMBOL and go to n'.
-   If N < 0, stands for `reduce -N'.  */
+   If N = 0, stands for 'run the default action'.
+   If N = MIN, stands for 'raise a syntax error'.
+   If N > 0, stands for 'shift SYMBOL and go to n'.
+   If N < 0, stands for 'reduce -N'.  */
 typedef int action_number;
 #define ACTION_NUMBER_MINIMUM INT_MIN
 
 static action_number *actrow;
 
 /* FROMS and TOS are reordered to be compressed.  ORDER[VECTOR] is the
-   new vector number of VECTOR.  We skip `empty' vectors (i.e.,
-   TALLY[VECTOR] = 0), and call these `entries'.  */
+   new vector number of VECTOR.  We skip 'empty' vectors (i.e.,
+   TALLY[VECTOR] = 0), and call these 'entries'.  */
 static vector_number *order;
 static int nentries;
 
