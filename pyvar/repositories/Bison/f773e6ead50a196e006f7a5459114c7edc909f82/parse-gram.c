@@ -3382,12 +3382,6 @@ gram_error (location const *loc, char const *msg)
   complain (loc, complaint, "%s", msg);
 }
 
-char const *
-token_name (int type)
-{
-  return yytname[YYTRANSLATE (type)];
-}
-
 static char const *
 char_name (char c)
 {
