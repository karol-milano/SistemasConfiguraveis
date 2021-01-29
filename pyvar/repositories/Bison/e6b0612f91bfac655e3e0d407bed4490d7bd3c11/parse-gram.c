@@ -2946,9 +2946,9 @@ handle_require (location const *loc, char const *version)
       return;
     }
 
-  /* Pretend to be at least 3.5, to check features published in that
-     version while developping it.  */
-  const char* api_version = "3.5";
+  /* Pretend to be at least that version, to check features published
+     in that version while developping it.  */
+  const char* api_version = "3.6";
   const char* package_version =
     0 < strverscmp (api_version, PACKAGE_VERSION)
     ? api_version : PACKAGE_VERSION;
