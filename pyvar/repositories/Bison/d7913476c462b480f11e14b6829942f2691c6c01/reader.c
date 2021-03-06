@@ -23,7 +23,7 @@
 #include "system.h"
 #include "getargs.h"
 #include "files.h"
-#include "alloc.h"
+#include "xalloc.h"
 #include "symtab.h"
 #include "lex.h"
 #include "gram.h"
@@ -390,7 +390,7 @@ parse_token_decl (int what_is, int what_is_not)
       if (token == TYPENAME)
 	{
 	  k = strlen (token_buffer);
-	  typename = NEW2 (k + 1, char);
+	  typename = XCALLOC (char, k + 1);
 	  strcpy (typename, token_buffer);
 	  value_components_used = 1;
 	  symbol = NULL;
@@ -516,7 +516,7 @@ parse_type_decl (void)
     }
 
   k = strlen (token_buffer);
-  name = NEW2 (k + 1, char);
+  name = XCALLOC (char, k + 1);
   strcpy (name, token_buffer);
 
   for (;;)
@@ -585,7 +585,7 @@ parse_assoc_decl (int assoc)
 
 	case TYPENAME:
 	  k = strlen (token_buffer);
-	  name = NEW2 (k + 1, char);
+	  name = XCALLOC (char, k + 1);
 	  strcpy (name, token_buffer);
 	  break;
 
@@ -774,7 +774,7 @@ parse_thong_decl (void)
   if (token == TYPENAME)
     {
       k = strlen (token_buffer);
-      typename = NEW2 (k + 1, char);
+      typename = XCALLOC (char, k + 1);
       strcpy (typename, token_buffer);
       value_components_used = 1;
       token = lex ();		/* fetch first token */
@@ -1216,8 +1216,7 @@ record_rule_line (void)
   if (nrules >= rline_allocated)
     {
       rline_allocated = nrules * 2;
-      rline = (short *) xrealloc ((char *) rline,
-				  rline_allocated * sizeof (short));
+      rline = XREALLOC (rline, short, rline_allocated);
     }
   rline[nrules] = lineno;
 }
@@ -1263,7 +1262,7 @@ get_type (void)
     }
 
   k = strlen (token_buffer);
-  name = NEW2 (k + 1, char);
+  name = XCALLOC (char, k + 1);
   strcpy (name, token_buffer);
 
   for (;;)
@@ -1361,7 +1360,7 @@ readgram (void)
 
 	  record_rule_line ();
 
-	  p = NEW (symbol_list);
+	  p = XCALLOC (symbol_list, 1);
 	  p->sym = lhs;
 
 	  crule1 = p1;
@@ -1439,19 +1438,19 @@ readgram (void)
 		  nrules++;
 		  nitems++;
 		  record_rule_line ();
-		  p = NEW (symbol_list);
+		  p = XCALLOC (symbol_list, 1);
 		  if (crule1)
 		    crule1->next = p;
 		  else
 		    grammar = p;
 		  p->sym = sdummy;
-		  crule1 = NEW (symbol_list);
+		  crule1 = XCALLOC (symbol_list, 1);
 		  p->next = crule1;
 		  crule1->next = crule;
 
 		  /* insert the dummy generated by that rule into this rule.  */
 		  nitems++;
-		  p = NEW (symbol_list);
+		  p = XCALLOC (symbol_list, 1);
 		  p->sym = sdummy;
 		  p1->next = p;
 		  p1 = p;
@@ -1462,7 +1461,7 @@ readgram (void)
 	      if (t == IDENTIFIER)
 		{
 		  nitems++;
-		  p = NEW (symbol_list);
+		  p = XCALLOC (symbol_list, 1);
 		  p->sym = symval;
 		  p1->next = p;
 		  p1 = p;
@@ -1477,7 +1476,7 @@ readgram (void)
 	    }			/* end of  read rhs of rule */
 
 	  /* Put an empty link in the list to mark the end of this rule  */
-	  p = NEW (symbol_list);
+	  p = XCALLOC (symbol_list, 1);
 	  p1->next = p;
 	  p1 = p;
 
@@ -1672,13 +1671,13 @@ packsymbols (void)
 
   /* int lossage = 0; JF set but not used */
 
-  tags = NEW2 (nsyms + 1, char *);
+  tags = XCALLOC (char *, nsyms + 1);
   tags[0] = DOLLAR;
-  user_toknums = NEW2 (nsyms + 1, short);
+  user_toknums = XCALLOC (short, nsyms + 1);
   user_toknums[0] = 0;
 
-  sprec = NEW2 (nsyms, short);
-  sassoc = NEW2 (nsyms, short);
+  sprec = XCALLOC (short, nsyms);
+  sassoc = XCALLOC (short, nsyms);
 
   max_user_token_number = 256;
   last_user_token_number = 256;
@@ -1749,7 +1748,7 @@ packsymbols (void)
     {
       int j;
 
-      token_translations = NEW2 (max_user_token_number + 1, short);
+      token_translations = XCALLOC (short, max_user_token_number + 1);
 
       /* initialize all entries for literal tokens to 2, the internal
          token number for $undefined., which represents all invalid
@@ -1827,12 +1826,12 @@ packgram (void)
 
   bucket *ruleprec;
 
-  ritem = NEW2 (nitems + 1, short);
-  rlhs = NEW2 (nrules, short) - 1;
-  rrhs = NEW2 (nrules, short) - 1;
-  rprec = NEW2 (nrules, short) - 1;
-  rprecsym = NEW2 (nrules, short) - 1;
-  rassoc = NEW2 (nrules, short) - 1;
+  ritem = XCALLOC (short, nitems + 1);
+  rlhs = XCALLOC (short, nrules) - 1;
+  rrhs = XCALLOC (short, nrules) - 1;
+  rprec = XCALLOC (short, nrules) - 1;
+  rprecsym = XCALLOC (short, nrules) - 1;
+  rassoc = XCALLOC (short, nrules) - 1;
 
   itemno = 0;
   ruleno = 1;
@@ -1906,7 +1905,7 @@ reader (void)
   nrules = 0;
   nitems = 0;
   rline_allocated = 10;
-  rline = NEW2 (rline_allocated, short);
+  rline = XCALLOC (short, rline_allocated);
 
   typed = 0;
   lastprec = 0;
