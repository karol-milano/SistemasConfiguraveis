@@ -288,7 +288,8 @@ Parser:\n\
   -L, --language=LANGUAGE    specify the output programming language\n\
                              (this is an experimental feature)\n\
   -S, --skeleton=FILE        specify the skeleton to use\n\
-  -t, --debug                instrument the parser for debugging\n\
+  -t, --debug                instrument the parser for tracing\n\
+                             same as `-Dparse.trace'\n\
       --locations            enable location support\n\
   -D, --define=NAME[=VALUE]  same as `%define NAME \"VALUE\"'\n\
   -p, --name-prefix=PREFIX   prepend PREFIX to the external symbols\n\
@@ -616,7 +617,8 @@ getargs (int argc, char *argv[])
 	break;
 
       case 't':
-        muscle_percent_define_insert ("debug", command_line_location (), "");
+        muscle_percent_define_insert ("parse.trace",
+                                      command_line_location (), "");
 	break;
 
       case 'v':
