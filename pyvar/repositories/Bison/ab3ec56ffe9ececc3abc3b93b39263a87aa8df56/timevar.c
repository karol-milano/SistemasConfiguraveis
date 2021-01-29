@@ -50,13 +50,13 @@ struct tms
 #endif
 
 #if defined HAVE_DECL_GETRUSAGE && !HAVE_DECL_GETRUSAGE
-extern int getrusage (int, struct rusage *);
+int getrusage (int, struct rusage *);
 #endif
 #if defined HAVE_DECL_TIMES && !HAVE_DECL_TIMES
-extern clock_t times (struct tms *);
+clock_t times (struct tms *);
 #endif
 #if defined HAVE_DECL_CLOCK && !HAVE_DECL_CLOCK
-extern clock_t clock (void);
+clock_t clock (void);
 #endif
 
 /* Calculation of scale factor to convert ticks to microseconds.
