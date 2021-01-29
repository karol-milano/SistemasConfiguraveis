@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.2.90.23-0bbcb-dirty.  */
+/* A Bison parser, made by GNU Bison 3.3.2.93-9d04-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -48,7 +48,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.2.90.23-0bbcb-dirty"
+#define YYBISON_VERSION "3.3.2.93-9d04-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -63,12 +63,12 @@
 #define YYPULL 1
 
 /* "%code top" blocks.  */
-#line 27 "src/parse-gram.y" /* yacc.c:315  */
+#line 27 "src/parse-gram.y"
 
   /* On column 0 to please syntax-check.  */
 #include <config.h>
 
-#line 72 "src/parse-gram.c" /* yacc.c:315  */
+#line 72 "src/parse-gram.c"
 /* Substitute the type names.  */
 #define YYSTYPE         GRAM_STYPE
 #define YYLTYPE         GRAM_LTYPE
@@ -101,233 +101,11 @@
 # define YYERROR_VERBOSE 1
 #endif
 
-/* In a future release of Bison, this section will be replaced
-   by #include "src/parse-gram.h".  */
-#ifndef YY_GRAM_SRC_PARSE_GRAM_H_INCLUDED
-# define YY_GRAM_SRC_PARSE_GRAM_H_INCLUDED
-/* Debug traces.  */
-#ifndef GRAM_DEBUG
-# if defined YYDEBUG
-#if YYDEBUG
-#   define GRAM_DEBUG 1
-#  else
-#   define GRAM_DEBUG 0
-#  endif
-# else /* ! defined YYDEBUG */
-#  define GRAM_DEBUG 1
-# endif /* ! defined YYDEBUG */
-#endif  /* ! defined GRAM_DEBUG */
-#if GRAM_DEBUG
-extern int gram_debug;
-#endif
-/* "%code requires" blocks.  */
-#line 21 "src/parse-gram.y" /* yacc.c:352  */
-
-  #include "symlist.h"
-  #include "symtab.h"
-#line 239 "src/parse-gram.y" /* yacc.c:352  */
-
-  typedef enum
-  {
-    param_none   = 0,
-    param_lex    = 1 << 0,
-    param_parse  = 1 << 1,
-    param_both   = param_lex | param_parse
-  } param_type;
-#line 682 "src/parse-gram.y" /* yacc.c:352  */
-
-  #include "muscle-tab.h"
-  typedef struct
-  {
-    char const *chars;
-    muscle_kind kind;
-  } value_type;
-
-#line 147 "src/parse-gram.c" /* yacc.c:352  */
-
-/* Token type.  */
-#ifndef GRAM_TOKENTYPE
-# define GRAM_TOKENTYPE
-  enum gram_tokentype
-  {
-    GRAM_EOF = 0,
-    STRING = 258,
-    PERCENT_TOKEN = 259,
-    PERCENT_NTERM = 260,
-    PERCENT_TYPE = 261,
-    PERCENT_DESTRUCTOR = 262,
-    PERCENT_PRINTER = 263,
-    PERCENT_LEFT = 264,
-    PERCENT_RIGHT = 265,
-    PERCENT_NONASSOC = 266,
-    PERCENT_PRECEDENCE = 267,
-    PERCENT_PREC = 268,
-    PERCENT_DPREC = 269,
-    PERCENT_MERGE = 270,
-    PERCENT_CODE = 271,
-    PERCENT_DEFAULT_PREC = 272,
-    PERCENT_DEFINE = 273,
-    PERCENT_DEFINES = 274,
-    PERCENT_ERROR_VERBOSE = 275,
-    PERCENT_EXPECT = 276,
-    PERCENT_EXPECT_RR = 277,
-    PERCENT_FLAG = 278,
-    PERCENT_FILE_PREFIX = 279,
-    PERCENT_GLR_PARSER = 280,
-    PERCENT_INITIAL_ACTION = 281,
-    PERCENT_LANGUAGE = 282,
-    PERCENT_NAME_PREFIX = 283,
-    PERCENT_NO_DEFAULT_PREC = 284,
-    PERCENT_NO_LINES = 285,
-    PERCENT_NONDETERMINISTIC_PARSER = 286,
-    PERCENT_OUTPUT = 287,
-    PERCENT_REQUIRE = 288,
-    PERCENT_SKELETON = 289,
-    PERCENT_START = 290,
-    PERCENT_TOKEN_TABLE = 291,
-    PERCENT_VERBOSE = 292,
-    PERCENT_YACC = 293,
-    BRACED_CODE = 294,
-    BRACED_PREDICATE = 295,
-    BRACKETED_ID = 296,
-    CHAR = 297,
-    EPILOGUE = 298,
-    EQUAL = 299,
-    ID = 300,
-    ID_COLON = 301,
-    PERCENT_PERCENT = 302,
-    PIPE = 303,
-    PROLOGUE = 304,
-    SEMICOLON = 305,
-    TAG = 306,
-    TAG_ANY = 307,
-    TAG_NONE = 308,
-    INT = 309,
-    PERCENT_PARAM = 310,
-    PERCENT_UNION = 311,
-    PERCENT_EMPTY = 312
-  };
-#endif
-
-/* Value type.  */
-#if ! defined GRAM_STYPE && ! defined GRAM_STYPE_IS_DECLARED
-
-union GRAM_STYPE
-{
-
-  /* precedence_declarator  */
-  assoc precedence_declarator;
-  /* "string"  */
-  char* STRING;
-  /* "{...}"  */
-  char* BRACED_CODE;
-  /* "%?{...}"  */
-  char* BRACED_PREDICATE;
-  /* "epilogue"  */
-  char* EPILOGUE;
-  /* "%{...%}"  */
-  char* PROLOGUE;
-  /* code_props_type  */
-  code_props_type code_props_type;
-  /* "integer"  */
-  int INT;
-  /* int.opt  */
-  int yytype_79;
-  /* named_ref.opt  */
-  named_ref* yytype_91;
-  /* "%param"  */
-  param_type PERCENT_PARAM;
-  /* token_decl  */
-  symbol* token_decl;
-  /* token_decl_for_prec  */
-  symbol* token_decl_for_prec;
-  /* id  */
-  symbol* id;
-  /* id_colon  */
-  symbol* id_colon;
-  /* symbol  */
-  symbol* symbol;
-  /* string_as_id  */
-  symbol* string_as_id;
-  /* string_as_id.opt  */
-  symbol* yytype_98;
-  /* generic_symlist  */
-  symbol_list* generic_symlist;
-  /* generic_symlist_item  */
-  symbol_list* generic_symlist_item;
-  /* nterm_decls  */
-  symbol_list* nterm_decls;
-  /* token_decls  */
-  symbol_list* token_decls;
-  /* token_decl.1  */
-  symbol_list* yytype_77;
-  /* token_decls_for_prec  */
-  symbol_list* token_decls_for_prec;
-  /* token_decl_for_prec.1  */
-  symbol_list* yytype_81;
-  /* symbol_decls  */
-  symbol_list* symbol_decls;
-  /* symbol_decl.1  */
-  symbol_list* yytype_84;
-  /* "%error-verbose"  */
-  uniqstr PERCENT_ERROR_VERBOSE;
-  /* "%<flag>"  */
-  uniqstr PERCENT_FLAG;
-  /* "%file-prefix"  */
-  uniqstr PERCENT_FILE_PREFIX;
-  /* "%name-prefix"  */
-  uniqstr PERCENT_NAME_PREFIX;
-  /* "%yacc"  */
-  uniqstr PERCENT_YACC;
-  /* "[identifier]"  */
-  uniqstr BRACKETED_ID;
-  /* "identifier"  */
-  uniqstr ID;
-  /* "identifier:"  */
-  uniqstr ID_COLON;
-  /* "<tag>"  */
-  uniqstr TAG;
-  /* tag.opt  */
-  uniqstr yytype_71;
-  /* tag  */
-  uniqstr tag;
-  /* variable  */
-  uniqstr variable;
-  /* "char"  */
-  unsigned char CHAR;
-  /* value  */
-  value_type value;
-#line 301 "src/parse-gram.c" /* yacc.c:352  */
-};
-
-typedef union GRAM_STYPE GRAM_STYPE;
-# define GRAM_STYPE_IS_TRIVIAL 1
-# define GRAM_STYPE_IS_DECLARED 1
-#endif
-
-/* Location type.  */
-#if ! defined GRAM_LTYPE && ! defined GRAM_LTYPE_IS_DECLARED
-typedef struct GRAM_LTYPE GRAM_LTYPE;
-struct GRAM_LTYPE
-{
-  int first_line;
-  int first_column;
-  int last_line;
-  int last_column;
-};
-# define GRAM_LTYPE_IS_DECLARED 1
-# define GRAM_LTYPE_IS_TRIVIAL 1
-#endif
-
-
-
-int gram_parse (void);
-
-#endif /* !YY_GRAM_SRC_PARSE_GRAM_H_INCLUDED  */
+#include "src/parse-gram.h"
 
 
 /* Unqualified %code blocks.  */
