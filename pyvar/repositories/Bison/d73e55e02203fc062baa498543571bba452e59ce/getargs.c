@@ -499,7 +499,7 @@ static struct option const long_options[] =
 /* Build a location for the current command line argument. */
 static
 location
-command_line_location()
+command_line_location (void)
 {
   location res;
   /* "<command line>" is used in GCC's messages about -D. */
