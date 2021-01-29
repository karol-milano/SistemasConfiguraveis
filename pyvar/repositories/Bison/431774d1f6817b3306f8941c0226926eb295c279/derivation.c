@@ -193,9 +193,8 @@ all_spaces (const char *s)
 //
 // This function implements this.
 //
-// When COND is true, put S on OUT, preceeded by *PADDING white
-// spaces.  Otherwise add the width to *PADDING.  Return the width of
-// S.
+// When COND is true, put S on OUT, preceded by *PADDING white spaces.
+// Otherwise add the width to *PADDING.  Return the width of S.
 static int
 fputs_if (bool cond, FILE *out, int *padding, const char *s)
 {
