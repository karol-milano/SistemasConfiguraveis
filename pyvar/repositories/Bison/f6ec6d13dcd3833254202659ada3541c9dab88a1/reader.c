@@ -748,6 +748,8 @@ parse_union_decl (void)
 
   typed = 1;
 
+  /* FIXME: I'm worried: are you sure attrs_obstack is properly
+     filled?  */
   if (no_lines_flag)
     obstack_1grow (&attrs_obstack, '\n');
 
@@ -763,7 +765,7 @@ parse_union_decl (void)
       /* If C contains '/', it is output by copy_comment ().  */
       if (c != '/')
 	{
-	  obstack_1grow (&attrs_obstack, c);
+	  obstack_1grow (&union_obstack, c);
 	  if (defines_flag)
 	    obstack_1grow (&defines_obstack, c);
 	}
