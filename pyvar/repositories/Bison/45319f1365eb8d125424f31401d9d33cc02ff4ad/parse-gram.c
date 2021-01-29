@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.404-c6ab.  */
+/* A Bison parser, made by GNU Bison 2.4.425-305c-dirty.  */
 
 /* Implementation for Bison's Yacc-like parsers in C
 
@@ -45,7 +45,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.404-c6ab"
+#define YYBISON_VERSION "2.4.425-305c-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -1433,26 +1433,27 @@ yytnamerr (char *yyres, const char *yystr)
 }
 # endif
 
-/* Copy into YYRESULT an error message about the unexpected token
-   YYTOKEN while in state YYSTATE.  Return the number of bytes copied,
-   including the terminating null byte.  If YYRESULT is null, do not
-   copy anything; just return the number of bytes that would be
-   copied.  As a special case, return 0 if an ordinary "syntax error"
-   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
-   size calculation.  */
-static YYSIZE_T
-yysyntax_error (char *yyresult, int yystate, int yytoken)
+/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
+   about the unexpected token YYTOKEN while in state YYSTATE.
+
+   Return 0 if *YYMSG was successfully written.  Return 1 if an ordinary
+   "syntax error" message will suffice instead.  Return 2 if *YYMSG is
+   not large enough to hold the message.  In the last case, also set
+   *YYMSG_ALLOC to either (a) the required number of bytes or (b) zero
+   if the required number of bytes is too large to store.  */
+static int
+yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
+                int yystate, int yytoken)
 {
   int yyn = yypact[yystate];
 
   if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
-    return 0;
+    return 1;
   else
     {
       YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
       YYSIZE_T yysize = yysize0;
       YYSIZE_T yysize1;
-      int yysize_overflow = 0;
       enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
       /* Internationalized format string. */
       const char *yyformat = 0;
@@ -1486,11 +1487,17 @@ yysyntax_error (char *yyresult, int yystate, int yytoken)
 	      }
 	    yyarg[yycount++] = yytname[yyx];
 	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
-	    yysize_overflow |= (yysize1 < yysize);
+	    if (! (yysize <= yysize1
+		   && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
+	      {
+		/* Overflow.  */
+		*yymsg_alloc = 0;
+		return 2;
+	      }
 	    yysize = yysize1;
 	  }
 
-        switch (yycount)
+      switch (yycount)
         {
 #define YYCASE_(N, S)                           \
           case N:                               \
@@ -1505,32 +1512,42 @@ yysyntax_error (char *yyresult, int yystate, int yytoken)
         }
 
       yysize1 = yysize + yystrlen (yyformat);
-      yysize_overflow |= (yysize1 < yysize);
+      if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
+        {
+          /* Overflow.  */
+          *yymsg_alloc = 0;
+          return 2;
+        }
       yysize = yysize1;
 
-      if (yysize_overflow)
-	return YYSIZE_MAXIMUM;
+      if (*yymsg_alloc < yysize)
+        {
+          *yymsg_alloc = 2 * yysize;
+          if (! (yysize <= *yymsg_alloc
+                 && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
+            *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
+          return 2;
+        }
 
-      if (yyresult)
-	{
-	  /* Avoid sprintf, as that infringes on the user's name space.
-	     Don't have undefined behavior even if the translation
-	     produced a string with the wrong number of "%s"s.  */
-	  char *yyp = yyresult;
-	  int yyi = 0;
-	  while ((*yyp = *yyformat) != '\0')
-            if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
-              {
-                yyp += yytnamerr (yyp, yyarg[yyi++]);
-                yyformat += 2;
-              }
-            else
-              {
-                yyp++;
-                yyformat++;
-              }
-	}
-      return yysize;
+      /* Avoid sprintf, as that infringes on the user's name space.
+         Don't have undefined behavior even if the translation
+         produced a string with the wrong number of "%s"s.  */
+      {
+        char *yyp = *yymsg;
+        int yyi = 0;
+        while ((*yyp = *yyformat) != '\0')
+          if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
+            {
+              yyp += yytnamerr (yyp, yyarg[yyi++]);
+              yyformat += 2;
+            }
+          else
+            {
+              yyp++;
+              yyformat++;
+            }
+      }
+      return 0;
     }
 }
 #endif /* YYERROR_VERBOSE */
@@ -1707,7 +1724,7 @@ YYLTYPE yylloc;
 #endif
 
 /* User initialization code.  */
-/* Line 1183 of yacc.c  */
+/* Line 1200 of yacc.c  */
 #line 80 "src/parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1715,8 +1732,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-/* Line 1183 of yacc.c  */
-#line 1720 "src/parse-gram.c"
+/* Line 1200 of yacc.c  */
+#line 1737 "src/parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1902,7 +1919,7 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 266 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -1913,106 +1930,106 @@ yyreduce:
                         plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1396 of yacc.c  */
-#line 1918 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 1935 "src/parse-gram.c"
     break;
 
   case 7:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 276 "src/parse-gram.y"
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-/* Line 1396 of yacc.c  */
-#line 1928 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 1945 "src/parse-gram.c"
     break;
 
   case 8:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 280 "src/parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1396 of yacc.c  */
-#line 1939 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 1956 "src/parse-gram.c"
     break;
 
   case 9:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 284 "src/parse-gram.y"
     { defines_flag = true; }
-/* Line 1396 of yacc.c  */
-#line 1947 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 1964 "src/parse-gram.c"
     break;
 
   case 10:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 286 "src/parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
-/* Line 1396 of yacc.c  */
-#line 1958 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 1975 "src/parse-gram.c"
     break;
 
   case 11:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 291 "src/parse-gram.y"
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1396 of yacc.c  */
-#line 1969 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 1986 "src/parse-gram.c"
     break;
 
   case 12:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 295 "src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
-/* Line 1396 of yacc.c  */
-#line 1977 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 1994 "src/parse-gram.c"
     break;
 
   case 13:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 296 "src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
-/* Line 1396 of yacc.c  */
-#line 1985 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2002 "src/parse-gram.c"
     break;
 
   case 14:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 297 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1396 of yacc.c  */
-#line 1993 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2010 "src/parse-gram.c"
     break;
 
   case 15:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 298 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1396 of yacc.c  */
-#line 2001 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2018 "src/parse-gram.c"
     break;
 
   case 16:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 300 "src/parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-/* Line 1396 of yacc.c  */
-#line 2012 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2029 "src/parse-gram.c"
     break;
 
   case 17:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 305 "src/parse-gram.y"
     {
       code_props action;
@@ -2022,92 +2039,92 @@ yyreduce:
       muscle_code_grow ("initial_action", action.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1396 of yacc.c  */
-#line 2027 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2044 "src/parse-gram.c"
     break;
 
   case 18:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 313 "src/parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
-/* Line 1396 of yacc.c  */
-#line 2035 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2052 "src/parse-gram.c"
     break;
 
   case 19:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 314 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1396 of yacc.c  */
-#line 2043 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2060 "src/parse-gram.c"
     break;
 
   case 20:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 315 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1396 of yacc.c  */
-#line 2051 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2068 "src/parse-gram.c"
     break;
 
   case 21:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 316 "src/parse-gram.y"
     { no_lines_flag = true; }
-/* Line 1396 of yacc.c  */
-#line 2059 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2076 "src/parse-gram.c"
     break;
 
   case 22:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 317 "src/parse-gram.y"
     { nondeterministic_parser = true; }
-/* Line 1396 of yacc.c  */
-#line 2067 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2084 "src/parse-gram.c"
     break;
 
   case 23:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 318 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1396 of yacc.c  */
-#line 2075 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2092 "src/parse-gram.c"
     break;
 
   case 24:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 319 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1396 of yacc.c  */
-#line 2083 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2100 "src/parse-gram.c"
     break;
 
   case 25:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 320 "src/parse-gram.y"
     { current_param = (yyvsp[0].param); }
-/* Line 1396 of yacc.c  */
-#line 2091 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2108 "src/parse-gram.c"
     break;
 
   case 26:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 320 "src/parse-gram.y"
     { current_param = param_none; }
-/* Line 1396 of yacc.c  */
-#line 2099 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2116 "src/parse-gram.c"
     break;
 
   case 27:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 321 "src/parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
-/* Line 1396 of yacc.c  */
-#line 2107 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2124 "src/parse-gram.c"
     break;
 
   case 28:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 323 "src/parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
@@ -2132,62 +2149,62 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-/* Line 1396 of yacc.c  */
-#line 2137 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2154 "src/parse-gram.c"
     break;
 
   case 29:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 346 "src/parse-gram.y"
     { token_table_flag = true; }
-/* Line 1396 of yacc.c  */
-#line 2145 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2162 "src/parse-gram.c"
     break;
 
   case 30:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 347 "src/parse-gram.y"
     { report_flag |= report_states; }
-/* Line 1396 of yacc.c  */
-#line 2153 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2170 "src/parse-gram.c"
     break;
 
   case 31:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 348 "src/parse-gram.y"
     { yacc_flag = true; }
-/* Line 1396 of yacc.c  */
-#line 2161 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2178 "src/parse-gram.c"
     break;
 
   case 33:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 353 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1396 of yacc.c  */
-#line 2169 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2186 "src/parse-gram.c"
     break;
 
   case 34:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 354 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1396 of yacc.c  */
-#line 2177 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2194 "src/parse-gram.c"
     break;
 
   case 37:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 366 "src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-/* Line 1396 of yacc.c  */
-#line 2187 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2204 "src/parse-gram.c"
     break;
 
   case 38:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 370 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2195,12 +2212,12 @@ yyreduce:
 	symbol_list_destructor_set (list, (yyvsp[-1].code), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1396 of yacc.c  */
-#line 2200 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2217 "src/parse-gram.c"
     break;
 
   case 39:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 377 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2208,32 +2225,32 @@ yyreduce:
 	symbol_list_printer_set (list, (yyvsp[-1].code), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1396 of yacc.c  */
-#line 2213 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2230 "src/parse-gram.c"
     break;
 
   case 40:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 384 "src/parse-gram.y"
     {
       default_prec = true;
     }
-/* Line 1396 of yacc.c  */
-#line 2223 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2240 "src/parse-gram.c"
     break;
 
   case 41:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 388 "src/parse-gram.y"
     {
       default_prec = false;
     }
-/* Line 1396 of yacc.c  */
-#line 2233 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2250 "src/parse-gram.c"
     break;
 
   case 42:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 392 "src/parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2241,89 +2258,89 @@ yyreduce:
       muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1396 of yacc.c  */
-#line 2246 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2263 "src/parse-gram.c"
     break;
 
   case 43:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 399 "src/parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1396 of yacc.c  */
-#line 2257 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2274 "src/parse-gram.c"
     break;
 
   case 44:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 413 "src/parse-gram.y"
     {}
-/* Line 1396 of yacc.c  */
-#line 2265 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2282 "src/parse-gram.c"
     break;
 
   case 45:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 414 "src/parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1396 of yacc.c  */
-#line 2273 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2290 "src/parse-gram.c"
     break;
 
   case 46:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 419 "src/parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1396 of yacc.c  */
-#line 2285 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2302 "src/parse-gram.c"
     break;
 
   case 47:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 430 "src/parse-gram.y"
     { current_class = nterm_sym; }
-/* Line 1396 of yacc.c  */
-#line 2293 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2310 "src/parse-gram.c"
     break;
 
   case 48:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 431 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1396 of yacc.c  */
-#line 2304 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2321 "src/parse-gram.c"
     break;
 
   case 49:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 435 "src/parse-gram.y"
     { current_class = token_sym; }
-/* Line 1396 of yacc.c  */
-#line 2312 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2329 "src/parse-gram.c"
     break;
 
   case 50:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 436 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1396 of yacc.c  */
-#line 2323 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2340 "src/parse-gram.c"
     break;
 
   case 51:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 441 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2332,12 +2349,12 @@ yyreduce:
 	symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1396 of yacc.c  */
-#line 2337 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2354 "src/parse-gram.c"
     break;
 
   case 52:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 452 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2350,202 +2367,202 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-/* Line 1396 of yacc.c  */
-#line 2355 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2372 "src/parse-gram.c"
     break;
 
   case 53:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 466 "src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
-/* Line 1396 of yacc.c  */
-#line 2363 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2380 "src/parse-gram.c"
     break;
 
   case 54:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 467 "src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
-/* Line 1396 of yacc.c  */
-#line 2371 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2388 "src/parse-gram.c"
     break;
 
   case 55:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 468 "src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
-/* Line 1396 of yacc.c  */
-#line 2379 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2396 "src/parse-gram.c"
     break;
 
   case 56:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 469 "src/parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
-/* Line 1396 of yacc.c  */
-#line 2387 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2404 "src/parse-gram.c"
     break;
 
   case 57:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 473 "src/parse-gram.y"
     { current_type = NULL; }
-/* Line 1396 of yacc.c  */
-#line 2395 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2412 "src/parse-gram.c"
     break;
 
   case 58:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 474 "src/parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-/* Line 1396 of yacc.c  */
-#line 2403 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2420 "src/parse-gram.c"
     break;
 
   case 59:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 480 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1396 of yacc.c  */
-#line 2411 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2428 "src/parse-gram.c"
     break;
 
   case 60:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 482 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1396 of yacc.c  */
-#line 2419 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2436 "src/parse-gram.c"
     break;
 
   case 61:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 486 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
-/* Line 1396 of yacc.c  */
-#line 2427 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2444 "src/parse-gram.c"
     break;
 
   case 62:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 487 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
-/* Line 1396 of yacc.c  */
-#line 2435 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2452 "src/parse-gram.c"
     break;
 
   case 63:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 493 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1396 of yacc.c  */
-#line 2443 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2460 "src/parse-gram.c"
     break;
 
   case 64:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 495 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1396 of yacc.c  */
-#line 2451 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2468 "src/parse-gram.c"
     break;
 
   case 65:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 499 "src/parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
-/* Line 1396 of yacc.c  */
-#line 2459 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2476 "src/parse-gram.c"
     break;
 
   case 66:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 500 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
-/* Line 1396 of yacc.c  */
-#line 2467 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2484 "src/parse-gram.c"
     break;
 
   case 67:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 504 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1396 of yacc.c  */
-#line 2475 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2492 "src/parse-gram.c"
     break;
 
   case 68:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 505 "src/parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1396 of yacc.c  */
-#line 2483 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2500 "src/parse-gram.c"
     break;
 
   case 69:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 506 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[0])); }
-/* Line 1396 of yacc.c  */
-#line 2491 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2508 "src/parse-gram.c"
     break;
 
   case 70:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 507 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[0])); }
