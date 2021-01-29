@@ -22,18 +22,18 @@
    your main control loop, etc. to force garbage collection.  */
 
 #ifdef HAVE_CONFIG_H
-#include <config.h>
+# include <config.h>
 #endif
 
-#ifdef HAVE_STRING_H
-#include <string.h>
+#if HAVE_STRING_H
+# include <string.h>
 #endif
-#ifdef HAVE_STDLIB_H
-#include <stdlib.h>
+#if HAVE_STDLIB_H
+# include <stdlib.h>
 #endif
 
 #ifdef emacs
-#include "blockinput.h"
+# include "blockinput.h"
 #endif
 
 /* If compiling with GCC 2, this file's not needed.  */
@@ -41,41 +41,41 @@
 
 /* If someone has defined alloca as a macro,
    there must be some other way alloca is supposed to work.  */
-#ifndef alloca
+# ifndef alloca
 
-#ifdef emacs
-#ifdef static
+#  ifdef emacs
+#   ifdef static
 /* actually, only want this if static is defined as ""
    -- this is for usg, in which emacs must undefine static
    in order to make unexec workable
    */
-#ifndef STACK_DIRECTION
+#    ifndef STACK_DIRECTION
 you
 lose
 -- must know STACK_DIRECTION at compile-time
-#endif /* STACK_DIRECTION undefined */
-#endif /* static */
-#endif /* emacs */
+#    endif /* STACK_DIRECTION undefined */
+#   endif /* static */
+#  endif /* emacs */
 
 /* If your stack is a linked list of frames, you have to
    provide an "address metric" ADDRESS_FUNCTION macro.  */
 
-#if defined (CRAY) && defined (CRAY_STACKSEG_END)
+#  if defined (CRAY) && defined (CRAY_STACKSEG_END)
 long i00afunc ();
-#define ADDRESS_FUNCTION(arg) (char *) i00afunc (&(arg))
-#else
-#define ADDRESS_FUNCTION(arg) &(arg)
-#endif
+#   define ADDRESS_FUNCTION(arg) (char *) i00afunc (&(arg))
+#  else
+#   define ADDRESS_FUNCTION(arg) &(arg)
+#  endif
 
-#if __STDC__
+#  if __STDC__
 typedef void *pointer;
-#else
+#  else
 typedef char *pointer;
-#endif
+#  endif
 
-#ifndef NULL
-#define	NULL	0
-#endif
+#  ifndef NULL
+#   define NULL 0
+#  endif
 
 /* Different portions of Emacs need to call different versions of
    malloc.  The Emacs executable needs alloca to call xmalloc, because
@@ -83,13 +83,14 @@ typedef char *pointer;
    hand, the utilities in lib-src need alloca to call malloc; some of
    them are very simple, and don't have an xmalloc routine.
 
-   Non-Emacs programs expect this to call use xmalloc.
+   Non-Emacs programs expect this to call xmalloc.
 
    Callers below should use malloc.  */
 
-#ifndef emacs
-#define malloc xmalloc
-#endif
+#  ifndef emacs
+#   undef malloc
+#   define malloc xmalloc
+#  endif
 extern pointer malloc ();
 
 /* Define STACK_DIRECTION if you know the direction of stack
@@ -100,18 +101,18 @@ extern pointer malloc ();
    STACK_DIRECTION < 0 => grows toward lower addresses
    STACK_DIRECTION = 0 => direction of growth unknown  */
 
-#ifndef STACK_DIRECTION
-#define	STACK_DIRECTION	0	/* Direction unknown.  */
-#endif
+#  ifndef STACK_DIRECTION
+#   define STACK_DIRECTION	0	/* Direction unknown.  */
+#  endif
 
-#if STACK_DIRECTION != 0
+#  if STACK_DIRECTION != 0
 
-#define	STACK_DIR	STACK_DIRECTION	/* Known at compile-time.  */
+#   define STACK_DIR	STACK_DIRECTION	/* Known at compile-time.  */
 
-#else /* STACK_DIRECTION == 0; need run-time code.  */
+#  else /* STACK_DIRECTION == 0; need run-time code.  */
 
 static int stack_dir;		/* 1 or -1 once known.  */
-#define	STACK_DIR	stack_dir
+#   define STACK_DIR	stack_dir
 
 static void
 find_stack_direction ()
@@ -135,7 +136,7 @@ find_stack_direction ()
     }
 }
 
-#endif /* STACK_DIRECTION == 0 */
+#  endif /* STACK_DIRECTION == 0 */
 
 /* An "alloca header" is used to:
    (a) chain together all alloca'ed blocks;
@@ -144,9 +145,9 @@ find_stack_direction ()
    It is very important that sizeof(header) agree with malloc
    alignment chunk size.  The following default should work okay.  */
 
