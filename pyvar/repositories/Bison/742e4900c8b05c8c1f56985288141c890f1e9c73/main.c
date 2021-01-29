@@ -110,7 +110,7 @@ main (int argc, char *argv[])
   timevar_pop (TV_LALR);
 
   /* Find and record any conflicts: places where one token of
-     look-ahead is not enough to disambiguate the parsing.  In file
+     lookahead is not enough to disambiguate the parsing.  In file
      conflicts.  Also resolve s/r conflicts based on precedence
      declarations.  */
   timevar_push (TV_CONFLICTS);
@@ -150,7 +150,7 @@ main (int argc, char *argv[])
   if (complaint_issued)
     goto finish;
 
-  /* Look-ahead tokens are no longer needed. */
+  /* Lookahead tokens are no longer needed. */
   timevar_push (TV_FREE);
   lalr_free ();
   timevar_pop (TV_FREE);
