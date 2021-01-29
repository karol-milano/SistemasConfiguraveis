@@ -456,6 +456,13 @@ muscle_percent_variable_update (char const *variable, location variable_loc,
     { "stype",                      "api.value.type",            -1 },
     { "variant=",                   "api.value.type=variant",    -1 },
     { "variant=true",               "api.value.type=variant",    -1 },
+    { "abstract",                   "api.parser.abstract",       muscle_keyword },
+    { "annotations",                "api.parser.annotations",    muscle_code },
+    { "extends",                    "api.parser.extends",        muscle_keyword },
+    { "final",                      "api.parser.final",          muscle_keyword },
+    { "implements",                 "api.parser.implements",     muscle_keyword },
+    { "public",                     "api.parser.public",         muscle_keyword },
+    { "strictfp",                   "api.parser.strictfp",       muscle_keyword },
     { NULL, NULL, -1, }
   };
 
