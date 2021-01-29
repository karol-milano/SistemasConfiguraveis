@@ -1,7 +1,8 @@
 m4_divert(-1)                                                       -*- C -*-
 
 # Yacc compatible skeleton for Bison
-# Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004
+
+# Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005
 # Free Software Foundation, Inc.
 
 # This program is free software; you can redistribute it and/or modify
@@ -1170,12 +1171,11 @@ yyerrlab:
 `---------------------------------------------------*/
 yyerrorlab:
 
-#ifdef __GNUC__
-  /* Pacify GCC when the user code never invokes YYERROR and the label
-     yyerrorlab therefore never appears in user code.  */
+  /* Pacify compilers like GCC when the user code never invokes
+     YYERROR and the label yyerrorlab therefore never appears in user
+     code.  */
   if (0)
      goto yyerrorlab;
-#endif
 
 ]b4_location_if([[  yyerror_range[0] = yylsp[1-yylen];
   yylsp -= yylen;
