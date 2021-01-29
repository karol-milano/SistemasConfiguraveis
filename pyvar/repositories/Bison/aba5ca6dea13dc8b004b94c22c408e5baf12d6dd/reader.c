@@ -1142,7 +1142,7 @@ int stack_offset;
 	      continue;
 	    }
 	  else
-	    warni(_("$%s is invalid"), printable_version(c));
+	    warns(_("$%s is invalid"), printable_version(c));
 
 	  break;
 
@@ -1156,7 +1156,7 @@ int stack_offset;
 	    }
 	  else
 	    {
-	      warni(_("@%s is invalid"), printable_version(c));
+	      warns(_("@%s is invalid"), printable_version(c));
 	      n = 1;
 	    }
 
@@ -1364,7 +1364,7 @@ int stack_offset;
 		  continue;
 		}
 	      else
-		warni(_("$%s is invalid"), printable_version(c));
+		warns(_("$%s is invalid"), printable_version(c));
 
 	      break;
 
