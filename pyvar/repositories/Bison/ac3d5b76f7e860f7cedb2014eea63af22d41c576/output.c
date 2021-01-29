@@ -554,14 +554,12 @@ merger_output (FILE *out)
   int n;
   merger_list* p;
   for (n = 1, p = merge_functions; p != NULL; n += 1, p = p->next)
-    {
-      if (p->type[0] == '\0')
-        fprintf (out, "  case %d: *yy0 = %s (*yy0, *yy1); break;\n",
-                 n, p->name);
-      else
-        fprintf (out, "  case %d: yy0->%s = %s (*yy0, *yy1); break;\n",
-                 n, p->type, p->name);
-    }
+    if (p->sym && p->sym->content->type_name)
+      fprintf (out, "  case %d: yy0->%s = %s (*yy0, *yy1); break;\n",
+               n, p->sym->content->type_name, p->name);
+    else
+      fprintf (out, "  case %d: *yy0 = %s (*yy0, *yy1); break;\n",
+               n, p->name);
   fputs ("]])\n\n", out);
 }
 
