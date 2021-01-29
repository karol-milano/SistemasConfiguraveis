@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.6.  */
+/* A Bison parser, made by GNU Bison 3.6.2.71-273f.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -49,7 +49,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.6"
+#define YYBISON_VERSION "3.6.2.71-273f"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -1057,75 +1057,75 @@ tron (yyo);
   YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
   switch (yykind)
     {
-    case 3: /* "string"  */
+    case YYSYMBOL_STRING: /* "string"  */
          { fputs (((*yyvaluep).STRING), yyo); }
         break;
 
-    case 4: /* "translatable string"  */
+    case YYSYMBOL_TSTRING: /* "translatable string"  */
          { fputs (((*yyvaluep).TSTRING), yyo); }
         break;
 
-    case 21: /* "%error-verbose"  */
+    case YYSYMBOL_PERCENT_ERROR_VERBOSE: /* "%error-verbose"  */
          { fputs (((*yyvaluep).PERCENT_ERROR_VERBOSE), yyo); }
         break;
 
-    case 24: /* "%<flag>"  */
+    case YYSYMBOL_PERCENT_FLAG: /* "%<flag>"  */
          { fprintf (yyo, "%%%s", ((*yyvaluep).PERCENT_FLAG)); }
         break;
 
-    case 25: /* "%file-prefix"  */
+    case YYSYMBOL_PERCENT_FILE_PREFIX: /* "%file-prefix"  */
          { fputs (((*yyvaluep).PERCENT_FILE_PREFIX), yyo); }
         break;
 
-    case 29: /* "%name-prefix"  */
+    case YYSYMBOL_PERCENT_NAME_PREFIX: /* "%name-prefix"  */
          { fputs (((*yyvaluep).PERCENT_NAME_PREFIX), yyo); }
         break;
 
-    case 34: /* "%pure-parser"  */
+    case YYSYMBOL_PERCENT_PURE_PARSER: /* "%pure-parser"  */
          { fputs (((*yyvaluep).PERCENT_PURE_PARSER), yyo); }
         break;
 
-    case 41: /* "{...}"  */
+    case YYSYMBOL_BRACED_CODE: /* "{...}"  */
          { fputs (((*yyvaluep).BRACED_CODE), yyo); }
         break;
 
-    case 42: /* "%?{...}"  */
+    case YYSYMBOL_BRACED_PREDICATE: /* "%?{...}"  */
          { fputs (((*yyvaluep).BRACED_PREDICATE), yyo); }
         break;
 
-    case 43: /* "[identifier]"  */
+    case YYSYMBOL_BRACKETED_ID: /* "[identifier]"  */
          { fprintf (yyo, "[%s]", ((*yyvaluep).BRACKETED_ID)); }
         break;
 
-    case 44: /* "character literal"  */
+    case YYSYMBOL_CHAR: /* "character literal"  */
          { fputs (char_name (((*yyvaluep).CHAR)), yyo); }
         break;
 
-    case 46: /* "epilogue"  */
+    case YYSYMBOL_EPILOGUE: /* "epilogue"  */
          { fputs (((*yyvaluep).EPILOGUE), yyo); }
         break;
 
-    case 48: /* "identifier"  */
+    case YYSYMBOL_ID: /* "identifier"  */
          { fputs (((*yyvaluep).ID), yyo); }
         break;
 
-    case 49: /* "identifier:"  */
+    case YYSYMBOL_ID_COLON: /* "identifier:"  */
          { fprintf (yyo, "%s:", ((*yyvaluep).ID_COLON)); }
         break;
 
-    case 52: /* "%{...%}"  */
+    case YYSYMBOL_PROLOGUE: /* "%{...%}"  */
          { fputs (((*yyvaluep).PROLOGUE), yyo); }
         break;
 
-    case 54: /* "<tag>"  */
+    case YYSYMBOL_TAG: /* "<tag>"  */
          { fprintf (yyo, "<%s>", ((*yyvaluep).TAG)); }
         break;
 
-    case 57: /* "integer literal"  */
+    case YYSYMBOL_INT: /* "integer literal"  */
          { fprintf (yyo, "%d", ((*yyvaluep).INT)); }
         break;
 
-    case 58: /* "%param"  */
+    case YYSYMBOL_PERCENT_PARAM: /* "%param"  */
 {
   switch (((*yyvaluep).PERCENT_PARAM))
     {
@@ -1140,75 +1140,75 @@ tron (yyo);
 }
         break;
 
-    case 68: /* code_props_type  */
+    case YYSYMBOL_code_props_type: /* code_props_type  */
          { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_props_type))); }
         break;
 
-    case 74: /* tag.opt  */
+    case YYSYMBOL_74_tag_opt: /* tag.opt  */
          { fputs (((*yyvaluep).yykind_74), yyo); }
         break;
 
-    case 75: /* generic_symlist  */
+    case YYSYMBOL_generic_symlist: /* generic_symlist  */
          { symbol_list_syms_print (((*yyvaluep).generic_symlist), yyo); }
         break;
 
-    case 76: /* generic_symlist_item  */
+    case YYSYMBOL_generic_symlist_item: /* generic_symlist_item  */
          { symbol_list_syms_print (((*yyvaluep).generic_symlist_item), yyo); }
         break;
 
-    case 77: /* tag  */
+    case YYSYMBOL_tag: /* tag  */
          { fprintf (yyo, "<%s>", ((*yyvaluep).tag)); }
         break;
 
-    case 78: /* nterm_decls  */
+    case YYSYMBOL_nterm_decls: /* nterm_decls  */
          { symbol_list_syms_print (((*yyvaluep).nterm_decls), yyo); }
         break;
 
-    case 79: /* token_decls  */
+    case YYSYMBOL_token_decls: /* token_decls  */
          { symbol_list_syms_print (((*yyvaluep).token_decls), yyo); }
         break;
 
