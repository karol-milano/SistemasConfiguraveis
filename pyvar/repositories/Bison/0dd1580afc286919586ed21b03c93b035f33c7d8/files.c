@@ -33,8 +33,9 @@ const char *base_name PARAMS ((char const *name));
 FILE *finput = NULL;
 
 struct obstack action_obstack;
-struct obstack attrs_obstack;
 struct obstack output_obstack;
+struct obstack pre_prologue_obstack;
+struct obstack post_prologue_obstack;
 
 /* Initializing some values below (such SPEC_NAME_PREFIX to `yy') is
    tempting, but don't do that: for the time being our handling of the
