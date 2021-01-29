@@ -435,7 +435,6 @@ error_message (const location *loc, warnings flags, severity sever,
         *indent_ptr = pos;
       else if (*indent_ptr > pos)
         fprintf (stderr, "%*s", *indent_ptr - pos, "");
-      indent_ptr = NULL;
     }
 
   const char* style = severity_style (sever);
@@ -506,6 +505,7 @@ complain_indent (location const *loc, warnings flags, unsigned *indent,
   va_start (args, message);
   complains (loc, flags, message, args);
   va_end (args);
+  indent_ptr = NULL;
 }
 
 void
