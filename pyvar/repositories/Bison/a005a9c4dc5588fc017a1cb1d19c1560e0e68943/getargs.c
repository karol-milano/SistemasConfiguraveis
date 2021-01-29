@@ -334,7 +334,8 @@ version (void)
   putc ('\n', stdout);
 
   fprintf (stdout,
-	   _("Copyright (C) %d Free Software Foundation, Inc.\n"), 2007);
+	   _("Copyright (C) %d Free Software Foundation, Inc.\n"),
+	   PACKAGE_COPYRIGHT_YEAR);
 
   fputs (_("\
 This is free software; see the source for copying conditions.  There is NO\n\
