@@ -559,7 +559,7 @@ getargs (int argc, char *argv[])
       case 'F': /* -FNAME[=VALUE]. */
         {
           char* name = optarg;
-          char* value = mbschr (optarg, '=');
+          char* value = strchr (optarg, '=');
           if (value)
             *value++ = 0;
           muscle_percent_define_insert (name, command_line_location (),
