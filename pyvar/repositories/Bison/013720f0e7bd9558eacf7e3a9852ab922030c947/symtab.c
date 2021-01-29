@@ -46,7 +46,7 @@ symbol *undeftoken = NULL;
 symbol *endtoken = NULL;
 symbol *accept = NULL;
 symbol *startsymbol = NULL;
-location startsymbol_location;
+location startsymbol_loc;
 
 /* Precedence relation graph. */
 static symgraph **prec_nodes;
@@ -198,7 +198,7 @@ semantic_type_new (uniqstr tag, const location *loc)
 
   uniqstr_assert (tag);
   res->tag = tag;
-  res->location = loc ? *loc : empty_location;
+  res->location = loc ? *loc : empty_loc;
   res->status = undeclared;
   for (int i = 0; i < CODE_PROPS_SIZE; ++i)
     code_props_none_init (&res->props[i]);
@@ -339,12 +339,12 @@ symbol_type_set (symbol *sym, uniqstr type_name, location loc)
       tag_seen = true;
       if (sym->content->type_name)
         complain_symbol_redeclared (sym, "%type",
-                                    sym->content->type_location, loc);
+                                    sym->content->type_loc, loc);
       else
         {
           uniqstr_assert (type_name);
           sym->content->type_name = type_name;
-          sym->content->type_location = loc;
+          sym->content->type_loc = loc;
         }
     }
 }
@@ -426,12 +426,12 @@ symbol_precedence_set (symbol *sym, int prec, assoc a, location loc)
       sym_content *s = sym->content;
       if (s->prec)
         complain_symbol_redeclared (sym, assoc_to_string (a),
-                                    s->prec_location, loc);
+                                    s->prec_loc, loc);
       else
         {
           s->prec = prec;
           s->assoc = a;
-          s->prec_location = loc;
+          s->prec_loc = loc;
         }
     }
 
@@ -587,10 +587,10 @@ symbol_merge_properties (symbol *sym, symbol *str)
     {
       if (str->content->type_name)
         symbol_type_set (sym,
-                         str->content->type_name, str->content->type_location);
+                         str->content->type_name, str->content->type_loc);
       else
         symbol_type_set (str,
-                         sym->content->type_name, sym->content->type_location);
+                         sym->content->type_name, sym->content->type_loc);
     }
 
 
@@ -604,10 +604,10 @@ symbol_merge_properties (symbol *sym, symbol *str)
     {
       if (str->content->prec)
         symbol_precedence_set (sym, str->content->prec, str->content->assoc,
-                               str->content->prec_location);
+                               str->content->prec_loc);
       else
         symbol_precedence_set (str, sym->content->prec, sym->content->assoc,
-                               sym->content->prec_location);
+                               sym->content->prec_loc);
     }
 }
 
@@ -1034,11 +1034,11 @@ symbols_pack (void)
   symbols_token_translations_init ();
 
   if (startsymbol->content->class == unknown_sym)
-    complain (&startsymbol_location, fatal,
+    complain (&startsymbol_loc, fatal,
               _("the start symbol %s is undefined"),
               startsymbol->tag);
   else if (startsymbol->content->class == token_sym)
-    complain (&startsymbol_location, fatal,
+    complain (&startsymbol_loc, fatal,
               _("the start symbol %s is a token"),
               startsymbol->tag);
 }
@@ -1209,14 +1209,14 @@ print_precedence_warnings (void)
           && !prec_nodes[i]->succ)
         {
           if (is_assoc_useless (s))
-            complain (&s->content->prec_location, Wprecedence,
+            complain (&s->content->prec_loc, Wprecedence,
                       _("useless precedence and associativity for %s"), s->tag);
           else if (s->content->assoc == precedence_assoc)
-            complain (&s->content->prec_location, Wprecedence,
+            complain (&s->content->prec_loc, Wprecedence,
                       _("useless precedence for %s"), s->tag);
         }
       else if (is_assoc_useless (s))
-        complain (&s->content->prec_location, Wprecedence,
+        complain (&s->content->prec_loc, Wprecedence,
                   _("useless associativity for %s, use %%precedence"), s->tag);
     }
   free (used_assoc);
