#!/bin/sh

flex $1
gcc -o $2 lex.yy.c
