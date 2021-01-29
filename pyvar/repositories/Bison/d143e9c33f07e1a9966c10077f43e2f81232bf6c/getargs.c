@@ -562,7 +562,7 @@ getargs (int argc, char *argv[])
       case 'F': /* -FNAME[=VALUE]. */
         {
           char* name = optarg;
-          char* value = strchr (optarg, '=');
+          char* value = mbschr (optarg, '=');
           if (value)
             *value++ = 0;
           muscle_percent_define_insert (name, command_line_location (),
