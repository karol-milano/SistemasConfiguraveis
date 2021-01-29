@@ -582,6 +582,7 @@ getargs (int argc, char *argv[])
           if (value)
             *value++ = 0;
           muscle_percent_define_insert (name, command_line_location (),
+                                        muscle_string,
                                         value ? value : "",
                                         c == 'D' ? MUSCLE_PERCENT_DEFINE_D
                                                  : MUSCLE_PERCENT_DEFINE_F);
@@ -666,7 +667,8 @@ getargs (int argc, char *argv[])
 
       case 't':
         muscle_percent_define_insert ("parse.trace",
-                                      command_line_location (), "",
+                                      command_line_location (),
+                                      muscle_keyword, "",
                                       MUSCLE_PERCENT_DEFINE_D);
         break;
 
