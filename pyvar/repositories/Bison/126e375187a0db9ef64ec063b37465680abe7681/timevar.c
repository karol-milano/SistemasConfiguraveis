@@ -1,5 +1,5 @@
 /* Timing variables for measuring compiler performance.
-   Copyright (C) 2000, 2002 Free Software Foundation, Inc.
+   Copyright (C) 2000, 2002, 2004 Free Software Foundation, Inc.
    Contributed by Alex Samuel <samuel@codesourcery.com>
 
 This file is part of Bison, the GNU Compiler Compiler.
@@ -63,13 +63,13 @@ struct tms
 #endif
 
 #if defined HAVE_DECL_GETRUSAGE && !HAVE_DECL_GETRUSAGE
-extern int getrusage PARAMS ((int, struct rusage *));
+extern int getrusage (int, struct rusage *);
 #endif
 #if defined HAVE_DECL_TIMES && !HAVE_DECL_TIMES
-extern clock_t times PARAMS ((struct tms *));
+extern clock_t times (struct tms *);
 #endif
 #if defined HAVE_DECL_CLOCK && !HAVE_DECL_CLOCK
-extern clock_t clock PARAMS ((void));
+extern clock_t clock (void);
 #endif
 
 #ifndef RUSAGE_SELF
@@ -187,11 +187,10 @@ static struct timevar_stack_def *unused_stack_instances;
    element.  */
 static struct timevar_time_def start_time;
 
-static void get_time
-  PARAMS ((struct timevar_time_def *));
-static void timevar_accumulate
-  PARAMS ((struct timevar_time_def *, struct timevar_time_def *,
-	   struct timevar_time_def *));
+static void get_time (struct timevar_time_def *);
+static void timevar_accumulate (struct timevar_time_def *,
+				struct timevar_time_def *,
+				struct timevar_time_def *);
 
 /* Fill the current times into TIME.  The definition of this function
    also defines any or all of the HAVE_USER_TIME, HAVE_SYS_TIME, and
