@@ -108,8 +108,10 @@ void packsymbols PARAMS((void));
 void output_token_defines PARAMS((FILE *));
 void packgram PARAMS((void));
 int read_signed_integer PARAMS((FILE *));
-static int get_type PARAMS((void));
 
+#if 0
+static int get_type PARAMS((void));
+#endif
 
 int lineno;
 symbol_list *grammar;
@@ -1460,7 +1462,7 @@ void
 readgram (void)
 {
   register int t;
-  register bucket *lhs;
+  register bucket *lhs = NULL;
   register symbol_list *p;
   register symbol_list *p1;
   register bucket *bp;
@@ -1763,6 +1765,7 @@ record_rule_line (void)
 }
 
 
+#if 0
 /* read in a %type declaration and record its information for get_type_name to access */
 /* this is unused.  it is only called from the #if 0 part of readgram */
 static int
@@ -1809,7 +1812,7 @@ get_type (void)
 	}
     }
 }
-
+#endif
 
 
 /* assign symbol numbers, and write definition of token names into fdefines.
