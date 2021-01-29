@@ -41,12 +41,13 @@ location_t startsymbol_location;
 `---------------------------------*/
 
 static symbol_t *
-symbol_new (const char *tag)
+symbol_new (const char *tag, location_t location)
 {
   symbol_t *res = XMALLOC (symbol_t, 1);
 
   res->tag = xstrdup (tag);
   res->type_name = NULL;
+  res->location = location;
   res->number = NUMBER_UNDEFINED;
   res->prec = 0;
   res->assoc = right_assoc;
@@ -170,8 +171,9 @@ symbol_check_defined (symbol_t *this)
 {
   if (this->class == unknown_sym)
     {
-      complain
-	(_("symbol %s is used, but is not defined as a token and has no rules"),
+      complain_at
+	(this->location,
+	 _("symbol %s is used, but is not defined as a token and has no rules"),
 	 this->tag);
       this->class = nterm_sym;
       this->number = nvars++;
@@ -363,7 +365,7 @@ symbols_new (void)
 `----------------------------------------------------------------*/
 
 symbol_t *
-getsym (const char *key)
+getsym (const char *key, location_t location)
 {
   symbol_t probe;
   symbol_t *entry;
@@ -374,7 +376,7 @@ getsym (const char *key)
   if (!entry)
     {
       /* First insertion in the hash. */
-      entry = symbol_new (key);
+      entry = symbol_new (key, location);
       hash_insert (symbol_table, entry);
     }
   return entry;
@@ -488,7 +490,9 @@ symbols_pack (void)
   symbols_token_translations_init ();
 
   if (startsymbol->class == unknown_sym)
-    fatal (_("the start symbol %s is undefined"), startsymbol->tag);
+    fatal_at (startsymbol_location,
+	      _("the start symbol %s is undefined"), startsymbol->tag);
   else if (startsymbol->class == token_sym)
-    fatal (_("the start symbol %s is a token"), startsymbol->tag);
+    fatal_at (startsymbol_location,
+	      _("the start symbol %s is a token"), startsymbol->tag);
 }
