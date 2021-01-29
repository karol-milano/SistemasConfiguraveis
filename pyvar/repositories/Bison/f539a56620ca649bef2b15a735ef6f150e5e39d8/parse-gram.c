@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.2.1.64-49972.  */
+/* A Bison parser, made by GNU Bison 3.2.1.100-30b99-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -47,7 +47,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.2.1.64-49972"
+#define YYBISON_VERSION "3.2.1.100-30b99-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -1049,82 +1049,82 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
 # endif
   switch (yytype)
     {
-          case 3: /* "string"  */
+    case 3: /* "string"  */
 #line 191 "src/parse-gram.y" /* yacc.c:681  */
-      { fputs (quotearg_style (c_quoting_style, (*(char**)(&(*yyvaluep)))), yyo); }
+      { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).STRING)), yyo); }
 #line 1056 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 22: /* "%<flag>"  */
 #line 198 "src/parse-gram.y" /* yacc.c:681  */
-      { fprintf (yyo, "%%%s", (*(uniqstr*)(&(*yyvaluep)))); }
+      { fprintf (yyo, "%%%s", ((*yyvaluep).PERCENT_FLAG)); }
 #line 1062 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 38: /* "{...}"  */
 #line 192 "src/parse-gram.y" /* yacc.c:681  */
-      { fprintf (yyo, "{\n%s\n}", (*(char**)(&(*yyvaluep)))); }
+      { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).BRACED_CODE)); }
 #line 1068 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 39: /* "%?{...}"  */
 #line 192 "src/parse-gram.y" /* yacc.c:681  */
-      { fprintf (yyo, "{\n%s\n}", (*(char**)(&(*yyvaluep)))); }
+      { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).BRACED_PREDICATE)); }
 #line 1074 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 40: /* "[identifier]"  */
 #line 196 "src/parse-gram.y" /* yacc.c:681  */
-      { fprintf (yyo, "[%s]", (*(uniqstr*)(&(*yyvaluep)))); }
+      { fprintf (yyo, "[%s]", ((*yyvaluep).BRACKETED_ID)); }
 #line 1080 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 41: /* "char"  */
 #line 188 "src/parse-gram.y" /* yacc.c:681  */
-      { fputs (char_name ((*(unsigned char*)(&(*yyvaluep)))), yyo); }
+      { fputs (char_name (((*yyvaluep).CHAR)), yyo); }
 #line 1086 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 42: /* "epilogue"  */
 #line 192 "src/parse-gram.y" /* yacc.c:681  */
-      { fprintf (yyo, "{\n%s\n}", (*(char**)(&(*yyvaluep)))); }
+      { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).EPILOGUE)); }
 #line 1092 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 44: /* "identifier"  */
 #line 195 "src/parse-gram.y" /* yacc.c:681  */
-      { fputs ((*(uniqstr*)(&(*yyvaluep))), yyo); }
+      { fputs (((*yyvaluep).ID), yyo); }
 #line 1098 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 45: /* "identifier:"  */
 #line 197 "src/parse-gram.y" /* yacc.c:681  */
-      { fprintf (yyo, "%s:", (*(uniqstr*)(&(*yyvaluep)))); }
+      { fprintf (yyo, "%s:", ((*yyvaluep).ID_COLON)); }
 #line 1104 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 48: /* "%{...%}"  */
 #line 192 "src/parse-gram.y" /* yacc.c:681  */
-      { fprintf (yyo, "{\n%s\n}", (*(char**)(&(*yyvaluep)))); }
+      { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).PROLOGUE)); }
 #line 1110 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 50: /* "<tag>"  */
 #line 199 "src/parse-gram.y" /* yacc.c:681  */
-      { fprintf (yyo, "<%s>", (*(uniqstr*)(&(*yyvaluep)))); }
+      { fprintf (yyo, "<%s>", ((*yyvaluep).TAG)); }
 #line 1116 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 53: /* "integer"  */
 #line 202 "src/parse-gram.y" /* yacc.c:681  */
-      { fprintf (yyo, "%d", (*(int*)(&(*yyvaluep)))); }
+      { fprintf (yyo, "%d", ((*yyvaluep).INT)); }
 #line 1122 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 54: /* "%param"  */
 #line 240 "src/parse-gram.y" /* yacc.c:681  */
       {
-  switch ((*(param_type*)(&(*yyvaluep))))
+  switch (((*yyvaluep).PERCENT_PARAM))
     {
 #define CASE(In, Out)                                           \
       case param_ ## In: fputs ("%" #Out, yyo); break
@@ -1140,48 +1140,48 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
 
     case 64: /* code_props_type  */
 #line 376 "src/parse-gram.y" /* yacc.c:681  */
-      { fprintf (yyo, "%s", code_props_type_string ((*(code_props_type*)(&(*yyvaluep))))); }
+      { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_props_type))); }
 #line 1145 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 71: /* tag.opt  */
 #line 195 "src/parse-gram.y" /* yacc.c:681  */
