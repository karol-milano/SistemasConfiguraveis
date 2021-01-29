@@ -1,6 +1,7 @@
 /* VCG description handler for Bison.
 
-   Copyright (C) 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.
+   Copyright (C) 2001, 2002, 2003, 2004, 2005, 2006 Free Software
+   Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -213,6 +214,7 @@ get_color_str (enum color color)
 {
   switch (color)
     {
+    default:		abort ();
     case white:		return "white";
     case blue:		return "blue";
     case red:		return "red";
@@ -245,7 +247,6 @@ get_color_str (enum color color)
     case orange:	return "orange";
     case orchid:	return "orchid";
     case black:		return "black";
-    default:		abort (); return NULL;
     }
 }
 
@@ -254,10 +255,10 @@ get_textmode_str (enum textmode textmode)
 {
   switch (textmode)
     {
+    default:		abort ();
     case centered:	return "center";
     case left_justify:	return "left_justify";
     case right_justify:	return "right_justify";
-    default:		abort (); return NULL;
     }
 }
 
@@ -266,11 +267,11 @@ get_shape_str (enum shape shape)
 {
   switch (shape)
     {
+    default:		abort ();
     case box:		return "box";
     case rhomb:		return "rhomb";
     case ellipse:	return "ellipse";
     case triangle:	return "triangle";
-    default:		abort (); return NULL;
     }
 }
 
@@ -279,9 +280,9 @@ get_decision_str (enum decision decision)
 {
   switch (decision)
     {
+    default:	abort ();
     case no:	return "no";
     case yes:	return "yes";
-    default:	abort (); return NULL;
     }
 }
 
@@ -290,11 +291,11 @@ get_orientation_str (enum orientation orientation)
 {
   switch (orientation)
     {
+    default:		abort ();
     case top_to_bottom:	return "top_to_bottom";
     case bottom_to_top: return "bottom_to_top";
     case left_to_right: return "left_to_right";
     case right_to_left: return "right_to_left";
-    default:		abort (); return NULL;
     }
 }
 
@@ -303,10 +304,10 @@ get_node_alignment_str (enum alignment alignment)
 {
   switch (alignment)
     {
+    default:		abort ();
     case center:	return "center";
     case top:		return "top";
     case bottom:	return "bottom";
-    default:		abort (); return NULL;
     }
 }
 
@@ -315,9 +316,9 @@ get_arrow_mode_str (enum arrow_mode arrow_mode)
 {
   switch (arrow_mode)
     {
+    default:		abort ();
     case fixed:		return "fixed";
     case free_a:	return "free";
-    default:		abort (); return NULL;
     }
 }
 
@@ -326,11 +327,11 @@ get_crossing_type_str (enum crossing_type crossing_type)
 {
   switch (crossing_type)
     {
+    default:		abort ();
     case bary:		return "bary";
     case median:	return "median";
     case barymedian:	return "barymedian";
     case medianbary:	return "medianbary";
-    default:		abort (); return NULL;
     }
 }
 
@@ -341,11 +342,11 @@ get_view_str (enum view view)
      so it is an error here if view == normal_view.  */
   switch (view)
     {
+    default:		abort ();
     case cfish:		return "cfish";
     case pfish:		return "pfish";
     case fcfish:	return "fcfish";
     case fpfish:	return "fpfish";
-    default:		abort (); return NULL;
     }
 }
 
@@ -354,11 +355,11 @@ get_linestyle_str (enum linestyle linestyle)
 {
   switch (linestyle)
     {
+    default:		abort ();
     case continuous:	return "continuous";
     case dashed:	return "dashed";
     case dotted:	return "dotted";
     case invisible:	return "invisible";
-    default:		abort (); return NULL;
     }
 }
 
@@ -367,10 +368,10 @@ get_arrowstyle_str (enum arrowstyle arrowstyle)
 {
   switch (arrowstyle)
     {
+    default:	abort ();
     case solid:	return "solid";
     case line:	return "line";
     case none:	return "none";
-    default:	abort (); return NULL;
     }
 }
 
