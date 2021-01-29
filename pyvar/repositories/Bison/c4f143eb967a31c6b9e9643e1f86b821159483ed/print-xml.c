@@ -19,11 +19,12 @@
    along with this program.  If not, see <http://www.gnu.org/licenses/>.  */
 
 #include <config.h>
-#include "system.h"
+#include "print-xml.h"
 
-#include <stdarg.h>
+#include "system.h"
 
 #include <bitset.h>
+#include <stdarg.h>
 
 #include "closure.h"
 #include "conflicts.h"
@@ -32,7 +33,6 @@
 #include "gram.h"
 #include "lalr.h"
 #include "lr0.h"
-#include "print-xml.h"
 #include "print.h"
 #include "reader.h"
 #include "reduce.h"
@@ -57,7 +57,6 @@ static struct escape_buf escape_bufs[num_escape_bufs];
 static void
 print_core (FILE *out, int level, state *s)
 {
-  size_t i;
   item_number *sitems = s->items;
   size_t snritems = s->nitems;
 
@@ -74,7 +73,7 @@ print_core (FILE *out, int level, state *s)
 
   xml_puts (out, level, "<itemset>");
 
-  for (i = 0; i < snritems; i++)
+  for (size_t i = 0; i < snritems; i++)
     {
       bool printed = false;
       item_number *sp1 = ritem + sitems[i];
@@ -380,15 +379,13 @@ print_state (FILE *out, int level, state *s)
 static void
 print_grammar (FILE *out, int level)
 {
-  symbol_number i;
-
   fputc ('\n', out);
   xml_puts (out, level, "<grammar>");
   grammar_rules_print_xml (out, level);
 
   /* Terminals */
   xml_puts (out, level + 1, "<terminals>");
-  for (i = 0; i < max_user_token_number + 1; i++)
+  for (symbol_number i = 0; i < max_user_token_number + 1; i++)
     if (token_translations[i] != undeftoken->content->number)
       {
         char const *tag = symbols[token_translations[i]]->tag;
@@ -411,7 +408,7 @@ print_grammar (FILE *out, int level)
 
   /* Nonterminals */
   xml_puts (out, level + 1, "<nonterminals>");
-  for (i = ntokens; i < nsyms + nuseless_nonterminals; i++)
+  for (symbol_number i = ntokens; i < nsyms + nuseless_nonterminals; i++)
     {
       char const *tag = symbols[i]->tag;
       xml_printf (out, level + 2,
@@ -428,8 +425,7 @@ print_grammar (FILE *out, int level)
 void
 xml_indent (FILE *out, int level)
 {
-  int i;
-  for (i = 0; i < level; i++)
+  for (int i = 0; i < level; i++)
     fputs ("  ", out);
 }
 
@@ -460,14 +456,13 @@ xml_escape_string (struct escape_buf *buf, char const *str)
 {
   size_t len = strlen (str);
   size_t max_expansion = sizeof "&quot;" - 1;
-  char *p;
 
   if (buf->size <= max_expansion * len)
     {
       buf->size = max_expansion * len + 1;
       buf->ptr = x2realloc (buf->ptr, &buf->size);
     }
-  p = buf->ptr;
+  char *p = buf->ptr;
 
   for (; *str; str++)
     switch (*str)
@@ -498,11 +493,11 @@ xml_escape (char const *str)
 void
 print_xml (void)
 {
-  int level = 0;
-
   FILE *out = xfopen (spec_xml_file, "w");
 
   fputs ("<?xml version=\"1.0\"?>\n\n", out);
+
+  int level = 0;
   xml_printf (out, level,
               "<bison-xml-report version=\"%s\" bug-report=\"%s\""
               " url=\"%s\">",
@@ -517,27 +512,21 @@ print_xml (void)
   /* print grammar */
   print_grammar (out, level + 1);
 
-  no_reduce_set =  bitset_create (ntokens, BITSET_FIXED);
+  no_reduce_set = bitset_create (ntokens, BITSET_FIXED);
 
   /* print automaton */
   fputc ('\n', out);
   xml_puts (out, level + 1, "<automaton>");
-  {
-    state_number i;
-    for (i = 0; i < nstates; i++)
-      print_state (out, level + 2, states[i]);
-  }
+  for (state_number i = 0; i < nstates; i++)
+    print_state (out, level + 2, states[i]);
   xml_puts (out, level + 1, "</automaton>");
 
   bitset_free (no_reduce_set);
 
   xml_puts (out, 0, "</bison-xml-report>");
 
-  {
-    int i;
-    for (i = 0; i < num_escape_bufs; ++i)
-      free (escape_bufs[i].ptr);
-  }
+  for (int i = 0; i < num_escape_bufs; ++i)
+    free (escape_bufs[i].ptr);
 
   xfclose (out);
 }
