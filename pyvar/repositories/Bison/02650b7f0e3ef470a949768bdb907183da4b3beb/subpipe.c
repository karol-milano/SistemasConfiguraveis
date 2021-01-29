@@ -19,7 +19,7 @@
 /* Written by Paul Eggert <eggert@twinsun.com>
    and Florian Krohm <florian@edamail.fishkill.ibm.com>.  */
 
-#if HAVE_CONFIG_H
+#ifdef HAVE_CONFIG_H
 # include <config.h>
 #endif
 
@@ -73,7 +73,7 @@
 
 #ifndef __attribute__
 /* This feature is available in gcc versions 2.5 and later.  */
-# if !defined (__GNUC__) || __GNUC__ < 2 || \
+# if ! defined __GNUC__ || __GNUC__ < 2 || \
 (__GNUC__ == 2 && __GNUC_MINOR__ < 5) || __STRICT_ANSI__
 #  define __attribute__(Spec) /* empty */
 # endif
