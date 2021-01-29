@@ -358,6 +358,7 @@ b4_output_begin([b4_parser_file_name])[
 /* C LALR(1) parser skeleton written by Richard Stallman, by
    simplifying the original so-called "semantic" parser.  */
 
+]b4_disclaimer[
 /* All symbols defined below should begin with yy or YY, to avoid
    infringing on user name space.  This should be done even for local
    variables, as they might otherwise be expanded by user macros.
@@ -365,7 +366,6 @@ b4_output_begin([b4_parser_file_name])[
    define necessary library symbols; they are noted "INFRINGES ON
    USER NAME SPACE" below.  */
 
-]b4_disclaimer[
 ]b4_identification[
 ]b4_percent_code_get([[top]])[]dnl
 m4_if(b4_api_prefix, [yy], [],
