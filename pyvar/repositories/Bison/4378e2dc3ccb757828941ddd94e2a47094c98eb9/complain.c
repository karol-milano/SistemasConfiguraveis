@@ -600,7 +600,7 @@ syntax_error (location loc,
       CASE (2, _("expected %1$s before %0$s"));
       CASE (3, _("expected %1$s or %2$s before %0$s"));
       CASE (4, _("expected %1$s or %2$s or %3$s before %0$s"));
-      CASE (5, _("expected %1$s or %2$s or %4$s or %5$s before %0$s"));
+      CASE (5, _("expected %1$s or %2$s or %3$s or %4$s before %0$s"));
 #undef CASE
     }
   location_print (loc, stderr);
