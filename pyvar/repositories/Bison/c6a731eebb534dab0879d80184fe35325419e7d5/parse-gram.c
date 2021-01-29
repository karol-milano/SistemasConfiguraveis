@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.7.1016-4862c.  */
+/* A Bison parser, made by GNU Bison 2.7.1021-bb417-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.7.1016-4862c"
+#define YYBISON_VERSION "2.7.1021-bb417-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -920,6 +920,21 @@ while (0)
 #define YYRHSLOC(Rhs, K) ((Rhs)[K])
 
 
+/* Enable debugging if requested.  */
+#if GRAM_DEBUG
+
+# ifndef YYFPRINTF
+#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
+#  define YYFPRINTF fprintf
+# endif
+
+# define YYDPRINTF(Args)                        \
+do {                                            \
+  if (yydebug)                                  \
+    YYFPRINTF Args;                             \
+} while (0)
+
+
 /* YY_LOCATION_PRINT -- Print the location on the stream.
    This macro was not mandated originally: define only if we know
    we won't break user code: when these are the locations we know.  */
@@ -937,25 +952,25 @@ yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
   int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
   if (0 <= yylocp->first_line)
     {
-      res += fprintf (yyo, "%d", yylocp->first_line);
+      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
       if (0 <= yylocp->first_column)
-        res += fprintf (yyo, ".%d", yylocp->first_column);
+        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
     }
   if (0 <= yylocp->last_line)
     {
       if (yylocp->first_line < yylocp->last_line)
         {
-          res += fprintf (yyo, "-%d", yylocp->last_line);
+          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
           if (0 <= end_col)
-            res += fprintf (yyo, ".%d", end_col);
+            res += YYFPRINTF (yyo, ".%d", end_col);
         }
       else if (0 <= end_col && yylocp->first_column < end_col)
-        res += fprintf (yyo, "-%d", end_col);
+        res += YYFPRINTF (yyo, "-%d", end_col);
     }
   return res;
  }
 
-#  define YY_LOCATION_PRINT(File, Loc)                                   \
+#  define YY_LOCATION_PRINT(File, Loc)          \
   yy_location_print_ (File, &(Loc))
 
 # else
@@ -964,20 +979,6 @@ yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
 #endif
 
 
-/* Enable debugging if requested.  */
-#if GRAM_DEBUG
-
-# ifndef YYFPRINTF
-#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
-#  define YYFPRINTF fprintf
-# endif
-
-# define YYDPRINTF(Args)                        \
-do {                                            \
-  if (yydebug)                                  \
-    YYFPRINTF Args;                             \
-} while (0)
-
 # define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
 do {                                                                      \
   if (yydebug)                                                            \
@@ -1009,73 +1010,73 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
   switch (yytype)
     {
     case 3: /* "string"  */
-#line 196 "src/parse-gram.y" /* yacc.c:706  */
+#line 196 "src/parse-gram.y" /* yacc.c:707  */
       { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), yyo); }
-#line 1015 "src/parse-gram.c" /* yacc.c:706  */
+#line 1016 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 4: /* "integer"  */
-#line 209 "src/parse-gram.y" /* yacc.c:706  */
+#line 209 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "%d", ((*yyvaluep).integer)); }
-#line 1021 "src/parse-gram.c" /* yacc.c:706  */
+#line 1022 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 24: /* "%<flag>"  */
-#line 205 "src/parse-gram.y" /* yacc.c:706  */
+#line 205 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "%%%s", ((*yyvaluep).uniqstr)); }
-#line 1027 "src/parse-gram.c" /* yacc.c:706  */
+#line 1028 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 40: /* "{...}"  */
-#line 198 "src/parse-gram.y" /* yacc.c:706  */
+#line 198 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 1033 "src/parse-gram.c" /* yacc.c:706  */
+#line 1034 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 42: /* "[identifier]"  */
-#line 203 "src/parse-gram.y" /* yacc.c:706  */
+#line 203 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "[%s]", ((*yyvaluep).uniqstr)); }
-#line 1039 "src/parse-gram.c" /* yacc.c:706  */
+#line 1040 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 43: /* "char"  */
-#line 190 "src/parse-gram.y" /* yacc.c:706  */
+#line 190 "src/parse-gram.y" /* yacc.c:707  */
       { fputs (char_name (((*yyvaluep).character)), yyo); }
