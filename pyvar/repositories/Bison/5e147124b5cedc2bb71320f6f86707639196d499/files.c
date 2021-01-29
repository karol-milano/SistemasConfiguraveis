@@ -211,9 +211,9 @@ skeleton_find (const char *envvar, const char *skeleton_name)
   if (!res)
     {
       /* Skeleton file name without path */
-      const char *skel_name = strrchr(skeleton_name, '/');
+      const char *skel_name = strrchr (skeleton_name, '/');
       if (!skel_name)
-        skel_name = strrchr(skeleton_name, '\\');
+        skel_name = strrchr (skeleton_name, '\\');
       if (!skel_name)
         skel_name = skeleton_name;
       else
