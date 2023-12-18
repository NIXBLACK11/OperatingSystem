#!/bin/bash

echo "Enter the number"

read num

fact=1

for ((i=1;i<=$num;i++)); do
    if [ $i -eq $num ]; then
        fact=$((fact*100))
    else
        fact=$((fact*i))
    fi
done

echo "The answer is = $fact"

