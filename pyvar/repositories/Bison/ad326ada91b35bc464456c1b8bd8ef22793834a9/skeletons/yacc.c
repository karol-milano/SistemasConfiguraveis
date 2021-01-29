@@ -1066,7 +1066,10 @@ yytnamerr (char *yyres, const char *yystr)
           case '\\':
             if (*++yyp != '\\')
               goto do_not_strip_quotes;
-            /* Fall through.  */
+            else
+              goto append;
+
+          append:
           default:
             if (yyres)
               yyres[yyn] = *yyp;
