@@ -65,40 +65,39 @@ print_core (FILE *out, int level, state *s)
   sitems = itemset;
   snritems = nitemset;
 
-  if (!snritems) {
-    xml_puts (out, level, "<itemset/>");
-    return;
-  }
+  if (!snritems)
+    {
+      xml_puts (out, level, "<itemset/>");
+      return;
+    }
 
   xml_puts (out, level, "<itemset>");
 
   for (i = 0; i < snritems; i++)
     {
       bool printed = false;
-      item_number *sp;
-      item_number *sp1;
-      rule_number r;
-
-      sp1 = sp = ritem + sitems[i];
+      item_number *sp1 = ritem + sitems[i];
+      item_number *sp = sp1;
+      rule *r;
 
-      while (*sp >= 0)
+      while (0 <= *sp)
         sp++;
 
-      r = item_number_as_rule_number (*sp);
-      sp = rules[r].rhs;
+      r = &rules[item_number_as_rule_number (*sp)];
+      sp = r->rhs;
 
       /* Display the lookahead tokens?  */
       if (item_number_is_rule_number (*sp1))
         {
           reductions *reds = s->reductions;
-          int red = state_reduction_find (s, &rules[r]);
+          int red = state_reduction_find (s, r);
           /* Print item with lookaheads if there are. */
           if (reds->lookahead_tokens && red != -1)
             {
               xml_printf (out, level + 1,
                           "<item rule-number=\"%d\" point=\"%d\">",
-                          rules[r].number, sp1 - sp);
-              state_rule_lookahead_tokens_print_xml (s, &rules[r],
+                          r->number, sp1 - sp);
+              state_rule_lookahead_tokens_print_xml (s, r,
                                                      out, level + 2);
               xml_puts (out, level + 1, "</item>");
               printed = true;
@@ -106,12 +105,10 @@ print_core (FILE *out, int level, state *s)
         }
 
       if (!printed)
-        {
-          xml_printf (out, level + 1,
-                      "<item rule-number=\"%d\" point=\"%d\"/>",
-                      rules[r].number,
-                      sp1 - sp);
-        }
+        xml_printf (out, level + 1,
+                    "<item rule-number=\"%d\" point=\"%d\"/>",
+                    r->number,
+                    sp1 - sp);
     }
   xml_puts (out, level, "</itemset>");
 }
@@ -136,10 +133,11 @@ print_transitions (state *s, FILE *out, int level)
       }
 
   /* Nothing to report. */
-  if (!n) {
-    xml_puts (out, level, "<transitions/>");
-    return;
-  }
+  if (!n)
+    {
+      xml_puts (out, level, "<transitions/>");
+      return;
+    }
 
   /* Report lookahead tokens and shifts.  */
   xml_puts (out, level, "<transitions>");
@@ -190,10 +188,11 @@ print_errs (FILE *out, int level, state *s)
       count = true;
 
   /* Nothing to report. */
-  if (!count) {
-    xml_puts (out, level, "<errors/>");
-    return;
-  }
+  if (!count)
+    {
+      xml_puts (out, level, "<errors/>");
+      return;
+    }
 
   /* Report lookahead tokens and errors.  */
   xml_puts (out, level, "<errors>");
@@ -287,10 +286,11 @@ print_reductions (FILE *out, int level, state *s)
       }
 
   /* Nothing to report. */
-  if (!report) {
-    xml_puts (out, level, "<reductions/>");
-    return;
-  }
+  if (!report)
+    {
+      xml_puts (out, level, "<reductions/>");
+      return;
+    }
 
   xml_puts (out, level, "<reductions>");
 
