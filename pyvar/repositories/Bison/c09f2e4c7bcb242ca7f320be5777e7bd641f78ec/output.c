@@ -554,12 +554,8 @@ merger_output (FILE *out)
   int n;
   merger_list* p;
   for (n = 1, p = merge_functions; p != NULL; n += 1, p = p->next)
-    if (p->sym && p->sym->content->type_name)
-      fprintf (out, "  case %d: yy0->%s = %s (*yy0, *yy1); break;\n",
-               n, p->sym->content->type_name, p->name);
-    else
-      fprintf (out, "  case %d: *yy0 = %s (*yy0, *yy1); break;\n",
-               n, p->name);
+    fprintf (out, "]b4_call_merger([%d], [%s], [%d])[\n",
+             n, p->name, p->sym->content->number);
   fputs ("]])\n\n", out);
 }
 
