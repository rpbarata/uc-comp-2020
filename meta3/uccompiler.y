%{
  #include "ast.h"
  #include "structs.h"
  int yylex(void);
  void yyerror (char *s);
  extern int line;
  extern int yyleng;
  extern int column;
  extern char* yytext;
  extern int flag;
  extern int errorFlag;
  Node node1;
  Node node2;

%}

%token CHAR ELSE WHILE IF INT SHORT DOUBLE RETURN VOID BITWISEAND BITWISEOR BITWISEXOR AND ASSIGN MUL COMMA DIV EQ GE GT LBRACE LE LPAR LT MINUS MOD NE NOT OR PLUS RBRACE RPAR SEMI RESERVED
%token <value> REALLIT INTLIT CHRLIT ID

%nonassoc NOELSE
%nonassoc ELSE

%left COMMA
%right ASSIGN

%union{
  char *value;
  Node node;
}

%type <node> Program FunctionsAndDeclarations FunctionsAndDeclarationsMandatory FunctionsAndDeclarationsZeroOrMore FunctionDefinition FunctionBody DeclarationsAndStatements FunctionDeclaration FunctionDeclarator ParameterList ParameterDeclaration Declaration DeclaratorList DeclaratorZeroOrMore TypeSpec Declarator Statement StatementZeroOrMore StatementOrError Expr ExprA ExprB ExprC ExprD ExprE ExprF ExprG ExprH ExprI ExprJ ExprK ExprL ExprM ExprN

%%
Program:
    FunctionsAndDeclarations  {treeRoot = createNode(Program, NULL); addChild(treeRoot, $1);}
    ;

FunctionsAndDeclarations:
    FunctionsAndDeclarationsMandatory FunctionsAndDeclarationsZeroOrMore  {$$ = addBrother($1, $2);}
    ;

FunctionsAndDeclarationsMandatory:
    FunctionDefinition  {$$ = $1;}
  | FunctionDeclaration {$$ = $1;}
  | Declaration         {$$ = $1;}
  ;

FunctionsAndDeclarationsZeroOrMore:
    FunctionsAndDeclarationsMandatory FunctionsAndDeclarationsZeroOrMore  {$$ = addBrother($1, $2);}
  |                                                                       {$$ = NULL;}
  ;

FunctionDefinition:
    TypeSpec FunctionDeclarator FunctionBody  {$$ = createNode(FuncDefinition, NULL); addChild($$, $1); addBrother($1, $2); addBrother($1, $3);}
  ;

FunctionBody:
    LBRACE DeclarationsAndStatements RBRACE {$$ = createNode(FuncBody, NULL); addChild($$, $2);}
  | LBRACE RBRACE                           {$$ = createNode(FuncBody, NULL);}
  ;

DeclarationsAndStatements:
    DeclarationsAndStatements Statement   {$$ = addBrother($1, $2);}
  | DeclarationsAndStatements Declaration {$$ = addBrother($1, $2);}
  | Statement                             {$$ = $1;}
  | Declaration                           {$$ = $1;}
  ;

FunctionDeclaration:
    TypeSpec FunctionDeclarator SEMI  {$$ = createNode(FuncDeclaration, NULL); addChild($$, $1); addBrother($1, $2);}
    ;

FunctionDeclarator:
    ID LPAR ParameterList RPAR  {$$ = createNode(Id, $1); node1 = createNode(ParamList, NULL); addBrother($$, node1); addChild(node1, $3);}
    ;

ParameterList:
    ParameterDeclaration                      {$$ = $1;}
  | ParameterList COMMA ParameterDeclaration  {$$ = addBrother($$, $3);}
  ;

ParameterDeclaration:
    TypeSpec ID {$$ = createNode(ParamDeclaration, NULL); addChild($$, $1); addBrother($1, createNode(Id, $2));}
  | TypeSpec    {$$ = createNode(ParamDeclaration, NULL); addChild($$, $1);}
  ;

