@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.150-0305.  */
+/* A Bison parser, made by GNU Bison 2.4.156-d497.  */
 
 /* Implementation for Bison's Yacc-like parsers in C
 
@@ -45,7 +45,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.150-0305"
+#define YYBISON_VERSION "2.4.156-d497"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -229,9 +229,9 @@ static int current_prec = 0;
      PIPE = 306,
      PROLOGUE = 307,
      SEMICOLON = 308,
-     TYPE = 309,
-     TYPE_TAG_ANY = 310,
-     TYPE_TAG_NONE = 311,
+     TAG = 309,
+     TAG_ANY = 310,
+     TAG_NONE = 311,
      PERCENT_UNION = 312
    };
 #endif
@@ -288,9 +288,9 @@ static int current_prec = 0;
 #define PIPE 306
 #define PROLOGUE 307
 #define SEMICOLON 308
-#define TYPE 309
-#define TYPE_TAG_ANY 310
-#define TYPE_TAG_NONE 311
+#define TAG 309
+#define TAG_ANY 310
+#define TAG_NONE 311
 #define PERCENT_UNION 312
 
 
@@ -700,10 +700,10 @@ static const char *const yytname[] =
   "\"%skeleton\"", "\"%start\"", "\"%token-table\"", "\"%verbose\"",
   "\"%yacc\"", "\"{...}\"", "\"char\"", "\"epilogue\"", "\"=\"",
   "\"identifier\"", "\"identifier:\"", "\"%%\"", "\"|\"", "\"%{...%}\"",
-  "\";\"", "\"type\"", "\"<*>\"", "\"<>\"", "\"%union\"", "$accept",
+  "\";\"", "\"<tag>\"", "\"<*>\"", "\"<>\"", "\"%union\"", "$accept",
   "input", "prologue_declarations", "prologue_declaration",
   "grammar_declaration", "union_name", "symbol_declaration", "$@1", "$@2",
-  "precedence_declaration", "precedence_declarator", "type.opt",
+  "precedence_declaration", "precedence_declarator", "tag.opt",
   "symbols.prec", "symbol.prec", "symbols.1", "generic_symlist",
   "generic_symlist_item", "symbol_def", "symbol_defs.1", "grammar",
   "rules_or_grammar_declaration", "rules", "$@3", "rhses.1", "rhs",
@@ -1113,7 +1113,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 /* Line 719 of yacc.c  */
 #line 1115 "../../src/parse-gram.c"
 	break;
-      case 54: /* "\"type\"" */
+      case 54: /* "\"<tag>\"" */
 
 /* Line 719 of yacc.c  */
 #line 187 "parse-gram.y"
