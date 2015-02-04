clear 
echo "enter a number: "
read a
echo "enter a number: "
read b
echo "Which operation would you like to perform"
echo "1) +"
echo "2) -"
echo "3) *"
echo "4) /"
echo "5) %"
echo "Enter your choice : "
read ch
case $ch in

1) echo `expr $a + $b` ;;
2) echo `expr $a - $b` ;;
3) echo `expr $a \* $b` ;;
4) echo `expr $a \/ $b` ;;
5) echo `expr $a % $b` ;;
*) echo "Invalid choice "

esac	
	
