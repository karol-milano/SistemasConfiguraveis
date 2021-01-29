@@ -137,7 +137,7 @@ location_print (location loc, FILE *out)
 }
 
 
-/* Persistant data used by location_caret to avoid reopening and rereading the
+/* Persistent data used by location_caret to avoid reopening and rereading the
    same file all over for each error.  */
 struct caret_info
 {
