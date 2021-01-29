@@ -574,16 +574,31 @@ getargs (int argc, char *argv[])
         /* Certain long options cause getopt_long to return 0.  */
         break;
 
-      case 'D': /* -DNAME[=VALUE]. */
-      case 'F': /* -FNAME[=VALUE]. */
+      case 'D': /* -DNAME[=(VALUE|"VALUE"|{VALUE})]. */
+      case 'F': /* -FNAME[=(VALUE|"VALUE"|{VALUE})]. */
         {
-          char* name = optarg;
-          char* value = strchr (optarg, '=');
+          char *name = optarg;
+          char *value = strchr (optarg, '=');
+          muscle_kind kind = muscle_keyword;
           if (value)
-            *value++ = 0;
+            {
+              char *end = value + strlen (value) - 1;
+              *value++ = 0;
+              if (*value == '{' && *end == '}')
+                {
+                  kind = muscle_code;
+                  ++value;
+                  *end = 0;
+                }
+              else if (*value == '"' && *end == '"')
+                {
+                  kind = muscle_string;
+                  ++value;
+                  *end = 0;
+                }
+            }
           muscle_percent_define_insert (name, command_line_location (),
-                                        muscle_string,
-                                        value ? value : "",
+                                        kind, value ? value : "",
                                         c == 'D' ? MUSCLE_PERCENT_DEFINE_D
                                                  : MUSCLE_PERCENT_DEFINE_F);
         }
