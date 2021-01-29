@@ -54,6 +54,7 @@ static struct bison_language const valid_languages[] = {
   /* lang,  skeleton,       ext,     hdr,     add_tab */
   { "c",    "c-skel.m4",    ".c",    ".h",    true },
   { "c++",  "c++-skel.m4",  ".cc",   ".hh",   true },
+  { "d",    "d-skel.m4",    ".d",    ".d",    false },
   { "java", "java-skel.m4", ".java", ".java", false },
   { "", "", "", "", false }
 };
