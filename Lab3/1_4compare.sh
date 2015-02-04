clear 
echo "enter 2 numbers a and b"
read a b
if [ $a= $b]
then 
echo "Both numbers are equal"
elif [ $a \> $b ]
	then 
	echo "a is greater than b"
	else
	echo "a is smaller than b"
fi
