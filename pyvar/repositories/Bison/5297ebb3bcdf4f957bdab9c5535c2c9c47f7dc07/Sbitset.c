@@ -33,9 +33,9 @@ Sbitset__new (Sbitset__Index nbits)
 Sbitset
 Sbitset__new_on_obstack (Sbitset__Index nbits, struct obstack *obstackp)
 {
-  char *result;
-  char *ptr;
-  char *end;
+  Sbitset result;
+  Sbitset ptr;
+  Sbitset end;
   aver (nbits);
   result = obstack_alloc (obstackp, Sbitset__nbytes (nbits));
   for (ptr = result, end = result + Sbitset__nbytes (nbits); ptr < end; ++ptr)
@@ -52,7 +52,7 @@ Sbitset__delete (Sbitset self)
 bool
 Sbitset__isEmpty (Sbitset self, Sbitset__Index nbits)
 {
-  char *last = self + Sbitset__nbytes (nbits) - 1;
+  Sbitset last = self + Sbitset__nbytes (nbits) - 1;
   for (; self < last; ++self)
     if (*self != 0)
       return false;
