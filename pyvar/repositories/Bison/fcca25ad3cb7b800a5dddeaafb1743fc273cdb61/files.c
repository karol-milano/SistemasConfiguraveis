@@ -18,7 +18,7 @@ along with Bison; see the file COPYING.  If not, write to
 the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
 
 
-#ifdef VMS
+#if defined (VMS) & !defined (__VMS_POSIX)
 #include <ssdef.h>
 #define unlink delete
 #ifndef XPFILE
@@ -108,7 +108,7 @@ openfiles()
   int base_length;
   int short_base_length;
 
-#ifdef VMS
+#if defined (VMS) & !defined (__VMS_POSIX)
   char *tmp_base = "sys$scratch:b_";
 #else
   char *tmp_base = "/tmp/b.";
@@ -373,7 +373,7 @@ int k;
         }
     }
 
-#ifdef VMS
+#if defined (VMS) & !defined (__VMS_POSIX)
   if (faction)
     delete(actfile);
   if (fattrs)
@@ -390,5 +390,5 @@ int k;
   if (tmpdefsfile) unlink(tmpdefsfile);
 #endif /* MSDOS */
   exit(k);
-#endif /* not VMS */
+#endif /* not VMS, or __VMS_POSIX */
 }
