@@ -124,16 +124,13 @@ print_errs (FILE *out, state_t *state)
   errs *errp = state->errs;
   int i;
 
-  if (!errp)
-    return;
-
   for (i = 0; i < errp->nerrs; ++i)
     if (errp->errs[i])
       fprintf (out, _("    %-4s\terror (nonassociative)\n"),
 	       tags[errp->errs[i]]);
 
   if (i > 0)
-	fputc ('\n', out);
+    fputc ('\n', out);
 }
 
 
@@ -192,10 +189,9 @@ print_reductions (FILE *out, state_t *state)
 	SETBIT (shiftset, SHIFT_SYMBOL (shiftp, i));
       }
 
-  if (errp)
-    for (i = 0; i < errp->nerrs; i++)
-      if (errp->errs[i])
-	SETBIT (shiftset, errp->errs[i]);
+  for (i = 0; i < errp->nerrs; i++)
+    if (errp->errs[i])
+      SETBIT (shiftset, errp->errs[i]);
 
   if (state->nlookaheads == 1 && !nodefault)
     {
