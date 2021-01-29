@@ -120,11 +120,9 @@ error_message (const location *loc, warnings flags, const char *prefix,
 
 /** Raise a complaint. That can be a fatal error, a complaint or just a
     warning.  */
-
 static inline void
 complains (const location *loc, warnings flags, const char *message,
            va_list args)
-
 {
   const char* prefix =
     flags & fatal ? _("fatal error")
@@ -159,24 +157,26 @@ complain_indent (location const *loc, warnings flags, unsigned *indent,
 }
 
 void
-complain_args (location const *loc, warnings w, int argc, char *argv[])
+complain_args (location const *loc, warnings w, unsigned *indent,
+               int argc, char *argv[])
 {
   switch (argc)
   {
   case 2:
-    complain (loc, w, "%s", _(argv[1]));
+    complain_indent (loc, w, indent, "%s", _(argv[1]));
     break;
   case 3:
-    complain (loc, w, _(argv[1]), argv[2]);
+    complain_indent (loc, w, indent, _(argv[1]), argv[2]);
     break;
   case 4:
-    complain (loc, w, _(argv[1]), argv[2], argv[3]);
+    complain_indent (loc, w, indent, _(argv[1]), argv[2], argv[3]);
     break;
   case 5:
-    complain (loc, w, _(argv[1]), argv[2], argv[3], argv[4]);
+    complain_indent (loc, w, indent, _(argv[1]), argv[2], argv[3], argv[4]);
     break;
   case 6:
-    complain (loc, w, _(argv[1]), argv[2], argv[3], argv[4], argv[5]);
+    complain_indent (loc, w, indent, _(argv[1]), argv[2], argv[3], argv[4],
+                     argv[5]);
     break;
   default:
     complain (loc, fatal, "too many arguments for complains");
