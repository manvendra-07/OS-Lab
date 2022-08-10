#!/bin/bash
echo "1. date"
echo "2. who"
echo "3. ls"
echo "4. pwd"
read -p "Enter your choice : " choice
if [ $choice -eq 1 ]
then
	date
elif [ $choice -eq 2 ]
then
	who
elif [ $choice -eq 3 ]
then
	ls
elif [ $choice -eq 4 ]
then
	pwd
else
	echo "Invalid Input"
fi
