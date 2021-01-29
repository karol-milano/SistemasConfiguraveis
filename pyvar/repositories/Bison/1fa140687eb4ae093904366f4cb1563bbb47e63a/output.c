@@ -130,14 +130,14 @@ static size_t
 get_lines_number (const char *s)
 {
   size_t lines = 0;
-  
+
   size_t i;
   for (i = 0; s[i]; ++i)
     {
       if (s[i] == '\n')
 	++lines;
-    }   
-  
+    }
+
   return lines;
 }
 
@@ -148,8 +148,8 @@ static inline void
 output_table_data (struct obstack *oout,
 		   short *table_data,
 		   short first,
-		   short begin,
-		   short end)
+		   int begin,
+		   int end)
 {
   int i;
   int j = 1;
@@ -941,7 +941,7 @@ output_parser (const char *skel_filename, FILE *out)
 	    {
 	      fputs (muscle_value, out);
 	      output_line += get_lines_number (muscle_value);
-	    }	  
+	    }
 	  else
 	    {
 	      fputs ("%%", out);
