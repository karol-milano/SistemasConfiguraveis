@@ -381,7 +381,7 @@ static const ]b4_int_type_for([b4_conflict_list_heads])[ yyconflp[] =
 /* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
    0, pointed into by YYCONFLP.  */
 ]dnl Do not use b4_int_type_for here, since there are places where
-dnl pointers onto yyconfl are taken, which type is "short int *".
+dnl pointers onto yyconfl are taken, whose type is "short int *".
 dnl We probably ought to introduce a type for confl.
 [static const short int yyconfl[] =
 {
