@@ -306,13 +306,20 @@ grammar_rule_check_and_complete (symbol_list *r)
                       lhs_type, rhs_type);
           else
             {
-              /* Install the default action.  */
-              code_props_rule_action_init (&r->action_props, "{ $$ = $1; }",
-                                           r->location, r,
-                                           /* name */ NULL,
-                                           /* type */ NULL,
-                                           /* is_predicate */ false);
-              code_props_translate_code (&r->action_props);
+              /* Install the default action only for C++.  */
+              bool is_cxx =
+                skeleton
+                ? STREQ (skeleton, "glr.cc") || STREQ (skeleton, "lalr1.cc")
+                : STREQ (language->language, "c++");
+              if (is_cxx)
+                {
+                  code_props_rule_action_init (&r->action_props, "{ $$ = $1; }",
+                                               r->location, r,
+                                               /* name */ NULL,
+                                               /* type */ NULL,
+                                               /* is_predicate */ false);
+                  code_props_translate_code (&r->action_props);
+                }
             }
         }
       /* Warn if there is no default for $$ but we need one.  */
