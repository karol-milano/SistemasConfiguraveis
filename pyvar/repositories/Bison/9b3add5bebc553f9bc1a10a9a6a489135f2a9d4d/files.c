@@ -51,19 +51,22 @@ char *infile = NULL;
 char *attrsfile = NULL;
 
 static char *base_name = NULL;
-static char *short_base_name = NULL;
+char *short_base_name = NULL;
 
 /* C source file extension (the parser source).  */
 const char *src_extension = NULL;
 /* Header file extension (if option ``-d'' is specified).  */
 const char *header_extension = NULL;
+
+/* Should we insert '.tab' in yacc-compatible parsers?  */
+int tab_extension = 0;
 
 
 /*--------------------------.
 | Is SUFFIX ending STRING?  |
 `--------------------------*/
 
-static int
+int
 strsuffix (const char *string, const char *suffix)
 {
   size_t string_len = strlen (string);
@@ -80,7 +83,7 @@ strsuffix (const char *string, const char *suffix)
 | STRING1, and STRING2.                                            |
 `-----------------------------------------------------------------*/
 
-static char *
+char*
 stringappend (const char *string1, const char *string2)
 {
   size_t len = strlen (string1) + strlen (string2);
@@ -334,6 +337,11 @@ compute_base_names (void)
 	short_base_length -= 4;
       short_base_name = strndup (spec_outfile, short_base_length);
 
+      /* FIXME: This is a quick and dirty way for me to find out if we
+	 should .tab or not, using the computations above.  */
+      if (strcmp (base_name, short_base_name))
+	tab_extension = 1;
+
       return;
     }
 
@@ -360,6 +368,10 @@ compute_base_names (void)
       if (ext_index)
 	compute_exts_from_gf (infile + ext_index);
 
+      /* It seems that when only a prefix is given, '.tab' should always be
+	 used.  */
+      tab_extension = 1;
+
       return;
     }
 
@@ -393,6 +405,9 @@ compute_base_names (void)
 			 strlen (short_base_name) + strlen (EXT_TAB) + 1);
     stpcpy (stpcpy (base_name, short_base_name), EXT_TAB);
 
+    /* By default, Bison should insert '.tab' were needed.  */
+    tab_extension = 1;
+
     return;
   }
 }
