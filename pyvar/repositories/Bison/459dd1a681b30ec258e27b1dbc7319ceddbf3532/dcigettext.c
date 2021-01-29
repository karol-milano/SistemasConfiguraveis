@@ -517,6 +517,7 @@ DCIGETTEXT (domainname, msgid1, msgid2, plural, n, category)
 	  /* We cannot get the current working directory.  Don't signal an
 	     error but simply return the default string.  */
 	  FREE_BLOCKS (block_list);
+	  __libc_rwlock_unlock (_nl_state_lock);
 	  __set_errno (saved_errno);
 	  return (plural == 0
 		  ? (char *) msgid1
