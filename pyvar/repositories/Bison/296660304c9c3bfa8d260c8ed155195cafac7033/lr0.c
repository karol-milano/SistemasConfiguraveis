@@ -58,10 +58,11 @@ core_print (size_t core_size, item_number *core, FILE *out)
     }
 }
 
-/*------------------------------------------------------------------.
-| A state was just discovered from another state.  Queue it for     |
-| later examination, in order to find its transitions.  Return it.  |
-`------------------------------------------------------------------*/
+/*-----------------------------------------------------------------.
+| A state was just discovered by transitioning on SYM from another |
+| state.  Queue this state for later examination, in order to find |
+| its outgoing transitions.  Return it.                            |
+`-----------------------------------------------------------------*/
 
 static state *
 state_list_append (symbol_number sym, size_t core_size, item_number *core)
@@ -98,7 +99,7 @@ static state **shiftset;
 
 
 /* KERNEL_BASE[symbol-number] -> list of item numbers (offsets inside
-   RITEM) of lenngth KERNEL_SIZE[symbol-number]. */
+   RITEM) of length KERNEL_SIZE[symbol-number]. */
 static item_number **kernel_base;
 static int *kernel_size;
 
