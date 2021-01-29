@@ -66,11 +66,12 @@ main (int argc, char *argv[])
   {
     char *cp = NULL;
     char const *localedir = relocate2 (LOCALEDIR, &cp);
-    (void) bindtextdomain (PACKAGE, localedir);
-    (void) bindtextdomain ("bison-runtime", localedir);
+    bindtextdomain ("bison", localedir);
+    bindtextdomain ("bison-gnulib", localedir);
+    bindtextdomain ("bison-runtime", localedir);
     free (cp);
   }
-  (void) textdomain (PACKAGE);
+  textdomain ("bison");
 
   {
     char const *cp = getenv ("LC_CTYPE");
