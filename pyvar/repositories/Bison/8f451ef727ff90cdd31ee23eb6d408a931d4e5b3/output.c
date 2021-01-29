@@ -130,7 +130,7 @@ struct obstack output_obstack;
 
 static inline void
 output_table_data (struct obstack* oout, 
-		   short* table, 
+		   short* table_data, 
 		   short first, 
 		   short begin, 
 		   short end)
@@ -149,7 +149,7 @@ output_table_data (struct obstack* oout,
 	}
       else
 	++j;
-      obstack_fgrow1 (oout, "%6d", table[i]);
+      obstack_fgrow1 (oout, "%6d", table_data[i]);
     }
   obstack_1grow (oout, 0);
 }
@@ -984,8 +984,8 @@ output_parser (void)
       else if ((c = getc (fskel)) == '%')
 	{
 	  /* Read the macro. */
-	  char* macro_key = 0;
-	  char* macro_value = 0;
+	  const char* macro_key = 0;
+	  const char* macro_value = 0;
 	  while (isalnum (c = getc (fskel)) || c == '_')
 	    obstack_1grow (&macro_obstack, c);
 	  obstack_1grow (&macro_obstack, 0);
