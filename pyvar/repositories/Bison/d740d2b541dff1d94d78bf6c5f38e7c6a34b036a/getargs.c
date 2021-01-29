@@ -361,7 +361,25 @@ THINGS is a list of comma separated words that can include:\n\
   `none'         disable the report\n\
 "), stdout);
 
-      printf (_("\nReport bugs to <%s>.\n"), PACKAGE_BUGREPORT);
+      putc ('\n', stdout);
+      printf (_("Report bugs to <%s>.\n"), PACKAGE_BUGREPORT);
+      printf (_("%s home page: <%s>.\n"), PACKAGE_NAME, PACKAGE_URL);
+      fputs (_("General help using GNU software: "
+               "<http://www.gnu.org/gethelp/>.\n"),
+             stdout);
+      /* Don't output this redundant message for English locales.
+         Note we still output for 'C' so that it gets included in the
+         man page.  */
+      const char *lc_messages = setlocale (LC_MESSAGES, NULL);
+      if (lc_messages && strcmp (lc_messages, "en_"))
+        /* TRANSLATORS: Replace LANG_CODE in this URL with your language
+           code <http://translationproject.org/team/LANG_CODE.html> to
+           form one of the URLs at http://translationproject.org/team/.
+           Otherwise, replace the entire URL with your translation team's
+           email address.  */
+        fputs (_("Report translation bugs to "
+                 "<http://translationproject.org/team/>.\n"), stdout);
+      fputs (_("For complete documentation, run: info bison.\n"), stdout);
     }
 
   exit (status);