-#line 33 "src/parse-gram.y" /* yacc.c:355  */
+#line 33 "src/parse-gram.y"
 
   #include "system.h"
   #include <errno.h>
@@ -410,7 +188,7 @@ int gram_parse (void);
   #define YYTYPE_INT8 int_fast8_t
   #define YYTYPE_UINT16 uint_fast16_t
   #define YYTYPE_UINT8 uint_fast8_t
-#line 249 "src/parse-gram.y" /* yacc.c:355  */
+#line 250 "src/parse-gram.y"
 
   /** Add a lex-param and/or a parse-param.
    *
@@ -421,7 +199,7 @@ int gram_parse (void);
   static void add_param (param_type type, char *decl, location loc);
   static param_type current_param = param_none;
 
-#line 425 "src/parse-gram.c" /* yacc.c:355  */
+#line 203 "src/parse-gram.c"
 
 #ifdef short
 # undef short
@@ -523,6 +301,8 @@ typedef short yytype_int16;
 #endif
 
 
+#define YY_ASSERT(E) ((void) (0 && (E)))
+
 #if 1
 
 /* The parser invokes alloca or malloc; define the necessary symbols.  */
@@ -694,19 +474,19 @@ static const yytype_uint8 yytranslate[] =
   /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   281,   281,   290,   291,   295,   296,   302,   306,   311,
-     312,   317,   318,   319,   320,   321,   326,   331,   332,   333,
-     334,   335,   336,   336,   337,   338,   339,   340,   341,   342,
-     343,   347,   348,   357,   358,   362,   373,   377,   381,   389,
-     399,   400,   410,   411,   417,   430,   430,   435,   435,   440,
-     444,   454,   455,   456,   457,   461,   462,   467,   468,   472,
-     473,   477,   478,   479,   492,   501,   505,   509,   517,   518,
-     522,   535,   536,   548,   552,   556,   564,   566,   571,   578,
-     588,   592,   596,   604,   605,   613,   614,   620,   621,   622,
-     629,   629,   637,   638,   639,   644,   647,   649,   651,   653,
-     655,   657,   659,   661,   663,   668,   669,   678,   702,   703,
-     704,   705,   717,   719,   734,   739,   740,   745,   754,   755,
-     759,   760
+       0,   282,   282,   291,   292,   296,   297,   303,   307,   312,
+     313,   318,   319,   320,   321,   322,   327,   332,   333,   334,
+     335,   336,   337,   337,   338,   339,   340,   341,   342,   343,
+     344,   348,   349,   358,   359,   363,   374,   378,   382,   390,
+     400,   401,   411,   412,   418,   431,   431,   436,   436,   441,
+     445,   455,   456,   457,   458,   462,   463,   468,   469,   473,
+     474,   478,   479,   480,   493,   502,   506,   510,   518,   519,
+     523,   536,   537,   549,   553,   557,   565,   567,   572,   579,
+     589,   593,   597,   605,   606,   614,   615,   621,   622,   623,
+     630,   630,   638,   639,   640,   645,   648,   650,   652,   654,
+     656,   658,   660,   662,   664,   669,   670,   679,   703,   704,
+     705,   706,   718,   720,   735,   740,   741,   746,   755,   756,
+     760,   761
 };
 #endif
 
@@ -1102,103 +882,103 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
   switch (yytype)
     {
     case 3: /* "string"  */
-#line 207 "src/parse-gram.y" /* yacc.c:680  */
+#line 208 "src/parse-gram.y"
       { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).STRING)), yyo); }
-#line 1108 "src/parse-gram.c" /* yacc.c:680  */
+#line 888 "src/parse-gram.c"
         break;
 
     case 20: /* "%error-verbose"  */
-#line 215 "src/parse-gram.y" /* yacc.c:680  */
+#line 216 "src/parse-gram.y"
       { fputs (((*yyvaluep).PERCENT_ERROR_VERBOSE), yyo); }
-#line 1114 "src/parse-gram.c" /* yacc.c:680  */
+#line 894 "src/parse-gram.c"
         break;
 
     case 23: /* "%<flag>"  */
-#line 218 "src/parse-gram.y" /* yacc.c:680  */
+#line 219 "src/parse-gram.y"
       { fprintf (yyo, "%%%s", ((*yyvaluep).PERCENT_FLAG)); }
-#line 1120 "src/parse-gram.c" /* yacc.c:680  */
+#line 900 "src/parse-gram.c"
         break;
 
     case 24: /* "%file-prefix"  */
-#line 215 "src/parse-gram.y" /* yacc.c:680  */
+#line 216 "src/parse-gram.y"
       { fputs (((*yyvaluep).PERCENT_FILE_PREFIX), yyo); }
-#line 1126 "src/parse-gram.c" /* yacc.c:680  */
+#line 906 "src/parse-gram.c"
         break;
 
     case 28: /* "%name-prefix"  */
-#line 215 "src/parse-gram.y" /* yacc.c:680  */
+#line 216 "src/parse-gram.y"
       { fputs (((*yyvaluep).PERCENT_NAME_PREFIX), yyo); }
-#line 1132 "src/parse-gram.c" /* yacc.c:680  */
+#line 912 "src/parse-gram.c"
         break;
 
     case 38: /* "%yacc"  */
-#line 215 "src/parse-gram.y" /* yacc.c:680  */
+#line 216 "src/parse-gram.y"
       { fputs (((*yyvaluep).PERCENT_YACC), yyo); }
-#line 1138 "src/parse-gram.c" /* yacc.c:680  */
+#line 918 "src/parse-gram.c"
         break;
 
     case 39: /* "{...}"  */
-#line 208 "src/parse-gram.y" /* yacc.c:680  */
+#line 209 "src/parse-gram.y"
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).BRACED_CODE)); }
-#line 1144 "src/parse-gram.c" /* yacc.c:680  */
+#line 924 "src/parse-gram.c"
         break;
 
     case 40: /* "%?{...}"  */
-#line 208 "src/parse-gram.y" /* yacc.c:680  */
+#line 209 "src/parse-gram.y"
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).BRACED_PREDICATE)); }
-#line 1150 "src/parse-gram.c" /* yacc.c:680  */
+#line 930 "src/parse-gram.c"
         break;
 
     case 41: /* "[identifier]"  */
