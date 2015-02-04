clear
echo "What is the capital of gujarat? (answer in lowercase) "

cnt=0
while [ $cnt = 0 ] 
do
read ans
key="gandhinagar"
if [ $ans = $key ]
	then echo "correct answer"
	exit
else echo "try again"
fi
done

