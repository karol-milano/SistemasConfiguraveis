@@ -33,7 +33,15 @@
 #endif
 
 #ifdef emacs
+# include "lisp.h"
 # include "blockinput.h"
+# define xalloc_die() memory_full ()
+# ifdef EMACS_FREE
+#  undef free
+#  define free EMACS_FREE
+# endif
+#else
+# include <xalloc.h>
 #endif
 
 /* If compiling with GCC 2, this file's not needed.  */
@@ -53,6 +61,8 @@
 you
 lose
 -- must know STACK_DIRECTION at compile-time
+/* Using #error here is not wise since this file should work for
+   old and obscure compilers.  */
 #    endif /* STACK_DIRECTION undefined */
 #   endif /* static */
 #  endif /* emacs */
@@ -67,32 +77,19 @@ long i00afunc ();
 #   define ADDRESS_FUNCTION(arg) &(arg)
 #  endif
 
-#  if __STDC__
-typedef void *pointer;
-#  else
-typedef char *pointer;
+#  ifndef POINTER_TYPE
+#   ifdef __STDC__
+#    define POINTER_TYPE void
+#   else
+#    define POINTER_TYPE char
+#   endif
 #  endif
+typedef POINTER_TYPE *pointer;
 
 #  ifndef NULL
 #   define NULL 0
 #  endif
 
-/* Different portions of Emacs need to call different versions of
-   malloc.  The Emacs executable needs alloca to call xmalloc, because
-   ordinary malloc isn't protected from input signals.  On the other
-   hand, the utilities in lib-src need alloca to call malloc; some of
-   them are very simple, and don't have an xmalloc routine.
-
-   Non-Emacs programs expect this to call xmalloc.
-
-   Callers below should use malloc.  */
-
-#  ifndef emacs
-#   undef malloc
-#   define malloc xmalloc
-#  endif
-extern pointer malloc ();
-
 /* Define STACK_DIRECTION if you know the direction of stack
    growth for your system; otherwise it will be automatically
    deduced at run-time.
@@ -169,7 +166,8 @@ static header *last_alloca_header = NULL;	/* -> last alloca header.  */
    implementations of C, for example under Gould's UTX/32.  */
 
 pointer
-alloca (size_t size)
+alloca (size)
+     size_t size;
 {
   auto char probe;		/* Probes stack depth: */
   register char *depth = ADDRESS_FUNCTION (probe);
@@ -215,8 +213,14 @@ alloca (size_t size)
   /* Allocate combined header + user data storage.  */
 
   {
-    register pointer new = malloc (sizeof (header) + size);
     /* Address of header.  */
+    register pointer new;
+
+    size_t combined_size = sizeof (header) + size;
+    if (combined_size < sizeof (header))
+      xalloc_die ();
+
+    new = xmalloc (combined_size);
 
     if (new == 0)
       abort();