-/* Line 1396 of yacc.c  */
-#line 2499 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2516 "src/parse-gram.c"
     break;
 
   case 71:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 513 "src/parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
-/* Line 1396 of yacc.c  */
-#line 2510 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2527 "src/parse-gram.c"
     break;
 
   case 72:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 518 "src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
-/* Line 1396 of yacc.c  */
-#line 2521 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2538 "src/parse-gram.c"
     break;
 
   case 73:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 523 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-/* Line 1396 of yacc.c  */
-#line 2533 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2550 "src/parse-gram.c"
     break;
 
   case 74:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 529 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1396 of yacc.c  */
-#line 2545 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2562 "src/parse-gram.c"
     break;
 
   case 75:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 535 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
@@ -2553,136 +2570,136 @@ yyreduce:
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1396 of yacc.c  */
-#line 2558 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2575 "src/parse-gram.c"
     break;
 
   case 82:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 565 "src/parse-gram.y"
     {
       yyerrok;
     }
-/* Line 1396 of yacc.c  */
-#line 2568 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2585 "src/parse-gram.c"
     break;
 
   case 83:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 571 "src/parse-gram.y"
     { current_lhs = (yyvsp[-1].symbol); current_lhs_location = (yylsp[-1]);
     current_lhs_named_ref = (yyvsp[0].named_ref); }
