@@ -90,7 +90,7 @@ Name (char const *name,                                                 \
                                                                         \
   lmin = min;                                                           \
   lmax = max;                                                           \
-  /* Build `NAME_min' and `NAME_max' in the obstack. */                 \
+  /* Build 'NAME_min' and 'NAME_max' in the obstack. */                 \
   obstack_printf (&format_obstack, "%s_min", name);                     \
   MUSCLE_INSERT_LONG_INT (obstack_finish0 (&format_obstack), lmin);     \
   obstack_printf (&format_obstack, "%s_max", name);                     \
