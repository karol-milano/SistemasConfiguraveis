@@ -1154,10 +1154,7 @@ parse_braces (symbol_list *rule, int stack_offset)
 
       /* Above loop exits when C is '}'.  */
       if (--count)
-	{
-	  obstack_1grow (&action_obstack, c);
-	  c = getc (finput);
-	}
+	obstack_1grow (&action_obstack, c);
     }
 
   obstack_1grow (&action_obstack, '\0');
