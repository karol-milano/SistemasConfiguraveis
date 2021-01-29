@@ -225,6 +225,7 @@ warnings_argmatch (char *args)
         }
 }
 
+/* Color style for this type of message.  */
 static const char*
 severity_style (severity s)
 {
@@ -242,6 +243,7 @@ severity_style (severity s)
   abort ();
 }
 
+/* Prefix for this type of message.  */
 static const char*
 severity_prefix (severity s)
 {
