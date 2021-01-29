@@ -974,16 +974,6 @@ parse_skel_decl (void)
   /* Complete with parse_dquoted_param () on the CVS branch 1.29.  */
 }
 
-/*---------------------------------------.
-| Parse what comes after %skeleton_path. |
-`---------------------------------------*/
-
-void
-parse_include_decl (void)
-{
-  /* Complete with parse_dquoted_param () on the CVS branch 1.29.  */
-}
-
 /*----------------------------------------------------------------.
 | Read from finput until `%%' is seen.  Discard the `%%'.  Handle |
 | any `%' declarations, and copy the contents of any `%{ ... %}'  |
@@ -1058,10 +1048,6 @@ read_declarations (void)
 	      parse_skel_decl ();
 	      break;
 
-	    case tok_include:
-	      parse_include_decl ();
-	      break;
-	      
 	    case tok_noop:
 	      break;
 
