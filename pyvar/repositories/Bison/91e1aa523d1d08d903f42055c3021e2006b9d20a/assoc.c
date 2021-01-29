@@ -28,7 +28,7 @@ assoc_to_string (assoc_t assoc)
   switch (assoc)
     {
     case undef_assoc:
-      return "undefined associativity";
+      return _("undefined associativity");
 
     case right_assoc:
       return "%right";
