@@ -257,7 +257,7 @@ literalchar(pp, pcode, term)
 	}
       else
 	{
-	  warni (_("unknown escape sequence: `\\' followed by `%s'"),
+	  warns (_("unknown escape sequence: `\\' followed by `%s'"),
 		 printable_version(c));
 	  code = '?';
 	}
