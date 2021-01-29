@@ -1,7 +1,7 @@
 /* Parse command line arguments for Bison.
 
    Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002, 2003, 2004,
-   2005, 2006, 2007, 2008 Free Software Foundation, Inc.
+   2005, 2006, 2007, 2008, 2009 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -181,6 +181,7 @@ static const char * const trace_args[] =
   "m4         - m4 traces",
   "skeleton   - skeleton postprocessing",
   "time       - time consumption",
+  "ielr       - IELR conversion",
   "all        - all of the above",
   0
 };
@@ -200,6 +201,7 @@ static const int trace_types[] =
   trace_m4,
   trace_skeleton,
   trace_time,
+  trace_ielr,
   trace_all
 };
 
