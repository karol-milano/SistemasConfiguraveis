@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.5.93.  */
+/* A Bison parser, made by GNU Bison 3.6.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -49,7 +49,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.5.93"
+#define YYBISON_VERSION "3.6"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -1632,6 +1632,8 @@ yypcontext_expected_tokens (const yypcontext_t *yyctx,
               yyarg[yycount++] = yysym;
           }
     }
+  if (yyarg && yycount == 0 && 0 < yyargn)
+    yyarg[0] = YYSYMBOL_YYEMPTY;
   return yycount;
 }
 
