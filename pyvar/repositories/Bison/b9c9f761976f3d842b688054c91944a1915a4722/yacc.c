@@ -239,6 +239,10 @@ b4_syncline([@oline@], [@ofile@])[
    /* Pacify GCC's `empty if-body' warning. */
 #  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
 #  ifndef YYSTACK_ALLOC_MAXIMUM
+    /* The OS might guarantee only one guard page at the bottom of the stack,
+       and a page size can be as small as 4096 bytes.  So we cannot safely
+       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
+       to allow for a few compiler-allocated temporary stack slots.  */
 #   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
 #  endif
 # else