-/* Line 1396 of yacc.c  */
-#line 2577 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2594 "src/parse-gram.c"
     break;
 
   case 85:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 576 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1396 of yacc.c  */
-#line 2585 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2602 "src/parse-gram.c"
     break;
 
   case 86:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 577 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1396 of yacc.c  */
-#line 2593 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2610 "src/parse-gram.c"
     break;
 
   case 88:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 583 "src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location,
 				  current_lhs_named_ref); }
-/* Line 1396 of yacc.c  */
-#line 2602 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2619 "src/parse-gram.c"
     break;
 
   case 89:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 586 "src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1396 of yacc.c  */
-#line 2610 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2627 "src/parse-gram.c"
     break;
 
   case 90:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 588 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1396 of yacc.c  */
-#line 2618 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2635 "src/parse-gram.c"
     break;
 
   case 91:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 590 "src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1396 of yacc.c  */
-#line 2626 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2643 "src/parse-gram.c"
     break;
 
   case 92:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 592 "src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-/* Line 1396 of yacc.c  */
-#line 2634 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2651 "src/parse-gram.c"
     break;
 
   case 93:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 594 "src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1396 of yacc.c  */
-#line 2642 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2659 "src/parse-gram.c"
     break;
 
   case 94:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 598 "src/parse-gram.y"
     { (yyval.named_ref) = 0; }