Declaration:
    TypeSpec DeclaratorList SEMI  {addBrother($1, $2->child);
                                   $2->child = $1;
                                   node1 = $2->brother;
                                   while(node1 != NULL){
                                      node2 = createNode($1->label, NULL);
                                      addBrother(node2, node1->child);
                                      node1->child = node2;
                                      node1 = node1->brother;
                                   }
                                   $$ = $2;}
  | error SEMI                    {$$ = createNode(Null, NULL);}
  ;

DeclaratorList:
    Declarator DeclaratorZeroOrMore {$$ = createNode(Declaration, NULL); addChild($$, $1); addBrother($$, $2);}
    ;

DeclaratorZeroOrMore:
    COMMA DeclaratorList  {$$ = $2;}
  |                       {$$ = NULL;}
  ;

TypeSpec:
    CHAR    {$$ = createNode(Char, NULL);}
  | INT     {$$ = createNode(Int, NULL);}
  | VOID    {$$ = createNode(Void, NULL);}
  | SHORT   {$$ = createNode(Short, NULL);}
  | DOUBLE  {$$ = createNode(Double, NULL);}
  ;

Declarator:
    ID ASSIGN Expr  {$$ = createNode(Id, $1); addBrother($$, $3);}
  | ID              {$$ = createNode(Id, $1);}
  ;

Statement:
    SEMI                                                      {$$ = NULL;}
  | Expr SEMI                                                 {$$ = $1;}
  | LBRACE RBRACE                                             {$$ = NULL;}
  | LBRACE StatementZeroOrMore RBRACE                         {if($2 != NULL && $2->brother != NULL){
                                                                $$ = createNode(StatList, NULL);
                                                                addChild($$, $2);
                                                               }
                                                               else $$ = $2;}
  | LBRACE error RBRACE                                       {$$ = createNode(Null, NULL);}
  | IF LPAR Expr RPAR StatementOrError ELSE StatementOrError  {$$ = createNode(If, NULL); addChild($$, $3);
                                                               if ($5 == NULL) addBrother($3, createNode(Null, NULL));
                                                               else addBrother($3, $5);
                                                               if ($7 == NULL) addBrother($3, createNode(Null, NULL));
                                                               else addBrother($3, $7);}
  | IF LPAR Expr RPAR StatementOrError %prec NOELSE            {$$ = createNode(If, NULL); addChild($$, $3);
                                                                if ($5 == NULL) addBrother($3, createNode(Null, NULL));
                                                                else addBrother($3, $5);
                                                                addBrother($3, createNode(Null, NULL));}
  | WHILE LPAR Expr RPAR StatementOrError                      {$$ = createNode(While, NULL); addChild($$, $3);
                                                                if ($5 == NULL) addBrother($3, createNode(Null, NULL));
                                                                else addBrother($3, $5);}
  | RETURN Expr SEMI                                           {$$ = createNode(Return, NULL); addChild($$, $2);}
  | RETURN SEMI                                                {$$ = createNode(Return, NULL); addChild($$, createNode(Null, NULL));}
  ;

StatementZeroOrMore:
    StatementZeroOrMore StatementOrError  {$$ = addBrother($1, $2);}
  | StatementOrError                      {$$ = $1;}
  ;

StatementOrError:
    Statement   {$$ = $1;}
  | error SEMI  {$$ = createNode(Null, NULL);}
  ;

Expr:
      ExprA             {$$ = $1;}
    | Expr COMMA ExprA  {$$ = createNode(Comma, NULL); addChild($$, $1); addBrother($1, $3);}
    ;

ExprA:
      ExprB               {$$ = $1;}
    | ExprB ASSIGN ExprA  {$$ = createNode(Store, NULL); addChild($$, $1); addBrother($1, $3);}
    ;

ExprB:
      ExprC           {$$ = $1;}
    | ExprB OR ExprC  {$$ = createNode(Or, NULL); addChild($$, $1); addBrother($1, $3);}
    ;

ExprC:
      ExprD           {$$ = $1;}
    | ExprC AND ExprD {$$ = createNode(And, NULL); addChild($$, $1); addBrother($1, $3);}
    ;

