#!/bin/bash
file=$1
if [ -f "Comp2020/meta1/${file}.uc" ]; then
  ./uccompiler -l < "Comp2020/meta1/${file}.uc" | diff "Comp2020/meta1/${file}.out" -  
else
  ./uccompiler -l < "Comp2020/meta1/${file}.c" | diff "Comp2020/meta1/${file}.out" - 
fi