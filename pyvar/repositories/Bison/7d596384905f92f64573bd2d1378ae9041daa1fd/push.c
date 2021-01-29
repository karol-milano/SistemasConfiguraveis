@@ -1624,16 +1624,19 @@ yyreturn:
   if (yyss != yyssa)
     YYSTACK_FREE (yyss);
 #endif
-]b4_push_if([yypushreturn:])[
-#if YYERROR_VERBOSE
+]b4_push_if([[  yyps->yynew = 1;
+
+yypushreturn:
+]])[#if YYERROR_VERBOSE
   if (yymsg != yymsgbuf)
     YYSTACK_FREE (yymsg);
 #endif
   /* Make sure YYID is used.  */
   return YYID (yyresult);
-]}
+}
+
 
-b4_epilogue
+]b4_epilogue
 b4_defines_if(
 [@output b4_spec_defines_file
 b4_copyright([Skeleton interface for Bison's Yacc-like parsers in C],dnl '
