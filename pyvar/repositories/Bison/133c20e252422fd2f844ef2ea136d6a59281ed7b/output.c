@@ -122,6 +122,11 @@ static short *state_count = NULL;
 static short *order = NULL;
 static short *base = NULL;
 static short *pos = NULL;
+
+/* TABLE_SIZE is the allocated size of both TABLE and CHECK.
+   We start with the original hard-coded value: SHRT_MAX
+   (yes, not USHRT_MAX). */
+static size_t table_size = SHRT_MAX;
 static short *table = NULL;
 static short *check = NULL;
 static int lowzero;
@@ -133,6 +138,35 @@ static struct obstack format_obstack;
 int error_verbose = 0;
 
 
+/*----------------------------------------------------------------.
+| If TABLE (and CHECK) appear to be small to be addressed at      |
+| DESIRED, grow them.  Note that TABLE[DESIRED] is to be used, so |
+| the desired size is at least DESIRED + 1.                       |
+`----------------------------------------------------------------*/
+
+static void
+table_grow (size_t desired)
+{
+  size_t old_size = table_size;
+
+  while (table_size <= desired)
+    table_size *= 2;
+
+  if (trace_flag)
+    fprintf (stderr, "growing table and check from: %d to %d\n",
+	     old_size, table_size);
+
+  table = XREALLOC (table, short, table_size);
+  check = XREALLOC (check, short, table_size);
+
+  for (/* Nothing. */; old_size < table_size; ++old_size)
+    {
+      table[old_size] = 0;
+      check[old_size] = -1;
+    }
+}
+
+
 /*------------------------------------------------------------------.
 | Create a function NAME which Format the FIRST and then            |
 | TABLE_DATA[BEGIN..END[ (of TYPE) into OOUT, and return the number |
@@ -768,8 +802,6 @@ matching_state (int vector)
   return -1;
 }
 
-/* FIXME: For the time being, best approximation... */
-#define MAXTABLE SHRT_MAX
 
 static int
 pack_vector (int vector)
@@ -783,7 +815,7 @@ pack_vector (int vector)
 
   assert (t);
 
-  for (j = lowzero - from[0]; j < MAXTABLE; j++)
+  for (j = lowzero - from[0]; j < (int) table_size; j++)
     {
       int k;
       int ok = 1;
@@ -791,8 +823,8 @@ pack_vector (int vector)
       for (k = 0; ok && k < t; k++)
 	{
 	  loc = j + from[k];
-	  if (loc > MAXTABLE)
-	    fatal (_("maximum table size (%d) exceeded"), MAXTABLE);
+	  if (loc > (int) table_size)
+	    table_grow (loc);
 
 	  if (table[loc] != 0)
 	    ok = 0;
@@ -835,8 +867,8 @@ pack_table (void)
 
   base = XCALLOC (short, nvectors);
   pos = XCALLOC (short, nentries);
-  table = XCALLOC (short, MAXTABLE);
-  check = XCALLOC (short, MAXTABLE);
+  table = XCALLOC (short, table_size);
+  check = XCALLOC (short, table_size);
 
   lowzero = 0;
   high = 0;
@@ -844,7 +876,7 @@ pack_table (void)
   for (i = 0; i < nvectors; i++)
     base[i] = SHRT_MIN;
 
-  for (i = 0; i < MAXTABLE; i++)
+  for (i = 0; i < (int) table_size; i++)
     check[i] = -1;
 
   for (i = 0; i < nentries; i++)
