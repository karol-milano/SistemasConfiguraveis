@@ -768,7 +768,7 @@ do {						\
 } while (0)
 
 #define YY_USER_ACTION  LOCATION_COLUMNS (*yylloc, yyleng)
-#define YY_LINES        LOCATION_LINES (*yylloc, yyleng); lineno += yyleng;
+#define YY_LINES        LOCATION_LINES (*yylloc, yyleng);
 #define YY_STEP         LOCATION_STEP (*yylloc)
 
 /* STRING_OBSTACK -- Used to store all the characters that we need to
