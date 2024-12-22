#**********************************************************************************************************
# Name				: 01.Relational operators                                   
# Date				: 18/3/2023                                                                  
# Author			: Arun.V                                                                    
# Code link			: 									         
# Descrition			: Relational operators are specfic to Numeric value both side operands	
# output			:



#**********************************************************************************************************

#! /bin/bash

echo Enter x 
read x

echo Enter y
read y
#**********************************************
if(( $x>$y ))
then
 echo x is greater than y
else
 echo y is greater than x
fi
#***********************************************
if(( $x<$y ))
then
 echo x is less than y
else
 echo y is less than x
fi
#***********************************************
if(( $x >= $y ))
then
 echo x is Greter than equal to y
else
 echo x is less than y
fi