-#line 216 "src/parse-gram.y" /* yacc.c:680  */
+#line 217 "src/parse-gram.y"
       { fprintf (yyo, "[%s]", ((*yyvaluep).BRACKETED_ID)); }
-#line 1156 "src/parse-gram.c" /* yacc.c:680  */
+#line 936 "src/parse-gram.c"
         break;
 
     case 42: /* "char"  */
-#line 204 "src/parse-gram.y" /* yacc.c:680  */
+#line 205 "src/parse-gram.y"
       { fputs (char_name (((*yyvaluep).CHAR)), yyo); }
-#line 1162 "src/parse-gram.c" /* yacc.c:680  */
+#line 942 "src/parse-gram.c"
         break;
 
     case 43: /* "epilogue"  */
-#line 208 "src/parse-gram.y" /* yacc.c:680  */
+#line 209 "src/parse-gram.y"
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).EPILOGUE)); }
-#line 1168 "src/parse-gram.c" /* yacc.c:680  */
+#line 948 "src/parse-gram.c"
         break;
 
     case 45: /* "identifier"  */
-#line 215 "src/parse-gram.y" /* yacc.c:680  */
+#line 216 "src/parse-gram.y"
       { fputs (((*yyvaluep).ID), yyo); }
-#line 1174 "src/parse-gram.c" /* yacc.c:680  */
+#line 954 "src/parse-gram.c"
         break;
 
     case 46: /* "identifier:"  */
-#line 217 "src/parse-gram.y" /* yacc.c:680  */
+#line 218 "src/parse-gram.y"
       { fprintf (yyo, "%s:", ((*yyvaluep).ID_COLON)); }
-#line 1180 "src/parse-gram.c" /* yacc.c:680  */
+#line 960 "src/parse-gram.c"
         break;
 
     case 49: /* "%{...%}"  */
-#line 208 "src/parse-gram.y" /* yacc.c:680  */
+#line 209 "src/parse-gram.y"
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).PROLOGUE)); }
-#line 1186 "src/parse-gram.c" /* yacc.c:680  */
+#line 966 "src/parse-gram.c"
         break;
 
     case 51: /* "<tag>"  */
-#line 219 "src/parse-gram.y" /* yacc.c:680  */
+#line 220 "src/parse-gram.y"
       { fprintf (yyo, "<%s>", ((*yyvaluep).TAG)); }
-#line 1192 "src/parse-gram.c" /* yacc.c:680  */
+#line 972 "src/parse-gram.c"
         break;
 
     case 54: /* "integer"  */
-#line 222 "src/parse-gram.y" /* yacc.c:680  */
+#line 223 "src/parse-gram.y"
       { fprintf (yyo, "%d", ((*yyvaluep).INT)); }
-#line 1198 "src/parse-gram.c" /* yacc.c:680  */
+#line 978 "src/parse-gram.c"
         break;
 
     case 55: /* "%param"  */
-#line 261 "src/parse-gram.y" /* yacc.c:680  */
+#line 262 "src/parse-gram.y"
       {
   switch (((*yyvaluep).PERCENT_PARAM))
     {
@@ -1211,107 +991,107 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
       case param_none: aver (false); break;
     }
 }
-#line 1215 "src/parse-gram.c" /* yacc.c:680  */
+#line 995 "src/parse-gram.c"
         break;
 
     case 65: /* code_props_type  */
-#line 397 "src/parse-gram.y" /* yacc.c:680  */
+#line 398 "src/parse-gram.y"
       { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_props_type))); }
-#line 1221 "src/parse-gram.c" /* yacc.c:680  */
+#line 1001 "src/parse-gram.c"
         break;
 
     case 71: /* tag.opt  */
-#line 215 "src/parse-gram.y" /* yacc.c:680  */
+#line 216 "src/parse-gram.y"
       { fputs (((*yyvaluep).yytype_71), yyo); }
-#line 1227 "src/parse-gram.c" /* yacc.c:680  */
+#line 1007 "src/parse-gram.c"
         break;
 
     case 72: /* generic_symlist  */
-#line 231 "src/parse-gram.y" /* yacc.c:680  */
+#line 232 "src/parse-gram.y"
       { symbol_list_syms_print (((*yyvaluep).generic_symlist), yyo); }
-#line 1233 "src/parse-gram.c" /* yacc.c:680  */
+#line 1013 "src/parse-gram.c"
         break;
 
     case 73: /* generic_symlist_item  */
-#line 231 "src/parse-gram.y" /* yacc.c:680  */
+#line 232 "src/parse-gram.y"
       { symbol_list_syms_print (((*yyvaluep).generic_symlist_item), yyo); }
-#line 1239 "src/parse-gram.c" /* yacc.c:680  */
+#line 1019 "src/parse-gram.c"
         break;
 
     case 74: /* tag  */
-#line 219 "src/parse-gram.y" /* yacc.c:680  */
+#line 220 "src/parse-gram.y"
       { fprintf (yyo, "<%s>", ((*yyvaluep).tag)); }
-#line 1245 "src/parse-gram.c" /* yacc.c:680  */
+#line 1025 "src/parse-gram.c"
         break;
 
     case 75: /* nterm_decls  */
-#line 231 "src/parse-gram.y" /* yacc.c:680  */
+#line 232 "src/parse-gram.y"
       { symbol_list_syms_print (((*yyvaluep).nterm_decls), yyo); }
-#line 1251 "src/parse-gram.c" /* yacc.c:680  */
+#line 1031 "src/parse-gram.c"
         break;
 
     case 76: /* token_decls  */
-#line 231 "src/parse-gram.y" /* yacc.c:680  */
+#line 232 "src/parse-gram.y"
       { symbol_list_syms_print (((*yyvaluep).token_decls), yyo); }
-#line 1257 "src/parse-gram.c" /* yacc.c:680  */
+#line 1037 "src/parse-gram.c"
         break;
 
     case 77: /* token_decl.1  */
-#line 231 "src/parse-gram.y" /* yacc.c:680  */
+#line 232 "src/parse-gram.y"
       { symbol_list_syms_print (((*yyvaluep).yytype_77), yyo); }
-#line 1263 "src/parse-gram.c" /* yacc.c:680  */
+#line 1043 "src/parse-gram.c"
         break;
 
     case 78: /* token_decl  */
-#line 225 "src/parse-gram.y" /* yacc.c:680  */
+#line 226 "src/parse-gram.y"
       { fprintf (yyo, "%s", ((*yyvaluep).token_decl) ? ((*yyvaluep).token_decl)->tag : "<NULL>"); }
-#line 1269 "src/parse-gram.c" /* yacc.c:680  */
+#line 1049 "src/parse-gram.c"
         break;
 
     case 79: /* int.opt  */
-#line 222 "src/parse-gram.y" /* yacc.c:680  */
+#line 223 "src/parse-gram.y"
       { fprintf (yyo, "%d", ((*yyvaluep).yytype_79)); }
-#line 1275 "src/parse-gram.c" /* yacc.c:680  */
+#line 1055 "src/parse-gram.c"
         break;
 
     case 80: /* token_decls_for_prec  */
-#line 231 "src/parse-gram.y" /* yacc.c:680  */
+#line 232 "src/parse-gram.y"
       { symbol_list_syms_print (((*yyvaluep).token_decls_for_prec), yyo); }
-#line 1281 "src/parse-gram.c" /* yacc.c:680  */
+#line 1061 "src/parse-gram.c"
         break;
 
     case 81: /* token_decl_for_prec.1  */
-#line 231 "src/parse-gram.y" /* yacc.c:680  */
+#line 232 "src/parse-gram.y"
       { symbol_list_syms_print (((*yyvaluep).yytype_81), yyo); }
