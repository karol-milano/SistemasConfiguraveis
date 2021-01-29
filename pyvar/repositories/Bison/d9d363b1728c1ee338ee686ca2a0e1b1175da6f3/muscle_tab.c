@@ -173,12 +173,12 @@ muscle_grow (const char *key, const char *val, const char *separator)
 void muscle_pair_list_grow (const char *muscle,
 			    const char *a1, const char *a2)
 {
-  char *value;
+  char *val;
   obstack_fgrow2 (&muscle_obstack, "[[[%s]], [[%s]]]", a1, a2);
   obstack_1grow (&muscle_obstack, 0);
-  value = obstack_finish (&muscle_obstack);
-  muscle_grow (muscle, value, ",\n");
-  obstack_free (&muscle_obstack, value);
+  val = obstack_finish (&muscle_obstack);
+  muscle_grow (muscle, val, ",\n");
+  obstack_free (&muscle_obstack, val);
 }
 
 /*-------------------------------.
