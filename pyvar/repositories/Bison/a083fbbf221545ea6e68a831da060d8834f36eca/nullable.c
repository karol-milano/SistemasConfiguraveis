@@ -49,7 +49,7 @@ set_nullable()
   short *r1;
 
 #ifdef	TRACE
-  fprintf(stderr, "Entering set_nullable");
+  fprintf(stderr, _("Entering set_nullable"));
 #endif
 
   nullable = NEW2(nvars, char) - ntokens;
