/* 
::::::::::::::::::::::::::::::::::
:::: Rui Barata, Nº2015238609 ::::
::::::::::::::::::::::::::::::::::
*/

%X COMMENT
%{
  #define INVALID_CHAR          1
  #define UNTERMINATED_COMMENT  2
  #define UNTERMINATED_CHAR     3
  #define ILLEGAL_CHAR          4
  #define PRINT_TOKENS_ERRORS   5
  #define PRINT_ERRORS          6

  int flag = PRINT_ERRORS;
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
number9                   [0-9]
number7                   [0-7]
real                      ({number9}*\.?{number9}+|{number9}+\.?{number9}*)([eE][-+]?{number9}+)?
id                        [a-zA-Z_][a-zA-Z_0-9]*
char                      \\({number7}{number7}?{number7}?|n|t|\\|\'|\")|[^'\n\\]
reserved                  \[|\]|\+\+|\-\-|auto|break|case|const|continue|default|do|enum|extern|float|for|goto|inline|long|register|restrict|signed|sizeof|static|struct|switch|typedef|union|unsigned|volatile|_Bool|_Complex|_Imaginary|_Pragma
newLine                   \n|\r|\r\n
whitespace                [ \t\f]
%%
char                      { newToken("CHAR"); } 
else                      { newToken("ELSE"); } 
while                     { newToken("WHILE"); } 
if                        { newToken("IF"); } 
int                       { newToken("INT"); } 
short                     { newToken("SHORT"); } 
double                    { newToken("DOUBLE"); } 
return                    { newToken("RETURN"); } 
void                      { newToken("VOID"); } 
\&                        { newToken("BITWISEAND"); } 
\|                        { newToken("BITWISEOR"); } 
\^                        { newToken("BITWISEXOR"); } 
\&\&                      { newToken("AND"); } 
\=                        { newToken("ASSIGN"); } 
\*                        { newToken("MUL"); } 
\,                        { newToken("COMMA"); } 
\/                        { newToken("DIV"); } 
\=\=                      { newToken("EQ"); } 
\>\=                      { newToken("GE"); } 
\>                        { newToken("GT"); } 
\{                        { newToken("LBRACE"); } 
\<\=                      { newToken("LE"); } 
\(                        { newToken("LPAR"); } 
\<                        { newToken("LT"); } 
\-                        { newToken("MINUS"); } 
\%                        { newToken("MOD"); } 
\!\=                      { newToken("NE"); }
\!                        { newToken("NOT"); }
\|\|                      { newToken("OR"); }
\+                        { newToken("PLUS"); }
\}                        { newToken("RBRACE"); }
\)                        { newToken("RPAR"); }
\;                        { newToken("SEMI"); }
\/\/.*                    { column += yyleng; }
\/\*                      { initBlockComment(); }
<COMMENT>{newLine}        { line_cached += 1; column_cached = 1; }
<COMMENT>.                { column_cached += yyleng; }
<COMMENT>\*\/             { endBlockComment(); }
<COMMENT><<EOF>>          { errorBlockComment(); }
{reserved}                { newTokenyyText("RESERVED"); }
{id}                      { newTokenyyText("ID"); }
{number9}+                { newTokenyyText("INTLIT"); }
{real}                    { newTokenyyText("REALLIT"); }
'{char}'                  { newTokenyyText("CHRLIT"); }
'([^'\n\r\\]|(\\.))*'     { throwError(INVALID_CHAR); }
'([^'\n\r\\]|(\\.))*\\?   { throwError(UNTERMINATED_CHAR); }
{newLine}                 { line++; column = 1; }
{whitespace}              { column += yyleng; }
<<EOF>>                   { return 0; }
.                         { throwError(ILLEGAL_CHAR); }
%%
int main(int argc, char** argv) {
  if(argc == 2) {
    if (strcmp(argv[1], "-l") == 0) flag = PRINT_TOKENS_ERRORS;
  }

  yylex();
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
  BEGIN COMMENT;
  line_cached = line;
  column_cached = column + yyleng;
}

void errorBlockComment() {
  throwError(UNTERMINATED_COMMENT); 
  column = column_cached;
  line = line_cached;
  BEGIN 0;
}

void endBlockComment() {
  BEGIN 0;
  line = line_cached;
  column = column_cached + yyleng;
}