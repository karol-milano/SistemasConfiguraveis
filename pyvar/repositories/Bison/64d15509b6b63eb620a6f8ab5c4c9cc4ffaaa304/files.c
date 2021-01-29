@@ -489,12 +489,13 @@ output_files (void)
       char *temp_name;
 
       obstack_save (&attrs_obstack, attrsfile);
-      obstack_free (&attrs_obstack, NULL);
       temp_name = stringappend (short_base_name, EXT_GUARD_C);
 #ifndef MSDOS
       temp_name = stringappend (temp_name, src_extension);
 #endif /* MSDOS */
       obstack_save (&guard_obstack, temp_name);
-      obstack_free (&guard_obstack, NULL);
     }
+
+  obstack_free (&guard_obstack, NULL);
+  obstack_free (&attrs_obstack, NULL);
 }
