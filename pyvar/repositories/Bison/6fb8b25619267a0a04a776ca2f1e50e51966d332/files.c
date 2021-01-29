@@ -360,7 +360,7 @@ output_file_name_check (char **file_name)
   bool conflict = false;
   if (STREQ (*file_name, grammar_file))
     {
-      complain (_("refusing to overwrite the input file %s"),
+      complain (complaint, _("refusing to overwrite the input file %s"),
                 quote (*file_name));
       conflict = true;
     }
@@ -370,8 +370,8 @@ output_file_name_check (char **file_name)
       for (i = 0; i < file_names_count; i++)
         if (STREQ (file_names[i], *file_name))
           {
-            warn (_("conflicting outputs to file %s"),
-                  quote (*file_name));
+            complain (Wother, _("conflicting outputs to file %s"),
+                      quote (*file_name));
             conflict = true;
           }
     }
