@@ -242,7 +242,8 @@ get_color_str (enum color_e c)
     case orchid:	return "orchid";
     case black:		return "black";
     default:
-      assert (!"Not a default color.");
+#define A_known_default_color 0
+      assert (A_known_default_color);
     }
   return NULL;
 }
@@ -256,7 +257,8 @@ get_textmode_str (enum textmode_e t)
     case left_justify:	return "left_justify";
     case right_justify:	return "right_justify";
     default:
-      assert (!"Not a text mode.");
+#define A_known_text_mode 0
+      assert (A_known_text_mode);
     }
   return NULL;
 }
@@ -271,7 +273,8 @@ get_shape_str (enum shape_e s)
     case ellipse:	return "ellipse";
     case triangle:	return "triangle";
     default:
-      assert (!"Not a shape.");
+#define A_known_shape 0
+      assert (A_known_shape);
     }
   return NULL;
 }
@@ -296,7 +299,8 @@ get_layoutalgorithm_str (enum layoutalgorithm_e l)
     case dfs:		return "dfs";
     case tree:		return "tree";
     default:
-      assert (!"Not a layout algorithm.");
+#define A_known_layout_algorithm 0
+      assert (A_known_layout_algorithm);
     }
   return NULL;
 }
@@ -309,7 +313,8 @@ get_decision_str (enum decision_e d)
     case no:	return "no";
     case yes:	return "yes";
     default:
-      assert (!"Either yes nor no.");
+#define Either_yes_nor_no 0
+      assert (Either_yes_nor_no);
     }
   return NULL;
 }
@@ -324,7 +329,8 @@ get_orientation_str (enum orientation_e o)
     case left_to_right: return "left_to_right";
     case right_to_left: return "right_to_left";
     default:
-      assert (!"Not an orientation.");
+#define A_knownn_orientation 0
+      assert (A_knownn_orientation);
     }
   return NULL;
 }
@@ -338,7 +344,8 @@ get_node_alignement_str (enum alignement_e a)
     case top:		return "top";
     case bottom:	return "bottom";
     default:
-      assert (!"Not an alignement.");
+#define A_known_alignement 0
+      assert (A_known_alignement);
     }
   return NULL;
 }
@@ -351,7 +358,8 @@ get_arrow_mode_str (enum arrow_mode_e a)
     case fixed:		return "fixed";
     case free_a:	return "free";
     default:
-      assert (!"Not an arrow mode.");
+#define A_known_arrow_mode 0
+      assert (A_known_arrow_mode);
     }
   return NULL;
 }
@@ -366,7 +374,8 @@ get_crossing_type_str (enum crossing_type_e c)
     case barymedian:	return "barymedian";
     case medianbary:	return "medianbary";
     default:
-      assert (!"Not a crossing type.");
+#define A_known_crossing_type 0
+      assert (A_known_crossing_type);
     }
   return NULL;
 }
@@ -382,7 +391,8 @@ get_view_str (enum view_e v)
     case fcfish:	return "fcfish";
     case fpfish:	return "fpfish";
     default:
-      assert (!"Not a view.");
+#define A_known_view 0
+      assert (A_known_view);
     }
   return NULL;
 }
@@ -397,7 +407,8 @@ get_linestyle_str (enum linestyle_e l)
     case dotted:	return "dotted";
     case invisible:	return "invisible";
     default:
-      assert (!"Not a line style.");
+#define A_known_line_style 0
+      assert (A_known_line_style);
     }
   return NULL;
 }
@@ -411,7 +422,8 @@ get_arrowstyle_str (enum arrowstyle_e a)
     case line:	return "line";
     case none:	return "none";
     default:
-      assert (!"Not an arrow style.");
+#define A_known_arrow_style 0
+      assert (A_known_arrow_style);
     }
   return NULL;
 }
