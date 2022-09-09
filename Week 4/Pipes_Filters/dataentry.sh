#Manvendra Singh
#200968146
#A Script to do data entry in BMI.dat file
choice='y'
while [ $choice != 'n' ]
do
        if [ -f "BMI.dat" ]
        then
                echo "File exists"
                read -p "Enter Name : " name
                read -p "Enter Location : " loc
                read -p "Enter State : " state
                read -p "Enter Age : " age
                read -p "Enter Month of entry : " month
                read -p "Enter Gender : " gender
                read -p "Enter Height : " height
                read -p "Enter Weight : " weight
                read -p "Enter Index : " index
                rownum=` cat BMI.dat | wc -l `
                echo "$rownum,$name,$loc,$state,$age,$month,$gender,$height,$weight,$index" | tee -a BMI.dat
        else
                echo "File doesn't exist creating one now"
                touch "BMI.dat"
                echo "Row No.,Name,Location,State,Age,Month of entry,Gender,Height,Weight,Index" | tee BMI.dat
                echo "File Created"
        fi
        read -p "Do you wish to continue ? " choice
done