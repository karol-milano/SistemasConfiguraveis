@@ -1,7 +1,7 @@
 /* Output the generated parsing program for Bison.
 
    Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002, 2003, 2004,
-   2005, 2006 Free Software Foundation, Inc.
+   2005, 2006, 2007 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -586,6 +586,15 @@ output_skeleton (void)
 static void
 prepare (void)
 {
+  /* BISON_USE_PUSH_FOR_PULL is for the test suite and should not be documented
+     for the user.  */
+  char const *use_push_for_pull_env = getenv ("BISON_USE_PUSH_FOR_PULL");
+  bool use_push_for_pull_flag = false;
+  if (use_push_for_pull_env != NULL
+      && use_push_for_pull_env[0] != '\0'
+      && 0 != strcmp (use_push_for_pull_env, "0"))
+    use_push_for_pull_flag = true;
+
   /* Flags. */
   MUSCLE_INSERT_BOOL ("debug_flag", debug_flag);
   MUSCLE_INSERT_BOOL ("defines_flag", defines_flag);
@@ -595,6 +604,7 @@ prepare (void)
   MUSCLE_INSERT_BOOL ("nondeterministic_flag", nondeterministic_parser);
   MUSCLE_INSERT_BOOL ("pull_flag", pull_parser);
   MUSCLE_INSERT_BOOL ("pure_flag", pure_parser);
+  MUSCLE_INSERT_BOOL ("use_push_for_pull_flag", use_push_for_pull_flag);
   MUSCLE_INSERT_BOOL ("push_flag", push_parser);
   MUSCLE_INSERT_BOOL ("synclines_flag", !no_lines_flag);
   MUSCLE_INSERT_BOOL ("tag_seen_flag", tag_seen);
