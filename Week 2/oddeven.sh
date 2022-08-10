#!/bin/bash
read -p "Enter a number : " n
if [ $(expr $n % 2) -eq  0 ]
then
	echo "Even Number"
else
	echo "Odd Number"
fi
