@@ -285,7 +285,7 @@ warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n\
 `----------------------*/
 
 /* Shorts options.  */
-const char *short_options = "yvegdhr:ltknVo:b:p:S:T::";
+static char const short_options[] = "yvegdhr:ltknVo:b:p:S:T::";
 
 /* Values for long options that do not have single-letter equivalents.  */
 enum