-    case 80: /* token_decl.1  */
+    case YYSYMBOL_80_token_decl_1: /* token_decl.1  */
          { symbol_list_syms_print (((*yyvaluep).yykind_80), yyo); }
         break;
 
-    case 81: /* token_decl  */
+    case YYSYMBOL_token_decl: /* token_decl  */
          { fprintf (yyo, "%s", ((*yyvaluep).token_decl) ? ((*yyvaluep).token_decl)->tag : "<NULL>"); }
         break;
 
-    case 82: /* int.opt  */
+    case YYSYMBOL_82_int_opt: /* int.opt  */
          { fprintf (yyo, "%d", ((*yyvaluep).yykind_82)); }
         break;
 
-    case 83: /* alias  */
+    case YYSYMBOL_alias: /* alias  */
          { fprintf (yyo, "%s", ((*yyvaluep).alias) ? ((*yyvaluep).alias)->tag : "<NULL>"); }
         break;
 
-    case 84: /* token_decls_for_prec  */
+    case YYSYMBOL_token_decls_for_prec: /* token_decls_for_prec  */
          { symbol_list_syms_print (((*yyvaluep).token_decls_for_prec), yyo); }
         break;
 
-    case 85: /* token_decl_for_prec.1  */
+    case YYSYMBOL_85_token_decl_for_prec_1: /* token_decl_for_prec.1  */
          { symbol_list_syms_print (((*yyvaluep).yykind_85), yyo); }
         break;
 
-    case 86: /* token_decl_for_prec  */
+    case YYSYMBOL_token_decl_for_prec: /* token_decl_for_prec  */
          { fprintf (yyo, "%s", ((*yyvaluep).token_decl_for_prec) ? ((*yyvaluep).token_decl_for_prec)->tag : "<NULL>"); }
         break;
 
-    case 87: /* symbol_decls  */
+    case YYSYMBOL_symbol_decls: /* symbol_decls  */
          { symbol_list_syms_print (((*yyvaluep).symbol_decls), yyo); }
         break;
 
-    case 88: /* symbol_decl.1  */
+    case YYSYMBOL_88_symbol_decl_1: /* symbol_decl.1  */
          { symbol_list_syms_print (((*yyvaluep).yykind_88), yyo); }
         break;
 
-    case 96: /* variable  */
+    case YYSYMBOL_variable: /* variable  */
          { fputs (((*yyvaluep).variable), yyo); }
         break;
 
-    case 97: /* value  */
+    case YYSYMBOL_value: /* value  */
 {
   switch (((*yyvaluep).value).kind)
     {
@@ -1219,19 +1219,19 @@ tron (yyo);
 }
         break;
 
-    case 98: /* id  */
+    case YYSYMBOL_id: /* id  */
          { fprintf (yyo, "%s", ((*yyvaluep).id) ? ((*yyvaluep).id)->tag : "<NULL>"); }
         break;
 
-    case 99: /* id_colon  */
+    case YYSYMBOL_id_colon: /* id_colon  */
          { fprintf (yyo, "%s:", ((*yyvaluep).id_colon)->tag); }
         break;
 
-    case 100: /* symbol  */
+    case YYSYMBOL_symbol: /* symbol  */
          { fprintf (yyo, "%s", ((*yyvaluep).symbol) ? ((*yyvaluep).symbol)->tag : "<NULL>"); }
         break;
 
-    case 101: /* string_as_id  */
+    case YYSYMBOL_string_as_id: /* string_as_id  */
          { fprintf (yyo, "%s", ((*yyvaluep).string_as_id) ? ((*yyvaluep).string_as_id)->tag : "<NULL>"); }
         break;
 
@@ -1681,39 +1681,39 @@ yydestruct (const char *yymsg,
   YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
   switch (yykind)
     {
-    case 75: /* generic_symlist  */
+    case YYSYMBOL_generic_symlist: /* generic_symlist  */
             { symbol_list_free (((*yyvaluep).generic_symlist)); }
         break;
 
-    case 76: /* generic_symlist_item  */
+    case YYSYMBOL_generic_symlist_item: /* generic_symlist_item  */
             { symbol_list_free (((*yyvaluep).generic_symlist_item)); }
         break;
 
-    case 78: /* nterm_decls  */
+    case YYSYMBOL_nterm_decls: /* nterm_decls  */
             { symbol_list_free (((*yyvaluep).nterm_decls)); }
         break;
 
-    case 79: /* token_decls  */
+    case YYSYMBOL_token_decls: /* token_decls  */
             { symbol_list_free (((*yyvaluep).token_decls)); }
         break;
 
-    case 80: /* token_decl.1  */
+    case YYSYMBOL_80_token_decl_1: /* token_decl.1  */
             { symbol_list_free (((*yyvaluep).yykind_80)); }
         break;
 
-    case 84: /* token_decls_for_prec  */
+    case YYSYMBOL_token_decls_for_prec: /* token_decls_for_prec  */
             { symbol_list_free (((*yyvaluep).token_decls_for_prec)); }
         break;
 
-    case 85: /* token_decl_for_prec.1  */
+    case YYSYMBOL_85_token_decl_for_prec_1: /* token_decl_for_prec.1  */
             { symbol_list_free (((*yyvaluep).yykind_85)); }
         break;
 
-    case 87: /* symbol_decls  */
+    case YYSYMBOL_symbol_decls: /* symbol_decls  */
             { symbol_list_free (((*yyvaluep).symbol_decls)); }
         break;
 
-    case 88: /* symbol_decl.1  */
+    case YYSYMBOL_88_symbol_decl_1: /* symbol_decl.1  */
             { symbol_list_free (((*yyvaluep).yykind_88)); }
         break;
 
