@@ -643,7 +643,7 @@ yysymbol_name (yysymbol_kind_t yysymbol)
 {
   static const char *const yy_sname[] =
   {
-  N_("end of file"), "error", "$undefined", N_("string"),
+  N_("end of file"), "error", N_("invalid token"), N_("string"),
   N_("translatable string"), "%token", "%nterm", "%type", "%destructor",
   "%printer", "%left", "%right", "%nonassoc", "%precedence", "%prec",
   "%dprec", "%merge", "%code", "%default-prec", "%define", "%defines",
