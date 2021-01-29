@@ -555,7 +555,10 @@ symbol_class_set (symbol *sym, symbol_class class, location loc, bool declaring)
                                _("previous declaration"));
             }
           else
-            s->status = declared;
+            {
+              sym->location = loc;
+              s->status = declared;
+            }
         }
     }
 }
