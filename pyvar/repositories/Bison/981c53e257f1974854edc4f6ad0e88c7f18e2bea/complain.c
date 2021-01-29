@@ -31,6 +31,7 @@
 
 warnings warnings_flag =
   Wconflicts_sr | Wconflicts_rr | Wdeprecated  | Wother;
+warnings errors_flag;
 
 bool complaint_issued;
 static unsigned *indent_ptr = 0;
@@ -55,7 +56,9 @@ warnings_print_categories (warnings warn_flags)
       for (i = 0; i < ARRAY_CARDINALITY (warn_names); ++i)
         if (warn_flags & 1 << i)
           {
-            fprintf (stderr, "%s-W%s", any ? ", " : " [", warn_names[i]);
+            bool err = warn_flags & errors_flag;
+            fprintf (stderr, "%s-W", any ? ", " : " [");
+            fprintf (stderr, "%s%s", err ? "error=" : "" , warn_names[i]);
             any = true;
           }
       if (any)
@@ -139,14 +142,16 @@ complains (const location *loc, warnings flags, const char *message,
         }
       else if (warnings_flag & Wyacc)
         {
-          set_warning_issued ();
-          error_message (loc, flags, _("warning"), message, args);
+          char* severity = Wyacc & errors_flag ? _("error") : _("warning");
+          set_warning_issued (Wyacc);
+          error_message (loc, flags, severity, message, args);
         }
     }
   else if (warnings_flag & flags)
     {
-      set_warning_issued ();
-      error_message (loc, flags, _("warning"), message, args);
+      char* severity = flags & errors_flag ? _("error") : _("warning");
+      set_warning_issued (flags);
+      error_message (loc, flags, severity, message, args);
     }
 }
 
@@ -184,10 +189,10 @@ void complain_at_indent (location loc, warnings flags, unsigned *indent,
 `--------------------------------*/
 
 void
-set_warning_issued (void)
+set_warning_issued (warnings warning)
 {
   static bool warning_issued = false;
-  if (!warning_issued && (warnings_flag & Werror))
+  if (!warning_issued && (warning & warnings_flag & errors_flag))
     {
       fprintf (stderr, "%s: warnings being treated as errors\n", program_name);
       complaint_issued = true;
