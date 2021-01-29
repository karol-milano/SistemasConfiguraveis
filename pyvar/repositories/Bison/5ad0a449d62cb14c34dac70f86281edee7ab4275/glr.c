@@ -201,7 +201,7 @@ typedef struct YYLTYPE
 ]])
 
 b4_defines_if([#include @output_header_name@],
-              [b4_shared_declarations])[
+	      [b4_shared_declarations])[
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
@@ -1836,8 +1836,14 @@ yyresolveLocations (yyGLRState* yys1, int yyn1,
 	    }
 	  else
 	    {
+	      /* Both yyresolveAction and yyresolveLocations traverse the GSS
+		 in reverse rightmost order.  It is only necessary to invoke
+		 yyresolveLocations on a subforest for which yyresolveAction
+		 would have been invoked next had an ambiguity not been
+		 detected.  Thus the location of the previous state (but not
+		 necessarily the previous state itself) is guaranteed to be
+		 resolved already.  */
 	      yyGLRState *yyprevious = yyoption->yystate;
-	      YYASSERT (yyprevious->yyresolved);
 	      yyrhsloc[0].yystate.yyloc = yyprevious->yyloc;
 	    }
 	  yychar_current = yychar;
