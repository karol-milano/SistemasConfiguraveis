@@ -60,7 +60,7 @@ bool error_verbose = false;
 #define GENERATE_MUSCLE_INSERT_TABLE(Name, Type)			\
 									\
 static void								\
-Name (const char *name,							\
+Name (char const *name,							\
       Type *table_data,							\
       Type first,							\
       int begin,							\
@@ -162,10 +162,7 @@ prepare_symbols (void)
     int j = 2;
     for (i = 0; i < nsyms; i++)
       {
-	char const *tag = symbols[i]->tag;
-	char const *cp = (*tag == '"'
-			  ? tag
-			  : quotearg_style (c_quoting_style, tag));
+	char const *cp = quotearg_style (c_quoting_style, symbols[i]->tag);
 	/* Width of the next token, including the two quotes, the
 	   comma and the space.  */
 	int width = strlen (cp) + 2;
