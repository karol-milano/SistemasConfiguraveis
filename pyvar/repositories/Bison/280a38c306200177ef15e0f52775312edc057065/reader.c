@@ -52,24 +52,24 @@ typedef struct symbol_list
 } symbol_list;
 
 int lineno;
-static symbol_list *grammar;
-static int start_flag;
-static bucket *startval;
+static symbol_list *grammar = NULL;
+static int start_flag = 0;
+static bucket *startval = NULL;
 
 /* Nonzero if components of semantic values are used, implying
    they must be unions.  */
 static int value_components_used;
 
 /* Nonzero if %union has been seen.  */
-static int typed;
+static int typed = 0;
 
 /* Incremented for each %left, %right or %nonassoc seen */
-static int lastprec;
+static int lastprec = 0;
 
-static bucket *errtoken = NULL;
-static bucket *undeftoken = NULL;
-static bucket *eoftoken = NULL;
-static bucket *axiom = NULL;
+bucket *errtoken = NULL;
+bucket *undeftoken = NULL;
+bucket *eoftoken = NULL;
+bucket *axiom = NULL;
 
 static symbol_list *
 symbol_list_new (bucket *sym)
@@ -1743,22 +1743,6 @@ packgram (void)
 void
 reader (void)
 {
-  start_flag = 0;
-  startval = NULL;		/* start symbol not specified yet. */
-
-  nsyms = 0;
-  nvars = 0;
-  nrules = 0;
-  nitems = 0;
-
-  typed = 0;
-  lastprec = 0;
-
-  semantic_parser = 0;
-  pure_parser = 0;
-
-  grammar = NULL;
-
   lex_init ();
   lineno = 1;
 
