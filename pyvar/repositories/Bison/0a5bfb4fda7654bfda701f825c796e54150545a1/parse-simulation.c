@@ -28,7 +28,7 @@
 #include "lssi.h"
 #include "nullable.h"
 
-typedef struct parse_state
+struct parse_state
 {
   // Path of state-items the parser has traversed.
   struct si_chunk
@@ -58,7 +58,7 @@ typedef struct parse_state
   // Causes chunk contents to be freed when the reference count is
   // one. Used when only the chunk metadata will be needed.
   bool free_contents_early;
-} parse_state;
+};
 
 
 static void
