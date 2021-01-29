@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.7.12-658d-dirty.  */
+/* A Bison parser, made by GNU Bison 3.7.14-eb26-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -49,7 +49,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.7.12-658d-dirty"
+#define YYBISON_VERSION "3.7.14-eb26-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -149,7 +149,7 @@ enum yysymbol_kind_t
   YYSYMBOL_BRACED_CODE = 41,               /* "{...}"  */
   YYSYMBOL_BRACED_PREDICATE = 42,          /* "%?{...}"  */
   YYSYMBOL_BRACKETED_ID = 43,              /* "[identifier]"  */
-  YYSYMBOL_CHAR = 44,                      /* "character literal"  */
+  YYSYMBOL_CHAR_LITERAL = 44,              /* "character literal"  */
   YYSYMBOL_COLON = 45,                     /* ":"  */
   YYSYMBOL_EPILOGUE = 46,                  /* "epilogue"  */
   YYSYMBOL_EQUAL = 47,                     /* "="  */
@@ -162,7 +162,7 @@ enum yysymbol_kind_t
   YYSYMBOL_TAG = 54,                       /* "<tag>"  */
   YYSYMBOL_TAG_ANY = 55,                   /* "<*>"  */
   YYSYMBOL_TAG_NONE = 56,                  /* "<>"  */
-  YYSYMBOL_INT = 57,                       /* "integer literal"  */
+  YYSYMBOL_INT_LITERAL = 57,               /* "integer literal"  */
   YYSYMBOL_PERCENT_PARAM = 58,             /* "%param"  */
   YYSYMBOL_PERCENT_UNION = 59,             /* "%union"  */
   YYSYMBOL_PERCENT_EMPTY = 60,             /* "%empty"  */
@@ -1115,8 +1115,8 @@ tron (yyo);
          { fprintf (yyo, "[%s]", ((*yyvaluep).BRACKETED_ID)); }
         break;
 
-    case YYSYMBOL_CHAR: /* "character literal"  */
-         { fputs (char_name (((*yyvaluep).CHAR)), yyo); }
+    case YYSYMBOL_CHAR_LITERAL: /* "character literal"  */
+         { fputs (char_name (((*yyvaluep).CHAR_LITERAL)), yyo); }
         break;
 
     case YYSYMBOL_EPILOGUE: /* "epilogue"  */
@@ -1139,8 +1139,8 @@ tron (yyo);
          { fprintf (yyo, "<%s>", ((*yyvaluep).TAG)); }
         break;
 
-    case YYSYMBOL_INT: /* "integer literal"  */
-         { fprintf (yyo, "%d", ((*yyvaluep).INT)); }
+    case YYSYMBOL_INT_LITERAL: /* "integer literal"  */
+         { fprintf (yyo, "%d", ((*yyvaluep).INT_LITERAL)); }
         break;
 
     case YYSYMBOL_PERCENT_PARAM: /* "%param"  */
@@ -2087,11 +2087,11 @@ yyreduce:
     break;
 
   case 12: /* prologue_declaration: "%expect" "integer literal"  */
-                                   { expected_sr_conflicts = (yyvsp[0].INT); }
+                                   { expected_sr_conflicts = (yyvsp[0].INT_LITERAL); }
     break;
 
   case 13: /* prologue_declaration: "%expect-rr" "integer literal"  */
-                                   { expected_rr_conflicts = (yyvsp[0].INT); }
+                                   { expected_rr_conflicts = (yyvsp[0].INT_LITERAL); }
     break;
 
   case 14: /* prologue_declaration: "%file-prefix" "string"  */
@@ -2506,7 +2506,7 @@ yyreduce:
     break;
 
   case 105: /* rhs: rhs "%dprec" "integer literal"  */
-    { grammar_current_rule_dprec_set ((yyvsp[0].INT), (yylsp[0])); }
+    { grammar_current_rule_dprec_set ((yyvsp[0].INT_LITERAL), (yylsp[0])); }
     break;
 
   case 106: /* rhs: rhs "%merge" "<tag>"  */
@@ -2514,11 +2514,11 @@ yyreduce:
     break;
 
   case 107: /* rhs: rhs "%expect" "integer literal"  */
-    { grammar_current_rule_expect_sr ((yyvsp[0].INT), (yylsp[0])); }
+    { grammar_current_rule_expect_sr ((yyvsp[0].INT_LITERAL), (yylsp[0])); }
     break;
 
   case 108: /* rhs: rhs "%expect-rr" "integer literal"  */
-    { grammar_current_rule_expect_rr ((yyvsp[0].INT), (yylsp[0])); }
+    { grammar_current_rule_expect_rr ((yyvsp[0].INT_LITERAL), (yylsp[0])); }
     break;
 
   case 109: /* named_ref.opt: %empty  */
@@ -2566,9 +2566,9 @@ yyreduce:
           location loc = muscle_percent_define_get_loc (var);
           subcomplain (&loc, complaint, _("definition of %s"), var);
         }
-      (yyval.id) = symbol_get (char_name ((yyvsp[0].CHAR)), (yylsp[0]));
+      (yyval.id) = symbol_get (char_name ((yyvsp[0].CHAR_LITERAL)), (yylsp[0]));
       symbol_class_set ((yyval.id), token_sym, (yylsp[0]), false);
-      symbol_code_set ((yyval.id), (yyvsp[0].CHAR), (yylsp[0]));
+      symbol_code_set ((yyval.id), (yyvsp[0].CHAR_LITERAL), (yylsp[0]));
     }
     break;
 
