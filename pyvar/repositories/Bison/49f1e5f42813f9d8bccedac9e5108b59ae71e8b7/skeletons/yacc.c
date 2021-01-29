@@ -155,7 +155,7 @@ m4_define([b4_rhs_location],
 # Declare the variables that are global, or local to YYPARSE if
 # pure-parser.
 m4_define([b4_declare_scanner_communication_variables], [[
-/* The lookahead symbol.  */
+/* Lookahead token kind.  */
 int yychar;
 
 ]b4_pure_if([[
@@ -571,6 +571,7 @@ union yyalloc
 /* YYNSTATES -- Number of states.  */
 #define YYNSTATES  ]b4_states_number[
 
+/* YYMAXUTOK -- Last valid token kind.  */
 #define YYMAXUTOK   ]b4_code_max[
 
 
@@ -1544,7 +1545,7 @@ yyparse (]m4_ifset([b4_parse_param], [b4_formals(b4_parse_param)], [void])[)]])[
   int yyn;
   /* The return value of yyparse.  */
   int yyresult;
-  /* Lookahead token as an internal (translated) token number.  */
+  /* Lookahead symbol kind.  */
   yysymbol_kind_t yytoken = ]b4_symbol(-2, kind)[;
   /* The variables used to return semantic value and location from the
      action routines.  */
