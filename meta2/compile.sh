#!/bin/bash

flex $1.l
yacc -d $1.y
gcc -o $1 y.tab.c lex.yy.c