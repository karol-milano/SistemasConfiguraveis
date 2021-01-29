@@ -1,6 +1,6 @@
 /* Muscle table manager for Bison.
 
-   Copyright (C) 2001, 2002, 2003, 2004, 2005, 2006, 2007 Free Software
+   Copyright (C) 2001, 2002, 2003, 2004, 2005, 2006, 2007, 2009 Free Software
    Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -540,13 +540,12 @@ muscle_percent_define_default (char const *variable, char const *value)
     {
       location loc;
       MUSCLE_INSERT_STRING (name, value);
-      loc.start.file = loc.end.file = "[Bison:muscle_percent_define_default]";
-      loc.start.line = loc.end.line = 1;
-      loc.start.column = loc.end.column = 0;
+      loc.start.file = loc.end.file = "<default value>";
+      loc.start.line = loc.end.line = -1;
+      loc.start.column = loc.end.column = -1;
       muscle_insert (loc_name, "");
       muscle_location_grow (loc_name, loc);
       muscle_insert (syncline_name, "");
-      muscle_syncline_grow (syncline_name, loc);
     }
 }
 
