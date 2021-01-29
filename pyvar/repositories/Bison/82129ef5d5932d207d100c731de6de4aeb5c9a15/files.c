@@ -1,4 +1,5 @@
-/* Open and close files for bison,
+/* Open and close files for Bison.
+
    Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002
    Free Software Foundation, Inc.
 
@@ -75,7 +76,7 @@ static char *
 concat2 (char const *str1, char const *str2)
 {
   size_t len = strlen (str1) + strlen (str2);
-  char *res = XMALLOC (char, len + 1);
+  char *res = xmalloc (len + 1);
   char *cp;
   cp = stpcpy (res, str1);
   cp = stpcpy (cp, str2);
@@ -127,9 +128,7 @@ static char *
 tr (const char *in, char from, char to)
 {
   char *temp;
-  char *out;
-
-  out = XMALLOC (char, strlen (in) + 1);
+  char *out = xmalloc (strlen (in) + 1);
 
   for (temp = out; *in; in++, out++)
     if (*in == from)
@@ -201,13 +200,17 @@ filename_split (const char *filename,
   *ext = strrchr (*base, '.');
   *tab = NULL;
 
-  /* If there is an exentension, check if there is a `.tab' part right
+  /* If there is an extension, check if there is a `.tab' part right
      before.  */
-  if (*ext
-      && (*ext - *base) > (int) strlen (".tab")
-      && (!strncmp (*ext - strlen (".tab"), ".tab", strlen (".tab"))
-	  || !strncmp (*ext - strlen ("_tab"), "_tab", strlen ("_tab"))))
-    *tab = *ext - strlen (".tab");
+  if (*ext)
+    {
+      size_t baselen = *ext - *base;
+      size_t dottablen = 4;
+      if (dottablen < baselen
+	  && (strncmp (*ext - dottablen, ".tab", dottablen) == 0
+	      || strncmp (*ext - dottablen, "_tab", dottablen) == 0))
+	*tab = *ext - dottablen;
+    }
 }
 
 
@@ -272,8 +275,7 @@ compute_base_names (void)
 		      (strlen (base) - (ext ? strlen (ext) : 0)));
 	}
 
-      full_base_name = XMALLOC (char,
-				strlen (short_base_name)
+      full_base_name = xmalloc (strlen (short_base_name)
 				+ strlen (TAB_EXT) + 1);
       stpcpy (stpcpy (full_base_name, short_base_name), TAB_EXT);
 
