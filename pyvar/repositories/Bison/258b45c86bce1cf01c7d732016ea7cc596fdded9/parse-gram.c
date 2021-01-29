@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.7.980-6f0a6-dirty.  */
+/* A Bison parser, made by GNU Bison 2.7.987-a2db-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.7.980-6f0a6-dirty"
+#define YYBISON_VERSION "2.7.987-a2db-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -1022,98 +1022,98 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
 # endif
   switch (yytype)
     {
-            case 3: // "string"
+    case 3: /* "string"  */
 /* Line 705 of yacc.c  */
 #line 196 "src/parse-gram.y"
-        { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), yyo); }
+      { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), yyo); }
 /* Line 705 of yacc.c  */
 #line 1031 "src/parse-gram.c"
         break;
 
-            case 4: // "integer"
+    case 4: /* "integer"  */
 /* Line 705 of yacc.c  */
 #line 209 "src/parse-gram.y"
-        { fprintf (yyo, "%d", ((*yyvaluep).integer)); }
+      { fprintf (yyo, "%d", ((*yyvaluep).integer)); }
 /* Line 705 of yacc.c  */
 #line 1039 "src/parse-gram.c"
         break;
 
-            case 24: // "%<flag>"
+    case 24: /* "%<flag>"  */
 /* Line 705 of yacc.c  */
 #line 205 "src/parse-gram.y"
-        { fprintf (yyo, "%%%s", ((*yyvaluep).uniqstr)); }
+      { fprintf (yyo, "%%%s", ((*yyvaluep).uniqstr)); }
 /* Line 705 of yacc.c  */
 #line 1047 "src/parse-gram.c"
         break;
 
-            case 40: // "{...}"
+    case 40: /* "{...}"  */
 /* Line 705 of yacc.c  */
 #line 198 "src/parse-gram.y"
