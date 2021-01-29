@@ -417,10 +417,10 @@ warnings_print_categories (warnings warn_flags, FILE *out)
  */
 static
 void
-error_message (const location *loc, unsigned *indent, warnings flags,
+error_message (const location *loc, int *indent, warnings flags,
                severity sever, const char *message, va_list args)
 {
-  unsigned pos = 0;
+  int pos = 0;
 
   if (loc)
     pos += location_print (*loc, stderr);
@@ -470,7 +470,7 @@ error_message (const location *loc, unsigned *indent, warnings flags,
 /** Raise a complaint (fatal error, error or just warning).  */
 
 static void
-complains (const location *loc, unsigned *indent, warnings flags,
+complains (const location *loc, int *indent, warnings flags,
            const char *message, va_list args)
 {
   severity s = warning_severity (flags);
@@ -498,7 +498,7 @@ complain (location const *loc, warnings flags, const char *message, ...)
 }
 
 void
-complain_indent (location const *loc, warnings flags, unsigned *indent,
+complain_indent (location const *loc, warnings flags, int *indent,
                  const char *message, ...)
 {
   va_list args;
@@ -508,7 +508,7 @@ complain_indent (location const *loc, warnings flags, unsigned *indent,
 }
 
 void
-complain_args (location const *loc, warnings w, unsigned *indent,
+complain_args (location const *loc, warnings w, int *indent,
                int argc, char *argv[])
 {
   switch (argc)
@@ -563,7 +563,7 @@ void
 duplicate_directive (char const *directive,
                      location first, location second)
 {
-  unsigned i = 0;
+  int i = 0;
   if (feature_flag & feature_caret)
     complain_indent (&second, Wother, &i, _("duplicate directive"));
   else
@@ -577,7 +577,7 @@ void
 duplicate_rule_directive (char const *directive,
                           location first, location second)
 {
-  unsigned i = 0;
+  int i = 0;
   complain_indent (&second, complaint, &i,
                    _("only one %s allowed per rule"), directive);
   i += SUB_INDENT;
