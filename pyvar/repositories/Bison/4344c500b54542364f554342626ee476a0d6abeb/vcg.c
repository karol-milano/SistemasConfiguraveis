@@ -1,5 +1,5 @@
 /* VCG description handler for Bison.
-   Copyright 2001, 2002 Free Software Foundation, Inc.
+   Copyright (C) 2001, 2002 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -243,11 +243,8 @@ get_color_str (enum color_e c)
     case orange:	return "orange";
     case orchid:	return "orchid";
     case black:		return "black";
-    default:
-#define A_known_default_color 0
-      assert (A_known_default_color);
+    default:		abort (); return NULL;
     }
-  return NULL;
 }
 
 static const char *
@@ -258,11 +255,8 @@ get_textmode_str (enum textmode_e t)
     case centered:	return "center";
     case left_justify:	return "left_justify";
     case right_justify:	return "right_justify";
-    default:
-#define A_known_text_mode 0
-      assert (A_known_text_mode);
+    default:		abort (); return NULL;
     }
-  return NULL;
 }
 
 static const char *
@@ -274,11 +268,8 @@ get_shape_str (enum shape_e s)
     case rhomb:		return "rhomb";
     case ellipse:	return "ellipse";
     case triangle:	return "triangle";
-    default:
-#define A_known_shape 0
-      assert (A_known_shape);
+    default:		abort (); return NULL;
     }
-  return NULL;
 }
 
 static const char *
@@ -300,11 +291,8 @@ get_layoutalgorithm_str (enum layoutalgorithm_e l)
     case minbackward:	return "minbackward";
     case dfs:		return "dfs";
     case tree:		return "tree";
-    default:
-#define A_known_layout_algorithm 0
-      assert (A_known_layout_algorithm);
+    default:		abort (); return NULL;
     }
-  return NULL;
 }
 
 static const char *
@@ -314,11 +302,8 @@ get_decision_str (enum decision_e d)
     {
     case no:	return "no";
     case yes:	return "yes";
-    default:
-#define Either_yes_nor_no 0
-      assert (Either_yes_nor_no);
+    default:	abort (); return NULL;
     }
-  return NULL;
 }
 
 static const char *
@@ -330,11 +315,8 @@ get_orientation_str (enum orientation_e o)
     case bottom_to_top: return "bottom_to_top";
     case left_to_right: return "left_to_right";
     case right_to_left: return "right_to_left";
-    default:
-#define A_knownn_orientation 0
-      assert (A_knownn_orientation);
+    default:		abort (); return NULL;
     }
-  return NULL;
 }
 
 static const char *
@@ -345,11 +327,8 @@ get_node_alignement_str (enum alignement_e a)
     case center:	return "center";
     case top:		return "top";
     case bottom:	return "bottom";
-    default:
-#define A_known_alignement 0
-      assert (A_known_alignement);
+    default:		abort (); return NULL;
     }
-  return NULL;
 }
 
 static const char *
@@ -359,11 +338,8 @@ get_arrow_mode_str (enum arrow_mode_e a)
     {
     case fixed:		return "fixed";
     case free_a:	return "free";
-    default:
-#define A_known_arrow_mode 0
-      assert (A_known_arrow_mode);
+    default:		abort (); return NULL;
     }
-  return NULL;
 }
 
 static const char *
@@ -375,11 +351,8 @@ get_crossing_type_str (enum crossing_type_e c)
     case median:	return "median";
     case barymedian:	return "barymedian";
     case medianbary:	return "medianbary";
-    default:
-#define A_known_crossing_type 0
-      assert (A_known_crossing_type);
+    default:		abort (); return NULL;
     }
-  return NULL;
 }
 
 static const char *
@@ -392,11 +365,8 @@ get_view_str (enum view_e v)
     case pfish:		return "pfish";
     case fcfish:	return "fcfish";
     case fpfish:	return "fpfish";
-    default:
-#define A_known_view 0
-      assert (A_known_view);
+    default:		abort (); return NULL;
     }
-  return NULL;
 }
 
 static const char *
@@ -408,11 +378,8 @@ get_linestyle_str (enum linestyle_e l)
     case dashed:	return "dashed";
     case dotted:	return "dotted";
     case invisible:	return "invisible";
-    default:
-#define A_known_line_style 0
-      assert (A_known_line_style);
+    default:		abort (); return NULL;
     }
-  return NULL;
 }
 
 static const char *
@@ -423,11 +390,8 @@ get_arrowstyle_str (enum arrowstyle_e a)
     case solid:	return "solid";
     case line:	return "line";
     case none:	return "none";
-    default:
-#define A_known_arrow_style 0
-      assert (A_known_arrow_style);
+    default:	abort (); return NULL;
     }
-  return NULL;
 }
 
 /*----------------------------.