-#line 1045 "src/parse-gram.c" /* yacc.c:706  */
+#line 1046 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 44: /* "epilogue"  */
-#line 198 "src/parse-gram.y" /* yacc.c:706  */
+#line 198 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-#line 1051 "src/parse-gram.c" /* yacc.c:706  */
+#line 1052 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 46: /* "identifier"  */
-#line 202 "src/parse-gram.y" /* yacc.c:706  */
+#line 202 "src/parse-gram.y" /* yacc.c:707  */
       { fputs (((*yyvaluep).uniqstr), yyo); }
-#line 1057 "src/parse-gram.c" /* yacc.c:706  */
+#line 1058 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 47: /* "identifier:"  */
-#line 204 "src/parse-gram.y" /* yacc.c:706  */
+#line 204 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "%s:", ((*yyvaluep).uniqstr)); }
-#line 1063 "src/parse-gram.c" /* yacc.c:706  */
+#line 1064 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 50: /* "%{...%}"  */
-#line 198 "src/parse-gram.y" /* yacc.c:706  */
+#line 198 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-#line 1069 "src/parse-gram.c" /* yacc.c:706  */
+#line 1070 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 52: /* "<tag>"  */
-#line 206 "src/parse-gram.y" /* yacc.c:706  */
+#line 206 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-#line 1075 "src/parse-gram.c" /* yacc.c:706  */
+#line 1076 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 55: /* "%param"  */
-#line 252 "src/parse-gram.y" /* yacc.c:706  */
+#line 252 "src/parse-gram.y" /* yacc.c:707  */
       {
   switch (((*yyvaluep).param))
     {
@@ -1088,67 +1089,67 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
       case param_none: aver (false); break;
     }
 }
-#line 1092 "src/parse-gram.c" /* yacc.c:706  */
+#line 1093 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 64: /* code_props_type  */
-#line 424 "src/parse-gram.y" /* yacc.c:706  */
+#line 424 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_type))); }
-#line 1098 "src/parse-gram.c" /* yacc.c:706  */
+#line 1099 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 73: /* symbol.prec  */
-#line 212 "src/parse-gram.y" /* yacc.c:706  */
+#line 212 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1104 "src/parse-gram.c" /* yacc.c:706  */
+#line 1105 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 77: /* tag  */
-#line 206 "src/parse-gram.y" /* yacc.c:706  */
+#line 206 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-#line 1110 "src/parse-gram.c" /* yacc.c:706  */
+#line 1111 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 87: /* variable  */
-#line 202 "src/parse-gram.y" /* yacc.c:706  */
+#line 202 "src/parse-gram.y" /* yacc.c:707  */
       { fputs (((*yyvaluep).uniqstr), yyo); }
-#line 1116 "src/parse-gram.c" /* yacc.c:706  */
+#line 1117 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 88: /* content.opt  */
-#line 198 "src/parse-gram.y" /* yacc.c:706  */
+#line 198 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-#line 1122 "src/parse-gram.c" /* yacc.c:706  */
+#line 1123 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 89: /* braceless  */
-#line 198 "src/parse-gram.y" /* yacc.c:706  */
+#line 198 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-#line 1128 "src/parse-gram.c" /* yacc.c:706  */
+#line 1129 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 90: /* id  */
-#line 212 "src/parse-gram.y" /* yacc.c:706  */
+#line 212 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1134 "src/parse-gram.c" /* yacc.c:706  */
+#line 1135 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 91: /* id_colon  */
-#line 213 "src/parse-gram.y" /* yacc.c:706  */
+#line 213 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "%s:", ((*yyvaluep).symbol)->tag); }
-#line 1140 "src/parse-gram.c" /* yacc.c:706  */
+#line 1141 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 92: /* symbol  */
-#line 212 "src/parse-gram.y" /* yacc.c:706  */
+#line 212 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1146 "src/parse-gram.c" /* yacc.c:706  */
+#line 1147 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
     case 93: /* string_as_id  */
