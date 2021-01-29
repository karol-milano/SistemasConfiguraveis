@@ -383,23 +383,15 @@ static void
 reduce_print (void)
 {
   if (nuseless_nonterminals > 0)
-    {
-      fprintf (stderr, "%s: %s: ", grammar_file, _("warning"));
-      fprintf (stderr, ngettext ("%d nonterminal useless in grammar",
-                                 "%d nonterminals useless in grammar",
-                                 nuseless_nonterminals),
-               nuseless_nonterminals);
-      fprintf (stderr, "\n");
-    }
+    warn (ngettext ("%d nonterminal useless in grammar",
+                    "%d nonterminals useless in grammar",
+                    nuseless_nonterminals),
+          nuseless_nonterminals);
   if (nuseless_productions > 0)
-    {
-      fprintf (stderr, "%s: %s: ", grammar_file, _("warning"));
-      fprintf (stderr, ngettext ("%d rule useless in grammar",
-                                 "%d rules useless in grammar",
-                                 nuseless_productions),
-               nuseless_productions);
-      fprintf (stderr, "\n");
-    }
+    warn (ngettext ("%d rule useless in grammar",
+                    "%d rules useless in grammar",
+                    nuseless_productions),
+          nuseless_productions);
 }
 
 void
