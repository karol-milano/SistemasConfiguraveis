@@ -37,9 +37,7 @@ extern int raw_flag;
 extern int yacc_flag;
 extern char * version_string;
 
-getargs(argc,argv)
-     int argc;
-     char *argv[];
+getargs (int argc, char *argv[])
 {
   register char *cp;
   static char Input_File[256];
@@ -145,8 +143,7 @@ getargs(argc,argv)
  *	See if "NAME" is present
  */
 int
-cli_present(Name)
-     char *Name;
+cli_present (char *Name)
 {
   struct {int Size; char *Ptr;} Descr;
 
@@ -159,9 +156,7 @@ cli_present(Name)
  *	Get value of "NAME"
  */
 int
-cli_get_value(Name,Buffer,Size)
-     char *Name;
-     char *Buffer;
+cli_get_value (char *Name, char *Buffer, int Size)
 {
   struct {int Size; char *Ptr;} Descr1,Descr2;
 
