@@ -931,6 +931,9 @@ enum { YYENOMEM = -2 };
       }                                                           \
   while (0)
 
+/* Backward compatibility with an undocumented macro.
+   Use GRAM_error or GRAM_UNDEF. */
+#define YYERRCODE GRAM_UNDEF
 
 /* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
    If N is 0, then set CURRENT to the empty location which ends
