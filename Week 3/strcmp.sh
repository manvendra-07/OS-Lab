#Manvendra Singh
#200968146
#!/bin/bash
read -p "Enter String 1 : " str1
read -p "Enter String 2 : " str2
if [ ${#str1} -eq 0 ] || [ ${#str2} -eq 0 ];
then
        echo "One of the strings is empty"
elif [[ $str1 == $str2 ]]
then
        echo "String are equal"
else
        echo "Strings are not equal"
fi