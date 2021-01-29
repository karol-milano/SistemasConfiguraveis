@@ -1,7 +1,7 @@
 m4_divert(-1)                                                       -*- C -*-
 
 # GLR skeleton for Bison
-# Copyright (C) 2002, 2003 Free Software Foundation, Inc.
+# Copyright (C) 2002, 2003, 2004 Free Software Foundation, Inc.
 
 # This program is free software; you can redistribute it and/or modify
 # it under the terms of the GNU General Public License as published by
@@ -636,6 +636,9 @@ yyFail (yyGLRStack* yystack]b4_pure_formals[, const char* yyformat, ...)
 static inline const char*
 yytokenName (yySymbol yytoken)
 {
+  if (yytoken == YYEMPTY)
+    return "";
+
   return yytname[yytoken];
 }
 #endif
@@ -1653,7 +1656,8 @@ yyreportSyntaxError (yyGLRStack* yystack,
 	  if (yymsg != 0)
 	    {
 	      char* yyp = yymsg;
-	      sprintf (yyp, "syntax error, unexpected %s",
+	      sprintf (yyp, "syntax error%s%s",
+		       (*yytokenp == YYEMPTY ? "" : ", unexpected "),
 		       yytokenName (*yytokenp));
 	      yyp += strlen (yyp);
 	      if (yycount < 5)
