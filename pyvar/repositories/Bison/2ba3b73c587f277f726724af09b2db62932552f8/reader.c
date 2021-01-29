@@ -941,6 +941,17 @@ parse_macro_decl (void)
   macro_insert (macro_key, macro_value);
 }
 
+
+/*----------------------------------.
+| Parse what comes after %skeleton. |
+`----------------------------------*/
+
+void
+parse_skel_decl (void)
+{
+  /* Complete with parse_dquoted_param () on the CVS branch 1.29.  */
+}
+
 /*------------------------------------------.
 | Parse what comes after %header_extension. |
 `------------------------------------------*/
@@ -1051,6 +1062,10 @@ read_declarations (void)
 	    case tok_define:
 	      parse_macro_decl ();
 	      break;
+	      
+	    case tok_skel:
+	      parse_skel_decl ();
+	      break;
 
 	    case tok_noop:
 	      break;
