@@ -361,7 +361,7 @@ warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n\
 `--------------------------------------*/
 
 void
-skeleton_arg (char const *arg, int prio, location const *loc)
+skeleton_arg (char const *arg, int prio, location loc)
 {
   if (prio < skeleton_prio)
     {
@@ -372,15 +372,12 @@ skeleton_arg (char const *arg, int prio, location const *loc)
     {
       char const *msg =
 	_("multiple skeleton declarations are invalid");
-      if (loc)
-	complain_at (*loc, msg);
-      else
-	complain (msg);
+      complain_at (loc, msg);
     }
 }
 
 void
-language_argmatch (char const *arg, int prio, location const *loc)
+language_argmatch (char const *arg, int prio, location loc)
 {
   char const *msg;
 
@@ -401,10 +398,7 @@ language_argmatch (char const *arg, int prio, location const *loc)
   else
     return;
 
-  if (loc)
-    complain_at (*loc, msg, arg);
-  else
-    complain (msg, arg);
+  complain_at (loc, msg, arg);
 }
 
 /*----------------------.
@@ -546,11 +540,13 @@ getargs (int argc, char *argv[])
 	break;
 
       case 'L':
-	language_argmatch (optarg, command_line_prio, NULL);
+	language_argmatch (optarg, command_line_prio,
+			   command_line_location ());
 	break;
 
       case 'S':
-	skeleton_arg (AS_FILE_NAME (optarg), command_line_prio, NULL);
+	skeleton_arg (AS_FILE_NAME (optarg), command_line_prio,
+		      command_line_location ());
 	break;
 
       case 'T':
