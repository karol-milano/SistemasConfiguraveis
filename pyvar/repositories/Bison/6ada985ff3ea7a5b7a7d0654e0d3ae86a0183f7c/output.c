@@ -206,7 +206,9 @@ prepare_symbol_names (char const *muscle_name)
         : quotearg_alloc (symbols[i]->tag, -1, qo);
       /* Width of the next token, including the two quotes, the
          comma and the space.  */
-      int width = strlen (cp) + 2;
+      int width
+        = strlen (cp) + 2
+        + (!quote && symbols[i]->translatable ? strlen ("N_()") : 0);
 
       if (j + width > 75)
         {
@@ -216,7 +218,11 @@ prepare_symbol_names (char const *muscle_name)
 
       if (i)
         obstack_1grow (&format_obstack, ' ');
+      if (!quote && symbols[i]->translatable)
+        obstack_sgrow (&format_obstack, "N_(");
       obstack_escape (&format_obstack, cp);
+      if (!quote && symbols[i]->translatable)
+        obstack_1grow (&format_obstack, ')');
       free (cp);
       obstack_1grow (&format_obstack, ',');
       j += width;
