@@ -29,21 +29,21 @@
 struct hash_table macro_table;
 
 static unsigned long
-mhash1 (const void* item)
+mhash1 (const void *item)
 {
-  return_STRING_HASH_1 (((macro_entry_t*) item)->key);
+  return_STRING_HASH_1 (((macro_entry_t *) item)->key);
 }
 
 static unsigned long
-mhash2 (const void* item)
+mhash2 (const void *item)
 {
-  return_STRING_HASH_2 (((macro_entry_t*) item)->key);
+  return_STRING_HASH_2 (((macro_entry_t *) item)->key);
 }
 
 static int
-mcmp (const void* x, const void* y)
+mcmp (const void *x, const void *y)
 {
-  return strcmp (((macro_entry_t*) x)->key, ((macro_entry_t*) y)->key);
+  return strcmp (((macro_entry_t*) x)->key, ((macro_entry_t *) y)->key);
 }
 
 void
@@ -51,18 +51,18 @@ macro_init (void)
 {
   hash_init (&macro_table, MTABSIZE, &mhash1, &mhash2, &mcmp);
 
-  /* Version and input file. */
+  /* Version and input file.  */
   macro_insert ("version", VERSION);
   macro_insert ("filename", "a.y");
 
-  /* Types. */
+  /* Types.  */
   macro_insert ("stype", "int");
   macro_insert ("ltype", "yyltype");
 
-  /* Tokens. */
+  /* Tokens.  */
   macro_insert ("tokendef", "");
 
-  /* Tables. */
+  /* Tables.  */
   macro_insert ("rhs", "0");
   macro_insert ("pact", "0");
   macro_insert ("prhs", "0");
@@ -76,7 +76,7 @@ macro_init (void)
   macro_insert ("defgoto", "0");
   macro_insert ("translate", "0");
 
-  /* Various macros. */
+  /* Various macros.  */
   macro_insert ("flag", "0");
   macro_insert ("last", "0");
   macro_insert ("pure", "0");
@@ -87,7 +87,7 @@ macro_init (void)
   macro_insert ("ntbase", "0");
   macro_insert ("verbose", "0");
 
-  /* Variable prefix names. */
+  /* Variable prefix names.  */
   macro_insert ("yyparse", "yyparse");
   macro_insert ("yylex", "yylex");
   macro_insert ("yyerror", "yyerror");
@@ -96,24 +96,24 @@ macro_init (void)
   macro_insert ("yydebug", "yydebug");
   macro_insert ("yynerrs", "yynerrs");
 
-  /* No parser macros. */
+  /* No parser macros.  */
   macro_insert ("nnts", "0");
   macro_insert ("nrules", "0");
   macro_insert ("nstates", "0");
   macro_insert ("ntokens", "0");
 
-  /* Stack parameters. */
+  /* Stack parameters.  */
   macro_insert ("maxdepth", "10000");
   macro_insert ("initdepth", "200");
 
-  /* C++ macros. */
+  /* C++ macros.  */
   macro_insert ("name", "Parser");
 }
 
 void 
 macro_insert (const char *key, const char *value)
 {
-  macro_entry_t* pair = XMALLOC (macro_entry_t, 1);
+  macro_entry_t *pair = XMALLOC (macro_entry_t, 1);
   pair->key = key;
   pair->value = value;
   hash_insert (&macro_table, pair);
@@ -123,6 +123,6 @@ const char*
 macro_find (const char *key)
 {
   macro_entry_t pair = { key, 0 };
-  macro_entry_t* result = hash_find_item (&macro_table, &pair);
+  macro_entry_t *result = hash_find_item (&macro_table, &pair);
   return result ? result->value : 0;
 }
