#!/bin/bash


make clean
make

GREEN='\033[0;32m'  
NC='\033[0m'
YELLOW='\033[1;33m'
CYAN='\033[1;36m'


echo "${YELLOW}Running compiler on all test files found in the /tests ${NC}";
TOTAL=0;


echo
for f in tests/*.txt ; 
do 
    echo "${YELLOW}Running $f (${f%.txt}.asm)...${NC}";
    ./scalpa -t -o "${f%.txt}.asm" < "$f" ;
    TOTAL=$((TOTAL+1))
done

echo
echo "${CYAN}*******************************";
echo "$TOTAL tests out of $TOTAL have succeeded.";
echo "SUCCESS YOUPI !!!!!";
echo "***************************************";

