#**********************************************************************************************************
# Name				: 01.Arthmetic operators                                   
# Date				: 1/3/2023                                                                  
# Author			: Arun.V                                                                    
# Code link			: 									         
# Descrition			: 	
# output			:



#**********************************************************************************************************

#!/bin/bash

echo "Enter Number x"
read x

echo "enter Numbet y"
read y

echo "Addition $(( $x + $y ))"
echo "Subtraction $(($x - $y))"
echo "Multiplication $(($x * $y))"
echo "Division $(($x / $y))"
echo "Modulus $(($x % $y))"
echo "Exp power $((x**y))"

echo Different ways $((x+y))

Total=$((x+y))

echo Total = $Total

((add=x+y))
echo add=$add

let "z=$((x+y))" #using let command
echo "z= $z"

sum=`expr $x + $y`  #using bcktick and expr
echo sum $sum


