@@ -198,11 +198,6 @@ output_gram (void)
 
     XFREE (yyrhs);
   }
-
-#if 0
-  if (!semantic_parser && !no_parser_flag)
-    obstack_sgrow (&table_obstack, "\n#endif\n");
-#endif
 }
 
 
@@ -1068,9 +1063,6 @@ output (void)
   XFREE (user_toknums);
   output_actions ();
 
-#if 0
-  if (!no_parser_flag) */
-#endif
   prepare ();
   /* Copy definitions in directive.  */
   obstack_1grow (&attrs_obstack, 0);
