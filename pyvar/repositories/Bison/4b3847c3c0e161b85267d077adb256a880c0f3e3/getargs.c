@@ -311,10 +311,11 @@ Parser:\n\
   -S, --skeleton=FILE              specify the skeleton to use\n\
   -t, --debug                      instrument the parser for debugging\n\
       --locations                  enable location support\n\
-  -D, --define=NAME[=VALUE]        similar to `%define NAME \"VALUE\"'\n\
-  -F, --force-define=NAME[=VALUE]  override `%define NAME \"VALUE\"'\n\
+  -D, --define=NAME[=VALUE]        similar to '%define NAME \"VALUE\"'\n\
+  -F, --force-define=NAME[=VALUE]  override '%define NAME \"VALUE\"'\n\
   -p, --name-prefix=PREFIX         prepend PREFIX to the external symbols\n\
-  -l, --no-lines                   don't generate `#line' directives\n\
+                                   deprecated by '-Dapi.prefix=PREFIX'\n\
+  -l, --no-lines                   don't generate '#line' directives\n\
   -k, --token-table                include a table of token names\n\
 \n\
 "), stdout);
