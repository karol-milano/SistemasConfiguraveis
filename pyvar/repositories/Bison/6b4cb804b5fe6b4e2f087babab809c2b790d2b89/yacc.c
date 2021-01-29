@@ -345,9 +345,11 @@ m4_if(b4_api_prefix, [yy], [],
 # define YYERROR_VERBOSE ]b4_error_verbose_flag[
 #endif
 
-/* In a future release of Bison, this section will be replaced
+]m4_ifval(m4_quote(b4_spec_defines_file),
+[[/* In a future release of Bison, this section will be replaced
    by #include "@basename(]b4_spec_defines_file[@)".  */
-]b4_shared_declarations[
+]])dnl
+b4_shared_declarations[
 
 /* Copy the second part of user declarations.  */
 ]b4_user_post_prologue
