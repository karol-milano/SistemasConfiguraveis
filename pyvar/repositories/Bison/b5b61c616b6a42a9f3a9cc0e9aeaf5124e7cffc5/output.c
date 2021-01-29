@@ -1075,7 +1075,8 @@ output_master_parser (void)
 
 #define MUSCLE_INSERT_PREFIX(Key, Value)	       			\
 {									\
-  obstack_fgrow2 (&muscle_obstack, "%s%s", spec_name_prefix, Value);	\
+  obstack_fgrow2 (&muscle_obstack, "%s%s", 				\
+		  spec_name_prefix ? spec_name_prefix : "yy", Value);	\
   obstack_1grow (&muscle_obstack, 0);					\
   muscle_insert (Key, obstack_finish (&muscle_obstack));	       	\
 }
@@ -1091,7 +1092,7 @@ prepare (void)
   MUSCLE_INSERT_INT ("final", final_state);
   MUSCLE_INSERT_INT ("maxtok", max_user_token_number);
   MUSCLE_INSERT_INT ("error-verbose", error_verbose);
-  MUSCLE_INSERT_STRING ("prefix", spec_name_prefix);
+  MUSCLE_INSERT_STRING ("prefix", spec_name_prefix ? spec_name_prefix : "yy");
 
   MUSCLE_INSERT_INT ("nnts", nvars);
   MUSCLE_INSERT_INT ("nrules", nrules);
@@ -1127,7 +1128,7 @@ yystype;\n\
 
   if (!pure_parser)
     fprintf (out, "\nextern YYSTYPE %slval;\n",
-	     spec_name_prefix);
+	     spec_name_prefix ? spec_name_prefix : "yy");
 
   if (locations_flag)
     {
@@ -1145,7 +1146,7 @@ typedef struct yyltype\n\
 #endif\n");
       if (!pure_parser)
 	fprintf (out, "\nextern YYLTYPE %slloc;\n",
-		 spec_name_prefix);
+		 spec_name_prefix ? spec_name_prefix : "yy");
     }
 
   if (semantic_parser)
