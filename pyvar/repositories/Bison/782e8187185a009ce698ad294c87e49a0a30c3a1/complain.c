@@ -161,3 +161,29 @@ complain_at_indent (location loc, warnings flags, unsigned *indent,
   complains (&loc, flags, message, args);
   va_end (args);
 }
+
+void
+complain_args (location const *loc, warnings w, int argc, char *argv[])
+{
+  switch (argc)
+  {
+  case 2:
+    complain (loc, w, "%s", _(argv[1]));
+    break;
+  case 3:
+    complain (loc, w, _(argv[1]), argv[2]);
+    break;
+  case 4:
+    complain (loc, w, _(argv[1]), argv[2], argv[3]);
+    break;
+  case 5:
+    complain (loc, w, _(argv[1]), argv[2], argv[3], argv[4]);
+    break;
+  case 6:
+    complain (loc, w, _(argv[1]), argv[2], argv[3], argv[4], argv[5]);
+    break;
+  default:
+    complain (loc, fatal, "too many arguments for complains");
+    break;
+  }
+}
