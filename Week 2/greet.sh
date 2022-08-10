#!/bin/bash
read -p "Enter Name : " name

if [ $name = "Peter" ]
then
	echo "Good Morning"
elif [ $name = "Alice" ]
then
	echo "Good Night"
fi
