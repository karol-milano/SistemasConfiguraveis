@@ -108,7 +108,7 @@ static void
 redeclaration (symbol* s, const char *what, location first, location second)
 {
   complain_at (second, _("%s redeclaration for %s"), what, s->tag);
-  complain_at (first, _("first declaration"));
+  complain_at (first, _("previous declaration"));
 }
 
 
