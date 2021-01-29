@@ -444,8 +444,13 @@ muscle_percent_variable_update (char const *variable, location variable_loc,
   } conversion_type;
   const conversion_type conversion[] =
   {
+    { "abstract",                   "api.parser.abstract",       muscle_keyword },
+    { "annotations",                "api.parser.annotations",    muscle_code },
     { "api.push_pull",              "api.push-pull",             muscle_keyword },
     { "api.tokens.prefix",          "api.token.prefix",          muscle_code },
+    { "extends",                    "api.parser.extends",        muscle_keyword },
+    { "final",                      "api.parser.final",          muscle_keyword },
+    { "implements",                 "api.parser.implements",     muscle_keyword },
     { "lex_symbol",                 "api.token.constructor",     -1 },
     { "location_type",              "api.location.type",         muscle_code },
     { "lr.default-reductions",      "lr.default-reduction",      muscle_keyword },
@@ -453,16 +458,11 @@ muscle_percent_variable_update (char const *variable, location variable_loc,
     { "lr.keep_unreachable_states", "lr.keep-unreachable-state", muscle_keyword },
     { "namespace",                  "api.namespace",             muscle_code },
     { "parser_class_name",          "api.parser.class",          muscle_code },
+    { "public",                     "api.parser.public",         muscle_keyword },
+    { "strictfp",                   "api.parser.strictfp",       muscle_keyword },
     { "stype",                      "api.value.type",            -1 },
     { "variant=",                   "api.value.type=variant",    -1 },
     { "variant=true",               "api.value.type=variant",    -1 },
-    { "abstract",                   "api.parser.abstract",       muscle_keyword },
-    { "annotations",                "api.parser.annotations",    muscle_code },
-    { "extends",                    "api.parser.extends",        muscle_keyword },
-    { "final",                      "api.parser.final",          muscle_keyword },
-    { "implements",                 "api.parser.implements",     muscle_keyword },
-    { "public",                     "api.parser.public",         muscle_keyword },
-    { "strictfp",                   "api.parser.strictfp",       muscle_keyword },
     { NULL, NULL, -1, }
   };
 
