@@ -61,7 +61,6 @@ int skeleton_prio = default_prio;
 const char *skeleton = NULL;
 int language_prio = default_prio;
 struct bison_language const *language = &valid_languages[0];
-const char *include = NULL;
 
 /** Decode an option's key.
  *
@@ -465,12 +464,10 @@ static char const short_options[] =
   "b:"
   "d"
   "f::"
-  "e"
   "g::"
   "h"
   "k"
   "l"
-  "n"
   "o:"
   "p:"
   "r:"
@@ -500,7 +497,6 @@ static struct option const long_options[] =
 
   /* Parser. */
   { "name-prefix",   required_argument,   0,   'p' },
-  { "include",       required_argument,   0,   'I' },
 
   /* Output. */
   { "file-prefix", required_argument,   0,   'b' },
@@ -529,7 +525,6 @@ static struct option const long_options[] =
   { "force-define",   required_argument,         0,   'F' },
   { "locations",      no_argument,               0, LOCATIONS_OPTION },
   { "no-lines",       no_argument,               0,   'l' },
-  { "raw",            no_argument,               0,     0 },
   { "skeleton",       required_argument,         0,   'S' },
   { "language",       required_argument,         0,   'L' },
   { "token-table",    no_argument,               0,   'k' },
@@ -604,10 +599,6 @@ getargs (int argc, char *argv[])
         }
         break;
 
-      case 'I':
-        include = AS_FILE_NAME (optarg);
-        break;
-
       case 'L':
         language_argmatch (optarg, command_line_prio,
                            command_line_location ());