-      { fputs ((*(uniqstr*)(&(*yyvaluep))), yyo); }
+      { fputs (((*yyvaluep).yytype_71), yyo); }
 #line 1151 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 73: /* symbol.prec  */
 #line 205 "src/parse-gram.y" /* yacc.c:681  */
-      { fprintf (yyo, "%s", (*(symbol**)(&(*yyvaluep)))->tag); }
+      { fprintf (yyo, "%s", ((*yyvaluep).yytype_73)->tag); }
 #line 1157 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 77: /* tag  */
 #line 199 "src/parse-gram.y" /* yacc.c:681  */
-      { fprintf (yyo, "<%s>", (*(uniqstr*)(&(*yyvaluep)))); }
+      { fprintf (yyo, "<%s>", ((*yyvaluep).tag)); }
 #line 1163 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 79: /* int.opt  */
 #line 202 "src/parse-gram.y" /* yacc.c:681  */
-      { fprintf (yyo, "%d", (*(int*)(&(*yyvaluep)))); }
+      { fprintf (yyo, "%d", ((*yyvaluep).yytype_79)); }
 #line 1169 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 88: /* variable  */
 #line 195 "src/parse-gram.y" /* yacc.c:681  */
-      { fputs ((*(uniqstr*)(&(*yyvaluep))), yyo); }
+      { fputs (((*yyvaluep).variable), yyo); }
 #line 1175 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 89: /* value  */
 #line 630 "src/parse-gram.y" /* yacc.c:681  */
       {
-  switch ((*(value_type*)(&(*yyvaluep))).kind)
+  switch (((*yyvaluep).value).kind)
     {
-    case muscle_code:    fprintf (yyo,  "{%s}",  (*(value_type*)(&(*yyvaluep))).chars); break;
-    case muscle_keyword: fprintf (yyo,   "%s",   (*(value_type*)(&(*yyvaluep))).chars); break;
-    case muscle_string:  fprintf (yyo, "\"%s\"", (*(value_type*)(&(*yyvaluep))).chars); break;
+    case muscle_code:    fprintf (yyo,  "{%s}",  ((*yyvaluep).value).chars); break;
+    case muscle_keyword: fprintf (yyo,   "%s",   ((*yyvaluep).value).chars); break;
+    case muscle_string:  fprintf (yyo, "\"%s\"", ((*yyvaluep).value).chars); break;
     }
 }
 #line 1188 "src/parse-gram.c" /* yacc.c:681  */
@@ -1189,35 +1189,34 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
 
     case 90: /* id  */
 #line 205 "src/parse-gram.y" /* yacc.c:681  */
-      { fprintf (yyo, "%s", (*(symbol**)(&(*yyvaluep)))->tag); }
+      { fprintf (yyo, "%s", ((*yyvaluep).id)->tag); }
 #line 1194 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 91: /* id_colon  */
 #line 206 "src/parse-gram.y" /* yacc.c:681  */
-      { fprintf (yyo, "%s:", (*(symbol**)(&(*yyvaluep)))->tag); }
+      { fprintf (yyo, "%s:", ((*yyvaluep).id_colon)->tag); }
 #line 1200 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 92: /* symbol  */
 #line 205 "src/parse-gram.y" /* yacc.c:681  */
-      { fprintf (yyo, "%s", (*(symbol**)(&(*yyvaluep)))->tag); }
+      { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
 #line 1206 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 93: /* string_as_id  */
 #line 205 "src/parse-gram.y" /* yacc.c:681  */
-      { fprintf (yyo, "%s", (*(symbol**)(&(*yyvaluep)))->tag); }
+      { fprintf (yyo, "%s", ((*yyvaluep).string_as_id)->tag); }
 #line 1212 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 94: /* string_as_id.opt  */
 #line 205 "src/parse-gram.y" /* yacc.c:681  */
-      { fprintf (yyo, "%s", (*(symbol**)(&(*yyvaluep)))->tag); }
+      { fprintf (yyo, "%s", ((*yyvaluep).yytype_94)->tag); }
 #line 1218 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
-
       default:
         break;
     }
