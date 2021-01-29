@@ -429,8 +429,11 @@ copy_definition (void)
 
 #if 0
   if (!no_lines_flag)
-    obstack_fgrow2 (&attrs_obstack, "#line %d %s\n",
-		    lineno, quotearg_style (c_quoting_style, infile));
+    {
+      obstack_fgrow2 (&attrs_obstack, muscle_find ("linef"),
+		      lineno, quotearg_style (c_quoting_style, 
+					      muscle_find("filename")));
+    }
 #endif
 
   after_percent = 0;
@@ -748,13 +751,16 @@ parse_union_decl (void)
 
   typed = 1;
 
+
   if (!no_lines_flag)
-    obstack_fgrow2 (&attrs_obstack, "\n#line %d %s\n",
-		    lineno, quotearg_style (c_quoting_style, 
-					    muscle_find("filename")));
+    {
+      obstack_fgrow2 (&attrs_obstack, muscle_find ("linef"),
+		      lineno, quotearg_style (c_quoting_style, 
+					      muscle_find("filename")));
+    }
   else
     obstack_1grow (&attrs_obstack, '\n');
-
+  
   obstack_sgrow (&attrs_obstack, "typedef union");
   if (defines_flag)
     obstack_sgrow (&defines_obstack, "typedef union");
@@ -1107,15 +1113,13 @@ copy_action (symbol_list *rule, int stack_offset)
   if (semantic_parser)
     stack_offset = 0;
 
-  sprintf (buf, "\ncase %d:\n", nrules);
-  obstack_grow (&action_obstack, buf, strlen (buf));
+  obstack_fgrow1 (&action_obstack, "\ncase %d:\n", nrules);
 
   if (!no_lines_flag)
     {
-      sprintf (buf, "#line %d %s\n",
-	       lineno, quotearg_style (c_quoting_style, 
-				       muscle_find ("filename")));
-      obstack_grow (&action_obstack, buf, strlen (buf));
+      obstack_fgrow2 (&action_obstack, muscle_find ("linef"),
+		      lineno, quotearg_style (c_quoting_style, 
+					      muscle_find ("filename")));
     }
   obstack_1grow (&action_obstack, '{');
 
@@ -1201,7 +1205,7 @@ copy_guard (symbol_list *rule, int stack_offset)
 
   obstack_fgrow1 (&guard_obstack, "\ncase %d:\n", nrules);
   if (!no_lines_flag)
-    obstack_fgrow2 (&guard_obstack, "#line %d %s\n",
+    obstack_fgrow2 (&guard_obstack, muscle_find ("linef"),
 		    lineno, quotearg_style (c_quoting_style,
 					    muscle_find ("filename")));
   obstack_1grow (&guard_obstack, '{');
