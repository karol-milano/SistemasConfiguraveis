@@ -175,7 +175,7 @@ prepare_symbols (void)
 
 	if (i)
 	  obstack_1grow (&format_obstack, ' ');
-	MUSCLE_OBSTACK_SGROW (&format_obstack, cp);
+	obstack_escape (&format_obstack, cp);
         free (cp);
 	obstack_1grow (&format_obstack, ',');
 	j += width;
