@@ -404,10 +404,10 @@ Tuning the Parser:\n\
   -t, --debug                      instrument the parser for tracing\n\
                                    same as '-Dparse.trace'\n\
       --locations                  enable location support\n\
-  -D, --define=NAME[=VALUE]        similar to '%define NAME \"VALUE\"'\n\
-  -F, --force-define=NAME[=VALUE]  override '%define NAME \"VALUE\"'\n\
+  -D, --define=NAME[=VALUE]        similar to '%define NAME VALUE'\n\
+  -F, --force-define=NAME[=VALUE]  override '%define NAME VALUE'\n\
   -p, --name-prefix=PREFIX         prepend PREFIX to the external symbols\n\
-                                   deprecated by '-Dapi.prefix=PREFIX'\n\
+                                   deprecated by '-Dapi.prefix={PREFIX}'\n\
   -l, --no-lines                   don't generate '#line' directives\n\
   -k, --token-table                include a table of token names\n\
   -y, --yacc                       emulate POSIX Yacc\n\
