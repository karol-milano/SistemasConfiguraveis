@@ -31,8 +31,7 @@
 #include "output.h"
 #include "reader.h"
 #include "conflicts.h"
-
-extern char *printable_version PARAMS ((int));
+#include "quote.h"
 
 /* Number of slots allocated (but not necessarily used yet) in `rline'  */
 static int rline_allocated;
@@ -266,7 +265,11 @@ copy_at (FILE *fin, FILE *fout, int stack_offset)
       locations_flag = 1;
     }
   else
-    complain (_("@%s is invalid"), printable_version (c));
+    {
+      char buf[] = "@c";
+      buf[1] = c;
+      complain (_("%s is invalid"), quote (buf));
+    }
 }
 
 /*-------------------------------------------------------------------.
@@ -702,7 +705,7 @@ static void
 parse_expect_decl (void)
 {
   int c;
-  int count;
+  size_t count;
   char buffer[20];
 
   c = getc (finput);
@@ -898,7 +901,9 @@ read_declarations (void)
 	fatal (_("no input grammar"));
       else
 	{
-	  complain (_("unknown character: %s"), printable_version (c));
+	  char buf[] = "c";
+	  buf[0] = c;
+	  complain (_("unknown character: %s"), quote (buf));
 	  skip_to_char ('%');
 	}
     }
@@ -1010,7 +1015,11 @@ copy_action (symbol_list * rule, int stack_offset)
 		  continue;
 		}
 	      else
-		complain (_("$%s is invalid"), printable_version (c));
+		{
+		  char buf[] = "$c";
+		  buf[1] = c;
+		  complain (_("%s is invalid"), quote (buf));
+		}
 
 	      break;
 
@@ -1159,7 +1168,11 @@ copy_guard (symbol_list * rule, int stack_offset)
 	      continue;
 	    }
 	  else
-	    complain (_("$%s is invalid"), printable_version (c));
+	    {
+	      char buf[] = "$c";
+	      buf[1] = c;
+	      complain (_("%s is invalid"), quote (buf));
+	    }
 	  break;
 
 	case '@':
@@ -1296,9 +1309,11 @@ readgram (void)
   symbol_list *p1;
   bucket *bp;
 
-  symbol_list *crule;		/* points to first symbol_list of current rule.  */
-  /* its symbol is the lhs of the rule.   */
-  symbol_list *crule1;		/* points to the symbol_list preceding crule.  */
+  /* Points to first symbol_list of current rule. its symbol is the
+     lhs of the rule.  */
+  symbol_list *crule;
+  /* Points to the symbol_list preceding crule.  */
+  symbol_list *crule1;
 
   p1 = NULL;
 
@@ -1309,7 +1324,8 @@ readgram (void)
       if (t == IDENTIFIER || t == BAR)
 	{
 	  int action_flag = 0;
-	  int rulelength = 0;	/* number of symbols in rhs of this rule so far  */
+	  /* Number of symbols in rhs of this rule so far */
+	  int rulelength = 0;
 	  int xactions = 0;	/* JF for error checking */
 	  bucket *first_rhs = 0;
 
@@ -1473,9 +1489,7 @@ readgram (void)
 	  if (t == GUARD)
 	    {
 	      if (!semantic_parser)
-		complain ("%s",
-			  _
-			  ("%guard present but %semantic_parser not specified"));
+		complain (_("%%guard present but %%semantic_parser not specified"));
 
 	      copy_guard (crule, rulelength);
 	      t = lex ();
@@ -1561,7 +1575,8 @@ readgram (void)
   if (nrules == 0)
     fatal (_("no rules in the input grammar"));
 
-  if (typed == 0		/* JF put out same default YYSTYPE as YACC does */
+  /* JF put out same default YYSTYPE as YACC does */
+  if (typed == 0
       && !value_components_used)
     {
       /* We used to use `unsigned long' as YYSTYPE on MSDOS,
@@ -1579,7 +1594,7 @@ readgram (void)
       {
 	complain (_
 		  ("symbol %s is used, but is not defined as a token and has no rules"),
-bp->tag);
+		  bp->tag);
 	bp->class = nterm_sym;
 	bp->value = nvars++;
       }
