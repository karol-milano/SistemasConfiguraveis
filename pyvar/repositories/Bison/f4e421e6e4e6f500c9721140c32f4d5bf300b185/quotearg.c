@@ -44,9 +44,15 @@
 #ifndef CHAR_BIT
 # define CHAR_BIT 8
 #endif
+#ifndef SIZE_MAX
+# define SIZE_MAX ((size_t) -1)
+#endif
 #ifndef UCHAR_MAX
 # define UCHAR_MAX ((unsigned char) -1)
 #endif
+#ifndef UINT_MAX
+# define UINT_MAX ((unsigned int) -1)
+#endif
 
 #if HAVE_C_BACKSLASH_A
 # define ALERT_CHAR '\a'
@@ -539,6 +545,7 @@ quotearg_n_options (int n, char const *arg,
      one small component of a "memory exhausted" message in slot 0.  */
   static char slot0[256];
   static unsigned int nslots = 1;
+  unsigned int n0 = n;
   struct slotvec
     {
       size_t size;
@@ -547,20 +554,26 @@ quotearg_n_options (int n, char const *arg,
   static struct slotvec slotvec0 = {sizeof slot0, slot0};
   static struct slotvec *slotvec = &slotvec0;
 
-  if (nslots <= n)
+  if (n < 0)
+    abort ();
+
+  if (nslots <= n0)
     {
-      int n1 = n + 1;
-      size_t s = n1 * sizeof (struct slotvec);
-      if (! (0 < n1 && n1 == s / sizeof (struct slotvec)))
-	abort ();
+      unsigned int n1 = n0 + 1;
+      size_t s = n1 * sizeof *slotvec;
+
+      if (SIZE_MAX / UINT_MAX <= sizeof *slotvec
+	  && n1 != s / sizeof *slotvec)
+	xalloc_die ();
+
       if (slotvec == &slotvec0)
 	{
-	  slotvec = (struct slotvec *) xmalloc (sizeof (struct slotvec));
+	  slotvec = (struct slotvec *) xmalloc (sizeof *slotvec);
 	  *slotvec = slotvec0;
 	}
       slotvec = (struct slotvec *) xrealloc (slotvec, s);
-      memset (slotvec + nslots, 0, (n1 - nslots) * sizeof (struct slotvec));
-      nslots = n;
+      memset (slotvec + nslots, 0, (n1 - nslots) * sizeof *slotvec);
+      nslots = n1;
     }
 
   {
@@ -580,7 +593,7 @@ quotearg_n_options (int n, char const *arg,
 }
 
 char *
-quotearg_n (unsigned int n, char const *arg)
+quotearg_n (int n, char const *arg)
 {
   return quotearg_n_options (n, arg, &default_quoting_options);
 }
@@ -592,7 +605,7 @@ quotearg (char const *arg)
 }
 
 char *
-quotearg_n_style (unsigned int n, enum quoting_style s, char const *arg)
+quotearg_n_style (int n, enum quoting_style s, char const *arg)
 {
   struct quoting_options o;
   o.style = s;
