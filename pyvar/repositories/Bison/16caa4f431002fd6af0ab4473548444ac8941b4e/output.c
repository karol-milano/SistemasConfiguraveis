@@ -325,10 +325,10 @@ merger_output (FILE *out)
   for (n = 1, p = merge_functions; p != NULL; n += 1, p = p->next)
     {
       if (p->type[0] == '\0')
-	fprintf (out, "  case %d: yyval = %s (*yy0, *yy1); break;\n",
+	fprintf (out, "  case %d: *yy0 = %s (*yy0, *yy1); break;\n",
 		 n, p->name);
       else
-	fprintf (out, "  case %d: yyval.%s = %s (*yy0, *yy1); break;\n",
+	fprintf (out, "  case %d: yy0->%s = %s (*yy0, *yy1); break;\n",
 		 n, p->type, p->name);
     }
   fputs ("]])\n\n", out);