-#line 212 "src/parse-gram.y" /* yacc.c:706  */
+#line 212 "src/parse-gram.y" /* yacc.c:707  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1152 "src/parse-gram.c" /* yacc.c:706  */
+#line 1153 "src/parse-gram.c" /* yacc.c:707  */
         break;
 
       default:
@@ -1164,10 +1165,8 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
 static void
 yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
 {
-  if (yytype < YYNTOKENS)
-    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
-  else
-    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);
+  YYFPRINTF (yyoutput, "%s %s (",
+             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);
 
   YY_LOCATION_PRINT (yyoutput, *yylocationp);
   YYFPRINTF (yyoutput, ": ");
@@ -1865,14 +1864,14 @@ YYLTYPE yylloc = yyloc_default;
   yychar = YYEMPTY; /* Cause a token to be read.  */
 
 /* User initialization code.  */
-#line 101 "src/parse-gram.y" /* yacc.c:1451  */
+#line 101 "src/parse-gram.y" /* yacc.c:1452  */
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-#line 1876 "src/parse-gram.c" /* yacc.c:1451  */
+#line 1875 "src/parse-gram.c" /* yacc.c:1452  */
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2066,7 +2065,7 @@ yyreduce:
     switch (yyn)
       {
           case 6:
-#line 288 "src/parse-gram.y" /* yacc.c:1668  */
+#line 288 "src/parse-gram.y" /* yacc.c:1669  */
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2076,79 +2075,79 @@ yyreduce:
                         plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2080 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2079 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 7:
-#line 298 "src/parse-gram.y" /* yacc.c:1668  */
+#line 298 "src/parse-gram.y" /* yacc.c:1669  */
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-#line 2088 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2087 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 8:
-#line 302 "src/parse-gram.y" /* yacc.c:1668  */
+#line 302 "src/parse-gram.y" /* yacc.c:1669  */
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2097 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2096 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 9:
-#line 306 "src/parse-gram.y" /* yacc.c:1668  */
+#line 306 "src/parse-gram.y" /* yacc.c:1669  */
     { defines_flag = true; }
-#line 2103 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2102 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 10:
-#line 308 "src/parse-gram.y" /* yacc.c:1668  */
+#line 308 "src/parse-gram.y" /* yacc.c:1669  */
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
-#line 2112 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2111 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 11:
-#line 313 "src/parse-gram.y" /* yacc.c:1668  */
+#line 313 "src/parse-gram.y" /* yacc.c:1669  */
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2121 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2120 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 12:
-#line 317 "src/parse-gram.y" /* yacc.c:1668  */
+#line 317 "src/parse-gram.y" /* yacc.c:1669  */
     { expected_sr_conflicts = (yyvsp[0].integer); }
-#line 2127 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2126 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 13:
-#line 318 "src/parse-gram.y" /* yacc.c:1668  */
+#line 318 "src/parse-gram.y" /* yacc.c:1669  */
     { expected_rr_conflicts = (yyvsp[0].integer); }
-#line 2133 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2132 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 14:
-#line 319 "src/parse-gram.y" /* yacc.c:1668  */
+#line 319 "src/parse-gram.y" /* yacc.c:1669  */
     { spec_file_prefix = (yyvsp[0].chars); }
-#line 2139 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2138 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 15:
-#line 321 "src/parse-gram.y" /* yacc.c:1668  */
+#line 321 "src/parse-gram.y" /* yacc.c:1669  */
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-#line 2148 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2147 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 16:
-#line 326 "src/parse-gram.y" /* yacc.c:1668  */
+#line 326 "src/parse-gram.y" /* yacc.c:1669  */
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[0].code), (yylsp[0]));
@@ -2157,59 +2156,59 @@ yyreduce:
       muscle_code_grow ("initial_action", action.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2161 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2160 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 17:
-#line 334 "src/parse-gram.y" /* yacc.c:1668  */
+#line 334 "src/parse-gram.y" /* yacc.c:1669  */
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
-#line 2167 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2166 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 18:
-#line 335 "src/parse-gram.y" /* yacc.c:1668  */
+#line 335 "src/parse-gram.y" /* yacc.c:1669  */
     { spec_name_prefix = (yyvsp[0].chars); }
-#line 2173 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2172 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 19:
-#line 336 "src/parse-gram.y" /* yacc.c:1668  */
+#line 336 "src/parse-gram.y" /* yacc.c:1669  */
     { no_lines_flag = true; }
-#line 2179 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2178 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 20:
-#line 337 "src/parse-gram.y" /* yacc.c:1668  */
+#line 337 "src/parse-gram.y" /* yacc.c:1669  */
     { nondeterministic_parser = true; }
-#line 2185 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2184 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 21:
-#line 338 "src/parse-gram.y" /* yacc.c:1668  */
+#line 338 "src/parse-gram.y" /* yacc.c:1669  */
     { spec_outfile = (yyvsp[0].chars); }
-#line 2191 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2190 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 22:
-#line 339 "src/parse-gram.y" /* yacc.c:1668  */
+#line 339 "src/parse-gram.y" /* yacc.c:1669  */
     { current_param = (yyvsp[0].param); }
-#line 2197 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2196 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 23:
-#line 339 "src/parse-gram.y" /* yacc.c:1668  */
+#line 339 "src/parse-gram.y" /* yacc.c:1669  */
     { current_param = param_none; }
-#line 2203 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2202 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 24:
-#line 340 "src/parse-gram.y" /* yacc.c:1668  */
+#line 340 "src/parse-gram.y" /* yacc.c:1669  */
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
-#line 2209 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2208 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 25:
-#line 342 "src/parse-gram.y" /* yacc.c:1668  */
+#line 342 "src/parse-gram.y" /* yacc.c:1669  */
     {
       char const *skeleton_user = (yyvsp[0].chars);
       if (strchr (skeleton_user, '/'))
@@ -2233,49 +2232,49 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-#line 2237 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2236 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 26:
-#line 365 "src/parse-gram.y" /* yacc.c:1668  */
+#line 365 "src/parse-gram.y" /* yacc.c:1669  */
     { token_table_flag = true; }
-#line 2243 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2242 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 27:
-#line 366 "src/parse-gram.y" /* yacc.c:1668  */
+#line 366 "src/parse-gram.y" /* yacc.c:1669  */
     { report_flag |= report_states; }
-#line 2249 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2248 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 28:
-#line 367 "src/parse-gram.y" /* yacc.c:1668  */
+#line 367 "src/parse-gram.y" /* yacc.c:1669  */
     { yacc_flag = true; }
-#line 2255 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2254 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 30:
-#line 372 "src/parse-gram.y" /* yacc.c:1668  */
+#line 372 "src/parse-gram.y" /* yacc.c:1669  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2261 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2260 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 31:
-#line 373 "src/parse-gram.y" /* yacc.c:1668  */
+#line 373 "src/parse-gram.y" /* yacc.c:1669  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2267 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2266 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 34:
-#line 385 "src/parse-gram.y" /* yacc.c:1668  */
+#line 385 "src/parse-gram.y" /* yacc.c:1669  */
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-#line 2275 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2274 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 35:
-#line 389 "src/parse-gram.y" /* yacc.c:1668  */
+#line 389 "src/parse-gram.y" /* yacc.c:1669  */
     {
       code_props code;
       code_props_symbol_action_init (&code, (yyvsp[-1].code), (yylsp[-1]));
@@ -2287,111 +2286,111 @@ yyreduce:
         symbol_list_free ((yyvsp[0].list));
       }
     }
-#line 2291 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2290 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 36:
-#line 401 "src/parse-gram.y" /* yacc.c:1668  */
+#line 401 "src/parse-gram.y" /* yacc.c:1669  */
     {
       default_prec = true;
     }
-#line 2299 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2298 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 37:
-#line 405 "src/parse-gram.y" /* yacc.c:1668  */
+#line 405 "src/parse-gram.y" /* yacc.c:1669  */
     {
       default_prec = false;
     }
-#line 2307 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2306 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 38:
-#line 409 "src/parse-gram.y" /* yacc.c:1668  */
+#line 409 "src/parse-gram.y" /* yacc.c:1669  */
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
       muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2318 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2317 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 39:
-#line 416 "src/parse-gram.y" /* yacc.c:1668  */
+#line 416 "src/parse-gram.y" /* yacc.c:1669  */
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2327 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2326 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 40:
-#line 426 "src/parse-gram.y" /* yacc.c:1668  */
+#line 426 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.code_type) = destructor; }
-#line 2333 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2332 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 41:
-#line 427 "src/parse-gram.y" /* yacc.c:1668  */
+#line 427 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.code_type) = printer; }
-#line 2339 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2338 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 42:
-#line 437 "src/parse-gram.y" /* yacc.c:1668  */
+#line 437 "src/parse-gram.y" /* yacc.c:1669  */
     {}
-#line 2345 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2344 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 43:
-#line 438 "src/parse-gram.y" /* yacc.c:1668  */
+#line 438 "src/parse-gram.y" /* yacc.c:1669  */
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2351 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2350 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 44:
-#line 443 "src/parse-gram.y" /* yacc.c:1668  */
+#line 443 "src/parse-gram.y" /* yacc.c:1669  */
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2361 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2360 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 45:
-#line 454 "src/parse-gram.y" /* yacc.c:1668  */
+#line 454 "src/parse-gram.y" /* yacc.c:1669  */
     { current_class = nterm_sym; }
-#line 2367 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2366 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 46:
-#line 455 "src/parse-gram.y" /* yacc.c:1668  */
+#line 455 "src/parse-gram.y" /* yacc.c:1669  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2376 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2375 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 47:
-#line 459 "src/parse-gram.y" /* yacc.c:1668  */
+#line 459 "src/parse-gram.y" /* yacc.c:1669  */
     { current_class = token_sym; }
-#line 2382 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2381 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 48:
-#line 460 "src/parse-gram.y" /* yacc.c:1668  */
+#line 460 "src/parse-gram.y" /* yacc.c:1669  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2391 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2390 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 49:
-#line 465 "src/parse-gram.y" /* yacc.c:1668  */
+#line 465 "src/parse-gram.y" /* yacc.c:1669  */
     {
       symbol_list *list;
       tag_seen = true;
@@ -2399,11 +2398,11 @@ yyreduce:
         symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-#line 2403 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2402 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 50:
-#line 476 "src/parse-gram.y" /* yacc.c:1668  */
+#line 476 "src/parse-gram.y" /* yacc.c:1669  */
     {
       symbol_list *list;
       ++current_prec;
@@ -2415,276 +2414,276 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-#line 2419 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2418 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 51:
-#line 490 "src/parse-gram.y" /* yacc.c:1668  */
+#line 490 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.assoc) = left_assoc; }
-#line 2425 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2424 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 52:
-#line 491 "src/parse-gram.y" /* yacc.c:1668  */
+#line 491 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.assoc) = right_assoc; }
-#line 2431 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2430 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 53:
-#line 492 "src/parse-gram.y" /* yacc.c:1668  */
+#line 492 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.assoc) = non_assoc; }
-#line 2437 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2436 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 54:
-#line 493 "src/parse-gram.y" /* yacc.c:1668  */
+#line 493 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.assoc) = precedence_assoc; }
-#line 2443 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2442 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 55:
-#line 497 "src/parse-gram.y" /* yacc.c:1668  */
+#line 497 "src/parse-gram.y" /* yacc.c:1669  */
     { current_type = NULL; }
-#line 2449 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2448 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 56:
-#line 498 "src/parse-gram.y" /* yacc.c:1668  */
+#line 498 "src/parse-gram.y" /* yacc.c:1669  */
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-#line 2455 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2454 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 57:
-#line 504 "src/parse-gram.y" /* yacc.c:1668  */
+#line 504 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2461 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2460 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 58:
-#line 506 "src/parse-gram.y" /* yacc.c:1668  */
-    { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2467 "src/parse-gram.c" /* yacc.c:1668  */
+#line 506 "src/parse-gram.y" /* yacc.c:1669  */
+    { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
+#line 2466 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 59:
-#line 510 "src/parse-gram.y" /* yacc.c:1668  */
+#line 510 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.symbol) = (yyvsp[0].symbol); }
-#line 2473 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2472 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 60:
-#line 511 "src/parse-gram.y" /* yacc.c:1668  */
+#line 511 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
-#line 2479 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2478 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 61:
-#line 517 "src/parse-gram.y" /* yacc.c:1668  */
+#line 517 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2485 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2484 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 62:
-#line 519 "src/parse-gram.y" /* yacc.c:1668  */
-    { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2491 "src/parse-gram.c" /* yacc.c:1668  */
+#line 519 "src/parse-gram.y" /* yacc.c:1669  */
+    { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
+#line 2490 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 63:
-#line 523 "src/parse-gram.y" /* yacc.c:1668  */
+#line 523 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.list) = (yyvsp[0].list); }
-#line 2497 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2496 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 64:
-#line 524 "src/parse-gram.y" /* yacc.c:1668  */
-    { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
-#line 2503 "src/parse-gram.c" /* yacc.c:1668  */
+#line 524 "src/parse-gram.y" /* yacc.c:1669  */
+    { (yyval.list) = symbol_list_append ((yyvsp[-1].list), (yyvsp[0].list)); }
+#line 2502 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 65:
-#line 528 "src/parse-gram.y" /* yacc.c:1668  */
+#line 528 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2509 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2508 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 66:
-#line 529 "src/parse-gram.y" /* yacc.c:1668  */
+#line 529 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2515 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2514 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 68:
-#line 534 "src/parse-gram.y" /* yacc.c:1668  */
+#line 534 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.uniqstr) = uniqstr_new ("*"); }
-#line 2521 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2520 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 69:
-#line 535 "src/parse-gram.y" /* yacc.c:1668  */
+#line 535 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.uniqstr) = uniqstr_new (""); }
-#line 2527 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2526 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 70:
-#line 541 "src/parse-gram.y" /* yacc.c:1668  */
+#line 541 "src/parse-gram.y" /* yacc.c:1669  */
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
-#line 2536 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2535 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 71:
-#line 546 "src/parse-gram.y" /* yacc.c:1668  */
+#line 546 "src/parse-gram.y" /* yacc.c:1669  */
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
-#line 2545 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2544 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 72:
-#line 551 "src/parse-gram.y" /* yacc.c:1668  */
+#line 551 "src/parse-gram.y" /* yacc.c:1669  */
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-#line 2555 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2554 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 73:
-#line 557 "src/parse-gram.y" /* yacc.c:1668  */
+#line 557 "src/parse-gram.y" /* yacc.c:1669  */
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2565 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2564 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 74:
-#line 563 "src/parse-gram.y" /* yacc.c:1668  */
+#line 563 "src/parse-gram.y" /* yacc.c:1669  */
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2576 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2575 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 81:
-#line 593 "src/parse-gram.y" /* yacc.c:1668  */
+#line 593 "src/parse-gram.y" /* yacc.c:1669  */
     {
       yyerrok;
     }
-#line 2584 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2583 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 82:
-#line 599 "src/parse-gram.y" /* yacc.c:1668  */
+#line 599 "src/parse-gram.y" /* yacc.c:1669  */
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2590 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2589 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 83:
-#line 600 "src/parse-gram.y" /* yacc.c:1668  */
+#line 600 "src/parse-gram.y" /* yacc.c:1669  */
     {
     /* Free the current lhs. */
     current_lhs (0, (yylsp[-3]), 0);
   }
-#line 2599 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2598 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 84:
-#line 607 "src/parse-gram.y" /* yacc.c:1668  */
+#line 607 "src/parse-gram.y" /* yacc.c:1669  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2605 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2604 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 85:
-#line 608 "src/parse-gram.y" /* yacc.c:1668  */
+#line 608 "src/parse-gram.y" /* yacc.c:1669  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2611 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2610 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 87:
-#line 614 "src/parse-gram.y" /* yacc.c:1668  */
+#line 614 "src/parse-gram.y" /* yacc.c:1669  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2618 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2617 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 88:
-#line 617 "src/parse-gram.y" /* yacc.c:1668  */
+#line 617 "src/parse-gram.y" /* yacc.c:1669  */
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2624 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2623 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 89:
-#line 619 "src/parse-gram.y" /* yacc.c:1668  */
+#line 619 "src/parse-gram.y" /* yacc.c:1669  */
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
-#line 2630 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2629 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 90:
-#line 621 "src/parse-gram.y" /* yacc.c:1668  */
+#line 621 "src/parse-gram.y" /* yacc.c:1669  */
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
-#line 2636 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2635 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 91:
-#line 623 "src/parse-gram.y" /* yacc.c:1668  */
+#line 623 "src/parse-gram.y" /* yacc.c:1669  */
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2642 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2641 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 92:
-#line 625 "src/parse-gram.y" /* yacc.c:1668  */
+#line 625 "src/parse-gram.y" /* yacc.c:1669  */
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-#line 2648 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2647 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 93:
-#line 627 "src/parse-gram.y" /* yacc.c:1668  */
+#line 627 "src/parse-gram.y" /* yacc.c:1669  */
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2654 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2653 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 94:
-#line 631 "src/parse-gram.y" /* yacc.c:1668  */
+#line 631 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.named_ref) = 0; }
-#line 2660 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2659 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 95:
-#line 633 "src/parse-gram.y" /* yacc.c:1668  */
+#line 633 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2666 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2665 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 97:
-#line 644 "src/parse-gram.y" /* yacc.c:1668  */
+#line 644 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
-#line 2672 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2671 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 98:
-#line 649 "src/parse-gram.y" /* yacc.c:1668  */
+#line 649 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.chars) = ""; }
-#line 2678 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2677 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 99:
-#line 650 "src/parse-gram.y" /* yacc.c:1668  */
+#line 650 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.chars) = (yyvsp[0].uniqstr); }
-#line 2684 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2683 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 101:
-#line 661 "src/parse-gram.y" /* yacc.c:1668  */
+#line 661 "src/parse-gram.y" /* yacc.c:1669  */
     {
       code_props plain_code;
       (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\n';
@@ -2693,42 +2692,42 @@ yyreduce:
       gram_scanner_last_string_free ();
       (yyval.chars) = plain_code.code;
     }
-#line 2697 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2696 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 102:
-#line 681 "src/parse-gram.y" /* yacc.c:1668  */
+#line 681 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2703 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2702 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 103:
-#line 683 "src/parse-gram.y" /* yacc.c:1668  */
+#line 683 "src/parse-gram.y" /* yacc.c:1669  */
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-#line 2713 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2712 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 104:
-#line 691 "src/parse-gram.y" /* yacc.c:1668  */
+#line 691 "src/parse-gram.y" /* yacc.c:1669  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2719 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2718 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 107:
-#line 703 "src/parse-gram.y" /* yacc.c:1668  */
+#line 703 "src/parse-gram.y" /* yacc.c:1669  */
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-#line 2728 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2727 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 109:
-#line 712 "src/parse-gram.y" /* yacc.c:1668  */
+#line 712 "src/parse-gram.y" /* yacc.c:1669  */
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2737,11 +2736,11 @@ yyreduce:
       muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2741 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2740 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
 
-#line 2745 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2744 "src/parse-gram.c" /* yacc.c:1669  */
         default: break;
       }
     if (yychar_backup != yychar)
@@ -2988,7 +2987,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 722 "src/parse-gram.y" /* yacc.c:1928  */
+#line 722 "src/parse-gram.y" /* yacc.c:1929  */
 
 
 /* Return the location of the left-hand side of a rule whose
