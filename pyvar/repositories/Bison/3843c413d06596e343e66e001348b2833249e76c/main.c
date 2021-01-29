@@ -41,8 +41,6 @@
 /* The name this program was run with, for messages.  */
 char *program_name;
 
-extern void berror PARAMS((const char *));
-
 int
 main (int argc, char *argv[])
 {
@@ -126,12 +124,3 @@ main (int argc, char *argv[])
 
   return complain_message_count ? EXIT_FAILURE : EXIT_SUCCESS;
 }
-
-/* Abort for an internal error denoted by string S.  */
-
-void
-berror (const char *s)
-{
-  fprintf (stderr, _("%s: internal error: %s\n"), program_name, s);
-  abort ();
-}
