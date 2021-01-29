@@ -409,7 +409,7 @@ duplicate_directive (char const *directive,
   else
     complain_indent (&second, Wother, &i, _("duplicate directive: %s"), directive);
   i += SUB_INDENT;
-  complain_indent (&first, complaint, &i, _("previous declaration"));
+  complain_indent (&first, Wother, &i, _("previous declaration"));
   fixits_register (&second, "");
 }
 
