@@ -89,7 +89,7 @@ print_core (FILE *out, int level, state *s)
           if (reds->lookahead_tokens && red != -1)
             {
               xml_printf (out, level + 1,
-                          "<item rule-number=\"%d\" point=\"%d\">",
+                          "<item rule-number=\"%d\" dot=\"%d\">",
                           r->number, sp1 - sp);
               state_rule_lookahead_tokens_print_xml (s, r,
                                                      out, level + 2);
@@ -100,7 +100,7 @@ print_core (FILE *out, int level, state *s)
 
       if (!printed)
         xml_printf (out, level + 1,
-                    "<item rule-number=\"%d\" point=\"%d\"/>",
+                    "<item rule-number=\"%d\" dot=\"%d\"/>",
                     r->number,
                     sp1 - sp);
     }
