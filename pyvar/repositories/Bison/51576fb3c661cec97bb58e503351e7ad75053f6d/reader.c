@@ -1198,7 +1198,13 @@ copy_action (symbol_list *rule, int stack_offset)
 	}
     }
 
-  obstack_sgrow (&action_obstack, ";\n    break;}");
+  /* As a Bison extension, add the ending semicolon.  Since some Yacc
+     don't do that, help people using bison as a Yacc finding their
+     missing semicolons.  */
+  if (yacc_flag)
+    obstack_sgrow (&action_obstack, "}\n    break;");
+  else
+    obstack_sgrow (&action_obstack, ";\n    break;}");
 }
 
 /*-------------------------------------------------------------------.
