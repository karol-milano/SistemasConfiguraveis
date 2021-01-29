@@ -99,11 +99,6 @@ main (int argc, char *argv[])
   lalr ();
   timevar_pop (TV_LALR);
 
-  timevar_push (TV_FREE);
-  nullable_free ();
-  derives_free ();
-  timevar_pop (TV_FREE);
-
   /* Find and record any conflicts: places where one token of
      lookahead is not enough to disambiguate the parsing.  In file
      conflicts.  Also resolve s/r conflicts based on precedence
@@ -153,6 +148,8 @@ main (int argc, char *argv[])
   timevar_pop (TV_PARSER);
 
   timevar_push (TV_FREE);
+  nullable_free ();
+  derives_free ();
   tables_free ();
   states_free ();
   reduce_free ();
