%{
  #include <stdlib.h>
  #include <stdio.h>
  #include <string.h>
  extern int line;
  extern int yyleng;
  extern int column;
  extern char* yytext;
  extern int flag;
  extern int errorFlag;
  int yylex(void);
  void yyerror (char *s);
%}

%token CHAR ELSE WHILE IF INT SHORT DOUBLE RETURN VOID BITWISEAND BITWISEOR BITWISEXOR AND ASSIGN MUL COMMA DIV EQ GE GT LBRACE LE LPAR LT MINUS MOD NE NOT OR PLUS RBRACE RPAR SEMI RESERVED
%token <value> REALLIT INTLIT CHRLIT ID

%nonassoc NOELSE
%nonassoc ELSE

%left COMMA
%right ASSIGN

%union{
  char *value;
  char *node;
}

%type <node> Program FunctionsAndDeclarations FunctionsAndDeclarationsMandatory FunctionsAndDeclarationsZeroOrMore FunctionDefinition FunctionBody DeclarationsAndStatements FunctionDeclaration FunctionDeclarator ParameterList ParameterDeclaration Declaration DeclaratorList DeclaratorZeroOrMore TypeSpec Declarator Statement StatementZeroOrMore StatementOrError Expr ExprA ExprB ExprC ExprD ExprE ExprF ExprG ExprH ExprI ExprJ ExprK ExprM ExprN ExprL

%%
Program:
  FunctionsAndDeclarations {$$ = NULL;}
  ;

FunctionsAndDeclarations:
  FunctionsAndDeclarationsMandatory FunctionsAndDeclarationsZeroOrMore {$$ = NULL;}
  ;

FunctionsAndDeclarationsMandatory:
  FunctionDefinition {$$ = NULL;}
  | FunctionDeclaration {$$ = NULL;}
  | Declaration {$$ = NULL;}
  ;

FunctionsAndDeclarationsZeroOrMore:
  FunctionsAndDeclarationsMandatory FunctionsAndDeclarationsZeroOrMore {$$ = NULL;}
  | {$$ = NULL;}
  ;

FunctionDefinition:
  TypeSpec FunctionDeclarator FunctionBody {$$ = NULL;}
  ;

FunctionBody:
  LBRACE DeclarationsAndStatements RBRACE {$$ = NULL;}
  | LBRACE RBRACE {$$ = NULL;}
  ;

DeclarationsAndStatements:
  Statement DeclarationsAndStatements {$$ = NULL;}
  | Declaration DeclarationsAndStatements {$$ = NULL;}
  | Statement {$$ = NULL;}
  | Declaration {$$ = NULL;}
  ;

FunctionDeclaration:
  TypeSpec FunctionDeclarator SEMI {$$ = NULL;}
  ;

FunctionDeclarator:
  ID LPAR ParameterList RPAR {$$ = NULL;}
  ;

ParameterList:
  ParameterDeclaration {$$ = NULL;}
  | ParameterList COMMA ParameterDeclaration {$$ = NULL;}
  ;

ParameterDeclaration:
  TypeSpec ID {$$ = NULL;}
  | TypeSpec {$$ = NULL;}
  ;

Declaration:
  TypeSpec DeclaratorList SEMI {$$ = NULL;}
  | error SEMI {$$ = NULL;}
  ;

DeclaratorList:
  Declarator DeclaratorZeroOrMore {$$ = NULL;}
  ;

DeclaratorZeroOrMore:
  COMMA DeclaratorList {$$ = NULL;}
  | {$$ = NULL;}
  ;

TypeSpec:
  CHAR {$$ = NULL;}
  | INT {$$ = NULL;}
  | VOID {$$ = NULL;}
  | SHORT {$$ = NULL;}
  | DOUBLE {$$ = NULL;}
  ;

Declarator:
  ID ASSIGN Expr {$$ = NULL;}
  | ID {$$ = NULL;}
  ;

