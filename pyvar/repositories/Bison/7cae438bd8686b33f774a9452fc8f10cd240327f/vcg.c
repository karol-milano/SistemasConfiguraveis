@@ -246,7 +246,7 @@ get_textmode_str (enum textmode_e t)
     case left_justify:	return "left_justify";
     case right_justify:	return "right_justify";
     default:
-      complain (_("vcg graph: no such text mode.."));
+      complain (_("vcg graph: no such text mode"));
       return get_textmode_str(G_TEXTMODE);
     }
   return NULL;
@@ -262,7 +262,7 @@ get_shape_str (enum shape_e s)
     case ellipse:	return "ellipse";
     case triangle:	return "triangle";
     default:
-      complain (_("vcg graph: no such shape.."));
+      complain (_("vcg graph: no such shape"));
       return get_shape_str(G_SHAPE);
     }
   return NULL;
@@ -301,7 +301,7 @@ get_decision_str (enum decision_e d, enum decision_e defaults)
     case no:	return "no";
     case yes:	return "yes";
     default:
-      complain (_("vcg graph: no such decision.."));
+      complain (_("vcg graph: no such decision"));
       return get_decision_str(defaults, 0);
     }
   return NULL;
@@ -317,7 +317,7 @@ get_orientation_str (enum orientation_e o)
     case left_to_right: return "left_to_right";
     case right_to_left: return "right_to_left";
     default:
-      complain (_("vcg graph: no such an orientation.."));
+      complain (_("vcg graph: no such an orientation"));
       return get_orientation_str(G_ORIENTATION);
     }
   return NULL;
@@ -332,7 +332,7 @@ get_node_alignement_str (enum alignement_e a)
     case top:		return "top";
     case bottom:	return "bottom";
     default:
-      complain (_("vcg graph: no such an alignement.."));
+      complain (_("vcg graph: no such an alignement"));
       return get_node_alignement_str(G_NODE_ALIGNEMENT);
     }
   return NULL;
@@ -346,7 +346,7 @@ get_arrow_mode_str (enum arrow_mode_e a)
     case fixed:		return "fixed";
     case free_a:	return "free";
     default:
-      complain (_("vcg graph: no such an arrow mode.."));
+      complain (_("vcg graph: no such an arrow mode"));
       return get_arrow_mode_str(G_ARROW_MODE);
     }
   return NULL;
@@ -362,7 +362,7 @@ get_crossing_type_str (enum crossing_type_e c)
     case barymedian:	return "barymedian";
     case medianbary:	return "medianbary";
     default:
-      complain (_("vcg graph: no such crossing_type.."));
+      complain (_("vcg graph: no such crossing_type"));
       return get_crossing_type_str(G_CROSSING_WEIGHT);
     }
   return NULL;
@@ -379,7 +379,7 @@ get_view_str (enum view_e v)
     case fcfish:	return "fcfish";
     case fpfish:	return "fpfish";
     default:
-      complain (_("vcg graph: no such view.."));
+      complain (_("vcg graph: no such view"));
       return get_view_str(G_VIEW);
     }
   return NULL;
@@ -395,7 +395,7 @@ get_linestyle_str (enum linestyle_e l)
     case dotted:	return "dotted";
     case invisible:	return "invisible";
     default:
-      complain (_("vcg graph: no such linestyle.."));
+      complain (_("vcg graph: no such linestyle"));
       return get_linestyle_str(E_LINESTYLE);
     }
   return NULL;
@@ -410,7 +410,7 @@ get_arrowstyle_str (enum arrowstyle_e a)
     case line:	return "line";
     case none:	return "none";
     default:
-      complain (_("vcg graph: no such an arrowstyle.."));
+      complain (_("vcg graph: no such an arrowstyle"));
       return get_arrowstyle_str(E_ARROWSTYLE);
     }
   return NULL;
