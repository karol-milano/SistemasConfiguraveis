@@ -2024,7 +2024,7 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 #define YYCHK1(YYE)							     \
   do {									     \
     switch (YYE) {							     \
-    default:								     \
+    case yyok:								     \
       break;								     \
     case yyabort:							     \
       goto yyabortlab;							     \
@@ -2032,6 +2032,8 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
       goto yyacceptlab;							     \
     case yyerr:								     \
       goto yyuser_error;						     \
+    default:								     \
+      goto yybuglab;							     \
     }									     \
   } while (0)
 
@@ -2187,6 +2189,10 @@ b4_syncline([@oline@], [@ofile@])])dnl
   yyresult = 0;
   goto yyreturn;
 
+ yybuglab:
+  YYASSERT (yyfalse);
+  /* Fall through.  */
+
  yyabortlab:
   yyresult = 1;
   goto yyreturn;
