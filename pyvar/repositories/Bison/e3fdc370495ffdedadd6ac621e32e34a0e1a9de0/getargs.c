@@ -51,8 +51,9 @@ int report_flag = report_none;
 int trace_flag = trace_none;
 
 static struct bison_language const valid_languages[] = {
-  { "c", "c-skel.m4", ".c", ".h", true },
-  { "c++", "c++-skel.m4", ".cc", ".hh", true },
+  /* lang,  skeleton,       ext,     hdr,     add_tab */
+  { "c",    "c-skel.m4",    ".c",    ".h",    true },
+  { "c++",  "c++-skel.m4",  ".cc",   ".hh",   true },
   { "java", "java-skel.m4", ".java", ".java", false },
   { "", "", "", "", false }
 };
@@ -432,8 +433,7 @@ language_argmatch (char const *arg, int prio, location loc)
 
   if (prio < language_prio)
     {
-      int i;
-      for (i = 0; valid_languages[i].language[0]; i++)
+      for (int i = 0; valid_languages[i].language[0]; ++i)
         if (c_strcasecmp (arg, valid_languages[i].language) == 0)
           {
             language_prio = prio;
