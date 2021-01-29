@@ -1637,9 +1637,9 @@ readgram (void)
   grammar = p;
   startval = axiom;
 
-  if (nsyms > MAXSHORT)
+  if (nsyms > SHRT_MAX)
     fatal (_("too many symbols (tokens plus nonterminals); maximum %d"),
-	   MAXSHORT);
+	   SHRT_MAX);
 
   assert (nsyms == ntokens + nvars);
 }
@@ -1741,11 +1741,7 @@ packgram (void)
   int ruleno;
   symbol_list *p;
 
-  /* We use short to index items.  */
-  if (nritems >= MAXSHORT)
-    fatal (_("too many items (max %d)"), MAXSHORT);
-
-  ritem = XCALLOC (short, nritems + 1);
+  ritem = XCALLOC (item_number_t, nritems + 1);
   rules = XCALLOC (rule_t, nrules) - 1;
 
   itemno = 0;
