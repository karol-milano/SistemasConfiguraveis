@@ -231,7 +231,7 @@ get_color_str (enum color_e c)
     case orchid:	return "orchid";
     case black:		return "black";
     default:
-      complain (_("vcg graph: no such a color."));
+      complain (_("vcg graph: no such color."));
       return get_color_str(G_COLOR);
     }
   return NULL;
@@ -246,7 +246,7 @@ get_textmode_str (enum textmode_e t)
     case left_justify:	return "left_justify";
     case right_justify:	return "right_justify";
     default:
-      complain (_("vcg graph: no such a text mode.."));
+      complain (_("vcg graph: no such text mode.."));
       return get_textmode_str(G_TEXTMODE);
     }
   return NULL;
@@ -262,7 +262,7 @@ get_shape_str (enum shape_e s)
     case ellipse:	return "ellipse";
     case triangle:	return "triangle";
     default:
-      complain (_("vcg graph: no such a shape.."));
+      complain (_("vcg graph: no such shape.."));
       return get_shape_str(G_SHAPE);
     }
   return NULL;
@@ -301,7 +301,7 @@ get_decision_str (enum decision_e d, enum decision_e defaults)
     case no:	return "no";
     case yes:	return "yes";
     default:
-      complain (_("vcg graph: no such a decision.."));
+      complain (_("vcg graph: no such decision.."));
       return get_decision_str(defaults, 0);
     }
   return NULL;
@@ -362,7 +362,7 @@ get_crossing_type_str (enum crossing_type_e c)
     case barymedian:	return "barymedian";
     case medianbary:	return "medianbary";
     default:
-      complain (_("vcg graph: no such a crossing_type.."));
+      complain (_("vcg graph: no such crossing_type.."));
       return get_crossing_type_str(G_CROSSING_WEIGHT);
     }
   return NULL;
@@ -379,7 +379,7 @@ get_view_str (enum view_e v)
     case fcfish:	return "fcfish";
     case fpfish:	return "fpfish";
     default:
-      complain (_("vcg graph: no such a view.."));
+      complain (_("vcg graph: no such view.."));
       return get_view_str(G_VIEW);
     }
   return NULL;
@@ -395,7 +395,7 @@ get_linestyle_str (enum linestyle_e l)
     case dotted:	return "dotted";
     case invisible:	return "invisible";
     default:
-      complain (_("vcg graph: no such a linestyle.."));
+      complain (_("vcg graph: no such linestyle.."));
       return get_linestyle_str(E_LINESTYLE);
     }
   return NULL;
