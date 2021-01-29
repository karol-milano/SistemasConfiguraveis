@@ -874,6 +874,45 @@ parse_thong_decl (void)
   nsyms--;
 }
 
+/*------------------------------------------.
+| Parse what comes after %header_extension. |
+`------------------------------------------*/
+
+static void
+parse_header_extension_decl (void)
+{
+  char buff[32];
+  int len;
+  
+  if (header_extension)
+    complain (_("multiple %%header_extension declarations"));
+  fscanf (finput, "%s", buff);
+  printf("-> %s\n", buff);
+  len = strlen (buff);
+  buff[len] = '\0';
+  src_extension = XMALLOC (char, len + 1);
+  stpcpy (header_extension, buff);
+}
+
+/*------------------------------------------.
+| Parse what comes after %source_extension. |
+`------------------------------------------*/
+
+static void
+parse_source_extension_decl (void)
+{
+  char buff[32];
+  int len;
+  
+  if (src_extension)
+    complain (_("multiple %%source_extension declarations"));
+  fscanf (finput, "%s", buff);
+  printf("-> %s\n", buff);
+  len = strlen (buff);
+  buff[len] = '\0';
+  src_extension = XMALLOC (char, len + 1);
+  stpcpy (src_extension, buff);
+}
 
 /*----------------------------------------------------------------.
 | Read from finput until `%%' is seen.  Discard the `%%'.  Handle |
@@ -944,6 +983,13 @@ read_declarations (void)
 	      parse_assoc_decl (non_assoc);
 	      break;
 
+	    case tok_hdrext:
+	      break;
+
+	    case tok_srcext:
+	      parse_source_extension_decl();
+	      break;
+
 	    case tok_noop:
 	      break;
 
