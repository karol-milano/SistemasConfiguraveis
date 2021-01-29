@@ -374,6 +374,14 @@ complain_args (location const *loc, warnings w, unsigned *indent,
   }
 }
 
+
+void
+bison_directive (location const *loc, char const *directive)
+{
+  complain (loc, Wyacc,
+            _("POSIX Yacc does not support %s"), directive);
+}
+
 void
 deprecated_directive (location const *loc, char const *old, char const *upd)
 {
