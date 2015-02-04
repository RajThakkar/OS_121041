clear
ch=1;
while [ $ch = 1 ]
do
echo "Enter number below 50: "
read n
echo square is `expr $n \* $n `

echo "do u want to continue? 0/1 "
read ch
if [ $ch = 0 ]
then exit 
fi
done 
