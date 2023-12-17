#!/bin/bash

echo "Enter the number"
read num

fact=1

for ((i = 1; i <= $num; i++)); do
    if [ $i -eq 2 ]; then
        fact=$fact
    else
        fact=$((fact * i))
    fi
done

echo "Factorial = $fact"