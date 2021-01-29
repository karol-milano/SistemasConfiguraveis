@@ -81,8 +81,8 @@ extern char *program_name;
  *
  *  The special value 0 resets the flags to 0.
  */
-static int
-flags_argmatch (const char *option, 
+static void
+flags_argmatch (const char *option,
 		const char * const keys[], const int values[],
 		int *flags, char *args)
 {
@@ -103,7 +103,7 @@ flags_argmatch (const char *option,
     *flags = ~0;
 }
 
-/** Decode a set of sub arguments. 
+/** Decode a set of sub arguments.
  *
  *  \param FlagName  the flag familly to update.
  *  \param args      the effective sub arguments to decode.
