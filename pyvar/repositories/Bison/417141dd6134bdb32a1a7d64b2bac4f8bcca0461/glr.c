@@ -1931,6 +1931,7 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 }
 
 /* DEBUGGING ONLY */
+#ifdef YYDEBUG
 static void yypstack (yyGLRStack* yystack, int yyk) ATTRIBUTE_UNUSED;
 static void yypdumpstack (yyGLRStack* yystack) ATTRIBUTE_UNUSED;
 
@@ -1998,6 +1999,7 @@ yypdumpstack (yyGLRStack* yystack)
 	     (long int) YYINDEX (yystack->yytops.yystates[yyi]));
   fprintf (stderr, "\n");
 }
+#endif
 ]
 
 b4_epilogue