-        { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
+      { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
 /* Line 705 of yacc.c  */
 #line 1055 "src/parse-gram.c"
         break;
 
-            case 42: // "[identifier]"
+    case 42: /* "[identifier]"  */
 /* Line 705 of yacc.c  */
 #line 203 "src/parse-gram.y"
-        { fprintf (yyo, "[%s]", ((*yyvaluep).uniqstr)); }
+      { fprintf (yyo, "[%s]", ((*yyvaluep).uniqstr)); }
 /* Line 705 of yacc.c  */
 #line 1063 "src/parse-gram.c"
         break;
 
-            case 43: // "char"
+    case 43: /* "char"  */
 /* Line 705 of yacc.c  */
 #line 190 "src/parse-gram.y"
-        { fputs (char_name (((*yyvaluep).character)), yyo); }
+      { fputs (char_name (((*yyvaluep).character)), yyo); }
 /* Line 705 of yacc.c  */
 #line 1071 "src/parse-gram.c"
         break;
 
-            case 44: // "epilogue"
+    case 44: /* "epilogue"  */
 /* Line 705 of yacc.c  */
 #line 198 "src/parse-gram.y"
-        { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
+      { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 705 of yacc.c  */
 #line 1079 "src/parse-gram.c"
         break;
 
-            case 46: // "identifier"
+    case 46: /* "identifier"  */
 /* Line 705 of yacc.c  */
 #line 202 "src/parse-gram.y"
-        { fputs (((*yyvaluep).uniqstr), yyo); }
+      { fputs (((*yyvaluep).uniqstr), yyo); }
 /* Line 705 of yacc.c  */
 #line 1087 "src/parse-gram.c"
         break;
 
-            case 47: // "identifier:"
+    case 47: /* "identifier:"  */
 /* Line 705 of yacc.c  */
 #line 204 "src/parse-gram.y"
-        { fprintf (yyo, "%s:", ((*yyvaluep).uniqstr)); }
+      { fprintf (yyo, "%s:", ((*yyvaluep).uniqstr)); }
 /* Line 705 of yacc.c  */
 #line 1095 "src/parse-gram.c"
         break;
 
-            case 50: // "%{...%}"
+    case 50: /* "%{...%}"  */
 /* Line 705 of yacc.c  */
 #line 198 "src/parse-gram.y"
-        { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
+      { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 705 of yacc.c  */
 #line 1103 "src/parse-gram.c"
         break;
 
-            case 52: // "<tag>"
+    case 52: /* "<tag>"  */
 /* Line 705 of yacc.c  */
 #line 206 "src/parse-gram.y"
-        { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
+      { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
 /* Line 705 of yacc.c  */
 #line 1111 "src/parse-gram.c"
         break;
 
-            case 55: // "%param"
+    case 55: /* "%param"  */
 /* Line 705 of yacc.c  */
 #line 252 "src/parse-gram.y"
-        {
+      {
   switch (((*yyvaluep).param))
     {
 #define CASE(In, Out)                                           \
@@ -1129,82 +1129,82 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
 #line 1130 "src/parse-gram.c"
         break;
 
-            case 64: // code_props_type
+    case 64: /* code_props_type  */
 /* Line 705 of yacc.c  */
 #line 424 "src/parse-gram.y"
-        { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_type))); }
+      { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_type))); }
 /* Line 705 of yacc.c  */
 #line 1138 "src/parse-gram.c"
         break;
 
-            case 73: // symbol.prec
+    case 73: /* symbol.prec  */
 /* Line 705 of yacc.c  */
 #line 212 "src/parse-gram.y"
-        { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
+      { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 705 of yacc.c  */
 #line 1146 "src/parse-gram.c"
         break;
 
-            case 77: // tag
+    case 77: /* tag  */
 /* Line 705 of yacc.c  */
 #line 206 "src/parse-gram.y"
-        { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
+      { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
 /* Line 705 of yacc.c  */
 #line 1154 "src/parse-gram.c"
         break;
 
-            case 87: // variable
+    case 87: /* variable  */
 /* Line 705 of yacc.c  */
 #line 202 "src/parse-gram.y"
-        { fputs (((*yyvaluep).uniqstr), yyo); }
+      { fputs (((*yyvaluep).uniqstr), yyo); }
 /* Line 705 of yacc.c  */
 #line 1162 "src/parse-gram.c"
         break;
 
-            case 88: // content.opt
+    case 88: /* content.opt  */
 /* Line 705 of yacc.c  */
 #line 198 "src/parse-gram.y"
-        { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
+      { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 705 of yacc.c  */
 #line 1170 "src/parse-gram.c"
         break;
 
-            case 89: // braceless
+    case 89: /* braceless  */
 /* Line 705 of yacc.c  */
 #line 198 "src/parse-gram.y"
-        { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
+      { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 705 of yacc.c  */
 #line 1178 "src/parse-gram.c"
         break;
 
-            case 90: // id
+    case 90: /* id  */
 /* Line 705 of yacc.c  */
 #line 212 "src/parse-gram.y"
-        { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
+      { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 705 of yacc.c  */
 #line 1186 "src/parse-gram.c"
         break;
 
-            case 91: // id_colon
+    case 91: /* id_colon  */
 /* Line 705 of yacc.c  */
 #line 213 "src/parse-gram.y"
-        { fprintf (yyo, "%s:", ((*yyvaluep).symbol)->tag); }
+      { fprintf (yyo, "%s:", ((*yyvaluep).symbol)->tag); }
 /* Line 705 of yacc.c  */
 #line 1194 "src/parse-gram.c"
         break;
 
-            case 92: // symbol
+    case 92: /* symbol  */
 /* Line 705 of yacc.c  */
 #line 212 "src/parse-gram.y"
-        { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
+      { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 705 of yacc.c  */
 #line 1202 "src/parse-gram.c"
         break;
 
-            case 93: // string_as_id
+    case 93: /* string_as_id  */
 /* Line 705 of yacc.c  */
 #line 212 "src/parse-gram.y"
-        { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
+      { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 705 of yacc.c  */
 #line 1210 "src/parse-gram.c"
         break;
