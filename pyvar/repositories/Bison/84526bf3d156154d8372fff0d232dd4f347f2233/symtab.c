@@ -67,7 +67,7 @@ symbol_new (uniqstr tag, location loc)
 
   /* If the tag is not a string (starts with a double quote), check
      that it is valid for Yacc. */
-  if (tag[0] != '\"' && tag[0] != '\'' && mbschr (tag, '-'))
+  if (tag[0] != '\"' && tag[0] != '\'' && strchr (tag, '-'))
     yacc_at (loc, _("POSIX Yacc forbids dashes in symbol names: %s"),
              tag);
 
