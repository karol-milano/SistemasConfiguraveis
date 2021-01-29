@@ -1286,12 +1286,12 @@ parse_action (symbol_list *rule, int rule_length)
 	switch (c)
 	  {
 	  case '\n':
-	    obstack_1grow (&action_obstack, c);
+	    copy_character (&action_obstack, c);
 	    ++lineno;
 	    break;
 
 	  case '{':
-	    obstack_1grow (&action_obstack, c);
+	    copy_character (&action_obstack, c);
 	    ++count;
 	    break;
 
@@ -1316,12 +1316,12 @@ parse_action (symbol_list *rule, int rule_length)
 	    fatal (_("unmatched %s"), "`{'");
 
 	  default:
-	    obstack_1grow (&action_obstack, c);
+	    copy_character (&action_obstack, c);
 	  }
 
       /* Above loop exits when C is '}'.  */
       if (--count)
-	obstack_1grow (&action_obstack, c);
+	copy_character (&action_obstack, c);
     }
 
   obstack_1grow (&action_obstack, '\0');
