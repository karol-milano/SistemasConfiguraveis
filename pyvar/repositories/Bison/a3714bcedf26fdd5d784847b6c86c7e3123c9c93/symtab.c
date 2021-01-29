@@ -228,7 +228,7 @@ symbol_check_defined (symbol_t *this)
       this->number = nvars++;
     }
 
-  return TRUE;
+  return true;
 }
 
 
@@ -299,7 +299,7 @@ symbol_check_alias_consistence (symbol_t *this)
 	    this->assoc = this->alias->assoc;
 	}
     }
-  return TRUE;
+  return true;
 }
 
 
@@ -332,7 +332,7 @@ symbol_pack (symbol_t *this)
 	}
       /* Do not do processing below for USER_NUMBER_ALIASs.  */
       if (this->user_token_number == USER_NUMBER_ALIAS)
-	return TRUE;
+	return true;
     }
   else /* this->class == token_sym */
     {
@@ -340,7 +340,7 @@ symbol_pack (symbol_t *this)
     }
 
   symbols[this->number] = this;
-  return TRUE;
+  return true;
 }
 
 
@@ -367,7 +367,7 @@ symbol_translation (symbol_t *this)
       token_translations[this->user_token_number] = this->number;
     }
 
-  return TRUE;
+  return true;
 }
 
 
@@ -383,7 +383,7 @@ static struct hash_table *symbol_table = NULL;
 static bool
 hash_compare_symbol_t (const symbol_t *m1, const symbol_t *m2)
 {
-  return strcmp (m1->tag, m2->tag) ? FALSE : TRUE;
+  return strcmp (m1->tag, m2->tag) == 0;
 }
 
 static unsigned int
@@ -501,7 +501,7 @@ symbols_check_defined (void)
 static void
 symbols_token_translations_init (void)
 {
-  int num_256_available_p = TRUE;
+  bool num_256_available_p = true;
   int i;
 
   /* Find the highest user token number, and whether 256, the POSIX
@@ -515,7 +515,7 @@ symbols_token_translations_init (void)
 	  if (this->user_token_number > max_user_token_number)
 	    max_user_token_number = this->user_token_number;
 	  if (this->user_token_number == 256)
-	    num_256_available_p = FALSE;
+	    num_256_available_p = false;
 	}
     }
 