-/* Line 1396 of yacc.c  */
-#line 2650 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2667 "src/parse-gram.c"
     break;
 
   case 95:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 600 "src/parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1396 of yacc.c  */
-#line 2658 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2675 "src/parse-gram.c"
     break;
 
   case 97:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 612 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
-/* Line 1396 of yacc.c  */
-#line 2666 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2683 "src/parse-gram.c"
     break;
 
   case 98:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 617 "src/parse-gram.y"
     { (yyval.chars) = ""; }
-/* Line 1396 of yacc.c  */
-#line 2674 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2691 "src/parse-gram.c"
     break;
 
   case 99:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 618 "src/parse-gram.y"
     { (yyval.chars) = (yyvsp[0].uniqstr); }
-/* Line 1396 of yacc.c  */
-#line 2682 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2699 "src/parse-gram.c"
     break;
 
   case 101:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 629 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -2692,51 +2709,51 @@ yyreduce:
       gram_scanner_last_string_free ();
       (yyval.chars) = plain_code.code;
     }
-/* Line 1396 of yacc.c  */
-#line 2697 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2714 "src/parse-gram.c"
     break;
 
   case 102:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 649 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1396 of yacc.c  */
-#line 2705 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2722 "src/parse-gram.c"
     break;
 
   case 103:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 651 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-/* Line 1396 of yacc.c  */
