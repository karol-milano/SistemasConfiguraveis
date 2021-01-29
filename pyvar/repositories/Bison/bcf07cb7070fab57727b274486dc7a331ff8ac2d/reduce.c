@@ -382,26 +382,24 @@ reduce_output (FILE *out)
 static void
 reduce_print (void)
 {
-  fprintf (stderr, "%s: %s: ", grammar_file, _("warning"));
-
   if (nuseless_nonterminals > 0)
-    fprintf (stderr, ngettext ("%d nonterminal",
-			       "%d nonterminals",
-			       nuseless_nonterminals),
-	     nuseless_nonterminals);
-
-  if (nuseless_nonterminals > 0 && nuseless_productions > 0)
-    fprintf (stderr, _(" and "));
-
+    {
+      fprintf (stderr, "%s: %s: ", grammar_file, _("warning"));
+      fprintf (stderr, ngettext ("%d nonterminal useless in grammar",
+                                 "%d nonterminals useless in grammar",
+                                 nuseless_nonterminals),
+               nuseless_nonterminals);
+      fprintf (stderr, "\n");
+    }
   if (nuseless_productions > 0)
-    fprintf (stderr, ngettext ("%d rule",
-			       "%d rules",
-			       nuseless_productions),
-	     nuseless_productions);
-
-  if (nuseless_nonterminals > 0 || nuseless_productions > 0)
-    fprintf (stderr, _(" useless in grammar"));
-  fprintf (stderr, "\n");
+    {
+      fprintf (stderr, "%s: %s: ", grammar_file, _("warning"));
+      fprintf (stderr, ngettext ("%d rule useless in grammar",
+                                 "%d rules useless in grammar",
+                                 nuseless_productions),
+               nuseless_productions);
+      fprintf (stderr, "\n");
+    }
 }
 
 void
