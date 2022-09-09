#200968146
#Script to do listing commands
#!/bin/bash
choice="n"
while [ $choice != 'y' ]
do
        echo "a. Display long listing of files"
        echo "b. Display long listing of files including hidden files"
        echo "c. Delete files from directory"
        echo "d. To exit"
        read -p "Enter Your Choice : " choice
        case $choice in
                a) ls -l;;
                b) ls -al;;
                c) read -p "Enter file name to be deleted : " fname
                        rm $fname;;
                d) read -p "Do you wish to exit ? " choice;;
                *) echo "Invalid Choice"
        esac
done