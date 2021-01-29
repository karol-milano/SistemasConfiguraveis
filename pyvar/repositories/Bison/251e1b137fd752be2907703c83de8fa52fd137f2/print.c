@@ -22,6 +22,7 @@
 #include "system.h"
 
 #include <bitset.h>
+#include <mbswidth.h>
 
 #include "closure.h"
 #include "conflicts.h"
@@ -49,7 +50,7 @@ static bitset no_reduce_set;
 static void
 max_length (size_t *width, const char *str)
 {
-  size_t len = strlen (str);
+  size_t len = mbswidth (str, 0);
   if (len > *width)
     *width = len;
 }
@@ -130,7 +131,7 @@ print_transitions (state *s, FILE *out, bool display_transitions_p)
         state *s1 = trans->states[i];
 
         fprintf (out, "    %s", tag);
-        for (int j = width - strlen (tag); j > 0; --j)
+        for (int j = width - mbswidth (tag, 0); j > 0; --j)
           fputc (' ', out);
         if (display_transitions_p)
           fprintf (out, _("shift, and go to state %d\n"), s1->number);
@@ -168,7 +169,7 @@ print_errs (FILE *out, state *s)
       {
         const char *tag = errp->symbols[i]->tag;
         fprintf (out, "    %s", tag);
-        for (int j = width - strlen (tag); j > 0; --j)
+        for (int j = width - mbswidth (tag, 0); j > 0; --j)
           fputc (' ', out);
         fputs (_("error (nonassociative)\n"), out);
       }
@@ -187,7 +188,7 @@ print_reduction (FILE *out, size_t width,
                  rule *r, bool enabled)
 {
   fprintf (out, "    %s", lookahead_token);
-  for (int j = width - strlen (lookahead_token); j > 0; --j)
+  for (int j = width - mbswidth (lookahead_token, 0); j > 0; --j)
     fputc (' ', out);
   if (!enabled)
     fputc ('[', out);
@@ -232,7 +233,7 @@ print_reductions (FILE *out, state *s)
   /* Compute the width of the lookahead token column.  */
   size_t width = 0;
   if (default_reduction)
-    width = strlen (_("$default"));
+    width = mbswidth (_("$default"), 0);
 
   if (reds->lookahead_tokens)
     for (int i = 0; i < ntokens; i++)
@@ -404,7 +405,7 @@ print_nonterminal_symbols (FILE *out)
             break;
         }
 
-      int column = 4 + strlen (tag);
+      int column = 4 + mbswidth (tag, 0);
       fprintf (out, "%4s%s", "", tag);
       if (symbols[i]->content->type_name)
         column += fprintf (out, " <%s>",
