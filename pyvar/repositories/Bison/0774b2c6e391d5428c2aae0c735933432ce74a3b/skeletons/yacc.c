@@ -2065,5 +2065,6 @@ yypushreturn:]])[
     YYSTACK_FREE (yymsg);]])[
   return yyresult;
 }
-]b4_epilogue[]dnl
+]b4_percent_code_get([[epilogue]])[]dnl
+b4_epilogue[]dnl
 b4_output_end
