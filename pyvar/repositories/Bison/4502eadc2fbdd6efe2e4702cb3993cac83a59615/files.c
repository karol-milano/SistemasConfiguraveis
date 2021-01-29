@@ -137,7 +137,7 @@ xfclose (FILE *ptr)
 `------------------------------------------------------------------*/
 
 /* In the string S, replace all characters FROM by TO.  */
-static char *
+static void
 tr (char *s, char from, char to)
 {
   for (; *s; s++)
