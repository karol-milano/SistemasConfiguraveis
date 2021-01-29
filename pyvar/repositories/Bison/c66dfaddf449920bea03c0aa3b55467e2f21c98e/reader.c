@@ -221,7 +221,7 @@ static bool
 symbol_typed_p (const symbol_list *s)
 {
   return (s->sym->type_name
-	  || s->midrule && s->midrule->used);
+	  || (s->midrule && s->midrule->used));
 }
 
 /*----------------------------------------------------------------.
