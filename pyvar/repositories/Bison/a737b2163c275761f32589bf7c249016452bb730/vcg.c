@@ -1,6 +1,6 @@
 /* VCG description handler for Bison.
 
-   Copyright (C) 2001, 2002 Free Software Foundation, Inc.
+   Copyright (C) 2001, 2002, 2003 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -210,9 +210,9 @@ new_edge (edge *e)
 `----------------------------------------------*/
 
 static const char *
-get_color_str (enum color c)
+get_color_str (enum color color)
 {
-  switch (c)
+  switch (color)
     {
     case white:		return "white";
     case blue:		return "blue";
@@ -251,9 +251,9 @@ get_color_str (enum color c)
 }
 
 static const char *
-get_textmode_str (enum textmode t)
+get_textmode_str (enum textmode textmode)
 {
-  switch (t)
+  switch (textmode)
     {
     case centered:	return "center";
     case left_justify:	return "left_justify";
@@ -263,9 +263,9 @@ get_textmode_str (enum textmode t)
 }
 
 static const char *
-get_shape_str (enum shape s)
+get_shape_str (enum shape shape)
 {
-  switch (s)
+  switch (shape)
     {
     case box:		return "box";
     case rhomb:		return "rhomb";
@@ -276,9 +276,9 @@ get_shape_str (enum shape s)
 }
 
 static const char *
-get_layoutalgorithm_str (enum layoutalgorithm l)
+get_layoutalgorithm_str (enum layoutalgorithm layoutalgorithm)
 {
-  switch (l)
+  switch (layoutalgorithm)
     {
     case normal:       	return "normal";
     case maxdepth:	return "maxdepth";
@@ -299,9 +299,9 @@ get_layoutalgorithm_str (enum layoutalgorithm l)
 }
 
 static const char *
-get_decision_str (enum decision d)
+get_decision_str (enum decision decision)
 {
-  switch (d)
+  switch (decision)
     {
     case no:	return "no";
     case yes:	return "yes";
@@ -310,9 +310,9 @@ get_decision_str (enum decision d)
 }
 
 static const char *
-get_orientation_str (enum orientation o)
+get_orientation_str (enum orientation orientation)
 {
-  switch (o)
+  switch (orientation)
     {
     case top_to_bottom:	return "top_to_bottom";
     case bottom_to_top: return "bottom_to_top";
@@ -323,9 +323,9 @@ get_orientation_str (enum orientation o)
 }
 
 static const char *
-get_node_alignment_str (enum alignment a)
+get_node_alignment_str (enum alignment alignment)
 {
-  switch (a)
+  switch (alignment)
     {
     case center:	return "center";
     case top:		return "top";
@@ -335,9 +335,9 @@ get_node_alignment_str (enum alignment a)
 }
 
 static const char *
-get_arrow_mode_str (enum arrow_mode a)
+get_arrow_mode_str (enum arrow_mode arrow_mode)
 {
-  switch (a)
+  switch (arrow_mode)
     {
     case fixed:		return "fixed";
     case free_a:	return "free";
@@ -346,9 +346,9 @@ get_arrow_mode_str (enum arrow_mode a)
 }
 
 static const char *
-get_crossing_type_str (enum crossing_type c)
+get_crossing_type_str (enum crossing_type crossing_type)
 {
-  switch (c)
+  switch (crossing_type)
     {
     case bary:		return "bary";
     case median:	return "median";
@@ -359,9 +359,9 @@ get_crossing_type_str (enum crossing_type c)
 }
 
 static const char *
-get_view_str (enum view v)
+get_view_str (enum view view)
 {
-  switch (v)
+  switch (view)
     {
     case normal_view:	return "normal_view";
     case cfish:		return "cfish";
@@ -373,9 +373,9 @@ get_view_str (enum view v)
 }
 
 static const char *
-get_linestyle_str (enum linestyle l)
+get_linestyle_str (enum linestyle linestyle)
 {
-  switch (l)
+  switch (linestyle)
     {
     case continuous:	return "continuous";
     case dashed:	return "dashed";
@@ -386,9 +386,9 @@ get_linestyle_str (enum linestyle l)
 }
 
 static const char *
-get_arrowstyle_str (enum arrowstyle a)
+get_arrowstyle_str (enum arrowstyle arrowstyle)
 {
-  switch (a)
+  switch (arrowstyle)
     {
     case solid:	return "solid";
     case line:	return "line";
