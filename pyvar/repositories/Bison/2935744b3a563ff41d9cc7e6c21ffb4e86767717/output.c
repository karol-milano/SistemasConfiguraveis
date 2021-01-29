@@ -291,7 +291,6 @@ static void
 type_names_output (FILE *out)
 {
   int i;
-  char const *sep = "";
 
   fputs ("m4_define([b4_type_names],\n[", out);
   for (i = 0; i < nsyms; ++i)
