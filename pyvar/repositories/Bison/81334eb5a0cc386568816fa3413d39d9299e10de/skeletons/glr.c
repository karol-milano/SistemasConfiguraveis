@@ -261,6 +261,11 @@ static YYLTYPE yyloc_default][]b4_yyloc_default;])[
 #  define YY_(Msgid) Msgid
 # endif
 #endif
+]b4_has_translations_if([
+#ifndef N_
+# define N_(Msgid) Msgid
+#endif
+])[
 
 #ifndef YYFREE
 # define YYFREE free