@@ -1916,7 +1915,7 @@ YYLTYPE yylloc = yyloc_default;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-#line 1920 "src/parse-gram.c" /* yacc.c:1428  */
+#line 1919 "src/parse-gram.c" /* yacc.c:1428  */
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2118,60 +2117,60 @@ yyreduce:
 #line 276 "src/parse-gram.y" /* yacc.c:1649  */
     {
       muscle_code_grow (union_seen ? "post_prologue" : "pre_prologue",
-                        translate_code ((*(char**)(&yyvsp[0])), (yylsp[0]), true), (yylsp[0]));
+                        translate_code ((yyvsp[0].PROLOGUE), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2125 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2124 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 7:
 #line 282 "src/parse-gram.y" /* yacc.c:1649  */
     {
-      muscle_percent_define_ensure ((*(uniqstr*)(&yyvsp[0])), (yylsp[0]), true);
+      muscle_percent_define_ensure ((yyvsp[0].PERCENT_FLAG), (yylsp[0]), true);
     }
-#line 2133 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2132 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 8:
 #line 286 "src/parse-gram.y" /* yacc.c:1649  */
     {
-      muscle_percent_define_insert ((*(uniqstr*)(&yyvsp[-1])), (yylsp[-1]), (*(value_type*)(&yyvsp[0])).kind, (*(value_type*)(&yyvsp[0])).chars,
+      muscle_percent_define_insert ((yyvsp[-1].variable), (yylsp[-1]), (yyvsp[0].value).kind, (yyvsp[0].value).chars,
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2142 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2141 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 9:
 #line 290 "src/parse-gram.y" /* yacc.c:1649  */
     { defines_flag = true; }
-#line 2148 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2147 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 10:
 #line 292 "src/parse-gram.y" /* yacc.c:1649  */
     {
       defines_flag = true;
-      spec_defines_file = xstrdup ((*(char**)(&yyvsp[0])));
+      spec_defines_file = xstrdup ((yyvsp[0].STRING));
     }
-#line 2157 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2156 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 11:
 #line 296 "src/parse-gram.y" /* yacc.c:1649  */
-    { expected_sr_conflicts = (*(int*)(&yyvsp[0])); }
-#line 2163 "src/parse-gram.c" /* yacc.c:1649  */
+    { expected_sr_conflicts = (yyvsp[0].INT); }
+#line 2162 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 12:
 #line 297 "src/parse-gram.y" /* yacc.c:1649  */
-    { expected_rr_conflicts = (*(int*)(&yyvsp[0])); }
-#line 2169 "src/parse-gram.c" /* yacc.c:1649  */
+    { expected_rr_conflicts = (yyvsp[0].INT); }
+#line 2168 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 13:
 #line 298 "src/parse-gram.y" /* yacc.c:1649  */
-    { spec_file_prefix = (*(char**)(&yyvsp[0])); }
-#line 2175 "src/parse-gram.c" /* yacc.c:1649  */
+    { spec_file_prefix = (yyvsp[0].STRING); }
+#line 2174 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 14:
@@ -2180,129 +2179,129 @@ yyreduce:
       nondeterministic_parser = true;
       glr_parser = true;
     }
-#line 2184 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2183 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 15:
 #line 305 "src/parse-gram.y" /* yacc.c:1649  */
     {
-      muscle_code_grow ("initial_action", translate_code ((*(char**)(&yyvsp[0])), (yylsp[0]), false), (yylsp[0]));
+      muscle_code_grow ("initial_action", translate_code ((yyvsp[0].BRACED_CODE), (yylsp[0]), false), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2193 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2192 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 16:
 #line 309 "src/parse-gram.y" /* yacc.c:1649  */
-    { language_argmatch ((*(char**)(&yyvsp[0])), grammar_prio, (yylsp[-1])); }
-#line 2199 "src/parse-gram.c" /* yacc.c:1649  */
+    { language_argmatch ((yyvsp[0].STRING), grammar_prio, (yylsp[-1])); }
+#line 2198 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 17:
 #line 310 "src/parse-gram.y" /* yacc.c:1649  */
-    { spec_name_prefix = (*(char**)(&yyvsp[0])); }
-#line 2205 "src/parse-gram.c" /* yacc.c:1649  */
+    { spec_name_prefix = (yyvsp[0].STRING); }
+#line 2204 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 18:
 #line 311 "src/parse-gram.y" /* yacc.c:1649  */
     { no_lines_flag = true; }
-#line 2211 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2210 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 19:
 #line 312 "src/parse-gram.y" /* yacc.c:1649  */
     { nondeterministic_parser = true; }
-#line 2217 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2216 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 20:
 #line 313 "src/parse-gram.y" /* yacc.c:1649  */
-    { spec_outfile = (*(char**)(&yyvsp[0])); }
-#line 2223 "src/parse-gram.c" /* yacc.c:1649  */
+    { spec_outfile = (yyvsp[0].STRING); }
+#line 2222 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 21:
 #line 314 "src/parse-gram.y" /* yacc.c:1649  */
-    { current_param = (*(param_type*)(&yyvsp[0])); }
-#line 2229 "src/parse-gram.c" /* yacc.c:1649  */
+    { current_param = (yyvsp[0].PERCENT_PARAM); }
+#line 2228 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 22:
 #line 314 "src/parse-gram.y" /* yacc.c:1649  */
     { current_param = param_none; }
-#line 2235 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2234 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 23:
 #line 315 "src/parse-gram.y" /* yacc.c:1649  */
-    { do_require (&(yylsp[0]), (*(char**)(&yyvsp[0]))); }
-#line 2241 "src/parse-gram.c" /* yacc.c:1649  */
+    { do_require (&(yylsp[0]), (yyvsp[0].STRING)); }
+#line 2240 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 24:
 #line 316 "src/parse-gram.y" /* yacc.c:1649  */
-    { do_skeleton (&(yylsp[0]), (*(char**)(&yyvsp[0]))); }
-#line 2247 "src/parse-gram.c" /* yacc.c:1649  */
+    { do_skeleton (&(yylsp[0]), (yyvsp[0].STRING)); }
+#line 2246 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 25:
 #line 317 "src/parse-gram.y" /* yacc.c:1649  */
     { token_table_flag = true; }
-#line 2253 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2252 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 26:
 #line 318 "src/parse-gram.y" /* yacc.c:1649  */
     { report_flag |= report_states; }
-#line 2259 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2258 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 27:
 #line 319 "src/parse-gram.y" /* yacc.c:1649  */
     { yacc_flag = true; }
-#line 2265 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2264 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 28:
 #line 320 "src/parse-gram.y" /* yacc.c:1649  */
     { current_class = unknown_sym; yyerrok; }
-#line 2271 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2270 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 30:
 #line 325 "src/parse-gram.y" /* yacc.c:1649  */
-    { add_param (current_param, (*(char**)(&yyvsp[0])), (yylsp[0])); }
-#line 2277 "src/parse-gram.c" /* yacc.c:1649  */
+    { add_param (current_param, (yyvsp[0].BRACED_CODE), (yylsp[0])); }
+#line 2276 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 31:
 #line 326 "src/parse-gram.y" /* yacc.c:1649  */
-    { add_param (current_param, (*(char**)(&yyvsp[0])), (yylsp[0])); }
-#line 2283 "src/parse-gram.c" /* yacc.c:1649  */
+    { add_param (current_param, (yyvsp[0].BRACED_CODE), (yylsp[0])); }
+#line 2282 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 34:
 #line 338 "src/parse-gram.y" /* yacc.c:1649  */
     {
-      grammar_start_symbol_set ((*(symbol**)(&yyvsp[0])), (yylsp[0]));
+      grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-#line 2291 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2290 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 35:
 #line 342 "src/parse-gram.y" /* yacc.c:1649  */
     {
       code_props code;
-      code_props_symbol_action_init (&code, (*(char**)(&yyvsp[-1])), (yylsp[-1]));
+      code_props_symbol_action_init (&code, (yyvsp[-1].BRACED_CODE), (yylsp[-1]));
       code_props_translate_code (&code);
       {
-        for (symbol_list *list = (*(symbol_list**)(&yyvsp[0])); list; list = list->next)
-          symbol_list_code_props_set (list, (*(code_props_type*)(&yyvsp[-2])), &code);
-        symbol_list_free ((*(symbol_list**)(&yyvsp[0])));
+        for (symbol_list *list = (yyvsp[0].generic_symlist); list; list = list->next)
+          symbol_list_code_props_set (list, (yyvsp[-2].code_props_type), &code);
+        symbol_list_free ((yyvsp[0].generic_symlist));
       }
     }
-#line 2306 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2305 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 36:
@@ -2310,7 +2309,7 @@ yyreduce:
     {
       default_prec = true;
     }
-#line 2314 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2313 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 37:
@@ -2318,7 +2317,7 @@ yyreduce:
     {
       default_prec = false;
     }
-#line 2322 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2321 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 38:
@@ -2327,61 +2326,61 @@ yyreduce:
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
       muscle_code_grow ("percent_code()",
-                        translate_code_braceless ((*(char**)(&yyvsp[0])), (yylsp[0])), (yylsp[0]));
+                        translate_code_braceless ((yyvsp[0].BRACED_CODE), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2334 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2333 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 39:
 #line 369 "src/parse-gram.y" /* yacc.c:1649  */
     {
-      muscle_percent_code_grow ((*(uniqstr*)(&yyvsp[-1])), (yylsp[-1]), translate_code_braceless ((*(char**)(&yyvsp[0])), (yylsp[0])), (yylsp[0]));
+      muscle_percent_code_grow ((yyvsp[-1].ID), (yylsp[-1]), translate_code_braceless ((yyvsp[0].BRACED_CODE), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2343 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2342 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 40:
 #line 378 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(code_props_type*)(&yyval)) = destructor; }
-#line 2349 "src/parse-gram.c" /* yacc.c:1649  */
+    { (yyval.code_props_type) = destructor; }
+#line 2348 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 41:
 #line 379 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(code_props_type*)(&yyval)) = printer; }
-#line 2355 "src/parse-gram.c" /* yacc.c:1649  */
+    { (yyval.code_props_type) = printer; }
+#line 2354 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 42:
 #line 389 "src/parse-gram.y" /* yacc.c:1649  */
     {}
-#line 2361 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2360 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 43:
 #line 390 "src/parse-gram.y" /* yacc.c:1649  */
     { muscle_percent_define_insert ("api.value.union.name",
-                                         (yylsp[0]), muscle_keyword, (*(uniqstr*)(&yyvsp[0])),
+                                         (yylsp[0]), muscle_keyword, (yyvsp[0].ID),
                                          MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE); }
-#line 2369 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2368 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 44:
 #line 397 "src/parse-gram.y" /* yacc.c:1649  */
     {
       union_seen = true;
-      muscle_code_grow ("union_members", translate_code_braceless ((*(char**)(&yyvsp[0])), (yylsp[0])), (yylsp[0]));
+      muscle_code_grow ("union_members", translate_code_braceless ((yyvsp[0].BRACED_CODE), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2379 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2378 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 45:
 #line 408 "src/parse-gram.y" /* yacc.c:1649  */
     { current_class = nterm_sym; }
-#line 2385 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2384 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 46:
@@ -2390,13 +2389,13 @@ yyreduce:
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2394 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2393 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 47:
 #line 413 "src/parse-gram.y" /* yacc.c:1649  */
     { current_class = token_sym; }
-#line 2400 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2399 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 48:
@@ -2405,183 +2404,183 @@ yyreduce:
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2409 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2408 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 49:
 #line 419 "src/parse-gram.y" /* yacc.c:1649  */
     {
       tag_seen = true;
-      for (symbol_list *list = (*(symbol_list**)(&yyvsp[0])); list; list = list->next)
-        symbol_type_set (list->content.sym, (*(uniqstr*)(&yyvsp[-1])), (yylsp[-1]));
-      symbol_list_free ((*(symbol_list**)(&yyvsp[0])));
+      for (symbol_list *list = (yyvsp[0].yytype_74); list; list = list->next)
+        symbol_type_set (list->content.sym, (yyvsp[-1].TAG), (yylsp[-1]));
+      symbol_list_free ((yyvsp[0].yytype_74));
     }
-#line 2420 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2419 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 50:
 #line 429 "src/parse-gram.y" /* yacc.c:1649  */
     {
       ++current_prec;
-      for (symbol_list *list = (*(symbol_list**)(&yyvsp[0])); list; list = list->next)
+      for (symbol_list *list = (yyvsp[0].yytype_72); list; list = list->next)
         {
-          symbol_type_set (list->content.sym, (*(uniqstr*)(&yyvsp[-1])), (yylsp[-1]));
-          symbol_precedence_set (list->content.sym, current_prec, (*(assoc*)(&yyvsp[-2])), (yylsp[-2]));
+          symbol_type_set (list->content.sym, (yyvsp[-1].yytype_71), (yylsp[-1]));
+          symbol_precedence_set (list->content.sym, current_prec, (yyvsp[-2].precedence_declarator), (yylsp[-2]));
         }
-      symbol_list_free ((*(symbol_list**)(&yyvsp[0])));
+      symbol_list_free ((yyvsp[0].yytype_72));
     }
-#line 2434 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2433 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 51:
 #line 441 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(assoc*)(&yyval)) = left_assoc; }
-#line 2440 "src/parse-gram.c" /* yacc.c:1649  */
+    { (yyval.precedence_declarator) = left_assoc; }
+#line 2439 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 52:
 #line 442 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(assoc*)(&yyval)) = right_assoc; }
-#line 2446 "src/parse-gram.c" /* yacc.c:1649  */
+    { (yyval.precedence_declarator) = right_assoc; }
+#line 2445 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 53:
 #line 443 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(assoc*)(&yyval)) = non_assoc; }
-#line 2452 "src/parse-gram.c" /* yacc.c:1649  */
+    { (yyval.precedence_declarator) = non_assoc; }
+#line 2451 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 54:
 #line 444 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(assoc*)(&yyval)) = precedence_assoc; }
-#line 2458 "src/parse-gram.c" /* yacc.c:1649  */
+    { (yyval.precedence_declarator) = precedence_assoc; }
+#line 2457 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 55:
 #line 448 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(uniqstr*)(&yyval)) = NULL; }
-#line 2464 "src/parse-gram.c" /* yacc.c:1649  */
+    { (yyval.yytype_71) = NULL; }
+#line 2463 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 56:
 #line 449 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(uniqstr*)(&yyval)) = (*(uniqstr*)(&yyvsp[0])); tag_seen = true; }
-#line 2470 "src/parse-gram.c" /* yacc.c:1649  */
+    { (yyval.yytype_71) = (yyvsp[0].TAG); tag_seen = true; }
+#line 2469 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 57:
 #line 455 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(symbol_list**)(&yyval)) = symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0])); }
-#line 2476 "src/parse-gram.c" /* yacc.c:1649  */
+    { (yyval.yytype_72) = symbol_list_sym_new ((yyvsp[0].yytype_73), (yylsp[0])); }
+#line 2475 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 58:
 #line 457 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(symbol_list**)(&yyval)) = symbol_list_append ((*(symbol_list**)(&yyvsp[-1])), symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0]))); }
-#line 2482 "src/parse-gram.c" /* yacc.c:1649  */
+    { (yyval.yytype_72) = symbol_list_append ((yyvsp[-1].yytype_72), symbol_list_sym_new ((yyvsp[0].yytype_73), (yylsp[0]))); }
+#line 2481 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 59:
 #line 462 "src/parse-gram.y" /* yacc.c:1649  */
     {
-      (*(symbol**)(&yyval)) = (*(symbol**)(&yyvsp[0]));
-      symbol_class_set ((*(symbol**)(&yyvsp[0])), token_sym, (yylsp[0]), false);
+      (yyval.yytype_73) = (yyvsp[0].symbol);
+      symbol_class_set ((yyvsp[0].symbol), token_sym, (yylsp[0]), false);
     }
-#line 2491 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2490 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 60:
 #line 467 "src/parse-gram.y" /* yacc.c:1649  */
     {
-      (*(symbol**)(&yyval)) = (*(symbol**)(&yyvsp[-1]));
-      symbol_user_token_number_set ((*(symbol**)(&yyvsp[-1])), (*(int*)(&yyvsp[0])), (yylsp[0]));
-      symbol_class_set ((*(symbol**)(&yyvsp[-1])), token_sym, (yylsp[-1]), false);
+      (yyval.yytype_73) = (yyvsp[-1].symbol);
+      symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].INT), (yylsp[0]));
+      symbol_class_set ((yyvsp[-1].symbol), token_sym, (yylsp[-1]), false);
     }
-#line 2501 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2500 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 61:
 #line 477 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(symbol_list**)(&yyval)) = symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0])); }
-#line 2507 "src/parse-gram.c" /* yacc.c:1649  */
+    { (yyval.yytype_74) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
+#line 2506 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 62:
 #line 479 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(symbol_list**)(&yyval)) = symbol_list_append ((*(symbol_list**)(&yyvsp[-1])), symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0]))); }
-#line 2513 "src/parse-gram.c" /* yacc.c:1649  */
+    { (yyval.yytype_74) = symbol_list_append ((yyvsp[-1].yytype_74), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
+#line 2512 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 64:
 #line 484 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(symbol_list**)(&yyval)) = symbol_list_append ((*(symbol_list**)(&yyvsp[-1])), (*(symbol_list**)(&yyvsp[0]))); }
-#line 2519 "src/parse-gram.c" /* yacc.c:1649  */
+    { (yyval.generic_symlist) = symbol_list_append ((yyvsp[-1].generic_symlist), (yyvsp[0].generic_symlist_item)); }
+#line 2518 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 65:
 #line 488 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(symbol_list**)(&yyval)) = symbol_list_sym_new ((*(symbol**)(&yyvsp[0])), (yylsp[0])); }
-#line 2525 "src/parse-gram.c" /* yacc.c:1649  */
+    { (yyval.generic_symlist_item) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
+#line 2524 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 66:
 #line 489 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(symbol_list**)(&yyval)) = symbol_list_type_new ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
-#line 2531 "src/parse-gram.c" /* yacc.c:1649  */
+    { (yyval.generic_symlist_item) = symbol_list_type_new ((yyvsp[0].tag), (yylsp[0])); }
+#line 2530 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 68:
 #line 494 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(uniqstr*)(&yyval)) = uniqstr_new ("*"); }
-#line 2537 "src/parse-gram.c" /* yacc.c:1649  */
+    { (yyval.tag) = uniqstr_new ("*"); }
+#line 2536 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 69:
 #line 495 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(uniqstr*)(&yyval)) = uniqstr_new (""); }
-#line 2543 "src/parse-gram.c" /* yacc.c:1649  */
+    { (yyval.tag) = uniqstr_new (""); }
+#line 2542 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 70:
 #line 501 "src/parse-gram.y" /* yacc.c:1649  */
     {
-      current_type = (*(uniqstr*)(&yyvsp[0]));
+      current_type = (yyvsp[0].TAG);
       tag_seen = true;
     }
-#line 2552 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2551 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 71:
 #line 506 "src/parse-gram.y" /* yacc.c:1649  */
     {
-      symbol_class_set ((*(symbol**)(&yyvsp[-2])), current_class, (yylsp[-2]), true);
-      symbol_type_set ((*(symbol**)(&yyvsp[-2])), current_type, (yylsp[-2]));
-      if (0 <= (*(int*)(&yyvsp[-1])))
+      symbol_class_set ((yyvsp[-2].id), current_class, (yylsp[-2]), true);
+      symbol_type_set ((yyvsp[-2].id), current_type, (yylsp[-2]));
+      if (0 <= (yyvsp[-1].yytype_79))
         {
           if (current_class != token_sym)
             gram_error (&(yylsp[-1]),
                         _("non-terminals cannot be given an explicit number"));
           else
-            symbol_user_token_number_set ((*(symbol**)(&yyvsp[-2])), (*(int*)(&yyvsp[-1])), (yylsp[-1]));
+            symbol_user_token_number_set ((yyvsp[-2].id), (yyvsp[-1].yytype_79), (yylsp[-1]));
         }
-      if ((*(symbol**)(&yyvsp[0])))
+      if ((yyvsp[0].yytype_94))
         {
           if (current_class != token_sym)
             gram_error (&(yylsp[0]),
                         _("non-terminals cannot be given a string alias"));
           else
-            symbol_make_alias ((*(symbol**)(&yyvsp[-2])), (*(symbol**)(&yyvsp[0])), (yylsp[0]));
+            symbol_make_alias ((yyvsp[-2].id), (yyvsp[0].yytype_94), (yylsp[0]));
         }
-      if (current_class != token_sym && (0 <= (*(int*)(&yyvsp[-1])) || !(*(symbol**)(&yyvsp[0]))))
+      if (current_class != token_sym && (0 <= (yyvsp[-1].yytype_79) || !(yyvsp[0].yytype_94)))
         YYERROR;
     }
-#line 2579 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2578 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 72:
 #line 532 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(int*)(&yyval)) = -1; }
-#line 2585 "src/parse-gram.c" /* yacc.c:1649  */
+    { (yyval.yytype_79) = -1; }
+#line 2584 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 80:
@@ -2589,13 +2588,13 @@ yyreduce:
     {
       yyerrok;
     }
-#line 2593 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2592 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 81:
 #line 567 "src/parse-gram.y" /* yacc.c:1649  */
-    { current_lhs ((*(symbol**)(&yyvsp[-1])), (yylsp[-1]), (*(named_ref**)(&yyvsp[0]))); }
-#line 2599 "src/parse-gram.c" /* yacc.c:1649  */
+    { current_lhs ((yyvsp[-1].id_colon), (yylsp[-1]), (yyvsp[0].yytype_87)); }
+#line 2598 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 82:
@@ -2604,122 +2603,122 @@ yyreduce:
       /* Free the current lhs. */
       current_lhs (0, (yylsp[-3]), 0);
     }
-#line 2608 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2607 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 83:
 #line 575 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2614 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2613 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 84:
 #line 576 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2620 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2619 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 86:
 #line 583 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2627 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2626 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 87:
 #line 586 "src/parse-gram.y" /* yacc.c:1649  */
-    { grammar_current_rule_symbol_append ((*(symbol**)(&yyvsp[-1])), (yylsp[-1]), (*(named_ref**)(&yyvsp[0]))); }
-#line 2633 "src/parse-gram.c" /* yacc.c:1649  */
+    { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].yytype_87)); }
+#line 2632 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 88:
 #line 588 "src/parse-gram.y" /* yacc.c:1649  */
-    { grammar_current_rule_action_append ((*(char**)(&yyvsp[-1])), (yylsp[-1]), (*(named_ref**)(&yyvsp[0])), (*(uniqstr*)(&yyvsp[-2]))); }
-#line 2639 "src/parse-gram.c" /* yacc.c:1649  */
+    { grammar_current_rule_action_append ((yyvsp[-1].BRACED_CODE), (yylsp[-1]), (yyvsp[0].yytype_87), (yyvsp[-2].yytype_71)); }
+#line 2638 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 89:
 #line 590 "src/parse-gram.y" /* yacc.c:1649  */
-    { grammar_current_rule_predicate_append ((*(char**)(&yyvsp[0])), (yylsp[0])); }
-#line 2645 "src/parse-gram.c" /* yacc.c:1649  */
+    { grammar_current_rule_predicate_append ((yyvsp[0].BRACED_PREDICATE), (yylsp[0])); }
+#line 2644 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 90:
 #line 592 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_empty_set ((yylsp[0])); }
-#line 2651 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2650 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 91:
 #line 594 "src/parse-gram.y" /* yacc.c:1649  */
-    { grammar_current_rule_prec_set ((*(symbol**)(&yyvsp[0])), (yylsp[0])); }
-#line 2657 "src/parse-gram.c" /* yacc.c:1649  */
+    { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
+#line 2656 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 92:
 #line 596 "src/parse-gram.y" /* yacc.c:1649  */
-    { grammar_current_rule_dprec_set ((*(int*)(&yyvsp[0])), (yylsp[0])); }
-#line 2663 "src/parse-gram.c" /* yacc.c:1649  */
+    { grammar_current_rule_dprec_set ((yyvsp[0].INT), (yylsp[0])); }
+#line 2662 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 93:
 #line 598 "src/parse-gram.y" /* yacc.c:1649  */
-    { grammar_current_rule_merge_set ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
-#line 2669 "src/parse-gram.c" /* yacc.c:1649  */
+    { grammar_current_rule_merge_set ((yyvsp[0].TAG), (yylsp[0])); }
+#line 2668 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 94:
 #line 600 "src/parse-gram.y" /* yacc.c:1649  */
-    { grammar_current_rule_expect_sr ((*(int*)(&yyvsp[0])), (yylsp[0])); }
-#line 2675 "src/parse-gram.c" /* yacc.c:1649  */
+    { grammar_current_rule_expect_sr ((yyvsp[0].INT), (yylsp[0])); }
+#line 2674 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 95:
 #line 602 "src/parse-gram.y" /* yacc.c:1649  */
-    { grammar_current_rule_expect_rr ((*(int*)(&yyvsp[0])), (yylsp[0])); }
-#line 2681 "src/parse-gram.c" /* yacc.c:1649  */
+    { grammar_current_rule_expect_rr ((yyvsp[0].INT), (yylsp[0])); }
+#line 2680 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 96:
 #line 606 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(named_ref**)(&yyval)) = 0; }
-#line 2687 "src/parse-gram.c" /* yacc.c:1649  */
+    { (yyval.yytype_87) = 0; }
+#line 2686 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 97:
 #line 607 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(named_ref**)(&yyval)) = named_ref_new ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
-#line 2693 "src/parse-gram.c" /* yacc.c:1649  */
+    { (yyval.yytype_87) = named_ref_new ((yyvsp[0].BRACKETED_ID), (yylsp[0])); }
+#line 2692 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 99:
 #line 640 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(value_type*)(&yyval)).kind = muscle_keyword; (*(value_type*)(&yyval)).chars = ""; }
-#line 2699 "src/parse-gram.c" /* yacc.c:1649  */
+    { (yyval.value).kind = muscle_keyword; (yyval.value).chars = ""; }
+#line 2698 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 100:
 #line 641 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(value_type*)(&yyval)).kind = muscle_keyword; (*(value_type*)(&yyval)).chars = (*(uniqstr*)(&yyvsp[0])); }
-#line 2705 "src/parse-gram.c" /* yacc.c:1649  */
+    { (yyval.value).kind = muscle_keyword; (yyval.value).chars = (yyvsp[0].ID); }
+#line 2704 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 101:
 #line 642 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(value_type*)(&yyval)).kind = muscle_string;  (*(value_type*)(&yyval)).chars = (*(char**)(&yyvsp[0])); }
-#line 2711 "src/parse-gram.c" /* yacc.c:1649  */
+    { (yyval.value).kind = muscle_string;  (yyval.value).chars = (yyvsp[0].STRING); }
+#line 2710 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 102:
 #line 643 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(value_type*)(&yyval)).kind = muscle_code;    (*(value_type*)(&yyval)).chars = strip_braces ((*(char**)(&yyvsp[0]))); }
-#line 2717 "src/parse-gram.c" /* yacc.c:1649  */
+    { (yyval.value).kind = muscle_code;    (yyval.value).chars = strip_braces ((yyvsp[0].BRACED_CODE)); }
+#line 2716 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 103:
 #line 656 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(symbol**)(&yyval)) = symbol_from_uniqstr ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
-#line 2723 "src/parse-gram.c" /* yacc.c:1649  */
+    { (yyval.id) = symbol_from_uniqstr ((yyvsp[0].ID), (yylsp[0])); }
+#line 2722 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 104:
@@ -2731,45 +2730,45 @@ yyreduce:
                       _("character literals cannot be non-terminals"));
           YYERROR;
         }
-      (*(symbol**)(&yyval)) = symbol_get (char_name ((*(unsigned char*)(&yyvsp[0]))), (yylsp[0]));
-      symbol_class_set ((*(symbol**)(&yyval)), token_sym, (yylsp[0]), false);
-      symbol_user_token_number_set ((*(symbol**)(&yyval)), (*(unsigned char*)(&yyvsp[0])), (yylsp[0]));
+      (yyval.id) = symbol_get (char_name ((yyvsp[0].CHAR)), (yylsp[0]));
+      symbol_class_set ((yyval.id), token_sym, (yylsp[0]), false);
+      symbol_user_token_number_set ((yyval.id), (yyvsp[0].CHAR), (yylsp[0]));
     }
-#line 2739 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2738 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 105:
 #line 672 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(symbol**)(&yyval)) = symbol_from_uniqstr ((*(uniqstr*)(&yyvsp[0])), (yylsp[0])); }
-#line 2745 "src/parse-gram.c" /* yacc.c:1649  */
+    { (yyval.id_colon) = symbol_from_uniqstr ((yyvsp[0].ID_COLON), (yylsp[0])); }
+#line 2744 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 108:
 #line 684 "src/parse-gram.y" /* yacc.c:1649  */
     {
-      (*(symbol**)(&yyval)) = symbol_get (quotearg_style (c_quoting_style, (*(char**)(&yyvsp[0]))), (yylsp[0]));
-      symbol_class_set ((*(symbol**)(&yyval)), token_sym, (yylsp[0]), false);
+      (yyval.string_as_id) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].STRING)), (yylsp[0]));
+      symbol_class_set ((yyval.string_as_id), token_sym, (yylsp[0]), false);
     }
-#line 2754 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2753 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 109:
 #line 692 "src/parse-gram.y" /* yacc.c:1649  */
-    { (*(symbol**)(&yyval)) = NULL; }
-#line 2760 "src/parse-gram.c" /* yacc.c:1649  */
+    { (yyval.yytype_94) = NULL; }
+#line 2759 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 112:
 #line 699 "src/parse-gram.y" /* yacc.c:1649  */
     {
-      muscle_code_grow ("epilogue", translate_code ((*(char**)(&yyvsp[0])), (yylsp[0]), true), (yylsp[0]));
+      muscle_code_grow ("epilogue", translate_code ((yyvsp[0].EPILOGUE), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2769 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2768 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
 
-#line 2773 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2772 "src/parse-gram.c" /* yacc.c:1649  */
         default: break;
       }
     if (yychar_backup != yychar)
