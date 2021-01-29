@@ -529,11 +529,14 @@ getargs (int argc, char *argv[])
         {
           char* name = optarg;
           char* value = strchr (optarg, '=');
+          char const * muscle_value = "";
           if (value)
-            *value++ = 0;
-          else
-            value = "";
-          muscle_percent_define_insert (name, command_line_location (), value);
+            {
+              *value++ = 0;
+              muscle_value = value;
+            }
+          muscle_percent_define_insert (name, command_line_location (),
+                                        muscle_value);
         }
 	break;
 
