@@ -278,6 +278,12 @@ complain_init (void)
     }
 }
 
+void
+complain_free (void)
+{
+  caret_free ();
+  styled_ostream_free (errstream);
+}
 
 /* A diagnostic with FLAGS is about to be issued.  With what severity?
    (severity_fatal, severity_error, severity_disabled, or
