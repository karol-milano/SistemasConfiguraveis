@@ -422,7 +422,7 @@ packgram (void)
       rules[ruleno].lhs = p->sym;
       rules[ruleno].rhs = ritem + itemno;
       rules[ruleno].location = p->location;
-      rules[ruleno].useful = TRUE;
+      rules[ruleno].useful = true;
       rules[ruleno].action = p->action;
       rules[ruleno].action_location = p->action_location;
       rules[ruleno].dprec = p->dprec;
@@ -507,8 +507,8 @@ reader (void)
 
   /* If something went wrong during the parsing, don't try to
      continue.  */
-  if (complain_message_count)
-    exit (1);
+  if (complaint_issued)
+    exit (EXIT_FAILURE);
 
   /* Grammar has been read.  Do some checking */
   if (nrules == 0)
