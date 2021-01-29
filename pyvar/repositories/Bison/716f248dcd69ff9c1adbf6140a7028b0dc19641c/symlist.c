@@ -118,7 +118,6 @@ symbol_list_n_type_name_get (symbol_list *rp, location loc, int n)
       if (rp == NULL || rp->sym == NULL)
 	{
 	  complain_at (loc, _("invalid $ value: $%d"), n);
-	  fprintf (stderr, "\n");
 	  return NULL;
 	}
       ++i;
