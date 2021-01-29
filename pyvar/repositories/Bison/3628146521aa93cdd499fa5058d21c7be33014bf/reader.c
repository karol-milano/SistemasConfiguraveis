@@ -1027,7 +1027,7 @@ get_type_name (int n, symbol_list *rule)
       i++;
     }
 
-  return (rp->sym->type_name);
+  return rp->sym->type_name;
 }
 
 
@@ -1332,7 +1332,7 @@ gensym (void)
   sym = getsym(token_buffer);
   sym->class = SNTERM;
   sym->value = nvars++;
-  return (sym);
+  return sym;
 }
 
 /* Parse the input grammar into a one symbol_list structure.
@@ -1685,7 +1685,7 @@ get_type (void)
       switch (t)
 	{
 	case SEMICOLON:
-	  return (lex());
+	  return lex();
 
 	case COMMA:
 	  break;
@@ -1699,7 +1699,7 @@ get_type (void)
 	  break;
 
 	default:
-	  return (t);
+	  return t;
 	}
     }
 }
