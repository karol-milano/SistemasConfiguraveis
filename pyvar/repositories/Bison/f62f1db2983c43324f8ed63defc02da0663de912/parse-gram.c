@@ -100,6 +100,103 @@
 # endif
 
 #include "src/parse-gram.h"
+/* Symbol type.  */
+enum yysymbol_type_t
+{
+  YYSYMBOL_YYEOF = 0,
+  YYSYMBOL_error = 1,
+  YYSYMBOL_YYUNDEF = 2,
+  YYSYMBOL_STRING = 3,
+  YYSYMBOL_TSTRING = 4,
+  YYSYMBOL_PERCENT_TOKEN = 5,
+  YYSYMBOL_PERCENT_NTERM = 6,
+  YYSYMBOL_PERCENT_TYPE = 7,
+  YYSYMBOL_PERCENT_DESTRUCTOR = 8,
+  YYSYMBOL_PERCENT_PRINTER = 9,
+  YYSYMBOL_PERCENT_LEFT = 10,
+  YYSYMBOL_PERCENT_RIGHT = 11,
+  YYSYMBOL_PERCENT_NONASSOC = 12,
+  YYSYMBOL_PERCENT_PRECEDENCE = 13,
+  YYSYMBOL_PERCENT_PREC = 14,
+  YYSYMBOL_PERCENT_DPREC = 15,
+  YYSYMBOL_PERCENT_MERGE = 16,
+  YYSYMBOL_PERCENT_CODE = 17,
+  YYSYMBOL_PERCENT_DEFAULT_PREC = 18,
+  YYSYMBOL_PERCENT_DEFINE = 19,
+  YYSYMBOL_PERCENT_DEFINES = 20,
+  YYSYMBOL_PERCENT_ERROR_VERBOSE = 21,
+  YYSYMBOL_PERCENT_EXPECT = 22,
+  YYSYMBOL_PERCENT_EXPECT_RR = 23,
+  YYSYMBOL_PERCENT_FLAG = 24,
+  YYSYMBOL_PERCENT_FILE_PREFIX = 25,
+  YYSYMBOL_PERCENT_GLR_PARSER = 26,
+  YYSYMBOL_PERCENT_INITIAL_ACTION = 27,
+  YYSYMBOL_PERCENT_LANGUAGE = 28,
+  YYSYMBOL_PERCENT_NAME_PREFIX = 29,
+  YYSYMBOL_PERCENT_NO_DEFAULT_PREC = 30,
+  YYSYMBOL_PERCENT_NO_LINES = 31,
+  YYSYMBOL_PERCENT_NONDETERMINISTIC_PARSER = 32,
+  YYSYMBOL_PERCENT_OUTPUT = 33,
+  YYSYMBOL_PERCENT_PURE_PARSER = 34,
+  YYSYMBOL_PERCENT_REQUIRE = 35,
+  YYSYMBOL_PERCENT_SKELETON = 36,
+  YYSYMBOL_PERCENT_START = 37,
+  YYSYMBOL_PERCENT_TOKEN_TABLE = 38,
+  YYSYMBOL_PERCENT_VERBOSE = 39,
+  YYSYMBOL_PERCENT_YACC = 40,
+  YYSYMBOL_BRACED_CODE = 41,
+  YYSYMBOL_BRACED_PREDICATE = 42,
+  YYSYMBOL_BRACKETED_ID = 43,
+  YYSYMBOL_CHAR = 44,
+  YYSYMBOL_COLON = 45,
+  YYSYMBOL_EPILOGUE = 46,
+  YYSYMBOL_EQUAL = 47,
+  YYSYMBOL_ID = 48,
+  YYSYMBOL_ID_COLON = 49,
+  YYSYMBOL_PERCENT_PERCENT = 50,
+  YYSYMBOL_PIPE = 51,
+  YYSYMBOL_PROLOGUE = 52,
+  YYSYMBOL_SEMICOLON = 53,
+  YYSYMBOL_TAG = 54,
+  YYSYMBOL_TAG_ANY = 55,
+  YYSYMBOL_TAG_NONE = 56,
+  YYSYMBOL_INT = 57,
+  YYSYMBOL_PERCENT_PARAM = 58,
+  YYSYMBOL_PERCENT_UNION = 59,
+  YYSYMBOL_PERCENT_EMPTY = 60,
+  YYSYMBOL_YYACCEPT = 61,
+  YYSYMBOL_input = 62,
+  YYSYMBOL_prologue_declarations = 63,
+  YYSYMBOL_prologue_declaration = 64,
+  YYSYMBOL_params = 66,
+  YYSYMBOL_grammar_declaration = 67,
+  YYSYMBOL_code_props_type = 68,
+  YYSYMBOL_union_name = 69,
+  YYSYMBOL_symbol_declaration = 70,
+  YYSYMBOL_precedence_declarator = 73,
+  YYSYMBOL_generic_symlist = 75,
+  YYSYMBOL_generic_symlist_item = 76,
+  YYSYMBOL_tag = 77,
+  YYSYMBOL_nterm_decls = 78,
+  YYSYMBOL_token_decls = 79,
+  YYSYMBOL_token_decl = 81,
+  YYSYMBOL_alias = 83,
+  YYSYMBOL_token_decls_for_prec = 84,
+  YYSYMBOL_token_decl_for_prec = 86,
+  YYSYMBOL_symbol_decls = 87,
+  YYSYMBOL_grammar = 89,
+  YYSYMBOL_rules_or_grammar_declaration = 90,
+  YYSYMBOL_rules = 91,
+  YYSYMBOL_rhs = 94,
+  YYSYMBOL_variable = 96,
+  YYSYMBOL_value = 97,
+  YYSYMBOL_id = 98,
+  YYSYMBOL_id_colon = 99,
+  YYSYMBOL_symbol = 100,
+  YYSYMBOL_string_as_id = 101
+};
+typedef enum yysymbol_type_t yysymbol_type_t;
+
 
 
 /* Unqualified %code blocks.  */
