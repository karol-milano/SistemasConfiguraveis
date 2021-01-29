@@ -28,7 +28,7 @@ assoc_to_string (assoc_t assoc)
   switch (assoc)
     {
     case undef_assoc:
-      return _("undefined associativity");
+      return "undefined associativity";
 
     case right_assoc:
       return "%right";
