@@ -66,10 +66,19 @@ int report_flag = report_none;
 int trace_flag = trace_none;
 int warnings_flag = warnings_none;
 
+static struct bison_language const valid_languages[] = {
+  { "c", "c-skel.m4", ".c", ".h", true },
+  { "c++", "c++-skel.m4", ".cc", ".hh", true },
+  { "", "", "", "", false }
+};
+
+static int skeleton_prio = 2;
 const char *skeleton = NULL;
+static int language_prio = 2;
+struct bison_language const *language = &valid_languages[0];
 const char *include = NULL;
 
-extern char *program_name;
+char *program_name;
 
 
 /** Decode an option's set of keys.
@@ -323,12 +332,63 @@ warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n\
 }
 
 
+/*-------------------------------------.
+| --skeleton and --language handling.  |
+`--------------------------------------*/
+
+void
+skeleton_arg (char const *arg, int prio, location const *loc)
+{
+  if (prio < skeleton_prio)
+    {
+      skeleton_prio = prio;
+      skeleton = arg;
+    }
+  else if (prio == skeleton_prio)
+    {
+      char const *msg =
+	_("multiple skeleton declarations are invalid");
+      if (loc)
+	complain_at (*loc, msg);
+      else
+	complain (msg);
+    }
+}
+
+void
+language_argmatch (char const *arg, int prio, location const *loc)
+{
+  char const *msg;
+
+  if (prio < language_prio)
+    {
+      int i;
+      for (i = 0; valid_languages[i].language[0]; i++)
+	if (strcasecmp (arg, valid_languages[i].language) == 0)
+	  {
+	    language_prio = prio;
+	    language = &valid_languages[i];
+	    return;
+	  }
+      msg = _("invalid language `%s'");
+    }
+  else if (language_prio == prio)
+    msg = _("multiple language declarations are invalid");
+  else
+    return;
+
+  if (loc)
+    complain_at (*loc, msg, arg);
+  else
+    complain (msg, arg);
+}
+
 /*----------------------.
 | Process the options.  |
 `----------------------*/
 
 /* Shorts options.  */
-static char const short_options[] = "yvegdhr:ltknVo:b:p:S:T::W";
+static char const short_options[] = "yvegdhr:L:ltknVo:b:p:S:T::W";
 
 /* Values for long options that do not have single-letter equivalents.  */
 enum
@@ -374,6 +434,7 @@ static struct option const long_options[] =
   { "no-parser",      no_argument,               0,   'n' },
   { "raw",            no_argument,               0,     0 },
   { "skeleton",       required_argument,         0,   'S' },
+  { "language",       required_argument,         0,   'L' },
   { "token-table",    no_argument,               0,   'k' },
 
   {0, 0, 0, 0}
@@ -414,8 +475,12 @@ getargs (int argc, char *argv[])
       case 'h':
 	usage (EXIT_SUCCESS);
 
+      case 'L':
+	language_argmatch (optarg, 0, NULL);
+	break;
+
       case 'S':
-	skeleton = AS_FILE_NAME (optarg);
+	skeleton_arg (AS_FILE_NAME (optarg), 0, NULL);
 	break;
 
       case 'I':
