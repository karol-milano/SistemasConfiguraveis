@@ -997,7 +997,7 @@ yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
               }
             *++yyesp = yystate;
           }
-        YYDPRINTF ((stderr, " G%hd", yystate));
+        YYDPRINTF ((stderr, " G%d", (int) yystate));
       }
     }
 }]])[
