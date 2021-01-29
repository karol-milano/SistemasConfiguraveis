@@ -462,7 +462,7 @@ output_rule_data()
     }
 
   if (! toknumflag  && ! noparserflag)
-    fprintf(ftable, "\n#if YYDEBUG != 0\n\n");
+    fprintf(ftable, "\n#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)\n\n");
 
   /* Output the table of symbol names.  */
 
