@@ -69,18 +69,8 @@ muscle_init (void)
   /* FIXME: there should probably be no default here, only in the
      skeletons.  */
 
-  /* Types.  */
-  MUSCLE_INSERT_STRING ("ltype", "yyltype");
-
   /* Default #line formatting.  */
   MUSCLE_INSERT_STRING ("linef", "#line %d %s\n");
-
-  /* Stack parameters.  */
-  MUSCLE_INSERT_STRING ("maxdepth", "10000");
-  MUSCLE_INSERT_STRING ("initdepth", "200");
-
-  /* C++ macros.  */
-  MUSCLE_INSERT_STRING ("name", "Parser");
 }
 
 
@@ -173,12 +163,12 @@ muscle_grow (const char *key, const char *val, const char *separator)
 void muscle_pair_list_grow (const char *muscle,
 			    const char *a1, const char *a2)
 {
-  char *val;
+  char *pair;
   obstack_fgrow2 (&muscle_obstack, "[[[%s]], [[%s]]]", a1, a2);
   obstack_1grow (&muscle_obstack, 0);
-  val = obstack_finish (&muscle_obstack);
-  muscle_grow (muscle, val, ",\n");
-  obstack_free (&muscle_obstack, val);
+  pair = obstack_finish (&muscle_obstack);
+  muscle_grow (muscle, pair, ",\n");
+  obstack_free (&muscle_obstack, pair);
 }
 
 /*-------------------------------.
