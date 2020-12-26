#!/bin/bash

make

echo "Will run scalpa on all test files.";
echo "Saving log in test.log";
FAIL=0;
TOTAL=0;
cp "/dev/null" "test.log";



echo
for f in tests/*.txt ; 
do 
    echo "Running $f (${f%.txt}.asm)...";
    echo -e "$f\n" >> "test.log";
    cat $f >> "test.log";
    echo >> "test.log";
    valgrind ./binary/scalpa "$f" "${f%.txt}.asm" >> "test.log" 2>&1;
    cat "${f%.txt}.asm" >> "test.log";
    
    echo -e "\n\n" >> "test.log";
    
    TOTAL=$((TOTAL+1))
done

echo
echo "$((TOTAL-FAIL)) on $TOTAL has succeeded.";
