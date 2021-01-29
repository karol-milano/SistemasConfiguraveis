@@ -708,7 +708,7 @@ getargs (int argc, char *argv[])
         break;
 
       case 'y':
-        warning_argmatch ("error=yacc", 0, 6);
+        warning_argmatch ("yacc", 0, 0);
         yacc_loc = command_line_location ();
         break;
 
