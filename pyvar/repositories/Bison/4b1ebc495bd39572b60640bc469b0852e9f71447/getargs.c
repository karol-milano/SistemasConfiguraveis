@@ -70,9 +70,9 @@ static struct bison_language const valid_languages[] = {
   { "", "", "", "", false }
 };
 
-static int skeleton_prio = 2;
+int skeleton_prio = default_prio;
 const char *skeleton = NULL;
-static int language_prio = 2;
+int language_prio = default_prio;
 struct bison_language const *language = &valid_languages[0];
 const char *include = NULL;
 
@@ -520,11 +520,11 @@ getargs (int argc, char *argv[])
 	break;
 
       case 'L':
-	language_argmatch (optarg, 0, NULL);
+	language_argmatch (optarg, command_line_prio, NULL);
 	break;
 
       case 'S':
-	skeleton_arg (AS_FILE_NAME (optarg), 0, NULL);
+	skeleton_arg (AS_FILE_NAME (optarg), command_line_prio, NULL);
 	break;
 
       case 'T':
