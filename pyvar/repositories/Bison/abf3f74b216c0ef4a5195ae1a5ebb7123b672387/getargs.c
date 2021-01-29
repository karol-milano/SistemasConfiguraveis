@@ -418,13 +418,13 @@ language_argmatch (char const *arg, int prio, location loc)
     {
       int i;
       for (i = 0; valid_languages[i].language[0]; i++)
-	if (c_strcasecmp (arg, valid_languages[i].language) == 0)
-	  {
-	    language_prio = prio;
-	    language = &valid_languages[i];
-	    return;
-	  }
-      msg = _("invalid language `%s'");
+        if (c_strcasecmp (arg, valid_languages[i].language) == 0)
+          {
+            language_prio = prio;
+            language = &valid_languages[i];
+            return;
+          }
+      msg = _("invalid language '%s'");
     }
   else if (language_prio == prio)
     msg = _("multiple language declarations are invalid");
@@ -679,9 +679,9 @@ getargs (int argc, char *argv[])
   if (argc - optind != 1)
     {
       if (argc - optind < 1)
-	error (0, 0, _("missing operand after `%s'"), argv[argc - 1]);
+        error (0, 0, _("missing operand after '%s'"), argv[argc - 1]);
       else
-	error (0, 0, _("extra operand `%s'"), argv[optind + 1]);
+        error (0, 0, _("extra operand '%s'"), argv[optind + 1]);
       usage (EXIT_FAILURE);
     }
 
