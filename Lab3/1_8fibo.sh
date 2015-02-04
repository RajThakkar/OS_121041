# fibonacci
clear
echo "Generate fibonacci numbers till what number ? "
read n
i=0
j=1
echo " $i "
echo " $j "
cnt=2
while [ $cnt -le $n ]
do
	cnt=`expr $cnt + 1`
	temp=$j
	j=`expr $j + $i `
	i=$temp
	echo " $j "
done
	
