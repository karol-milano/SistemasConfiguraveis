@@ -39,8 +39,6 @@ char *program_name;
 
 extern void berror PARAMS((const char *));
 
-extern char *printable_version PARAMS ((int));
-
 int
 main (int argc, char *argv[])
 {
@@ -98,23 +96,6 @@ main (int argc, char *argv[])
   exit (complain_message_count ? 1 : 0);
 }
 
-/* Return a string containing a printable version of C:
-   either C itself, or the corresponding \DDD code.  */
-
-char *
-printable_version (int c)
-{
-  static char buf[10];
-  if (c < ' ' || c >= '\177')
-    sprintf (buf, "\\%o", c);
-  else
-    {
-      buf[0] = c;
-      buf[1] = '\0';
-    }
-  return buf;
-}
-
 /* Abort for an internal error denoted by string S.  */
 
 void
