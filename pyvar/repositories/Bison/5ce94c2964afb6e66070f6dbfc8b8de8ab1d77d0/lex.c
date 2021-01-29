@@ -268,11 +268,11 @@ literalchar(pp, pcode, term)
      so that `\012' and `\n' can be interchangeable.  */
 
   p = *pp;
-  if (code >= 040 && code < 0177)
-    *p++ = code;
-  else if (code == '\\')  {*p++ = '\\'; *p++ = '\\';}
+  if (code == '\\')  {*p++ = '\\'; *p++ = '\\';}
   else if (code == '\'')  {*p++ = '\\'; *p++ = '\'';}
   else if (code == '\"')  {*p++ = '\\'; *p++ = '\"';}
+  else if (code >= 040 && code < 0177)
+    *p++ = code;
   else if (code == '\t')  {*p++ = '\\'; *p++ = 't';}
   else if (code == '\n')  {*p++ = '\\'; *p++ = 'n';}
   else if (code == '\r')  {*p++ = '\\'; *p++ = 'r';}
@@ -381,6 +381,7 @@ lex()
       {
 	int code, discode;
 	char discard[10], *dp;
+
 	p = token_buffer;
 	*p++ = '\'';
 	literalchar(&p, &code, '\'');
@@ -389,8 +390,12 @@ lex()
 	if (c != '\'')
 	  {
 	    warn(_("use \"...\" for multi-character literal tokens"));
-	    dp = discard;
-	    while (literalchar(&dp, &discode, '\'')) {}
+	    while (1)
+	      {
+		dp = discard;
+		if (! literalchar(&dp, &discode, '\''))
+		  break;
+	      }
 	  }
 	*p++ = '\'';
 	*p = 0;
