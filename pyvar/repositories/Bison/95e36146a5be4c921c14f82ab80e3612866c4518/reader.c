@@ -351,7 +351,6 @@ parse_token_decl (symbol_class what_is, symbol_class what_is_not)
   int token = 0;
   char *typename = 0;
   struct bucket *symbol = NULL;	/* pts to symbol being defined */
-  int k;
 
   for (;;)
     {
@@ -370,9 +369,7 @@ parse_token_decl (symbol_class what_is, symbol_class what_is_not)
 	}
       if (token == TYPENAME)
 	{
-	  k = strlen (token_buffer);
-	  typename = XCALLOC (char, k + 1);
-	  strcpy (typename, token_buffer);
+	  typename = xstrdup (token_buffer);
 	  value_components_used = 1;
 	  symbol = NULL;
 	}
@@ -488,7 +485,6 @@ get_type_name (int n, symbol_list * rule)
 static void
 parse_type_decl (void)
 {
-  int k;
   char *name;
 
   if (lex () != TYPENAME)
@@ -498,9 +494,7 @@ parse_type_decl (void)
       return;
     }
 
-  k = strlen (token_buffer);
-  name = XCALLOC (char, k + 1);
-  strcpy (name, token_buffer);
+  name = xstrdup (token_buffer);
 
   for (;;)
     {
@@ -547,7 +541,6 @@ parse_type_decl (void)
 static void
 parse_assoc_decl (associativity assoc)
 {
-  int k;
   char *name = NULL;
   int prev = 0;
 
@@ -567,11 +560,8 @@ parse_assoc_decl (associativity assoc)
 
       switch (t)
 	{
-
 	case TYPENAME:
-	  k = strlen (token_buffer);
-	  name = XCALLOC (char, k + 1);
-	  strcpy (name, token_buffer);
+	  name = xstrdup (token_buffer);
 	  break;
 
 	case COMMA:
@@ -757,15 +747,13 @@ parse_thong_decl (void)
   int token;
   struct bucket *symbol;
   char *typename = 0;
-  int k, usrtoknum;
+  int usrtoknum;
 
   translations = 1;
   token = lex ();		/* fetch typename or first token */
   if (token == TYPENAME)
     {
-      k = strlen (token_buffer);
-      typename = XCALLOC (char, k + 1);
-      strcpy (typename, token_buffer);
+      typename = xstrdup (token_buffer);
       value_components_used = 1;
       token = lex ();		/* fetch first token */
     }
@@ -1253,9 +1241,7 @@ get_type (void)
       return t;
     }
 
-  k = strlen (token_buffer);
-  name = XCALLOC (char, k + 1);
-  strcpy (name, token_buffer);
+  name = xstrdup (token_buffer);
 
   for (;;)
     {
