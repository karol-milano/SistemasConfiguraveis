@@ -49,10 +49,10 @@ print_derives (void)
       rule **rp;
       fprintf (stderr, "\t%s derives\n", symbols[i]->tag);
       for (rp = derives[i - ntokens]; *rp; ++rp)
-	{
-	  fprintf (stderr, "\t\t%3d ", (*rp)->user_number);
-	  rule_rhs_print (*rp, stderr);
-	}
+        {
+          fprintf (stderr, "\t\t%3d ", (*rp)->user_number);
+          rule_rhs_print (*rp, stderr);
+        }
     }
 
   fputs ("\n\n", stderr);
@@ -96,10 +96,10 @@ derives_compute (void)
       rule_list *p = dset[i - ntokens];
       derives[i - ntokens] = q;
       while (p)
-	{
-	  *q++ = p->value;
-	  p = p->next;
-	}
+        {
+          *q++ = p->value;
+          p = p->next;
+        }
       *q++ = NULL;
     }
 
