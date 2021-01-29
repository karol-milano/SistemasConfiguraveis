@@ -524,20 +524,20 @@ int (obstack_make_room) (obstack, length)
   return obstack_make_room (obstack, length);
 }
 
-void (obstack_grow) (obstack, pointer, length)
+void (obstack_grow) (obstack, data, length)
      struct obstack *obstack;
-     POINTER pointer;
+     const POINTER data;
      int length;
 {
-  obstack_grow (obstack, pointer, length);
+  obstack_grow (obstack, data, length);
 }
 
-void (obstack_grow0) (obstack, pointer, length)
+void (obstack_grow0) (obstack, data, length)
      struct obstack *obstack;
-     POINTER pointer;
+     const POINTER data;
      int length;
 {
-  obstack_grow0 (obstack, pointer, length);
+  obstack_grow0 (obstack, data, length);
 }
 
 void (obstack_1grow) (obstack, character)
@@ -581,20 +581,20 @@ POINTER (obstack_alloc) (obstack, length)
   return obstack_alloc (obstack, length);
 }
 
-POINTER (obstack_copy) (obstack, pointer, length)
+POINTER (obstack_copy) (obstack, address, length)
      struct obstack *obstack;
-     POINTER pointer;
+     const POINTER address;
      int length;
 {
-  return obstack_copy (obstack, pointer, length);
+  return obstack_copy (obstack, address, length);
 }
 
-POINTER (obstack_copy0) (obstack, pointer, length)
+POINTER (obstack_copy0) (obstack, address, length)
      struct obstack *obstack;
-     POINTER pointer;
+     const POINTER address;
      int length;
 {
-  return obstack_copy0 (obstack, pointer, length);
+  return obstack_copy0 (obstack, address, length);
 }
 
 #endif /* __STDC__ */
