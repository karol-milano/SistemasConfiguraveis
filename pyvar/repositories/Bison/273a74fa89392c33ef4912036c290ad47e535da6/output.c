@@ -183,10 +183,10 @@ static unsigned int *conflict_list = NULL;
 static int conflict_list_cnt;
 static int conflict_list_free;
 
-/* TABLE_SIZE is the allocated size of both TABLE and CHECK.
-   We start with the original hard-coded value: SHRT_MAX
-   (yes, not USHRT_MAX). */
-static size_t table_size = SHRT_MAX;
+/* TABLE_SIZE is the allocated size of both TABLE and CHECK.  We start
+   with more or less the original hard-coded value (which was
+   SHRT_MAX).  */
+static size_t table_size = 32768;
 static base_t *table = NULL;
 static base_t *check = NULL;
 /* The value used in TABLE to denote explicit parse errors
@@ -216,7 +216,7 @@ table_grow (size_t desired)
   while (table_size <= desired)
     table_size *= 2;
 
-  if (trace_flag)
+  if (trace_flag & trace_resource)
     fprintf (stderr, "growing table and check from: %d to %d\n",
 	     old_size, table_size);
 
@@ -1381,7 +1381,7 @@ output_skeleton (void)
   m4_invoke (tempfile);
 
   /* If `debugging', keep this file alive. */
-  if (!trace_flag)
+  if (!(trace_flag & trace_tools))
     unlink (tempfile);
 
   free (tempfile);
