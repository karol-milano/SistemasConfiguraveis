@@ -98,6 +98,7 @@
 #include "output.h"
 #include "lalr.h"
 #include "reader.h"
+#include "symtab.h"
 #include "conflicts.h"
 #include "muscle_tab.h"
 
@@ -252,7 +253,7 @@ output_rule_data (void)
       /* Be sure not to use twice the same quotearg slot. */
       const char *cp =
 	quotearg_n_style (1, c_quoting_style,
-			  quotearg_style (escape_quoting_style, tags[i]));
+			  quotearg_style (escape_quoting_style, symbols[i]->tag));
       /* Width of the next token, including the two quotes, the coma
 	 and the space.  */
       int strsize = strlen (cp) + 2;
@@ -1075,8 +1076,8 @@ yystype;\n\
 
       for (i = ntokens; i < nsyms; i++)
 	/* don't make these for dummy nonterminals made by gensym.  */
-	if (*tags[i] != '@')
-	  fprintf (out, "# define NT%s\t%d\n", tags[i], i);
+	if (*symbols[i]->tag != '@')
+	  fprintf (out, "# define NT%s\t%d\n", symbols[i]->tag, i);
     }
 
   fprintf (out, "\n#endif /* not %s */\n", macro_name);
