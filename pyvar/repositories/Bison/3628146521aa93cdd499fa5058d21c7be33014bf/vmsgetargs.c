@@ -124,7 +124,7 @@ getargs(argc,argv)
    */
   if (cli_present("BISON$FILE_PREFIX"))
     {
-      cli_get_value("BISON$FILE_PREFIX", file_prefix_spec, 
+      cli_get_value("BISON$FILE_PREFIX", file_prefix_spec,
 		     sizeof(file_prefix_spec));
       for (cp = spec_file_prefix = file_prefix_spec; *cp; cp++)
 	if (isupper(*cp))
@@ -135,7 +135,7 @@ getargs(argc,argv)
    */
   if (cli_present("BISON$NAME_PREFIX"))
     {
-      cli_get_value("BISON$NAME_PREFIX", name_prefix_spec, 
+      cli_get_value("BISON$NAME_PREFIX", name_prefix_spec,
 		     sizeof(name_prefix_spec));
       for (cp = spec_name_prefix = name_prefix_spec; *cp; cp++)
 	if (isupper(*cp))
@@ -156,7 +156,7 @@ cli_present(Name)
 
   Descr.Ptr = Name;
   Descr.Size = strlen(Name);
-  return((cli$present(&Descr) & 1) ? 1 : 0);
+  return (cli$present(&Descr) & 1) ? 1 : 0;
 }
 
 /*
@@ -175,7 +175,7 @@ cli_get_value(Name,Buffer,Size)
   Descr2.Size = Size-1;
   if (cli$get_value(&Descr1,&Descr2,&Descr2.Size) & 1) {
     Buffer[Descr2.Size] = 0;
-    return(1);
+    return 1;
   }
-  return(0);
+  return 0;
 }