-#line 1287 "src/parse-gram.c" /* yacc.c:680  */
+#line 1067 "src/parse-gram.c"
         break;
 
     case 82: /* token_decl_for_prec  */
-#line 225 "src/parse-gram.y" /* yacc.c:680  */
+#line 226 "src/parse-gram.y"
       { fprintf (yyo, "%s", ((*yyvaluep).token_decl_for_prec) ? ((*yyvaluep).token_decl_for_prec)->tag : "<NULL>"); }
-#line 1293 "src/parse-gram.c" /* yacc.c:680  */
+#line 1073 "src/parse-gram.c"
         break;
 
     case 83: /* symbol_decls  */
-#line 231 "src/parse-gram.y" /* yacc.c:680  */
+#line 232 "src/parse-gram.y"
       { symbol_list_syms_print (((*yyvaluep).symbol_decls), yyo); }
-#line 1299 "src/parse-gram.c" /* yacc.c:680  */
+#line 1079 "src/parse-gram.c"
         break;
 
     case 84: /* symbol_decl.1  */
-#line 231 "src/parse-gram.y" /* yacc.c:680  */
+#line 232 "src/parse-gram.y"
       { symbol_list_syms_print (((*yyvaluep).yytype_84), yyo); }
-#line 1305 "src/parse-gram.c" /* yacc.c:680  */
+#line 1085 "src/parse-gram.c"
         break;
 
     case 92: /* variable  */
-#line 215 "src/parse-gram.y" /* yacc.c:680  */
+#line 216 "src/parse-gram.y"
       { fputs (((*yyvaluep).variable), yyo); }
-#line 1311 "src/parse-gram.c" /* yacc.c:680  */
+#line 1091 "src/parse-gram.c"
         break;
 
     case 93: /* value  */
-#line 692 "src/parse-gram.y" /* yacc.c:680  */
+#line 693 "src/parse-gram.y"
       {
   switch (((*yyvaluep).value).kind)
     {
@@ -1320,37 +1100,37 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
     case muscle_string:  fprintf (yyo, "\"%s\"", ((*yyvaluep).value).chars); break;
     }
 }
-#line 1324 "src/parse-gram.c" /* yacc.c:680  */
+#line 1104 "src/parse-gram.c"
         break;
 
     case 94: /* id  */
-#line 225 "src/parse-gram.y" /* yacc.c:680  */
+#line 226 "src/parse-gram.y"
       { fprintf (yyo, "%s", ((*yyvaluep).id) ? ((*yyvaluep).id)->tag : "<NULL>"); }
-#line 1330 "src/parse-gram.c" /* yacc.c:680  */
+#line 1110 "src/parse-gram.c"
         break;
 
     case 95: /* id_colon  */
-#line 226 "src/parse-gram.y" /* yacc.c:680  */
+#line 227 "src/parse-gram.y"
       { fprintf (yyo, "%s:", ((*yyvaluep).id_colon)->tag); }
-#line 1336 "src/parse-gram.c" /* yacc.c:680  */
+#line 1116 "src/parse-gram.c"
         break;
 
     case 96: /* symbol  */
-#line 225 "src/parse-gram.y" /* yacc.c:680  */
+#line 226 "src/parse-gram.y"
       { fprintf (yyo, "%s", ((*yyvaluep).symbol) ? ((*yyvaluep).symbol)->tag : "<NULL>"); }
-#line 1342 "src/parse-gram.c" /* yacc.c:680  */
+#line 1122 "src/parse-gram.c"
         break;
 
     case 97: /* string_as_id  */
-#line 225 "src/parse-gram.y" /* yacc.c:680  */
+#line 226 "src/parse-gram.y"
       { fprintf (yyo, "%s", ((*yyvaluep).string_as_id) ? ((*yyvaluep).string_as_id)->tag : "<NULL>"); }
-#line 1348 "src/parse-gram.c" /* yacc.c:680  */
+#line 1128 "src/parse-gram.c"
         break;
 
     case 98: /* string_as_id.opt  */
-#line 225 "src/parse-gram.y" /* yacc.c:680  */
+#line 226 "src/parse-gram.y"
       { fprintf (yyo, "%s", ((*yyvaluep).yytype_98) ? ((*yyvaluep).yytype_98)->tag : "<NULL>"); }
-#line 1354 "src/parse-gram.c" /* yacc.c:680  */
+#line 1134 "src/parse-gram.c"
         break;
 
       default:
