@@ -73,7 +73,7 @@ log_resolution (rule *r, symbol_number token,
 	{
 	case shift_resolution:
 	case right_resolution:
-	  obstack_fgrow2 (&solved_conflicts_obstack,
+	  obstack_printf (&solved_conflicts_obstack,
 			  _("    Conflict between rule %d and token %s"
 			    " resolved as shift"),
 			  r->number,
@@ -82,7 +82,7 @@ log_resolution (rule *r, symbol_number token,
 
 	case reduce_resolution:
 	case left_resolution:
-	  obstack_fgrow2 (&solved_conflicts_obstack,
+	  obstack_printf (&solved_conflicts_obstack,
 			  _("    Conflict between rule %d and token %s"
 			    " resolved as reduce"),
 			  r->number,
@@ -90,7 +90,7 @@ log_resolution (rule *r, symbol_number token,
 	  break;
 
 	case nonassoc_resolution:
-	  obstack_fgrow2 (&solved_conflicts_obstack,
+	  obstack_printf (&solved_conflicts_obstack,
 			  _("    Conflict between rule %d and token %s"
 			    " resolved as an error"),
 			  r->number,
@@ -102,33 +102,33 @@ log_resolution (rule *r, symbol_number token,
       switch (resolution)
 	{
 	case shift_resolution:
-	  obstack_fgrow2 (&solved_conflicts_obstack,
+	  obstack_printf (&solved_conflicts_obstack,
 			  " (%s < %s)",
 			  r->prec->tag,
 			  symbols[token]->tag);
 	  break;
 
 	case reduce_resolution:
-	  obstack_fgrow2 (&solved_conflicts_obstack,
+	  obstack_printf (&solved_conflicts_obstack,
 			  " (%s < %s)",
 			  symbols[token]->tag,
 			  r->prec->tag);
 	  break;
 
 	case left_resolution:
-	  obstack_fgrow1 (&solved_conflicts_obstack,
+	  obstack_printf (&solved_conflicts_obstack,
 			  " (%%left %s)",
 			  symbols[token]->tag);
 	  break;
 
 	case right_resolution:
-	  obstack_fgrow1 (&solved_conflicts_obstack,
+	  obstack_printf (&solved_conflicts_obstack,
 			  " (%%right %s)",
 			  symbols[token]->tag);
 	  break;
 
 	case nonassoc_resolution:
-	  obstack_fgrow1 (&solved_conflicts_obstack,
+	  obstack_printf (&solved_conflicts_obstack,
 			  " (%%nonassoc %s)",
 			  symbols[token]->tag);
 	  break;
@@ -145,7 +145,7 @@ log_resolution (rule *r, symbol_number token,
         {
         case shift_resolution:
         case right_resolution:
-          obstack_fgrow2 (&solved_conflicts_xml_obstack,
+          obstack_printf (&solved_conflicts_xml_obstack,
                           "        <resolution rule=\"%d\" symbol=\"%s\""
                           " type=\"shift\">",
                           r->number,
@@ -154,7 +154,7 @@ log_resolution (rule *r, symbol_number token,
 
         case reduce_resolution:
         case left_resolution:
-          obstack_fgrow2 (&solved_conflicts_xml_obstack,
+          obstack_printf (&solved_conflicts_xml_obstack,
                           "        <resolution rule=\"%d\" symbol=\"%s\""
                           " type=\"reduce\">",
                           r->number,
@@ -162,7 +162,7 @@ log_resolution (rule *r, symbol_number token,
           break;
 
         case nonassoc_resolution:
-          obstack_fgrow2 (&solved_conflicts_xml_obstack,
+          obstack_printf (&solved_conflicts_xml_obstack,
                           "        <resolution rule=\"%d\" symbol=\"%s\""
                           " type=\"error\">",
                           r->number,
@@ -174,33 +174,33 @@ log_resolution (rule *r, symbol_number token,
       switch (resolution)
         {
         case shift_resolution:
-          obstack_fgrow2 (&solved_conflicts_xml_obstack,
+          obstack_printf (&solved_conflicts_xml_obstack,
                           "%s &lt; %s",
                           xml_escape_n (0, r->prec->tag),
                           xml_escape_n (1, symbols[token]->tag));
           break;
 
         case reduce_resolution:
-          obstack_fgrow2 (&solved_conflicts_xml_obstack,
+          obstack_printf (&solved_conflicts_xml_obstack,
                           "%s &lt; %s",
                           xml_escape_n (0, symbols[token]->tag),
                           xml_escape_n (1, r->prec->tag));
           break;
 
         case left_resolution:
-          obstack_fgrow1 (&solved_conflicts_xml_obstack,
+          obstack_printf (&solved_conflicts_xml_obstack,
                           "%%left %s",
                           xml_escape (symbols[token]->tag));
           break;
 
         case right_resolution:
-          obstack_fgrow1 (&solved_conflicts_xml_obstack,
+          obstack_printf (&solved_conflicts_xml_obstack,
                           "%%right %s",
                           xml_escape (symbols[token]->tag));
           break;
 
         case nonassoc_resolution:
-          obstack_fgrow1 (&solved_conflicts_xml_obstack,
+          obstack_printf (&solved_conflicts_xml_obstack,
                           "%%nonassoc %s",
                           xml_escape (symbols[token]->tag));
       break;
