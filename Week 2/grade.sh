#!/bin/bash
read -p "Enter CGPA : " cgpa
if [ $cgpa = "7.0" ]
then
	echo "Grade = C"
elif [ $cgpa = "8.0" ]
then
	echo "Grade = B"
elif [ $cgpa = "9.0" ]
then
	echo "Grade = A"
elif [ $cgpa = "10.0" ]
then
	echo "Grade = A+"
else
	echo "Grade = D"
fi

