@@ -162,21 +162,21 @@ complain_args (location const *loc, warnings w, unsigned *indent,
 {
   switch (argc)
   {
+  case 1:
+    complain_indent (loc, w, indent, "%s", _(argv[0]));
+    break;
   case 2:
-    complain_indent (loc, w, indent, "%s", _(argv[1]));
+    complain_indent (loc, w, indent, _(argv[0]), argv[1]);
     break;
   case 3:
-    complain_indent (loc, w, indent, _(argv[1]), argv[2]);
+    complain_indent (loc, w, indent, _(argv[0]), argv[1], argv[2]);
     break;
   case 4:
-    complain_indent (loc, w, indent, _(argv[1]), argv[2], argv[3]);
+    complain_indent (loc, w, indent, _(argv[0]), argv[1], argv[2], argv[3]);
     break;
   case 5:
-    complain_indent (loc, w, indent, _(argv[1]), argv[2], argv[3], argv[4]);
-    break;
-  case 6:
-    complain_indent (loc, w, indent, _(argv[1]), argv[2], argv[3], argv[4],
-                     argv[5]);
+    complain_indent (loc, w, indent, _(argv[0]), argv[1], argv[2], argv[3],
+                     argv[4]);
     break;
   default:
     complain (loc, fatal, "too many arguments for complains");
