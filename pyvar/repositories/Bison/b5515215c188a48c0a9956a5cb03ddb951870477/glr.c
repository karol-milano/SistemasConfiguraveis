@@ -311,7 +311,7 @@ static YYLTYPE yyloc_default][]b4_yyloc_default;])[
  } while (yyfalse)
 #endif
 
-]b4_attribute_define[
+]b4_attribute_define([noreturn])[
 
 #ifndef YYASSERT
 # define YYASSERT(Condition) ((void) ((Condition) || (abort (), 0)))
