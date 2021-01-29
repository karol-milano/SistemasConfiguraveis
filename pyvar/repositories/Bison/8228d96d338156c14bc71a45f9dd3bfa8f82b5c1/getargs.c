@@ -853,7 +853,7 @@ getargs (int argc, char *argv[])
       usage (EXIT_FAILURE);
     }
 
-  current_file = grammar_file = uniqstr_new (argv[optind]);
+  grammar_file = uniqstr_new (argv[optind]);
   MUSCLE_INSERT_C_STRING ("file_name", grammar_file);
 }
 
