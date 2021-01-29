@@ -1,6 +1,6 @@
 /* Declaration for error-reporting function for Bison.
 
-   Copyright (C) 2000, 2001, 2002, 2004, 2005, 2006
+   Copyright (C) 2000, 2001, 2002, 2004, 2005, 2006, 2009
    Free Software Foundation, Inc.
 
    This program is free software: you can redistribute it and/or modify
@@ -120,6 +120,27 @@ complain (const char *message, ...)
 }
 
 
+/*--------------------------------------------------------------.
+| An incompatibility with POSIX Yacc: mapped either to warn* or |
+| complain* depending on yacc_flag.                             |
+`--------------------------------------------------------------*/
+
+void
+yacc_at (location loc, const char *message, ...)
+{
+  if (yacc_flag)
+    {
+      ERROR_MESSAGE (&loc, NULL, message);
+      complaint_issued = true;
+    }
+  else if (warnings_flag & warnings_yacc)
+    {
+      set_warning_issued ();
+      ERROR_MESSAGE (&loc, _("warning"), message);
+    }
+}
+
+
 /*-------------------------------------------------.
 | A severe error has occurred, we cannot proceed.  |
 `-------------------------------------------------*/
