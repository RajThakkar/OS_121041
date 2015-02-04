clear
a=(1 2 3 4 5 6 7 8 9 10) 
echo list is ${a[@]}
n=10
echo "enter a number to find in the list: "
read num
index=0
while [ $index -le $n ]
do
	if [ $num = ${a[index]} ]
	then echo element found at position ` expr $index + 1`
	exit
	else
	index=` expr $index + 1`
	fi
	done
echo "element not found"
