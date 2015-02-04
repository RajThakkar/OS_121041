clear 
echo "enter a number: "
read a
echo "enter a number: "
read b

echo `expr $a + $b`
echo `expr $a - $b` 
echo `expr $a \* $b`
echo `expr $a \/ $b`
echo `expr $a % $b`


