@@ -527,9 +527,9 @@ while (0)
      fprintf (File, "%d.%d-%d.%d",			\
               (Loc).first_line, (Loc).first_column,	\
               (Loc).last_line,  (Loc).last_column)
+# else
+#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
 # endif
-#else
-# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
 #endif
 
 
