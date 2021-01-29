@@ -1,5 +1,5 @@
 /* Parse command line arguments for bison.
-   Copyright 1984, 1986, 1989, 1992, 2000, 2001, 2002
+   Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002
    Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -410,11 +410,12 @@ getargs (int argc, char *argv[])
 	exit (1);
       }
 
-  if (optind != argc - 1)
+  if (argc - optind != 1)
     {
-      error (0, 0,
-	     (optind == argc
-	      ? _("too few arguments") : _("too many arguments")));
+      if (argc - optind < 1)
+	error (0, 0, _("missing operand after `%s'"), argv[argc - 1]);
+      else
+	error (0, 0, _("extra operand `%s'"), argv[optind + 1]);
       usage (EXIT_FAILURE);
     }
 
