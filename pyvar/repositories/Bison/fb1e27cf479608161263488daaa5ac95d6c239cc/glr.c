@@ -292,12 +292,14 @@ b4_percent_code_get[]dnl
 #define YYSIZEMAX ((size_t) -1)
 
 #ifdef __cplusplus
-   typedef bool yybool;
+  typedef bool yybool;
+# define yytrue true
+# define yyfalse false
 #else
-   typedef unsigned char yybool;
+  typedef unsigned char yybool;
+# define yytrue 1
+# define yyfalse 0
 #endif
-#define yytrue 1
-#define yyfalse 0
 
 #ifndef YYSETJMP
 # include <setjmp.h>