@@ -493,7 +590,6 @@ union yyalloc
 /* YYNSTATES -- Number of states.  */
 #define YYNSTATES  167
 
-#define YYUNDEFTOK  2
 #define YYMAXUTOK   315
 
 
@@ -815,8 +911,6 @@ enum { YYNOMEM = -2 };
       }                                                           \
   while (0)
 
-/* Error symbol internal number. */
-#define YYTERROR        1
 /* Error token external number. */
 #define YYERRCODE       256
 
@@ -1376,7 +1470,7 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
   yy_state_t *yyesp = yyes_prev;
   /* Reduce until we encounter a shift and thereby accept the token.  */
   YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yysymbol_name (yytoken)));
-  if (yytoken == YYUNDEFTOK)
+  if (yytoken == YYSYMBOL_YYUNDEF)
     {
       YYDPRINTF ((stderr, " Always Err\n"));
       return 1;
@@ -1499,7 +1593,7 @@ yyexpected_tokens (const yyparse_context_t *yyctx,
 
   int yyx;
   for (yyx = 0; yyx < YYNTOKENS; ++yyx)
-    if (yyx != YYTERROR && yyx != YYUNDEFTOK)
+    if (yyx != YYSYMBOL_error && yyx != YYSYMBOL_YYUNDEF)
       switch (yy_lac (yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yyx))
         {
         case YYNOMEM:
@@ -1833,7 +1927,7 @@ yybackup:
 
   /* Not known => get a lookahead token if don't already have one.  */
 
-  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
+  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
   if (yychar == YYEMPTY)
     {
       YYDPRINTF ((stderr, "Reading a token\n"));
@@ -1842,7 +1936,8 @@ yybackup:
 
   if (yychar <= YYEOF)
     {
-      yychar = yytoken = YYEOF;
+      yychar = YYEOF;
+      yytoken = YYSYMBOL_YYEOF;
       YYDPRINTF ((stderr, "Now at end of input.\n"));
     }
   else
@@ -2580,8 +2675,8 @@ yyerrlab1:
       yyn = yypact[yystate];
       if (!yypact_value_is_default (yyn))
         {
-          yyn += YYTERROR;
-          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
+          yyn += YYSYMBOL_error;
+          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_error)
             {
               yyn = yytable[yyn];
               if (0 < yyn)
