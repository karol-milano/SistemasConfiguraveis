@@ -1012,7 +1012,6 @@ prepare (void)
   MUSCLE_INSERT_INT ("debug", debug_flag);
   MUSCLE_INSERT_INT ("final", final_state);
   MUSCLE_INSERT_INT ("maxtok", max_user_token_number);
-  MUSCLE_INSERT_INT ("ntbase", ntokens);
   MUSCLE_INSERT_INT ("error-verbose", error_verbose);
   MUSCLE_INSERT_STRING ("prefix", spec_name_prefix);
 
@@ -1057,7 +1056,7 @@ yystype;\n\
       for (i = ntokens; i < nsyms; i++)
 	/* don't make these for dummy nonterminals made by gensym.  */
 	if (*tags[i] != '@')
-	  fprintf (out, "# define\tNT%s\t%d\n", tags[i], i);
+	  fprintf (out, "# define NT%s\t%d\n", tags[i], i);
     }
 
   fprintf (out, "\n#endif /* not %s */\n", macro_name);
