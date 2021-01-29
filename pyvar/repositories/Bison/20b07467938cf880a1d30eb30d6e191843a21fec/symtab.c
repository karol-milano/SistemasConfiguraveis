@@ -302,6 +302,19 @@ semantic_type_redeclaration (semantic_type *s, const char *what, location first,
                    _("previous declaration"));
 }
 
+static void
+complain_class_redeclared (symbol *sym, symbol_class class, location second)
+{
+  unsigned i = 0;
+  complain_indent (&second, complaint, &i,
+                   class == token_sym
+                   ? _("symbol %s redeclared as a token")
+                   : _("symbol %s redeclared as a nonterminal"), sym->tag);
+  i += SUB_INDENT;
+  complain_indent (&sym->location, complaint, &i,
+                   _("previous definition"));
+}
+
 
 void
 symbol_location_as_lhs_set (symbol *sym, location loc)
@@ -430,27 +443,26 @@ symbol_precedence_set (symbol *sym, int prec, assoc a, location loc)
 void
 symbol_class_set (symbol *sym, symbol_class class, location loc, bool declaring)
 {
-  bool warned = false;
-  if (sym->content->class != unknown_sym && sym->content->class != class)
+  aver (class != unknown_sym);
+  sym_content *s = sym->content;
+  if (s->class != unknown_sym && s->class != class)
+    complain_class_redeclared (sym, class, loc);
+  else
     {
-      complain (&loc, complaint, _("symbol %s redefined"), sym->tag);
-      /* Don't report both "redefined" and "redeclared".  */
-      warned = true;
-    }
+      s->class = class;
 
-  if (class == nterm_sym && sym->content->class != nterm_sym)
-    sym->content->number = nvars++;
-  else if (class == token_sym && sym->content->number == NUMBER_UNDEFINED)
-    sym->content->number = ntokens++;
+      if (class == nterm_sym && s->class != nterm_sym)
+        s->number = nvars++;
+      else if (class == token_sym && s->number == NUMBER_UNDEFINED)
+        s->number = ntokens++;
 
-  sym->content->class = class;
-
-  if (declaring)
-    {
-      if (sym->content->status == declared && !warned)
-        complain (&loc, Wother, _("symbol %s redeclared"), sym->tag);
-      else
-        sym->content->status = declared;
+      if (declaring)
+        {
+          if (s->status == declared)
+            complain (&loc, Wother, _("symbol %s redeclared"), sym->tag);
+          else
+            s->status = declared;
+        }
     }
 }
 
