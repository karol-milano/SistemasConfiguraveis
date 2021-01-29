@@ -177,7 +177,7 @@
   static void handle_skeleton (location const *loc, char const *skel);
 
   /* Handle a %yacc directive.  */
-  static void handle_yacc (location const *loc, char const *directive);
+  static void handle_yacc (location const *loc);
 
   static void gram_error (location const *, char const *);
 
@@ -912,10 +912,6 @@ tron (yyo);
          { fputs (((*yyvaluep).PERCENT_PURE_PARSER), yyo); }
         break;
 
-    case 39: /* "%yacc"  */
-         { fputs (((*yyvaluep).PERCENT_YACC), yyo); }
-        break;
-
     case 40: /* "{...}"  */
          { fputs (((*yyvaluep).BRACED_CODE), yyo); }
         break;
@@ -2119,7 +2115,7 @@ yyreduce:
     break;
 
   case 29:
-                                { handle_yacc (&(yyloc), (yyvsp[0].PERCENT_YACC)); }
+                                { handle_yacc (&(yyloc)); }
     break;
 
   case 30:
@@ -3017,23 +3013,14 @@ handle_skeleton (location const *loc, char const *skel)
 
 
 static void
-handle_yacc (location const *loc, char const *directive)
+handle_yacc (location const *loc)
 {
+  const char *directive = "%yacc";
   bison_directive (loc, directive);
-  bool warned = false;
-
   if (location_empty (yacc_loc))
     yacc_loc = *loc;
   else
-    {
-      duplicate_directive (directive, yacc_loc, *loc);
-      warned = true;
-    }
-
-  if (!warned
-      && STRNEQ (directive, "%fixed-output-files")
-      && STRNEQ (directive, "%yacc"))
-    deprecated_directive (loc, directive, "%fixed-output-files");
+    duplicate_directive (directive, yacc_loc, *loc);
 }
 
 
