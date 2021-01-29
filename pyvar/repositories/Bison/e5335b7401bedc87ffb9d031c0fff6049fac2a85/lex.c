@@ -271,7 +271,9 @@ literalchar (char **pp, int *pcode, char term)
      so that `\012' and `\n' can be interchangeable.  */
 
   p = *pp;
-  if (code == '\\')  {*p++ = '\\'; *p++ = '\\';}
+  if (code == term && wasquote)
+    *p++ = code;
+  else if (code == '\\')  {*p++ = '\\'; *p++ = '\\';}
   else if (code == '\'')  {*p++ = '\\'; *p++ = '\'';}
   else if (code == '\"')  {*p++ = '\\'; *p++ = '\"';}
   else if (code >= 040 && code < 0177)
