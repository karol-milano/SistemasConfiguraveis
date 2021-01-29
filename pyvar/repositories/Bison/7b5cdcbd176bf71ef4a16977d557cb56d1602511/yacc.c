@@ -1480,7 +1480,8 @@ yyreturn:
   if (yymsg != yymsgbuf)
     YYSTACK_FREE (yymsg);
 #endif
-  return yyresult;
+  /* Make sure YYID is used.  */
+  return YYID (yyresult);
 ]}
 
 
