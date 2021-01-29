@@ -31,7 +31,6 @@
 
 warnings warnings_flag =
   Wconflicts_sr | Wconflicts_rr | Wdeprecated  | Wother;
-warnings errors_flag;
 
 bool complaint_issued;
 static unsigned *indent_ptr = 0;
@@ -56,9 +55,7 @@ warnings_print_categories (warnings warn_flags)
       for (i = 0; i < ARRAY_CARDINALITY (warn_names); ++i)
         if (warn_flags & 1 << i)
           {
-            bool err = warn_flags & errors_flag;
-            fprintf (stderr, "%s-W", any ? ", " : " [");
-            fprintf (stderr, "%s%s", err ? "error=" : "" , warn_names[i]);
+            fprintf (stderr, "%s-W%s", any ? ", " : " [", warn_names[i]);
             any = true;
           }
       if (any)
@@ -142,16 +139,14 @@ complains (const location *loc, warnings flags, const char *message,
         }
       else if (warnings_flag & Wyacc)
         {
-          char* severity = Wyacc & errors_flag ? _("error") : _("warning");
-          set_warning_issued (Wyacc);
-          error_message (loc, flags, severity, message, args);
+          set_warning_issued ();
+          error_message (loc, flags, _("warning"), message, args);
         }
     }
   else if (warnings_flag & flags)
     {
-      char* severity = flags & errors_flag ? _("error") : _("warning");
-      set_warning_issued (flags);
-      error_message (loc, flags, severity, message, args);
+      set_warning_issued ();
+      error_message (loc, flags, _("warning"), message, args);
     }
 }
 
@@ -189,10 +184,10 @@ void complain_at_indent (location loc, warnings flags, unsigned *indent,
 `--------------------------------*/
 
 void
-set_warning_issued (warnings warning)
+set_warning_issued (void)
 {
   static bool warning_issued = false;
-  if (!warning_issued && (warning & warnings_flag & errors_flag))
+  if (!warning_issued && (warnings_flag & Werror))
     {
       fprintf (stderr, "%s: warnings being treated as errors\n", program_name);
       complaint_issued = true;
