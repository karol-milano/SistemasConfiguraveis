@@ -19,13 +19,14 @@
    Boston, MA 02111-1307, USA.  */
 
 #include "system.h"
+
 #include "assoc.h"
 
 
 const char *
-assoc_to_string (assoc_t assoc)
+assoc_to_string (assoc a)
 {
-  switch (assoc)
+  switch (a)
     {
     case undef_assoc:
       return "undefined associativity";
