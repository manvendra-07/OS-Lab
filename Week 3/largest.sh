##Manvendra Singh
##200968146
#!/bin/bash
read -p "Enter three numbers : " n1 n2 n3
if ((n1 > n2 && n1 > n3))
then
        echo "Largest Number = $n1"
elif ((n2 > n1 && n2 > n3))
then
        echo "Largest Number = $n2"
elif ((n3 > n1 && n3 > n2))
then
        echo "Largest Number = $n3"
else
        echo "All the numbers are equal"
fi