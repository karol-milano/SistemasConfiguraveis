@@ -392,12 +392,20 @@ print_grammar (FILE *out, int level)
     if (token_translations[i] != undeftoken->number)
       {
 	char const *tag = symbols[token_translations[i]]->tag;
-	xml_printf (out, level + 2,
-		    "<terminal symbol-number=\"%d\" token-number=\"%d\""
-                    " name=\"%s\" usefulness=\"%s\"/>",
-		    token_translations[i], i, xml_escape (tag),
-                    reduce_token_unused_in_grammar (token_translations[i])
-                      ? "unused-in-grammar" : "useful");
+        int precedence = symbols[token_translations[i]]->prec;
+        assoc associativity = symbols[token_translations[i]]->assoc;
+        xml_indent (out, level + 2);
+        fprintf (out,
+                 "<terminal symbol-number=\"%d\" token-number=\"%d\""
+                 " name=\"%s\" usefulness=\"%s\"",
+                 token_translations[i], i, xml_escape (tag),
+                 reduce_token_unused_in_grammar (token_translations[i])
+                   ? "unused-in-grammar" : "useful");
+        if (precedence)
+          fprintf (out, " prec=\"%d\"", precedence);
+        if (associativity != undef_assoc)
+          fprintf (out, " assoc=\"%s\"", assoc_to_string (associativity) + 1);
+        fputs ("/>\n", out);
       }
   xml_puts (out, level + 1, "</terminals>");
 
@@ -418,11 +426,17 @@ print_grammar (FILE *out, int level)
 }
 
 void
-xml_puts (FILE *out, int level, char const *s)
+xml_indent (FILE *out, int level)
 {
   int i;
   for (i = 0; i < level; i++)
     fputs ("  ", out);
+}
+
+void
+xml_puts (FILE *out, int level, char const *s)
+{
+  xml_indent (out, level);
   fputs (s, out);
   fputc ('\n', out);
 }
@@ -430,11 +444,9 @@ xml_puts (FILE *out, int level, char const *s)
 void
 xml_printf (FILE *out, int level, char const *fmt, ...)
 {
-  int i;
   va_list arglist;
 
-  for (i = 0; i < level; i++)
-    fputs ("  ", out);
+  xml_indent (out, level);
 
   va_start (arglist, fmt);
   vfprintf (out, fmt, arglist);
