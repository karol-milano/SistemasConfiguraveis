@@ -1154,10 +1154,10 @@ yytnamerr (char *yyres, const char *yystr)
     do_not_strip_quotes: ;
     }
 
-  if (! yyres)
+  if (yyres)
+    return (YYPTRDIFF_T) (yystpcpy (yyres, yystr) - yyres);
+  else
     return yystrlen (yystr);
-
-  return yystpcpy (yyres, yystr) - yyres;
 }
 # endif
 
@@ -1490,7 +1490,7 @@ b4_function_define([[yyparse]], [[int]], b4_parse_param)[
   yystacksize = YYINITDEPTH;]b4_lac_if([[
 
   yyes = yyesa;
-  yyes_capacity = sizeof yyesa / sizeof *yyes;
+  yyes_capacity = (YYPTRDIFF_T) (sizeof yyesa / sizeof *yyes);
   if (YYMAXDEPTH < yyes_capacity)
     yyes_capacity = YYMAXDEPTH;]])[
 
