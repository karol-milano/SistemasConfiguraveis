@@ -135,78 +135,78 @@ log_resolution (rule *r, symbol_number token,
 	}
 
       obstack_sgrow (&solved_conflicts_obstack, ".\n");
+    }
 
-      /* XML report */
-      if (xml_flag)
-	{
-	  /* The description of the resolution. */
-	  switch (resolution)
-	    {
-	    case shift_resolution:
-	    case right_resolution:
-	      obstack_fgrow2 (&solved_conflicts_xml_obstack,
-			      "        <resolution rule=\"%d\" symbol=\"%s\""
-			      " type=\"shift\">",
-			      r->number,
-			      xml_escape (symbols[token]->tag));
-	      break;
-
-	    case reduce_resolution:
-	    case left_resolution:
-	      obstack_fgrow2 (&solved_conflicts_xml_obstack,
-			      "        <resolution rule=\"%d\" symbol=\"%s\""
-			      " type=\"reduce\">",
-			      r->number,
-			      xml_escape (symbols[token]->tag));
-	      break;
-
-	    case nonassoc_resolution:
-	      obstack_fgrow2 (&solved_conflicts_xml_obstack,
-			      "        <resolution rule=\"%d\" symbol=\"%s\""
-			      " type=\"error\">",
-			      r->number,
-			      xml_escape (symbols[token]->tag));
-	      break;
-	    }
-
-	  /* The reason. */
-	  switch (resolution)
-	    {
-	    case shift_resolution:
-	      obstack_fgrow2 (&solved_conflicts_xml_obstack,
-			      "%s &lt; %s",
-			      xml_escape_n (0, r->prec->tag),
-			      xml_escape_n (1, symbols[token]->tag));
-	      break;
-
-	    case reduce_resolution:
-	      obstack_fgrow2 (&solved_conflicts_xml_obstack,
-			      "%s &lt; %s",
-			      xml_escape_n (0, symbols[token]->tag),
-			      xml_escape_n (1, r->prec->tag));
-	      break;
-
-	    case left_resolution:
-	      obstack_fgrow1 (&solved_conflicts_xml_obstack,
-			      "%%left %s",
-			      xml_escape (symbols[token]->tag));
-	      break;
-
-	    case right_resolution:
-	      obstack_fgrow1 (&solved_conflicts_xml_obstack,
-			      "%%right %s",
-			      xml_escape (symbols[token]->tag));
-	      break;
-
-	    case nonassoc_resolution:
-	      obstack_fgrow1 (&solved_conflicts_xml_obstack,
-			      "%%nonassoc %s",
-			      xml_escape (symbols[token]->tag));
-	  break;
-	    }
+  /* XML report */
+  if (xml_flag)
+    {
+      /* The description of the resolution. */
+      switch (resolution)
+        {
+        case shift_resolution:
+        case right_resolution:
+          obstack_fgrow2 (&solved_conflicts_xml_obstack,
+                          "        <resolution rule=\"%d\" symbol=\"%s\""
+                          " type=\"shift\">",
+                          r->number,
+                          xml_escape (symbols[token]->tag));
+          break;
+
+        case reduce_resolution:
+        case left_resolution:
+          obstack_fgrow2 (&solved_conflicts_xml_obstack,
+                          "        <resolution rule=\"%d\" symbol=\"%s\""
+                          " type=\"reduce\">",
+                          r->number,
+                          xml_escape (symbols[token]->tag));
+          break;
+
+        case nonassoc_resolution:
+          obstack_fgrow2 (&solved_conflicts_xml_obstack,
+                          "        <resolution rule=\"%d\" symbol=\"%s\""
+                          " type=\"error\">",
+                          r->number,
+                          xml_escape (symbols[token]->tag));
+          break;
+        }
 
-	  obstack_sgrow (&solved_conflicts_xml_obstack, "</resolution>\n");
-	}
+      /* The reason. */
+      switch (resolution)
+        {
+        case shift_resolution:
+          obstack_fgrow2 (&solved_conflicts_xml_obstack,
+                          "%s &lt; %s",
+                          xml_escape_n (0, r->prec->tag),
+                          xml_escape_n (1, symbols[token]->tag));
+          break;
+
+        case reduce_resolution:
+          obstack_fgrow2 (&solved_conflicts_xml_obstack,
+                          "%s &lt; %s",
+                          xml_escape_n (0, symbols[token]->tag),
+                          xml_escape_n (1, r->prec->tag));
+          break;
+
+        case left_resolution:
+          obstack_fgrow1 (&solved_conflicts_xml_obstack,
+                          "%%left %s",
+                          xml_escape (symbols[token]->tag));
+          break;
+
+        case right_resolution:
+          obstack_fgrow1 (&solved_conflicts_xml_obstack,
+                          "%%right %s",
+                          xml_escape (symbols[token]->tag));
+          break;
+
+        case nonassoc_resolution:
+          obstack_fgrow1 (&solved_conflicts_xml_obstack,
+                          "%%nonassoc %s",
+                          xml_escape (symbols[token]->tag));
+      break;
+        }
+
+      obstack_sgrow (&solved_conflicts_xml_obstack, "</resolution>\n");
     }
 }
 
