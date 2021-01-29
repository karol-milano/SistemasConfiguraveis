@@ -129,8 +129,8 @@ struct obstack output_obstack;
 /* FIXME. */
 
 static inline void
-output_table_data (struct obstack* oout, 
-		   short* table_data, 
+output_table_data (struct obstack *oout, 
+		   short *table_data, 
 		   short first, 
 		   short begin, 
 		   short end)
@@ -969,7 +969,7 @@ output_parser (void)
     }
   fskel = xfopen (skeleton, "r");
 
-  /* New output code. */
+  /* New output code.  */
   line = 1;
   c = getc (fskel);
   while (c != EOF)
@@ -983,14 +983,14 @@ output_parser (void)
 	}
       else if ((c = getc (fskel)) == '%')
 	{
-	  /* Read the macro. */
-	  const char* macro_key = 0;
-	  const char* macro_value = 0;
+	  /* Read the macro.  */
+	  const char *macro_key = 0;
+	  const char *macro_value = 0;
 	  while (isalnum (c = getc (fskel)) || c == '_')
 	    obstack_1grow (&macro_obstack, c);
 	  obstack_1grow (&macro_obstack, 0);
 
-	  /* Output the right value, or see if it's something special. */
+	  /* Output the right value, or see if it's something special.  */
 	  macro_key = obstack_finish (&macro_obstack);
 	  macro_value = macro_find (macro_key);
 	  if (macro_value)
@@ -1013,7 +1013,7 @@ output_parser (void)
 	obstack_1grow (&table_obstack, '%');
     }
 
-  /* End. */
+  /* End.  */
   xfclose (fskel);
 }
 
