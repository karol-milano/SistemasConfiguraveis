@@ -717,10 +717,10 @@ ssb_equals (const search_state_bundle *s1, const search_state_bundle *s2)
 typedef gl_list_t ssb_list;
 
 static size_t
-visited_hasher (const search_state *ss, size_t max)
+visited_hasher (const search_state *ss, size_t maximum)
 {
-  return (parse_state_hasher (ss->states[0], max)
-          + parse_state_hasher (ss->states[1], max)) % max;
+  return (parse_state_hasher (ss->states[0], maximum)
+          + parse_state_hasher (ss->states[1], maximum)) % maximum;
 }
 
 static bool
