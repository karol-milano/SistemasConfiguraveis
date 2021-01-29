@@ -3463,10 +3463,9 @@ handle_require (location const *loc, char const *version)
       return;
     }
   required_version = major * 100 + minor;
-  /* Pretend to be at least 3.2, even if we are only 3.1-211, as it
-     allows us to check features published in 3.2 while developping
-     3.2.  */
-  const char* api_version = "3.2";
+  /* Pretend to be at least 3.4, to check features published in 3.4
+     while developping it.  */
+  const char* api_version = "3.4";
   const char* package_version =
     strverscmp (api_version, PACKAGE_VERSION) > 0
     ? api_version : PACKAGE_VERSION;
