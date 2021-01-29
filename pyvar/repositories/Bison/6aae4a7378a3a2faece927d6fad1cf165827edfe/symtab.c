@@ -243,7 +243,11 @@ semantic_type_new (uniqstr tag, const location *loc)
 | Print a symbol.  |
 `-----------------*/
 
-#define SYMBOL_ATTR_PRINT(Attr)                         \
+#define SYMBOL_INT_ATTR_PRINT(Attr)                     \
+  if (s->content)                                       \
+    fprintf (f, " %s = %d", #Attr, s->content->Attr)
+
+#define SYMBOL_STR_ATTR_PRINT(Attr)                     \
   if (s->content && s->content->Attr)                   \
     fprintf (f, " %s { %s }", #Attr, s->content->Attr)
 
@@ -264,7 +268,11 @@ symbol_print (symbol const *s, FILE *f)
                : c == nterm_sym    ? "nterm"
                : NULL, /* abort.  */
                s->tag);
-      SYMBOL_ATTR_PRINT (type_name);
+      putc (' ', f);
+      location_print (s->location, f);
+      SYMBOL_INT_ATTR_PRINT (code);
+      SYMBOL_INT_ATTR_PRINT (number);
+      SYMBOL_STR_ATTR_PRINT (type_name);
       SYMBOL_CODE_PRINT (destructor);
       SYMBOL_CODE_PRINT (printer);
     }
@@ -573,9 +581,9 @@ symbol_class_set (symbol *sym, symbol_class class, location loc, bool declaring)
 }
 
 
-/*------------------------------------------------.
-| Set the USER_TOKEN_NUMBER associated with SYM.  |
-`------------------------------------------------*/
+/*----------------------------.
+| Set the token code of SYM.  |
+`----------------------------*/
 
 void
 symbol_code_set (symbol *sym, int code, location loc)
@@ -1000,7 +1008,7 @@ symbol_cmp (void const *a, void const *b)
 }
 
 /* Store in *SORTED an array of pointers to the symbols contained in
-   TABLE, sorted (alphabetically) by tag. */
+   TABLE, sorted by order of appearance (i.e., by location). */
 
 static void
 table_sort (struct hash_table *table, symbol ***sorted)
