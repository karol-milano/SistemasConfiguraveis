@@ -538,7 +538,7 @@ static struct option const long_options[] =
 };
 
 /* Under DOS, there is no difference on the case.  This can be
-   troublesome when looking for `.tab' etc.  */
+   troublesome when looking for '.tab' etc.  */
 #ifdef MSDOS
 # define AS_FILE_NAME(File) (strlwr (File), (File))
 #else
