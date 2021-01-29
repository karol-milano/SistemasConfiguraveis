@@ -19,11 +19,6 @@
    Boston, MA 02111-1307, USA.  */
 
 
-/* set_derives finds, for each variable (nonterminal), which rules can
-   derive it.  It sets up the value of derives so that derives[i -
-   ntokens] points to a vector of rule numbers, terminated with -1.
-   */
-
 #include "system.h"
 #include "getargs.h"
 #include "types.h"
@@ -31,8 +26,7 @@
 #include "gram.h"
 #include "derives.h"
 
-short **derives;
-
+short **derives = NULL;
 
 static void
 print_derives (void)
@@ -51,7 +45,7 @@ print_derives (void)
 	  fprintf (stderr, "\t\t%d:", *sp);
 	  for (rhsp = ritem + rule_table[*sp].rhs; *rhsp > 0; ++rhsp)
 	    fprintf (stderr, " %s", tags[*rhsp]);
-	  fputc ('\n', stderr);
+	  fprintf (stderr, " (rule %d)\n", -*rhsp);
 	}
     }
 