-#ifndef	ALIGN_SIZE
-#define	ALIGN_SIZE	sizeof(double)
-#endif
+#  ifndef	ALIGN_SIZE
+#   define ALIGN_SIZE	sizeof(double)
+#  endif
 
 typedef union hdr
 {
@@ -168,16 +169,15 @@ static header *last_alloca_header = NULL;	/* -> last alloca header.  */
    implementations of C, for example under Gould's UTX/32.  */
 
 pointer
-alloca (size)
-     unsigned size;
+alloca (size_t size)
 {
   auto char probe;		/* Probes stack depth: */
   register char *depth = ADDRESS_FUNCTION (probe);
 
-#if STACK_DIRECTION == 0
+#  if STACK_DIRECTION == 0
   if (STACK_DIR == 0)		/* Unknown growth direction.  */
     find_stack_direction ();
-#endif
+#  endif
 
   /* Reclaim garbage, defined as all alloca'd storage that
      was allocated from deeper in the stack than currently.  */
@@ -185,9 +185,9 @@ alloca (size)
   {
     register header *hp;	/* Traverses linked list.  */
 
-#ifdef emacs
+#  ifdef emacs
     BLOCK_INPUT;
-#endif
+#  endif
 
     for (hp = last_alloca_header; hp != NULL;)
       if ((STACK_DIR > 0 && hp->h.deep > depth)
@@ -204,9 +204,9 @@ alloca (size)
 
     last_alloca_header = hp;	/* -> last valid storage.  */
 
-#ifdef emacs
+#  ifdef emacs
     UNBLOCK_INPUT;
-#endif
+#  endif
   }
 
   if (size == 0)
@@ -232,15 +232,15 @@ alloca (size)
   }
 }
 
-#if defined (CRAY) && defined (CRAY_STACKSEG_END)
+#  if defined (CRAY) && defined (CRAY_STACKSEG_END)
 
-#ifdef DEBUG_I00AFUNC
-#include <stdio.h>
-#endif
+#   ifdef DEBUG_I00AFUNC
+#    include <stdio.h>
+#   endif
 
-#ifndef CRAY_STACK
-#define CRAY_STACK
-#ifndef CRAY2
+#   ifndef CRAY_STACK
+#    define CRAY_STACK
+#    ifndef CRAY2
 /* Stack structures for CRAY-1, CRAY X-MP, and CRAY Y-MP */
 struct stack_control_header
   {
@@ -292,7 +292,7 @@ struct stack_segment_linkage
     long sss7;
   };
 
-#else /* CRAY2 */
+#    else /* CRAY2 */
 /* The following structure defines the vector of words
    returned by the STKSTAT library routine.  */
 struct stk_stat
@@ -345,10 +345,10 @@ struct stk_trailer
     long unknown14;
   };
 
-#endif /* CRAY2 */
-#endif /* not CRAY_STACK */
+#    endif /* CRAY2 */
+#   endif /* not CRAY_STACK */
 
-#ifdef CRAY2
+#   ifdef CRAY2
 /* Determine a "stack measure" for an arbitrary ADDRESS.
    I doubt that "lint" will like this much.  */
 
@@ -419,7 +419,7 @@ i00afunc (long *address)
   return (result);
 }
 
-#else /* not CRAY2 */
+#   else /* not CRAY2 */
 /* Stack address function for a CRAY-1, CRAY X-MP, or CRAY Y-MP.
    Determine the number of the cell within the stack,
    given the address of the cell.  The purpose of this
@@ -464,9 +464,9 @@ i00afunc (long address)
 
   while (!(this_segment <= address && address <= stkl))
     {
-#ifdef DEBUG_I00AFUNC
+#    ifdef DEBUG_I00AFUNC
       fprintf (stderr, "%011o %011o %011o\n", this_segment, address, stkl);
-#endif
+#    endif
       if (pseg == 0)
 	break;
       stkl = stkl - pseg;
@@ -485,9 +485,9 @@ i00afunc (long address)
 
   while (pseg != 0)
     {
-#ifdef DEBUG_I00AFUNC
+#    ifdef DEBUG_I00AFUNC
       fprintf (stderr, "%011o %011o\n", pseg, size);
-#endif
+#    endif
       stkl = stkl - pseg;
       ssptr = (struct stack_segment_linkage *) stkl;
       size = ssptr->sssize;
@@ -497,8 +497,8 @@ i00afunc (long address)
   return (result);
 }
 
-#endif /* not CRAY2 */
-#endif /* CRAY */
+#   endif /* not CRAY2 */
+#  endif /* CRAY */
 
-#endif /* no alloca */
+# endif /* no alloca */
 #endif /* not GCC version 2 */
