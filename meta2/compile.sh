#!/bin/sh

flex uccompiler.l
yacc -d -v uccompiler.y
clang-3.9 -Wall -o uccompiler -Wno-unused-function *.c
