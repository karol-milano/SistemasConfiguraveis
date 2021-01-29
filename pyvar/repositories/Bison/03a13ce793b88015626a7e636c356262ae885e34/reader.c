@@ -307,10 +307,10 @@ grammar_rule_check_and_complete (symbol_list *r)
           else
             {
               /* Install the default action only for C++.  */
-              bool is_cxx =
-                skeleton
-                ? STREQ (skeleton, "glr.cc") || STREQ (skeleton, "lalr1.cc")
-                : STREQ (language->language, "c++");
+              const bool is_cxx =
+                STREQ (language->language, "c++")
+                || (skeleton && (STREQ (skeleton, "glr.cc")
+                                 || STREQ (skeleton, "lalr1.cc")));
               if (is_cxx)
                 {
                   code_props_rule_action_init (&r->action_props, "{ $$ = $1; }",
