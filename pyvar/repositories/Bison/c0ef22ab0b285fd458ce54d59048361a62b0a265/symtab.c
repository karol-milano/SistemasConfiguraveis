@@ -450,7 +450,7 @@ semantic_type_check_defined (semantic_type *sem_type)
   /* <*> and <> do not have to be "declared".  */
   if (sem_type->status == declared
       || !*sem_type->tag
-      || STREQ(sem_type->tag, "*"))
+      || STREQ (sem_type->tag, "*"))
     {
       int i;
       for (i = 0; i < 2; ++i)
@@ -1110,7 +1110,7 @@ static void
 init_assoc (void)
 {
   graphid i;
-  used_assoc = xcalloc(nsyms, sizeof(*used_assoc));
+  used_assoc = xcalloc (nsyms, sizeof *used_assoc);
   for (i = 0; i < nsyms; ++i)
     used_assoc[i] = false;
 }
