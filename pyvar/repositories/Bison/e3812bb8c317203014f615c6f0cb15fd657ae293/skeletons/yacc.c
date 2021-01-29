@@ -673,7 +673,7 @@ static const ]b4_int_type_for([b4_toknum])[ yytoknum[] =
 
 /* Error token number */
 #define YYTERROR        1
-#define YYERRCODE       256
+#define YYERRCODE       ]b4_symbol(1, user_number)[
 
 ]b4_locations_if([[
 ]b4_yylloc_default_define[
