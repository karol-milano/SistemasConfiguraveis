@@ -117,7 +117,6 @@ static void record_rule_line PARAMS((void));
 static void packsymbols PARAMS((void));
 static void output_token_defines PARAMS((FILE *));
 static void packgram PARAMS((void));
-static int read_signed_integer PARAMS((FILE *));
 
 #if 0
 static int get_type PARAMS((void));
@@ -146,6 +145,10 @@ static bucket *undeftoken;
 /* Nonzero if any action or guard uses the @n construct.  */
 static int yylsp_needed;
 
+
+/*===================\
+| Low level lexing.  |
+\===================*/
 
 static void
 skip_to_char (int target)
@@ -157,15 +160,45 @@ skip_to_char (int target)
     complain (_("   Skipping to next %c"), target);
 
   do
-    c = skip_white_space();
+    c = skip_white_space ();
   while (c != target && c != EOF);
   if (c != EOF)
-    ungetc(c, finput);
+    ungetc (c, finput);
 }
 
 
-/* Dump the string from FIN to FOUT.  MATCH is the delimiter of
-   the string (either ' or ").  */
+/*---------------------------------------------------------.
+| Read a signed integer from STREAM and return its value.  |
+`---------------------------------------------------------*/
+
+static inline int
+read_signed_integer (FILE *stream)
+{
+  register int c = getc (stream);
+  register int sign = 1;
+  register int n = 0;
+
+  if (c == '-')
+    {
+      c = getc (stream);
+      sign = -1;
+    }
+
+  while (isdigit (c))
+    {
+      n = 10 * n + (c - '0');
+      c = getc (stream);
+    }
+
+  ungetc (c, stream);
+
+  return sign * n;
+}
+
+/*-------------------------------------------------------------------.
+| Dump the string from FINPUT to FOUTPUT.  MATCH is the delimiter of |
+| the string (either ' or ").                                        |
+`-------------------------------------------------------------------*/
 
 static inline void
 copy_string (FILE *fin, FILE *fout, int match)
@@ -350,7 +383,7 @@ reader (void)
   /* Write closing delimiters for actions and guards.  */
   output_trailers ();
   if (yylsp_needed)
-    fprintf ("#define YYLSP_NEEDED\n\n", ftable);
+    fputs ("#define YYLSP_NEEDED\n\n", ftable);
   /* Assign the symbols their symbol numbers.  Write #defines for the
      token symbols into FDEFINES if requested.  */
   packsymbols ();
@@ -1950,29 +1983,3 @@ packgram (void)
 
   ritem[itemno] = 0;
 }
-
-/* Read a signed integer from STREAM and return its value.  */
-
-static int
-read_signed_integer (FILE *stream)
-{
-  register int c = getc(stream);
-  register int sign = 1;
-  register int n;
-
-  if (c == '-')
-    {
-      c = getc(stream);
-      sign = -1;
-    }
-  n = 0;
-  while (isdigit(c))
-    {
-      n = 10*n + (c - '0');
-      c = getc(stream);
-    }
-
-  ungetc(c, stream);
-
-  return n * sign;
-}