@@ -1938,57 +1718,57 @@ yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocatio
   switch (yytype)
     {
     case 72: /* generic_symlist  */
-#line 230 "src/parse-gram.y" /* yacc.c:1257  */
+#line 231 "src/parse-gram.y"
       { symbol_list_free (((*yyvaluep).generic_symlist)); }
-#line 1944 "src/parse-gram.c" /* yacc.c:1257  */
+#line 1724 "src/parse-gram.c"
         break;
 
     case 73: /* generic_symlist_item  */
-#line 230 "src/parse-gram.y" /* yacc.c:1257  */
+#line 231 "src/parse-gram.y"
       { symbol_list_free (((*yyvaluep).generic_symlist_item)); }
-#line 1950 "src/parse-gram.c" /* yacc.c:1257  */
+#line 1730 "src/parse-gram.c"
         break;
 
     case 75: /* nterm_decls  */
-#line 230 "src/parse-gram.y" /* yacc.c:1257  */
+#line 231 "src/parse-gram.y"
       { symbol_list_free (((*yyvaluep).nterm_decls)); }
-#line 1956 "src/parse-gram.c" /* yacc.c:1257  */
+#line 1736 "src/parse-gram.c"
         break;
 
     case 76: /* token_decls  */
-#line 230 "src/parse-gram.y" /* yacc.c:1257  */
+#line 231 "src/parse-gram.y"
       { symbol_list_free (((*yyvaluep).token_decls)); }
-#line 1962 "src/parse-gram.c" /* yacc.c:1257  */
+#line 1742 "src/parse-gram.c"
         break;
 
     case 77: /* token_decl.1  */
-#line 230 "src/parse-gram.y" /* yacc.c:1257  */
+#line 231 "src/parse-gram.y"
       { symbol_list_free (((*yyvaluep).yytype_77)); }
-#line 1968 "src/parse-gram.c" /* yacc.c:1257  */
+#line 1748 "src/parse-gram.c"
         break;
 
     case 80: /* token_decls_for_prec  */
-#line 230 "src/parse-gram.y" /* yacc.c:1257  */
+#line 231 "src/parse-gram.y"
       { symbol_list_free (((*yyvaluep).token_decls_for_prec)); }
-#line 1974 "src/parse-gram.c" /* yacc.c:1257  */
+#line 1754 "src/parse-gram.c"
         break;
 
     case 81: /* token_decl_for_prec.1  */
-#line 230 "src/parse-gram.y" /* yacc.c:1257  */
+#line 231 "src/parse-gram.y"
       { symbol_list_free (((*yyvaluep).yytype_81)); }
-#line 1980 "src/parse-gram.c" /* yacc.c:1257  */
+#line 1760 "src/parse-gram.c"
         break;
 
     case 83: /* symbol_decls  */
-#line 230 "src/parse-gram.y" /* yacc.c:1257  */
+#line 231 "src/parse-gram.y"
       { symbol_list_free (((*yyvaluep).symbol_decls)); }
-#line 1986 "src/parse-gram.c" /* yacc.c:1257  */
+#line 1766 "src/parse-gram.c"
         break;
 
     case 84: /* symbol_decl.1  */
-#line 230 "src/parse-gram.y" /* yacc.c:1257  */
+#line 231 "src/parse-gram.y"
       { symbol_list_free (((*yyvaluep).yytype_84)); }
-#line 1992 "src/parse-gram.c" /* yacc.c:1257  */
+#line 1772 "src/parse-gram.c"
         break;
 
       default:
@@ -2105,7 +1885,7 @@ YYLTYPE yylloc = yyloc_default;
   yychar = YYEMPTY; /* Cause a token to be read.  */
 
 /* User initialization code.  */
-#line 129 "src/parse-gram.y" /* yacc.c:1431  */
+#line 130 "src/parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -2113,7 +1893,7 @@ YYLTYPE yylloc = yyloc_default;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-#line 2117 "src/parse-gram.c" /* yacc.c:1431  */
+#line 1897 "src/parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2131,6 +1911,8 @@ yynewstate:
 | yynewstate -- set current state (the top of the stack) to yystate.  |
 `--------------------------------------------------------------------*/
 yysetstate:
+  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
+  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
   *yyssp = (yytype_int16) yystate;
 
   if (yyss + yystacksize - 1 <= yyssp)
@@ -2198,8 +1980,6 @@ yysetstate:
     }
 #endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */
 
-  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
-
   if (yystate == YYFINAL)
     YYACCEPT;
 
@@ -2312,189 +2092,189 @@ yyreduce:
     switch (yyn)
       {
   case 6:
-#line 297 "src/parse-gram.y" /* yacc.c:1652  */
+#line 298 "src/parse-gram.y"
     {
       muscle_code_grow (union_seen ? "post_prologue" : "pre_prologue",
                         translate_code ((yyvsp[0].PROLOGUE), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2322 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2102 "src/parse-gram.c"
     break;
 
   case 7:
-#line 303 "src/parse-gram.y" /* yacc.c:1652  */
+#line 304 "src/parse-gram.y"
     {
       muscle_percent_define_ensure ((yyvsp[0].PERCENT_FLAG), (yylsp[0]), true);
     }
-#line 2330 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2110 "src/parse-gram.c"
     break;
 
   case 8:
-#line 307 "src/parse-gram.y" /* yacc.c:1652  */
+#line 308 "src/parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].variable), (yyloc), (yyvsp[0].value).kind, (yyvsp[0].value).chars,
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2339 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2119 "src/parse-gram.c"
     break;
 
   case 9:
-#line 311 "src/parse-gram.y" /* yacc.c:1652  */
+#line 312 "src/parse-gram.y"
     { defines_flag = true; }
-#line 2345 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2125 "src/parse-gram.c"
     break;
 
   case 10:
-#line 313 "src/parse-gram.y" /* yacc.c:1652  */
+#line 314 "src/parse-gram.y"
     {
       defines_flag = true;
       spec_header_file = xstrdup ((yyvsp[0].STRING));
     }
-#line 2354 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2134 "src/parse-gram.c"
     break;
 
   case 11:
-#line 317 "src/parse-gram.y" /* yacc.c:1652  */
+#line 318 "src/parse-gram.y"
     { handle_error_verbose (&(yyloc), (yyvsp[0].PERCENT_ERROR_VERBOSE)); }
-#line 2360 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2140 "src/parse-gram.c"
     break;
 
   case 12:
-#line 318 "src/parse-gram.y" /* yacc.c:1652  */
+#line 319 "src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].INT); }
-#line 2366 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2146 "src/parse-gram.c"
     break;
 
   case 13:
-#line 319 "src/parse-gram.y" /* yacc.c:1652  */
+#line 320 "src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].INT); }
-#line 2372 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2152 "src/parse-gram.c"
     break;
 
   case 14:
-#line 320 "src/parse-gram.y" /* yacc.c:1652  */
+#line 321 "src/parse-gram.y"
     { handle_file_prefix (&(yyloc), &(yylsp[-1]), (yyvsp[-1].PERCENT_FILE_PREFIX), (yyvsp[0].STRING)); }
-#line 2378 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2158 "src/parse-gram.c"
     break;
 
   case 15:
-#line 322 "src/parse-gram.y" /* yacc.c:1652  */
+#line 323 "src/parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-#line 2387 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2167 "src/parse-gram.c"
     break;
 
   case 16:
-#line 327 "src/parse-gram.y" /* yacc.c:1652  */
+#line 328 "src/parse-gram.y"
     {
       muscle_code_grow ("initial_action", translate_code ((yyvsp[0].BRACED_CODE), (yylsp[0]), false), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2396 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2176 "src/parse-gram.c"
     break;
 
   case 17:
-#line 331 "src/parse-gram.y" /* yacc.c:1652  */
+#line 332 "src/parse-gram.y"
     { language_argmatch ((yyvsp[0].STRING), grammar_prio, (yylsp[-1])); }
-#line 2402 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2182 "src/parse-gram.c"
     break;
 
   case 18:
-#line 332 "src/parse-gram.y" /* yacc.c:1652  */
+#line 333 "src/parse-gram.y"
     { handle_name_prefix (&(yyloc), (yyvsp[-1].PERCENT_NAME_PREFIX), (yyvsp[0].STRING)); }
-#line 2408 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2188 "src/parse-gram.c"
     break;
 
   case 19:
-#line 333 "src/parse-gram.y" /* yacc.c:1652  */
+#line 334 "src/parse-gram.y"
     { no_lines_flag = true; }
-#line 2414 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2194 "src/parse-gram.c"
     break;
 
   case 20:
-#line 334 "src/parse-gram.y" /* yacc.c:1652  */
+#line 335 "src/parse-gram.y"
     { nondeterministic_parser = true; }
-#line 2420 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2200 "src/parse-gram.c"
     break;
 
   case 21:
-#line 335 "src/parse-gram.y" /* yacc.c:1652  */
+#line 336 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].STRING); }
-#line 2426 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2206 "src/parse-gram.c"
     break;
 
   case 22:
-#line 336 "src/parse-gram.y" /* yacc.c:1652  */
+#line 337 "src/parse-gram.y"
     { current_param = (yyvsp[0].PERCENT_PARAM); }
-#line 2432 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2212 "src/parse-gram.c"
     break;
 
   case 23:
-#line 336 "src/parse-gram.y" /* yacc.c:1652  */
+#line 337 "src/parse-gram.y"
     { current_param = param_none; }
-#line 2438 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2218 "src/parse-gram.c"
     break;
 
   case 24:
-#line 337 "src/parse-gram.y" /* yacc.c:1652  */
+#line 338 "src/parse-gram.y"
     { handle_require (&(yylsp[0]), (yyvsp[0].STRING)); }
-#line 2444 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2224 "src/parse-gram.c"
     break;
 
   case 25:
-#line 338 "src/parse-gram.y" /* yacc.c:1652  */
+#line 339 "src/parse-gram.y"
     { handle_skeleton (&(yylsp[0]), (yyvsp[0].STRING)); }
-#line 2450 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2230 "src/parse-gram.c"
     break;
 
   case 26:
-#line 339 "src/parse-gram.y" /* yacc.c:1652  */
+#line 340 "src/parse-gram.y"
     { token_table_flag = true; }
-#line 2456 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2236 "src/parse-gram.c"
     break;
 
   case 27:
-#line 340 "src/parse-gram.y" /* yacc.c:1652  */
+#line 341 "src/parse-gram.y"
     { report_flag |= report_states; }
-#line 2462 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2242 "src/parse-gram.c"
     break;
 
   case 28:
-#line 341 "src/parse-gram.y" /* yacc.c:1652  */
+#line 342 "src/parse-gram.y"
     { handle_yacc (&(yyloc), (yyvsp[0].PERCENT_YACC)); }
-#line 2468 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2248 "src/parse-gram.c"
     break;
 
   case 29:
-#line 342 "src/parse-gram.y" /* yacc.c:1652  */
+#line 343 "src/parse-gram.y"
     { current_class = unknown_sym; yyerrok; }
-#line 2474 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2254 "src/parse-gram.c"
     break;
 
   case 31:
-#line 347 "src/parse-gram.y" /* yacc.c:1652  */
+#line 348 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].BRACED_CODE), (yylsp[0])); }
-#line 2480 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2260 "src/parse-gram.c"
     break;
 
   case 32:
-#line 348 "src/parse-gram.y" /* yacc.c:1652  */
+#line 349 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].BRACED_CODE), (yylsp[0])); }
-#line 2486 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2266 "src/parse-gram.c"
     break;
 
   case 34:
-#line 359 "src/parse-gram.y" /* yacc.c:1652  */
+#line 360 "src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-#line 2494 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2274 "src/parse-gram.c"
     break;
 
   case 35:
-#line 363 "src/parse-gram.y" /* yacc.c:1652  */
+#line 364 "src/parse-gram.y"
     {
       code_props code;
       code_props_symbol_action_init (&code, (yyvsp[-1].BRACED_CODE), (yylsp[-1]));
@@ -2505,27 +2285,27 @@ yyreduce:
         symbol_list_free ((yyvsp[0].generic_symlist));
       }
     }
-#line 2509 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2289 "src/parse-gram.c"
     break;
 
   case 36:
-#line 374 "src/parse-gram.y" /* yacc.c:1652  */
+#line 375 "src/parse-gram.y"
     {
       default_prec = true;
     }
-#line 2517 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2297 "src/parse-gram.c"
     break;
 
   case 37:
-#line 378 "src/parse-gram.y" /* yacc.c:1652  */
+#line 379 "src/parse-gram.y"
     {
       default_prec = false;
     }
-#line 2525 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2305 "src/parse-gram.c"
     break;
 
   case 38:
-#line 382 "src/parse-gram.y" /* yacc.c:1652  */
+#line 383 "src/parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2533,207 +2313,207 @@ yyreduce:
                         translate_code_braceless ((yyvsp[0].BRACED_CODE), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2537 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2317 "src/parse-gram.c"
     break;
 
   case 39:
-#line 390 "src/parse-gram.y" /* yacc.c:1652  */
+#line 391 "src/parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].ID), (yylsp[-1]), translate_code_braceless ((yyvsp[0].BRACED_CODE), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2546 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2326 "src/parse-gram.c"
     break;
 
   case 40:
-#line 399 "src/parse-gram.y" /* yacc.c:1652  */
+#line 400 "src/parse-gram.y"
     { (yyval.code_props_type) = destructor; }
-#line 2552 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2332 "src/parse-gram.c"
     break;
 
   case 41:
-#line 400 "src/parse-gram.y" /* yacc.c:1652  */
+#line 401 "src/parse-gram.y"
     { (yyval.code_props_type) = printer; }
-#line 2558 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2338 "src/parse-gram.c"
     break;
 
   case 42:
-#line 410 "src/parse-gram.y" /* yacc.c:1652  */
+#line 411 "src/parse-gram.y"
     {}
-#line 2564 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2344 "src/parse-gram.c"
     break;
 
   case 43:
-#line 411 "src/parse-gram.y" /* yacc.c:1652  */
+#line 412 "src/parse-gram.y"
     { muscle_percent_define_insert ("api.value.union.name",
                                          (yylsp[0]), muscle_keyword, (yyvsp[0].ID),
                                          MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE); }
-#line 2572 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2352 "src/parse-gram.c"
     break;
 
   case 44:
-#line 418 "src/parse-gram.y" /* yacc.c:1652  */
+#line 419 "src/parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("union_members", translate_code_braceless ((yyvsp[0].BRACED_CODE), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2582 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2362 "src/parse-gram.c"
     break;
 
   case 45:
-#line 430 "src/parse-gram.y" /* yacc.c:1652  */
+#line 431 "src/parse-gram.y"
     { current_class = nterm_sym; }
-#line 2588 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2368 "src/parse-gram.c"
     break;
 
   case 46:
-#line 431 "src/parse-gram.y" /* yacc.c:1652  */
+#line 432 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       symbol_list_free ((yyvsp[0].nterm_decls));
     }
-#line 2597 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2377 "src/parse-gram.c"
     break;
 
   case 47:
-#line 435 "src/parse-gram.y" /* yacc.c:1652  */
+#line 436 "src/parse-gram.y"
     { current_class = token_sym; }
-#line 2603 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2383 "src/parse-gram.c"
     break;
 
   case 48:
-#line 436 "src/parse-gram.y" /* yacc.c:1652  */
+#line 437 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       symbol_list_free ((yyvsp[0].token_decls));
     }
-#line 2612 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2392 "src/parse-gram.c"
     break;
 
   case 49:
-#line 441 "src/parse-gram.y" /* yacc.c:1652  */
+#line 442 "src/parse-gram.y"
     {
       symbol_list_free ((yyvsp[0].symbol_decls));
     }
-#line 2620 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2400 "src/parse-gram.c"
     break;
 
   case 50:
-#line 445 "src/parse-gram.y" /* yacc.c:1652  */
+#line 446 "src/parse-gram.y"
     {
       ++current_prec;
       for (symbol_list *list = (yyvsp[0].token_decls_for_prec); list; list = list->next)
         symbol_precedence_set (list->content.sym, current_prec, (yyvsp[-1].precedence_declarator), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].token_decls_for_prec));
     }
-#line 2631 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2411 "src/parse-gram.c"
     break;
 
   case 51:
-#line 454 "src/parse-gram.y" /* yacc.c:1652  */
+#line 455 "src/parse-gram.y"
     { (yyval.precedence_declarator) = left_assoc; }
-#line 2637 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2417 "src/parse-gram.c"
     break;
 
   case 52:
-#line 455 "src/parse-gram.y" /* yacc.c:1652  */
+#line 456 "src/parse-gram.y"
     { (yyval.precedence_declarator) = right_assoc; }
-#line 2643 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2423 "src/parse-gram.c"
     break;
 
   case 53:
-#line 456 "src/parse-gram.y" /* yacc.c:1652  */
+#line 457 "src/parse-gram.y"
     { (yyval.precedence_declarator) = non_assoc; }
-#line 2649 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2429 "src/parse-gram.c"
     break;
 
   case 54:
-#line 457 "src/parse-gram.y" /* yacc.c:1652  */
+#line 458 "src/parse-gram.y"
     { (yyval.precedence_declarator) = precedence_assoc; }
-#line 2655 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2435 "src/parse-gram.c"
     break;
 
   case 55:
-#line 461 "src/parse-gram.y" /* yacc.c:1652  */
+#line 462 "src/parse-gram.y"
     { (yyval.yytype_71) = NULL; }
-#line 2661 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2441 "src/parse-gram.c"
     break;
 
   case 56:
-#line 462 "src/parse-gram.y" /* yacc.c:1652  */
+#line 463 "src/parse-gram.y"
     { (yyval.yytype_71) = (yyvsp[0].TAG); }
-#line 2667 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2447 "src/parse-gram.c"
     break;
 
   case 58:
-#line 468 "src/parse-gram.y" /* yacc.c:1652  */
+#line 469 "src/parse-gram.y"
     { (yyval.generic_symlist) = symbol_list_append ((yyvsp[-1].generic_symlist), (yyvsp[0].generic_symlist_item)); }
-#line 2673 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2453 "src/parse-gram.c"
     break;
 
   case 59:
-#line 472 "src/parse-gram.y" /* yacc.c:1652  */
+#line 473 "src/parse-gram.y"
     { (yyval.generic_symlist_item) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2679 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2459 "src/parse-gram.c"
     break;
 
   case 60:
-#line 473 "src/parse-gram.y" /* yacc.c:1652  */
+#line 474 "src/parse-gram.y"
     { (yyval.generic_symlist_item) = symbol_list_type_new ((yyvsp[0].tag), (yylsp[0])); }
-#line 2685 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2465 "src/parse-gram.c"
     break;
 
   case 62:
-#line 478 "src/parse-gram.y" /* yacc.c:1652  */
+#line 479 "src/parse-gram.y"
     { (yyval.tag) = uniqstr_new ("*"); }
-#line 2691 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2471 "src/parse-gram.c"
     break;
 
   case 63:
-#line 479 "src/parse-gram.y" /* yacc.c:1652  */
+#line 480 "src/parse-gram.y"
     { (yyval.tag) = uniqstr_new (""); }
-#line 2697 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2477 "src/parse-gram.c"
     break;
 
   case 65:
-#line 502 "src/parse-gram.y" /* yacc.c:1652  */
+#line 503 "src/parse-gram.y"
     {
       (yyval.token_decls) = (yyvsp[0].yytype_77);
     }
-#line 2705 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2485 "src/parse-gram.c"
     break;
 
   case 66:
-#line 506 "src/parse-gram.y" /* yacc.c:1652  */
+#line 507 "src/parse-gram.y"
     {
       (yyval.token_decls) = symbol_list_type_set ((yyvsp[0].yytype_77), (yyvsp[-1].TAG), (yylsp[-1]));
     }
-#line 2713 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2493 "src/parse-gram.c"
     break;
 
   case 67:
-#line 510 "src/parse-gram.y" /* yacc.c:1652  */
+#line 511 "src/parse-gram.y"
     {
       (yyval.token_decls) = symbol_list_append ((yyvsp[-2].token_decls), symbol_list_type_set ((yyvsp[0].yytype_77), (yyvsp[-1].TAG), (yylsp[-1])));
     }
-#line 2721 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2501 "src/parse-gram.c"
     break;
 
   case 68:
-#line 517 "src/parse-gram.y" /* yacc.c:1652  */
+#line 518 "src/parse-gram.y"
     { (yyval.yytype_77) = symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0])); }
-#line 2727 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2507 "src/parse-gram.c"
     break;
 
   case 69:
-#line 518 "src/parse-gram.y" /* yacc.c:1652  */
+#line 519 "src/parse-gram.y"
     { (yyval.yytype_77) = symbol_list_append ((yyvsp[-1].yytype_77), symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0]))); }
-#line 2733 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2513 "src/parse-gram.c"
     break;
 
   case 70:
-#line 523 "src/parse-gram.y" /* yacc.c:1652  */
+#line 524 "src/parse-gram.y"
     {
       (yyval.token_decl) = (yyvsp[-2].id);
       symbol_class_set ((yyvsp[-2].id), current_class, (yylsp[-2]), true);
@@ -2742,238 +2522,238 @@ yyreduce:
       if ((yyvsp[0].yytype_98))
         symbol_make_alias ((yyvsp[-2].id), (yyvsp[0].yytype_98), (yylsp[0]));
     }
-#line 2746 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2526 "src/parse-gram.c"
     break;
 
   case 71:
-#line 535 "src/parse-gram.y" /* yacc.c:1652  */
+#line 536 "src/parse-gram.y"
     { (yyval.yytype_79) = -1; }
-#line 2752 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2532 "src/parse-gram.c"
     break;
 
   case 73:
-#line 549 "src/parse-gram.y" /* yacc.c:1652  */
+#line 550 "src/parse-gram.y"
     {
       (yyval.token_decls_for_prec) = (yyvsp[0].yytype_81);
     }
-#line 2760 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2540 "src/parse-gram.c"
     break;
 
   case 74:
-#line 553 "src/parse-gram.y" /* yacc.c:1652  */
+#line 554 "src/parse-gram.y"
     {
       (yyval.token_decls_for_prec) = symbol_list_type_set ((yyvsp[0].yytype_81), (yyvsp[-1].TAG), (yylsp[-1]));
     }
-#line 2768 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2548 "src/parse-gram.c"
     break;
 
   case 75:
-#line 557 "src/parse-gram.y" /* yacc.c:1652  */
+#line 558 "src/parse-gram.y"
     {
       (yyval.token_decls_for_prec) = symbol_list_append ((yyvsp[-2].token_decls_for_prec), symbol_list_type_set ((yyvsp[0].yytype_81), (yyvsp[-1].TAG), (yylsp[-1])));
     }
-#line 2776 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2556 "src/parse-gram.c"
     break;
 
   case 76:
-#line 565 "src/parse-gram.y" /* yacc.c:1652  */
+#line 566 "src/parse-gram.y"
     { (yyval.yytype_81) = symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0])); }
-#line 2782 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2562 "src/parse-gram.c"
     break;
 
   case 77:
-#line 567 "src/parse-gram.y" /* yacc.c:1652  */
+#line 568 "src/parse-gram.y"
     { (yyval.yytype_81) = symbol_list_append ((yyvsp[-1].yytype_81), symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0]))); }
-#line 2788 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2568 "src/parse-gram.c"
     break;
 
   case 78:
-#line 572 "src/parse-gram.y" /* yacc.c:1652  */
+#line 573 "src/parse-gram.y"
     {
       (yyval.token_decl_for_prec) = (yyvsp[-1].id);
       symbol_class_set ((yyvsp[-1].id), token_sym, (yylsp[-1]), false);
       if (0 <= (yyvsp[0].yytype_79))
         symbol_user_token_number_set ((yyvsp[-1].id), (yyvsp[0].yytype_79), (yylsp[0]));
     }
-#line 2799 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2579 "src/parse-gram.c"
     break;
 
   case 80:
-#line 589 "src/parse-gram.y" /* yacc.c:1652  */
+#line 590 "src/parse-gram.y"
     {
       (yyval.symbol_decls) = (yyvsp[0].yytype_84);
     }
-#line 2807 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2587 "src/parse-gram.c"
     break;
 
   case 81:
-#line 593 "src/parse-gram.y" /* yacc.c:1652  */
+#line 594 "src/parse-gram.y"
     {
       (yyval.symbol_decls) = symbol_list_type_set ((yyvsp[0].yytype_84), (yyvsp[-1].TAG), (yylsp[-1]));
     }
-#line 2815 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2595 "src/parse-gram.c"
     break;
 
   case 82:
-#line 597 "src/parse-gram.y" /* yacc.c:1652  */
+#line 598 "src/parse-gram.y"
     {
       (yyval.symbol_decls) = symbol_list_append ((yyvsp[-2].symbol_decls), symbol_list_type_set ((yyvsp[0].yytype_84), (yyvsp[-1].TAG), (yylsp[-1])));
     }
-#line 2823 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2603 "src/parse-gram.c"
     break;
 
   case 83:
-#line 604 "src/parse-gram.y" /* yacc.c:1652  */
+#line 605 "src/parse-gram.y"
     { (yyval.yytype_84) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2829 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2609 "src/parse-gram.c"
     break;
 
   case 84:
-#line 605 "src/parse-gram.y" /* yacc.c:1652  */
+#line 606 "src/parse-gram.y"
     { (yyval.yytype_84) = symbol_list_append ((yyvsp[-1].yytype_84), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2835 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2615 "src/parse-gram.c"
     break;
 
   case 89:
-#line 623 "src/parse-gram.y" /* yacc.c:1652  */
+#line 624 "src/parse-gram.y"
     {
       yyerrok;
     }
-#line 2843 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2623 "src/parse-gram.c"
     break;
 
   case 90:
-#line 629 "src/parse-gram.y" /* yacc.c:1652  */
+#line 630 "src/parse-gram.y"
     { current_lhs ((yyvsp[-1].id_colon), (yylsp[-1]), (yyvsp[0].yytype_91)); }
-#line 2849 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2629 "src/parse-gram.c"
     break;
 
   case 91:
-#line 630 "src/parse-gram.y" /* yacc.c:1652  */
+#line 631 "src/parse-gram.y"
     {
       /* Free the current lhs. */
       current_lhs (0, (yylsp[-3]), 0);
     }
-#line 2858 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2638 "src/parse-gram.c"
     break;
 
   case 92:
-#line 637 "src/parse-gram.y" /* yacc.c:1652  */
+#line 638 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2864 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2644 "src/parse-gram.c"
     break;
 
   case 93:
-#line 638 "src/parse-gram.y" /* yacc.c:1652  */
+#line 639 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2870 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2650 "src/parse-gram.c"
     break;
 
   case 95:
-#line 645 "src/parse-gram.y" /* yacc.c:1652  */
+#line 646 "src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2877 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2657 "src/parse-gram.c"
     break;
 
   case 96:
-#line 648 "src/parse-gram.y" /* yacc.c:1652  */
+#line 649 "src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].yytype_91)); }
-#line 2883 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2663 "src/parse-gram.c"
     break;
 
   case 97:
-#line 650 "src/parse-gram.y" /* yacc.c:1652  */
+#line 651 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[-1].BRACED_CODE), (yylsp[-1]), (yyvsp[0].yytype_91), (yyvsp[-2].yytype_71)); }
-#line 2889 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2669 "src/parse-gram.c"
     break;
 
   case 98:
-#line 652 "src/parse-gram.y" /* yacc.c:1652  */
+#line 653 "src/parse-gram.y"
     { grammar_current_rule_predicate_append ((yyvsp[0].BRACED_PREDICATE), (yylsp[0])); }
-#line 2895 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2675 "src/parse-gram.c"
     break;
 
   case 99:
-#line 654 "src/parse-gram.y" /* yacc.c:1652  */
+#line 655 "src/parse-gram.y"
     { grammar_current_rule_empty_set ((yylsp[0])); }
-#line 2901 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2681 "src/parse-gram.c"
     break;
 
   case 100:
-#line 656 "src/parse-gram.y" /* yacc.c:1652  */
+#line 657 "src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2907 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2687 "src/parse-gram.c"
     break;
 
   case 101:
-#line 658 "src/parse-gram.y" /* yacc.c:1652  */
+#line 659 "src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].INT), (yylsp[0])); }
-#line 2913 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2693 "src/parse-gram.c"
     break;
 
   case 102:
-#line 660 "src/parse-gram.y" /* yacc.c:1652  */
+#line 661 "src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].TAG), (yylsp[0])); }
-#line 2919 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2699 "src/parse-gram.c"
     break;
 
   case 103:
-#line 662 "src/parse-gram.y" /* yacc.c:1652  */
+#line 663 "src/parse-gram.y"
     { grammar_current_rule_expect_sr ((yyvsp[0].INT), (yylsp[0])); }
-#line 2925 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2705 "src/parse-gram.c"
     break;
 
   case 104:
-#line 664 "src/parse-gram.y" /* yacc.c:1652  */
+#line 665 "src/parse-gram.y"
     { grammar_current_rule_expect_rr ((yyvsp[0].INT), (yylsp[0])); }
-#line 2931 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2711 "src/parse-gram.c"
     break;
 
   case 105:
-#line 668 "src/parse-gram.y" /* yacc.c:1652  */
+#line 669 "src/parse-gram.y"
     { (yyval.yytype_91) = 0; }
-#line 2937 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2717 "src/parse-gram.c"
     break;
 
   case 106:
-#line 669 "src/parse-gram.y" /* yacc.c:1652  */
+#line 670 "src/parse-gram.y"
     { (yyval.yytype_91) = named_ref_new ((yyvsp[0].BRACKETED_ID), (yylsp[0])); }
-#line 2943 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2723 "src/parse-gram.c"
     break;
 
   case 108:
-#line 702 "src/parse-gram.y" /* yacc.c:1652  */
+#line 703 "src/parse-gram.y"
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = ""; }
-#line 2949 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2729 "src/parse-gram.c"
     break;
 
   case 109:
-#line 703 "src/parse-gram.y" /* yacc.c:1652  */
+#line 704 "src/parse-gram.y"
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = (yyvsp[0].ID); }
-#line 2955 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2735 "src/parse-gram.c"
     break;
 
   case 110:
-#line 704 "src/parse-gram.y" /* yacc.c:1652  */
+#line 705 "src/parse-gram.y"
     { (yyval.value).kind = muscle_string;  (yyval.value).chars = (yyvsp[0].STRING); }
-#line 2961 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2741 "src/parse-gram.c"
     break;
 
   case 111:
-#line 705 "src/parse-gram.y" /* yacc.c:1652  */
+#line 706 "src/parse-gram.y"
     { (yyval.value).kind = muscle_code;    (yyval.value).chars = strip_braces ((yyvsp[0].BRACED_CODE)); }
-#line 2967 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2747 "src/parse-gram.c"
     break;
 
   case 112:
-#line 718 "src/parse-gram.y" /* yacc.c:1652  */
+#line 719 "src/parse-gram.y"
     { (yyval.id) = symbol_from_uniqstr ((yyvsp[0].ID), (yylsp[0])); }
-#line 2973 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2753 "src/parse-gram.c"
     break;
 
   case 113:
-#line 720 "src/parse-gram.y" /* yacc.c:1652  */
+#line 721 "src/parse-gram.y"
     {
       if (current_class == nterm_sym)
         {
@@ -2985,41 +2765,41 @@ yyreduce:
       symbol_class_set ((yyval.id), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.id), (yyvsp[0].CHAR), (yylsp[0]));
     }
-#line 2989 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2769 "src/parse-gram.c"
     break;
 
   case 114:
-#line 734 "src/parse-gram.y" /* yacc.c:1652  */
+#line 735 "src/parse-gram.y"
     { (yyval.id_colon) = symbol_from_uniqstr ((yyvsp[0].ID_COLON), (yylsp[0])); }
-#line 2995 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2775 "src/parse-gram.c"
     break;
 
   case 117:
-#line 746 "src/parse-gram.y" /* yacc.c:1652  */
+#line 747 "src/parse-gram.y"
     {
       (yyval.string_as_id) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].STRING)), (yylsp[0]));
       symbol_class_set ((yyval.string_as_id), token_sym, (yylsp[0]), false);
     }
-#line 3004 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2784 "src/parse-gram.c"
     break;
 
   case 118:
-#line 754 "src/parse-gram.y" /* yacc.c:1652  */
+#line 755 "src/parse-gram.y"
     { (yyval.yytype_98) = NULL; }
-#line 3010 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2790 "src/parse-gram.c"
     break;
 
   case 121:
-#line 761 "src/parse-gram.y" /* yacc.c:1652  */
+#line 762 "src/parse-gram.y"
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[0].EPILOGUE), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 3019 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2799 "src/parse-gram.c"
     break;
 
 
-#line 3023 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2803 "src/parse-gram.c"
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3268,7 +3048,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 767 "src/parse-gram.y" /* yacc.c:1918  */
+#line 768 "src/parse-gram.y"
 
 
 /* Return the location of the left-hand side of a rule whose