ExprD:
      ExprE                 {$$ = $1;}
    | ExprD BITWISEOR ExprE {$$ = createNode(BitWiseOr, NULL); addChild($$, $1); addBrother($1, $3);}
    ;

ExprE:
      ExprF                   {$$ = $1;}
    | ExprE BITWISEXOR ExprF  {$$ = createNode(BitWiseXor, NULL); addChild($$, $1); addBrother($1, $3);}
    ;

ExprF:
      ExprG                   {$$ = $1;}
    | ExprF BITWISEAND ExprG  {$$ = createNode(BitWiseAnd, NULL); addChild($$, $1); addBrother($1, $3);}
    ;

ExprG:
      ExprH           {$$ = $1;}
    | ExprG EQ ExprH  {$$ = createNode(Eq, NULL); addChild($$, $1); addBrother($1, $3);}
    | ExprG NE ExprH  {$$ = createNode(Ne, NULL); addChild($$, $1); addBrother($1, $3);}
    ;

ExprH:
      ExprI           {$$ = $1;}
    | ExprH LT ExprI  {$$ = createNode(Lt, NULL); addChild($$, $1); addBrother($1, $3);}
    | ExprH GT ExprI  {$$ = createNode(Gt, NULL); addChild($$, $1); addBrother($1, $3);}
    | ExprH LE ExprI  {$$ = createNode(Le, NULL); addChild($$, $1); addBrother($1, $3);}
    | ExprH GE ExprI  {$$ = createNode(Ge, NULL); addChild($$, $1); addBrother($1, $3);}
    ;

ExprI:
      ExprJ             {$$ = $1;}
    | ExprI PLUS ExprJ  {$$ = createNode(Add, NULL); addChild($$, $1); addBrother($1, $3);}
    | ExprI MINUS ExprJ {$$ = createNode(Sub, NULL); addChild($$, $1); addBrother($1, $3);}
    ;

ExprJ:
      ExprK           {$$ = $1;}
    | ExprJ MUL ExprK {$$ = createNode(Mul, NULL); addChild($$, $1); addBrother($1, $3);}
    | ExprJ DIV ExprK {$$ = createNode(Div, NULL); addChild($$, $1); addBrother($1, $3);}
    | ExprJ MOD ExprK {$$ = createNode(Mod, NULL); addChild($$, $1); addBrother($1, $3);}
    ;

ExprK:
      ExprM       {$$ = $1;}
    | PLUS ExprK  {$$ = createNode(Plus, NULL); addChild($$, $2);}
    | MINUS ExprK {$$ = createNode(Minus, NULL); addChild($$, $2);}
    | NOT ExprK   {$$ = createNode(Not, NULL); addChild($$, $2);}
    ;

ExprL:
      ExprA             {$$ = $1;}
    | ExprL COMMA ExprA {$$ = addBrother($1, $3);}

ExprM:
      ExprN               {$$ = $1;}
    | ID LPAR RPAR        {$$ = createNode(Call, NULL); addChild($$, createNode(Id, $1));}
    | ID LPAR ExprL RPAR  {$$ = createNode(Call, NULL); node1 = createNode(Id, $1); addChild($$, node1); addBrother(node1, $3);}
    | ID LPAR error RPAR  {$$ = createNode(Null, NULL); free($1);}
    ;

ExprN:
      ID              {$$ = createNode(Id, $1);}
    | INTLIT          {$$ = createNode(IntLit, $1);}
    | CHRLIT          {$$ = createNode(ChrLit, $1);}
    | REALLIT         {$$ = createNode(RealLit, $1);}
    | LPAR Expr RPAR  {$$ = $2;}
    | LPAR error RPAR {$$ = createNode(Null, NULL);}
    ;
%%

void yyerror (char *s) {
  if(flag > 6) printf("Line %d, col %d: %s: %s\n", line, column-(int)yyleng, s, yytext);
  errorFlag = 1;
}
