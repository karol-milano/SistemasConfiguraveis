@@ -1451,6 +1451,23 @@ readgram (void)
 	t = lex ();
       }
 
+  /* grammar has been read.  Do some checking */
+
+  if (nrules == 0)
+    fatal (_("no rules in the input grammar"));
+
+  /* Report any undefined symbols and consider them nonterminals.  */
+
+  for (bp = firstsymbol; bp; bp = bp->next)
+    if (bp->class == unknown_sym)
+      {
+	complain (_
+		  ("symbol %s is used, but is not defined as a token and has no rules"),
+		  bp->tag);
+	bp->class = nterm_sym;
+	bp->value = nvars++;
+      }
+
   /* Insert the initial rule, which line is that of the first rule
      (not that of the start symbol):
 
@@ -1466,25 +1483,9 @@ readgram (void)
   grammar = p;
   startval = axiom;
 
-  /* grammar has been read.  Do some checking */
-
   if (nsyms > MAXSHORT)
     fatal (_("too many symbols (tokens plus nonterminals); maximum %d"),
 	   MAXSHORT);
-  if (nrules == 0)
-    fatal (_("no rules in the input grammar"));
-
-  /* Report any undefined symbols and consider them nonterminals.  */
-
-  for (bp = firstsymbol; bp; bp = bp->next)
-    if (bp->class == unknown_sym)
-      {
-	complain (_
-		  ("symbol %s is used, but is not defined as a token and has no rules"),
-		  bp->tag);
-	bp->class = nterm_sym;
-	bp->value = nvars++;
-      }
 
   ntokens = nsyms - nvars;
 }
