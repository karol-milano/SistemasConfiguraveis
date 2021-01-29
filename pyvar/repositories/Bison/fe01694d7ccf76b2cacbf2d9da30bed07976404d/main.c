@@ -71,8 +71,7 @@ char *argv[];
 
   /* Find and record any conflicts: places where one token of lookahead is not
      enough to disambiguate the parsing.  In file conflicts.
-     Currently this does not do anything to resolve them;
-     the trivial form of conflict resolution that exists is done in output.  */
+     Also resolve s/r conflicts based on precedence declarations.  */
   initialize_conflicts();
 
   /* print information about results, if requested.  In file print. */
