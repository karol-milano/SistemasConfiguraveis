@@ -1675,7 +1675,7 @@ yyresolveValue (yySemanticOption* yyoptionList, yyGLRStack* yystack,
 	      yymerge = yyfalse;
 	      break;
 	    default:
-	      /* This cannot happen so it is not worth a YYASSERT (false),
+	      /* This cannot happen so it is not worth a YYASSERT (yyfalse),
 	         but some compilers complain if the default case is
 		 omitted.  */
 	      break;
