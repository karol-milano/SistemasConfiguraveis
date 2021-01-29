@@ -585,7 +585,7 @@ command_line_location (void)
    request.  This is consistent with the way GCC and Clang behave.  */
 
 static void
-getargs_colors (int argc _GL_UNUSED, char *argv[] _GL_UNUSED)
+getargs_colors (int argc, char *argv[])
 {
   for (int i = 1; i < argc; i++)
     {
