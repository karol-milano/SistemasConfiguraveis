@@ -297,6 +297,7 @@ grammar_rule_check_and_complete (symbol_list *r)
               const bool is_cxx =
                 STREQ (language->language, "c++")
                 || (skeleton && (STREQ (skeleton, "glr.cc")
+                                 || STREQ (skeleton, "glr2.cc")
                                  || STREQ (skeleton, "lalr1.cc")));
               if (is_cxx)
                 {