-#line 2717 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2734 "src/parse-gram.c"
     break;
 
   case 104:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 659 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1396 of yacc.c  */
-#line 2725 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2742 "src/parse-gram.c"
     break;
 
   case 107:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 671 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-/* Line 1396 of yacc.c  */
-#line 2736 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2753 "src/parse-gram.c"
     break;
 
   case 109:
-/* Line 1396 of yacc.c  */
+/* Line 1413 of yacc.c  */
 #line 680 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -2746,13 +2763,13 @@ yyreduce:
       muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1396 of yacc.c  */
-#line 2751 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2768 "src/parse-gram.c"
     break;
 
 
-/* Line 1396 of yacc.c  */
-#line 2756 "src/parse-gram.c"
+/* Line 1413 of yacc.c  */
+#line 2773 "src/parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2790,37 +2807,28 @@ yyerrlab:
 #if ! YYERROR_VERBOSE
       yyerror (YY_("syntax error"));
 #else
-      {
-	YYSIZE_T yysize = yysyntax_error (0, yystate, yytoken);
-	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
-	  {
-	    YYSIZE_T yyalloc = 2 * yysize;
-	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
-	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
-	    if (yymsg != yymsgbuf)
-	      YYSTACK_FREE (yymsg);
-	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
-	    if (yymsg)
-	      yymsg_alloc = yyalloc;
-	    else
-	      {
-		yymsg = yymsgbuf;
-		yymsg_alloc = sizeof yymsgbuf;
-	      }
-	  }
-
-	if (0 < yysize && yysize <= yymsg_alloc)
-	  {
-	    (void) yysyntax_error (yymsg, yystate, yytoken);
-	    yyerror (yymsg);
-	  }
-	else
-	  {
-	    yyerror (YY_("syntax error"));
-	    if (yysize != 0)
-	      goto yyexhaustedlab;
-	  }
-      }
+      while (1)
+        {
+          int yysyntax_error_status =
+            yysyntax_error (&yymsg_alloc, &yymsg, yystate, yytoken);
+          if (yysyntax_error_status == 2 && 0 < yymsg_alloc)
+            {
+              if (yymsg != yymsgbuf)
+                YYSTACK_FREE (yymsg);
+              yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
+              if (yymsg)
+                continue;
+              yymsg = yymsgbuf;
+              yymsg_alloc = sizeof yymsgbuf;
+            }
+          if (yysyntax_error_status == 0)
+            yyerror (yymsg);
+          else
+            yyerror (YY_("syntax error"));
+          if (yysyntax_error_status == 2)
+            goto yyexhaustedlab;
+          break;
+        }
 #endif
     }
 
@@ -2968,7 +2976,7 @@ yyreturn:
   return YYID (yyresult);
 }
 
-/* Line 1615 of yacc.c  */
+/* Line 1623 of yacc.c  */
 #line 690 "src/parse-gram.y"
 
 
