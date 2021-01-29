@@ -615,14 +615,6 @@ static struct option const long_options[] =
   {0, 0, 0, 0}
 };
 
-/* Under DOS, there is no difference on the case.  This can be
-   troublesome when looking for '.tab' etc.  */
-#ifdef MSDOS
-# define AS_FILE_NAME(File) (strlwr (File), (File))
-#else
-# define AS_FILE_NAME(File) (File)
-#endif
-
 /* Build a location for the current command line argument. */
 static
 location
@@ -719,7 +711,7 @@ getargs (int argc, char *argv[])
         break;
 
       case 'S':
-        skeleton_arg (AS_FILE_NAME (optarg), command_line_prio,
+        skeleton_arg (optarg, command_line_prio,
                       command_line_location ());
         break;
 
@@ -740,7 +732,7 @@ getargs (int argc, char *argv[])
         break;
 
       case 'b':
-        spec_file_prefix = AS_FILE_NAME (optarg);
+        spec_file_prefix = optarg;
         break;
 
       case 'd':
@@ -749,7 +741,7 @@ getargs (int argc, char *argv[])
         if (optarg)
           {
             free (spec_header_file);
-            spec_header_file = xstrdup (AS_FILE_NAME (optarg));
+            spec_header_file = xstrdup (optarg);
           }
         break;
 
@@ -758,7 +750,7 @@ getargs (int argc, char *argv[])
         if (optarg)
           {
             free (spec_graph_file);
-            spec_graph_file = xstrdup (AS_FILE_NAME (optarg));
+            spec_graph_file = xstrdup (optarg);
           }
         break;
 
@@ -774,7 +766,7 @@ getargs (int argc, char *argv[])
         break;
 
       case 'o':
-        spec_outfile = AS_FILE_NAME (optarg);
+        spec_outfile = optarg;
         break;
 
       case 'p':
@@ -806,7 +798,7 @@ getargs (int argc, char *argv[])
         if (optarg)
           {
             free (spec_xml_file);
-            spec_xml_file = xstrdup (AS_FILE_NAME (optarg));
+            spec_xml_file = xstrdup (optarg);
           }
         break;
 
@@ -834,7 +826,7 @@ getargs (int argc, char *argv[])
 
       case REPORT_FILE_OPTION:
         free (spec_verbose_file);
-        spec_verbose_file = xstrdup (AS_FILE_NAME (optarg));
+        spec_verbose_file = xstrdup (optarg);
         break;
 
       case STYLE_OPTION:
