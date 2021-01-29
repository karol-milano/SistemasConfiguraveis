@@ -464,7 +464,7 @@ error_message (const location *loc, int *indent, warnings flags,
       {
         putc ('\n', stderr);
         flush (stderr);
-        if (loc && feature_flag & feature_caret && !(flags & no_caret))
+        if (loc && !(flags & no_caret))
           location_caret (*loc, style, stderr);
       }
   }
@@ -555,8 +555,7 @@ deprecated_directive (location const *loc, char const *old, char const *upd)
       complain (loc, Wdeprecated,
                 _("deprecated directive: %s, use %s"),
                 quote (old), quote_n (1, upd));
-      if (feature_flag & feature_caret)
-        location_caret_suggestion (*loc, upd, stderr);
+      location_caret_suggestion (*loc, upd, stderr);
       /* Register updates only if -Wdeprecated is enabled.  */
       fixits_register (loc, upd);
     }
