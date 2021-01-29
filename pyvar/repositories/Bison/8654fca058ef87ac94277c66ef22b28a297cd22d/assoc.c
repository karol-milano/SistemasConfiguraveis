@@ -29,9 +29,6 @@ assoc_to_string (assoc a)
 {
   switch (a)
     {
-    default:
-      abort ();
-
     case undef_assoc:
       return "undefined associativity";
 
@@ -47,4 +44,5 @@ assoc_to_string (assoc a)
     case precedence_assoc:
       return "%precedence";
     }
+  abort ();
 }
