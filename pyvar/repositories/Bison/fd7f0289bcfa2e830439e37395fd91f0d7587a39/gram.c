@@ -69,16 +69,9 @@ rule_lhs_print (rule const *r, symbol const *previous_lhs, FILE *out)
 {
   fprintf (out, "  %3d ", r->number);
   if (previous_lhs != r->lhs)
-    {
-      fprintf (out, "%s:", r->lhs->tag);
-    }
+    fprintf (out, "%s:", r->lhs->tag);
   else
-    {
-      int n;
-      for (n = strlen (previous_lhs->tag); n > 0; --n)
-        fputc (' ', out);
-      fputc ('|', out);
-    }
+    fprintf (out, "%*s|", (int) strlen (previous_lhs->tag), "");
 }
 
 void
