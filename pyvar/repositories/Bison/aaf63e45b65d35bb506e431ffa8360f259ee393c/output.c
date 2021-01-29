@@ -70,7 +70,7 @@ Name (char const *name,							\
   int i;								\
   int j = 1;								\
 									\
-  obstack_fgrow1 (&format_obstack, "%6d", first);			\
+  obstack_printf (&format_obstack, "%6d", first);			\
   for (i = begin; i < end; ++i)						\
     {									\
       obstack_1grow (&format_obstack, ',');				\
@@ -81,7 +81,7 @@ Name (char const *name,							\
 	}								\
       else								\
 	++j;								\
-      obstack_fgrow1 (&format_obstack, "%6d", table_data[i]);		\
+      obstack_printf (&format_obstack, "%6d", table_data[i]);		\
       if (table_data[i] < min)						\
 	min = table_data[i];						\
       if (max < table_data[i])						\
@@ -93,10 +93,10 @@ Name (char const *name,							\
   lmin = min;								\
   lmax = max;								\
   /* Build `NAME_min' and `NAME_max' in the obstack. */			\
-  obstack_fgrow1 (&format_obstack, "%s_min", name);			\
+  obstack_printf (&format_obstack, "%s_min", name);			\
   obstack_1grow (&format_obstack, 0);					\
   MUSCLE_INSERT_LONG_INT (obstack_finish (&format_obstack), lmin);	\
-  obstack_fgrow1 (&format_obstack, "%s_max", name);			\
+  obstack_printf (&format_obstack, "%s_max", name);			\
   obstack_1grow (&format_obstack, 0);					\
   MUSCLE_INSERT_LONG_INT (obstack_finish (&format_obstack), lmax);	\
 }
