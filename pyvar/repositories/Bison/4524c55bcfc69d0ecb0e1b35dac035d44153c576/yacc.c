@@ -1596,8 +1596,7 @@ yypushreturn:
   return YYID (yyresult);
 }
 
-
-]b4_epilogue
+]b4_epilogue[]dnl
 b4_defines_if(
 [@output(b4_spec_defines_file@)@
 b4_copyright([Interface for Bison's Yacc-like parsers in C])dnl'
