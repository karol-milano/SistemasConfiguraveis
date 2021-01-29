@@ -216,16 +216,17 @@ static void
 print_reduction (FILE *out, int level, char const *lookahead,
                  rule *r, bool enabled)
 {
-  if (r->number)
+  const bool final = r->lhs->symbol == acceptsymbol;
+  if (final)
     xml_printf (out, level,
-                "<reduction symbol=\"%s\" rule=\"%d\" enabled=\"%s\"/>",
+                "<reduction symbol=\"%s\" rule=\"accept\" enabled=\"%s\"/>",
                 xml_escape (lookahead),
-                r->number,
                 enabled ? "true" : "false");
   else
     xml_printf (out, level,
-                "<reduction symbol=\"%s\" rule=\"accept\" enabled=\"%s\"/>",
+                "<reduction symbol=\"%s\" rule=\"%d\" enabled=\"%s\"/>",
                 xml_escape (lookahead),
+                r->number,
                 enabled ? "true" : "false");
 }
 
