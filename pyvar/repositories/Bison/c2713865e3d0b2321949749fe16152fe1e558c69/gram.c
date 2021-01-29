@@ -53,6 +53,11 @@ int pure_parser;
 
 int error_token_number;
 
+
+/*------------------------.
+| Dump RITEM for traces.  |
+`------------------------*/
+
 void
 ritem_print (FILE *out)
 {
@@ -65,3 +70,32 @@ ritem_print (FILE *out)
       fprintf (out, "  (rule %d)\n", -ritem[i]);
   fputs ("\n\n", out);
 }
+
+
+/*------------------------------------------.
+| Return the size of the longest rule RHS.  |
+`------------------------------------------*/
+
+size_t
+ritem_longest_rhs (void)
+{
+  short *itemp;
+  int length;
+  int max;
+
+  length = 0;
+  max = 0;
+  for (itemp = ritem; *itemp; itemp++)
+    if (*itemp > 0)
+      {
+	length++;
+      }
+    else
+      {
+	if (length > max)
+	  max = length;
+	length = 0;
+      }
+
+  return max;
+}
