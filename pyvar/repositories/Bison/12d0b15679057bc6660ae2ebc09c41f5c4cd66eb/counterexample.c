@@ -712,10 +712,10 @@ ssb_equals (const search_state_bundle *s1, const search_state_bundle *s2)
 typedef gl_list_t ssb_list;
 
 static size_t
-visited_hasher (const search_state *ss, size_t maximum)
+visited_hasher (const search_state *ss, size_t max)
 {
-  return (parse_state_hasher (ss->states[0], maximum)
-          + parse_state_hasher (ss->states[1], maximum)) % maximum;
+  return (parse_state_hasher (ss->states[0], max)
+          + parse_state_hasher (ss->states[1], max)) % max;
 }
 
 static bool
