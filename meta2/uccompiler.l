/*
Rui Barata, Nº2015238609
*/

%X COMMENT
%{
  #include "ast.h"
  #include "y.tab.h"
  #define INVALID_CHAR                      1
  #define UNTERMINATED_COMMENT              2
  #define UNTERMINATED_CHAR                 3
  #define ILLEGAL_CHAR                      4
  #define PRINT_ERRORS                      5 // 1
  #define PRINT_TOKENS_ERRORS               6 // 2
  #define PRINT_SYNTAX_AND_LEXICAL_ERRORS   7 // 3
  #define PRINT_SYNTAX_TREE                 8 // 4

  int flag = PRINT_SYNTAX_AND_LEXICAL_ERRORS;
  int errorFlag = 0;
  int line = 1;
  int column = 1;
  int line_cached;
  int column_cached;

  void newToken(char*);
  void newTokenyyText(char*);
  void throwError(int);
  void initBlockComment();
  void errorBlockComment();
  void endBlockComment();
%}

%option nounput
%option noinput

number9                   [0-9]
number7                   [0-7]
real                      ({number9}*\.?{number9}+|{number9}+\.?{number9}*)([eE][-+]?{number9}+)?
id                        [a-zA-Z_][a-zA-Z_0-9]*
char                      \\({number7}{number7}?{number7}?|n|t|\\|\'|\")|[^'\n\\]
reserved                  \[|\]|\+\+|\-\-|auto|break|case|const|continue|default|do|enum|extern|float|for|goto|inline|long|register|restrict|signed|sizeof|static|struct|switch|typedef|union|unsigned|volatile|_Bool|_Complex|_Imaginary|_Pragma
newLine                   \n|\r|\r\n
whitespace                \t|" "|\v|\f
%%
char                      { newToken("CHAR"); return CHAR;}
else                      { newToken("ELSE"); return ELSE;}
while                     { newToken("WHILE"); return WHILE;}
if                        { newToken("IF"); return IF;}
int                       { newToken("INT"); return INT;}
short                     { newToken("SHORT"); return SHORT;}
double                    { newToken("DOUBLE"); return DOUBLE;}
return                    { newToken("RETURN"); return RETURN;}
void                      { newToken("VOID"); return VOID;}
\&                        { newToken("BITWISEAND"); return BITWISEAND;}
\|                        { newToken("BITWISEOR"); return BITWISEOR;}
\^                        { newToken("BITWISEXOR"); return BITWISEXOR;}
\&\&                      { newToken("AND"); return AND;}
\=                        { newToken("ASSIGN"); return ASSIGN;}
\*                        { newToken("MUL"); return MUL;}
\,                        { newToken("COMMA"); return COMMA;}
\/                        { newToken("DIV"); return DIV;}
\=\=                      { newToken("EQ"); return EQ;}
\>\=                      { newToken("GE"); return GE;}
\>                        { newToken("GT"); return GT;}
\{                        { newToken("LBRACE"); return LBRACE;}
\<\=                      { newToken("LE"); return LE;}
\(                        { newToken("LPAR"); return LPAR;}
\<                        { newToken("LT"); return LT;}
\-                        { newToken("MINUS"); return MINUS;}
\%                        { newToken("MOD"); return MOD;}
\!\=                      { newToken("NE"); return NE;}
\!                        { newToken("NOT"); return NOT;}
\|\|                      { newToken("OR"); return OR;}
\+                        { newToken("PLUS"); return PLUS;}
\}                        { newToken("RBRACE"); return RBRACE;}
\)                        { newToken("RPAR"); return RPAR;}
\;                        { newToken("SEMI"); return SEMI;}
\/\/.*                    { column += yyleng; }
\/\*                      { BEGIN COMMENT; initBlockComment(); }
<COMMENT>{newLine}        { line_cached += 1; column_cached = 1; }
<COMMENT>.                { column_cached += yyleng; }
<COMMENT>\*\/             { BEGIN 0; endBlockComment(); }
<COMMENT><<EOF>>          { errorBlockComment(); BEGIN 0; }
{reserved}                { newTokenyyText("RESERVED"); return RESERVED;}
{id}                      { newTokenyyText("ID"); yylval.value = strdup(yytext); return ID;}
{number9}+                { newTokenyyText("INTLIT");  yylval.value = strdup(yytext); return INTLIT;}
{real}                    { newTokenyyText("REALLIT"); yylval.value = strdup(yytext); return REALLIT;}
'{char}'                  { newTokenyyText("CHRLIT");  yylval.value = strdup(yytext); return CHRLIT;}
'([^'\n\r\\]|(\\.))*'     { throwError(INVALID_CHAR); }
'([^'\n\r\\]|(\\.))*\\?   { throwError(UNTERMINATED_CHAR); }
{newLine}                 { line++; column = 1; }
{whitespace}              { column += yyleng; }
<<EOF>>                   { column++; return 0; }
.                         { throwError(ILLEGAL_CHAR); }
%%
int main(int argc, char** argv) {
  if(argc == 2) {
    if (strcmp(argv[1], "-l") == 0) flag = PRINT_TOKENS_ERRORS;
    else if (strcmp(argv[1], "-e1") == 0) flag = PRINT_ERRORS;
    else if (strcmp(argv[1], "-t") == 0) flag = PRINT_SYNTAX_TREE;
    else if (strcmp(argv[1], "-e2") == 0) flag = PRINT_SYNTAX_AND_LEXICAL_ERRORS;
  }

  yyparse();
  if (treeRoot == NULL){
    return 0;
  }

  if(!errorFlag) {
    if(flag == PRINT_SYNTAX_TREE) printTree(treeRoot, 0);
  }

  freeTree(treeRoot);
  return 0;
}

int yywrap() {
  return 1;
}

void newToken(char* keyword) {
  if(flag == PRINT_TOKENS_ERRORS){
    printf("%s\n", keyword);
  }
  column += yyleng;
}

void newTokenyyText(char* token) {
  if(flag == PRINT_TOKENS_ERRORS){
    printf("%s(%s)\n", token, yytext);
  }
  column += yyleng;
}

void throwError(int error) {
  if(error == INVALID_CHAR){
    printf("Line %d, col %d: invalid char constant (%s)\n", line, column, yytext);
    column += yyleng;
  }
  else if(error == UNTERMINATED_COMMENT) {
    printf("Line %d, col %d: unterminated comment\n", line, column);
    column_cached += yyleng;
  }
  else if(error == UNTERMINATED_CHAR) {
    printf("Line %d, col %d: unterminated char constant\n", line, column);
    column += yyleng;
  }
  else if(error == ILLEGAL_CHAR) {
    printf("Line %d, col %d: illegal character (%s)\n", line, column, yytext);
    column += yyleng;
  }
}

void initBlockComment() {
  line_cached = line;
  column_cached = column + yyleng;
}

void errorBlockComment() {
  throwError(UNTERMINATED_COMMENT);
  column = column_cached;
  line = line_cached;
}

void endBlockComment() {
  line = line_cached;
  column = column_cached + yyleng;
}