Statement:
  SEMI {$$ = NULL;}
  | Expr SEMI {$$ = NULL;}
  | LBRACE RBRACE {$$ = NULL;}
  | LBRACE StatementZeroOrMore RBRACE {$$ = NULL;}
  | LBRACE error RBRACE {$$ = NULL;}
  | IF LPAR Expr RPAR StatementOrError ELSE StatementOrError {$$ = NULL;}
  | IF LPAR Expr RPAR StatementOrError %prec NOELSE {$$ = NULL;}
  | WHILE LPAR Expr RPAR StatementOrError {$$ = NULL;}
  | RETURN Expr SEMI {$$ = NULL;}
  | RETURN SEMI {$$ = NULL;}
  ;


StatementZeroOrMore:
  StatementZeroOrMore StatementOrError {$$ = NULL;}
  | StatementOrError {$$ = NULL;}
  ;


StatementOrError:
  Statement {$$ = NULL;}
  | error SEMI {$$ = NULL;}
  ;

Expr:
  ExprA {$$ = NULL;}
  | Expr COMMA ExprA {$$ = NULL;}
  ;

ExprA:
  ExprB {$$ = NULL;}
  | ExprB ASSIGN ExprA {$$ = NULL;}
  ;

ExprB:
  ExprC {$$ = NULL;}
  | ExprB OR ExprC {$$ = NULL;}
  ;

ExprC:
  ExprD {$$ = NULL;}
  | ExprC AND ExprD {$$ = NULL;}
  ;

ExprD:
  ExprE {$$ = NULL;}
  | ExprD BITWISEOR ExprE {$$ = NULL;}
  ;

ExprE:
  ExprF {$$ = NULL;}
  | ExprE BITWISEXOR ExprF {$$ = NULL;}
  ;

ExprF:
  ExprG {$$ = NULL;}
  | ExprF BITWISEAND ExprG {$$ = NULL;}
  ;

ExprG:
  ExprH {$$ = NULL;}
  | ExprG EQ ExprH {$$ = NULL;}
  | ExprG NE ExprH {$$ = NULL;}
  ;

ExprH:
  ExprI {$$ = NULL;}
  | ExprH LT ExprI {$$ = NULL;}
  | ExprH GT ExprI {$$ = NULL;}
  | ExprH LE ExprI {$$ = NULL;}
  | ExprH GE ExprI {$$ = NULL;}
  ;

ExprI:
  ExprJ {$$ = NULL;}
  | ExprI PLUS ExprJ {$$ = NULL;}
  | ExprI MINUS ExprJ {$$ = NULL;}
  ;

ExprJ:
  ExprK {$$ = NULL;}
  | ExprJ MUL ExprK {$$ = NULL;}
  | ExprJ DIV ExprK {$$ = NULL;}
  | ExprJ MOD ExprK {$$ = NULL;}
  ;

ExprK:
  ExprL {$$ = NULL;}
  | PLUS ExprK {$$ = NULL;}
  | MINUS ExprK {$$ = NULL;}
  | NOT ExprK {$$ = NULL;}
  ;

ExprM:
  ExprA {$$ = NULL;}
  | ExprM COMMA ExprA {$$ = NULL;}

ExprL:
  ExprN {$$ = NULL;}
  | ID LPAR RPAR {$$ = NULL;}
  | ID LPAR ExprM RPAR {$$ = NULL;}
  | ID LPAR error RPAR {$$ = NULL;}
  ;

ExprN:
  ID {$$ = NULL;}
  | INTLIT {$$ = NULL;}
  | CHRLIT {$$ = NULL;}
  | REALLIT {$$ = NULL;}
  | LPAR Expr RPAR {$$ = NULL;}
  | LPAR error RPAR {$$ = NULL;}
  ;

%%

void yyerror (char *s) {
  if(flag > 6) printf("Line %d, col %d: %s: %s\n", line, column-(int)yyleng, s, yytext);
  errorFlag = 1;
}
