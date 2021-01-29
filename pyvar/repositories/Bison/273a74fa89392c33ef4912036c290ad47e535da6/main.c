@@ -48,16 +48,11 @@ char *program_name;
 | Tracking space and time.  |
 `--------------------------*/
 
-#if HAVE_MALLOC_H & HAVE_SYS_TIMES_H
-# include <malloc.h>
-# include <sys/times.h>
-#endif
-
 static void
 stage (const char *title)
 {
-#if HAVE_MALLOC_H & HAVE_SYS_TIMES_H
-  if (trace_flag)
+#if HAVE_MALLINFO && HAVE_STRUCT_MALLINFO & HAVE_TIMES & HAVE_STRUCT_TMS
+  if (trace_flag & trace_resource)
     {
       struct mallinfo minfo = mallinfo ();
       struct tms tinfo;
@@ -81,7 +76,7 @@ main (int argc, char *argv[])
 
   getargs (argc, argv);
 
-  if (trace_flag)
+  if (trace_flag & trace_bitsets)
     bitset_stats_enable ();
 
   muscle_init ();
@@ -171,7 +166,7 @@ main (int argc, char *argv[])
   alloca (0);
 #endif
 
-  if (trace_flag)
+  if (trace_flag & trace_bitsets)
     bitset_stats_dump (stderr);
 
   return complain_message_count ? EXIT_FAILURE : EXIT_SUCCESS;
