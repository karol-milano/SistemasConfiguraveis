@@ -35,9 +35,6 @@
 #include "getargs.h"
 #include "gram.h"
 
-struct obstack pre_prologue_obstack;
-struct obstack post_prologue_obstack;
-
 /* Initializing some values below (such SPEC_NAME_PREFIX to `yy') is
    tempting, but don't do that: for the time being our handling of the
    %directive vs --option leaves precedence to the options by deciding
