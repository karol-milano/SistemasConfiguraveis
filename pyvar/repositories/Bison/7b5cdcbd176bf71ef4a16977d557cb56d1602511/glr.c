@@ -2523,7 +2523,8 @@ b4_syncline([@oline@], [@ofile@])])dnl
       yyfreeGLRStack (&yystack);
     }
 
-  return yyresult;
+  /* Make sure YYID is used.  */
+  return YYID (yyresult);
 }
 
 /* DEBUGGING ONLY */
