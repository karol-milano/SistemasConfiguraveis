@@ -360,6 +360,8 @@ FEATURE is a list of comma separated words that can include:\n\
       fputs (_("General help using GNU software: "
                "<http://www.gnu.org/gethelp/>.\n"),
              stdout);
+
+#if (defined __GLIBC__ && __GLIBC__ >= 2) && !defined __UCLIBC__
       /* Don't output this redundant message for English locales.
          Note we still output for 'C' so that it gets included in the
          man page.  */
@@ -372,6 +374,7 @@ FEATURE is a list of comma separated words that can include:\n\
            email address.  */
         fputs (_("Report translation bugs to "
                  "<http://translationproject.org/team/>.\n"), stdout);
+#endif
       fputs (_("For complete documentation, run: info bison.\n"), stdout);
     }
 
