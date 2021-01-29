@@ -168,8 +168,7 @@ symbol_destructor_get (symbol *sym)
     return sym->destructor;
 
   /* Apply the default %destructor only to user-defined symbols.  */
-  if (sym == errtoken || sym == undeftoken || sym == accept
-      || UNIQSTR_EQ (sym->tag, uniqstr_new ("$end")))
+  if (sym->tag[0] == '$' || sym == errtoken)
     return NULL;
   return default_destructor;
 }
@@ -214,8 +213,7 @@ symbol_printer_get (symbol *sym)
     return sym->printer;
 
   /* Apply the default %printer only to user-defined symbols.  */
-  if (sym == errtoken || sym == undeftoken || sym == accept
-      || UNIQSTR_EQ (sym->tag, uniqstr_new ("$end")))
+  if (sym->tag[0] == '$' || sym == errtoken)
     return NULL;
   return default_printer;
 }
