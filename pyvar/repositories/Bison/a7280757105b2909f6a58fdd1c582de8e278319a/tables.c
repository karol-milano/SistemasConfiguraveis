@@ -290,7 +290,7 @@ action_row (state *s)
 
       /* Do not use any default reduction if there is a shift for
          error */
-      if (sym == errtoken->number)
+      if (sym == errtoken->content->number)
         nodefault = true;
     }
 
@@ -300,7 +300,7 @@ action_row (state *s)
   for (i = 0; i < errp->num; i++)
     {
       symbol *sym = errp->symbols[i];
-      actrow[sym->number] = ACTION_NUMBER_MINIMUM;
+      actrow[sym->content->number] = ACTION_NUMBER_MINIMUM;
     }
 
   /* Turn off default reductions where requested by the user.  See
