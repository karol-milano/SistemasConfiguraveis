@@ -604,7 +604,7 @@ syntax_error (location loc,
   const char *format = NULL;
   switch (argc)
     {
-# define CASE(N, S)                         \
+#define CASE(N, S)                          \
       case N:                               \
         format = S;                         \
         break
@@ -615,7 +615,7 @@ syntax_error (location loc,
       CASE (3, _("expected %1$s or %2$s before %0$s"));
       CASE (4, _("expected %1$s or %2$s or %3$s before %0$s"));
       CASE (5, _("expected %1$s or %2$s or %4$s or %5$s before %0$s"));
-# undef CASE
+#undef CASE
     }
   location_print (loc, stderr);
   fputs (": ", stderr);
