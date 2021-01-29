@@ -567,33 +567,6 @@ token_actions (void)
 }
 
 
-static void
-free_shifts (void)
-{
-  shifts *sp, *sptmp;	/* JF derefrenced freed ptr */
-
-  for (sp = first_shift; sp; sp = sptmp)
-    {
-      sptmp = sp->next;
-      XFREE (sp);
-    }
-}
-
-
-static void
-free_reductions (void)
-{
-  reductions *rp, *rptmp;	/* JF fixed freed ptr */
-
-  for (rp = first_reduction; rp; rp = rptmp)
-    {
-      rptmp = rp->next;
-      XFREE (rp);
-    }
-}
-
-
-
 static void
 save_column (int symbol, int default_state)
 {
@@ -946,8 +919,8 @@ output_actions (void)
   width = XCALLOC (short, nvectors);
 
   token_actions ();
-  free_shifts ();
-  free_reductions ();
+  LIST_FREE (shifts, first_shift);
+  LIST_FREE (reductions, first_reduction);
   XFREE (LA);
   XFREE (LAruleno);
 
@@ -1045,17 +1018,6 @@ output_master_parser (void)
 }
 
 
-static void
-free_itemsets (void)
-{
-  core *cp, *cptmp;
-  for (cp = first_state; cp; cp = cptmp)
-    {
-      cptmp = cp->next;
-      XFREE (cp);
-    }
-}
-
 /* FIXME. */
 
 #define MUSCLE_INSERT_INT(Key, Value)				\
@@ -1115,7 +1077,7 @@ output (void)
 {
   obstack_init (&output_obstack);
 
-  free_itemsets ();
+  LIST_FREE (core, first_state);
 
   output_token_translations ();
   output_gram ();
