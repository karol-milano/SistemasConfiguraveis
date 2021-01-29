@@ -1092,8 +1092,10 @@ prepare (void)
   MUSCLE_INSERT_INT ("defines_flag", defines_flag);
 
   /* Copy definitions in directive.  */
-  obstack_1grow (&attrs_obstack, 0);
-  muscle_insert ("prologue", obstack_finish (&attrs_obstack));
+  obstack_1grow (&pre_prologue_obstack, 0);
+  obstack_1grow (&post_prologue_obstack, 0);
+  muscle_insert ("pre_prologue", obstack_finish (&pre_prologue_obstack));
+  muscle_insert ("post_prologue", obstack_finish (&post_prologue_obstack));
 
   /* Find the right skeleton file.  */
   if (!skeleton)
@@ -1131,5 +1133,6 @@ output (void)
   obstack_free (&muscle_obstack, NULL);
   obstack_free (&format_obstack, NULL);
   obstack_free (&action_obstack, NULL);
-  obstack_free (&attrs_obstack, NULL);
+  obstack_free (&pre_prologue_obstack, NULL);
+  obstack_free (&post_prologue_obstack, NULL);
 }
