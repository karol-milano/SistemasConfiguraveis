@@ -60,8 +60,8 @@ columns (void)
   int res = 80;
   if (cp && *cp)
     {
-      unsigned long ul = strtoul (cp, NULL, 10);
-      res = ul < INT_MAX ? ul : INT_MAX;
+      long l = strtol (cp, NULL, 10);
+      res = 0 <= l && l <= INT_MAX ? l : INT_MAX;
     }
   else
     {
@@ -149,7 +149,7 @@ location_compute (location *loc, boundary *cur, char const *token, size_t size)
     complain (loc, Wother, _("byte number overflow"));
 }
 
-static unsigned
+static int
 boundary_print (boundary const *b, FILE *out)
 {
   return fprintf (out, "%s:%d.%d@%d",
@@ -157,10 +157,10 @@ boundary_print (boundary const *b, FILE *out)
                   b->line, b->column, b->byte);
 }
 
-unsigned
+int
 location_print (location loc, FILE *out)
 {
-  unsigned res = 0;
+  int res = 0;
   if (trace_flag & trace_locations)
     {
       res += boundary_print (&loc.start, out);
