#**********************************************************************************************************
# Name				: 05.Variables                                    
# Date				: 27/1/2023                                                                  
# Author			: Arun.V                                                                    
# Code link			: 									         
# Descrition			: Types of Assigning Variable 
#				 
# output			:
#arun@arun:~/practise$ ./script.sh
#name1 is Arun
#name2 is Arun
#value1 is 10
#value2 is 10
#name1 is GOPI
#value1 is 50


#**********************************************************************************************************


#! /bin/bash

#variable value assigned to another variable
name1=Arun
echo "name1 is "$name1
name2=$name1
echo "name2 is "$name2

value1=10
echo "value1 is "$value1
value2=$value1
echo "value2 is "$value2

#update variable value
name1=GOPI
echo "name1 is "$name1

value1=50
echo "value1 is "$value1



