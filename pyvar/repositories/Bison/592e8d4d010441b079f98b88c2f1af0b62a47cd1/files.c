@@ -1,5 +1,5 @@
 /* Open and close files for bison,
-   Copyright 1984, 1986, 1989, 1992, 2000, 2001, 2002
+   Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002
    Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -32,8 +32,6 @@ const char *base_name PARAMS ((char const *name));
 
 FILE *finput = NULL;
 
-struct obstack action_obstack;
-struct obstack output_obstack;
 struct obstack pre_prologue_obstack;
 struct obstack post_prologue_obstack;
 
