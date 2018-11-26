#!/bin/bash
echo "usage ./validate.sh <exe> <numbers_of_input-output>"
echo "Confronto in corso.."
echo ""

for i in `seq 0 $2`;
do
cat input$i.txt | ./$1 | diff -y - output$i.txt
done;

echo ""
echo "##END##"