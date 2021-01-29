@@ -69,7 +69,7 @@ static void
 print_core (FILE *out, state_t *state)
 {
   int i;
-  short *sitems = state->items;
+  item_number_t *sitems = state->items;
   int snritems   = state->nitems;
 
   /* New experimental feature: if TRACE_FLAGS output all the items of
@@ -85,8 +85,8 @@ print_core (FILE *out, state_t *state)
     {
       for (i = 0; i < snritems; i++)
 	{
-	  short *sp;
-	  short *sp1;
+	  item_number_t *sp;
+	  item_number_t *sp1;
 	  int rule;
 
 	  sp1 = sp = ritem + sitems[i];
@@ -361,7 +361,7 @@ static void
 print_grammar (FILE *out)
 {
   int i, j;
-  short *rule;
+  item_number_t *rule;
   char buffer[90];
   int column = 0;
 
