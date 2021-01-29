@@ -527,14 +527,10 @@ getargs (int argc, char *argv[])
         {
           char* name = optarg;
           char* value = strchr (optarg, '=');
-          char const * muscle_value = "";
           if (value)
-            {
-              *value++ = 0;
-              muscle_value = value;
-            }
+            *value++ = 0;
           muscle_percent_define_insert (name, command_line_location (),
-                                        muscle_value);
+                                        value ? value : "");
         }
 	break;
 
