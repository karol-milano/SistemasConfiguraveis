@@ -63,8 +63,8 @@ static long
 on_success (const char *buf, size_t buflen, void *callback_arg)
 {
   callback_arg_t *arg = (callback_arg_t *) callback_arg;
-  assert (buflen < sizeof arg->buf);
-  strncpy (arg->buf, buf, buflen);
+  assert (buflen + 1 < sizeof arg->buf);
+  *stpncpy (arg->buf, buf, buflen) = '\0';
   return 1;
 }
 
@@ -73,7 +73,7 @@ on_failure (unsigned code MAYBE_UNUSED, const char *msg MAYBE_UNUSED,
             void *callback_arg)
 {
   callback_arg_t *arg = (callback_arg_t *) callback_arg;
-  assert (strlen (arg->fallback) < sizeof arg->buf);
+  assert (strlen (arg->fallback) + 1 < sizeof arg->buf);
   strcpy (arg->buf, arg->fallback);
   return 0;
 }
