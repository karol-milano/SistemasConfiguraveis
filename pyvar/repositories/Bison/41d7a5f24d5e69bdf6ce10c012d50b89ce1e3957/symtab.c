@@ -168,6 +168,23 @@ symbol_type_set (symbol *sym, uniqstr type_name, location loc)
     }
 }
 
+/*-----------------------------------.
+| Get the CLASS associated with SYM. |
+`-----------------------------------*/
+
+const char *
+symbol_class_get_string (symbol *sym)
+{
+  if (sym->class)
+    {
+      if (sym->class == token_sym)
+	return "terminal";
+      else if (sym->class == nterm_sym)
+	return "nonterminal";
+    }
+  return "unknown";
+}
+
 
 /*-----------------------------------------.
 | Set the DESTRUCTOR associated with SYM.  |
