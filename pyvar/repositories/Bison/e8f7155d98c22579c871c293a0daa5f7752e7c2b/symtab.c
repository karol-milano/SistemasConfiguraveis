@@ -52,6 +52,12 @@ location startsymbol_location;
 
 static symgraph **prec_nodes;
 
+/*-----------------------------------.
+| Store which associativity is used. |
+`-----------------------------------*/
+
+bool *used_assoc = NULL;
+
 /*---------------------------------.
 | Create a new symbol, named TAG.  |
 `---------------------------------*/
@@ -1073,3 +1079,61 @@ print_precedence_warnings (void)
                   _("useless precedence for %s"), s->tag);
     }
 }
+
+/*---------------------------------------.
+| Initialize association tracking table. |
+`---------------------------------------*/
+
+static void
+init_assoc (void)
+{
+  graphid i;
+  used_assoc = xcalloc(nsyms, sizeof(*used_assoc));
+  for (i = 0; i < nsyms; ++i)
+    used_assoc[i] = false;
+}
+
+/*------------------------------------------------------------------.
+| Test if the associativity for the symbols is defined and useless. |
+`------------------------------------------------------------------*/
+
+static inline bool
+is_assoc_useless (symbol *s)
+{
+  return s
+      && s->assoc != undef_assoc
+      && s->assoc != precedence_assoc
+      && !used_assoc[s->number];
+}
+
+/*-------------------------------.
+| Register a used associativity. |
+`-------------------------------*/
+
+void
+register_assoc (graphid i, graphid j)
+{
+  if (!used_assoc)
+    init_assoc ();
+  used_assoc[i] = true;
+  used_assoc[j] = true;
+}
+
+/*------------------------------------------------------.
+| Print a warning for each unused symbol associativity. |
+`------------------------------------------------------*/
+
+void
+print_assoc_warnings (void)
+{
+  graphid i;
+  if (!used_assoc)
+    init_assoc ();
+  for (i = 0; i < nsyms; ++i)
+    {
+      symbol *s = symbols[i];
+      if (is_assoc_useless (s))
+        complain (&s->location, Wother,
+                  _("useless associativity for %s"), s->tag);
+    }
+}
