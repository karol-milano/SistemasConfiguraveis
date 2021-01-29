@@ -216,8 +216,7 @@ static void
 print_reduction (FILE *out, int level, char const *lookahead,
                  rule *r, bool enabled)
 {
-  const bool final = r->lhs->symbol == acceptsymbol;
-  if (final)
+  if (rule_is_initial (r))
     xml_printf (out, level,
                 "<reduction symbol=\"%s\" rule=\"accept\" enabled=\"%s\"/>",
                 xml_escape (lookahead),
