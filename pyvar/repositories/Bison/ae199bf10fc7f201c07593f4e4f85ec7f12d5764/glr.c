@@ -1674,6 +1674,11 @@ yyresolveValue (yySemanticOption* yyoptionList, yyGLRStack* yystack,
 	      yybest = yyp;
 	      yymerge = yyfalse;
 	      break;
+	    default:
+	      /* This cannot happen so it is not worth a YYASSERT (false),
+	         but some compilers complain if the default case is
+		 omitted.  */
+	      break;
 	    }
 	  yypp = &yyp->yynext;
 	}
