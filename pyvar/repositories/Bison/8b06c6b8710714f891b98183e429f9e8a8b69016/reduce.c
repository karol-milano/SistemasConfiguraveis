@@ -57,6 +57,13 @@ rule_number nuseless_productions;
 static int nuseful_nonterminals;
 symbol_number nuseless_nonterminals;
 
+#define bitset_swap(Lhs, Rhs)                   \
+  do {                                          \
+    bitset lhs__ = Lhs;                         \
+    Lhs = Rhs;                                  \
+    Rhs = lhs__;                                \
+  } while (0)
+
 /*-------------------------------------------------------------------.
 | Another way to do this would be with a set for each production and |
 | then do subset tests against N0, but even for the C grammar the    |
@@ -119,11 +126,7 @@ useless_nonterminals (void)
           }
       if (bitset_equal_p (N, Np))
         break;
-      {
-        bitset Ns = Np;
-        Np = N;
-        N = Ns;
-      }
+      bitset_swap (N, Np);
     }
   bitset_free (N);
   N = Np;
@@ -181,11 +184,7 @@ inaccessable_symbols (void)
               }
           if (bitset_equal_p (V, Vp))
             break;
-          {
-            bitset Vs = Vp;
-            Vp = V;
-            V = Vs;
-          }
+          bitset_swap (V, Vp);
         }
     }
 
