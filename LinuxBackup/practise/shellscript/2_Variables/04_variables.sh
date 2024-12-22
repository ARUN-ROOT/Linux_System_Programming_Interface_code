#**********************************************************************************************************
# Name				: 04.Variables                                    
# Date				: 27/1/2023                                                                  
# Author			: Arun.V                                                                    
# Code link			: 									         
# Descrition			: Special Variables in Shell Scripts	
# output			:
#arun@arun:~/practise$ ./script.sh ARUN GOPI 25 
#First Argument ./script.sh
#Second Argument ARUN
#Third Argument GOPI
#********************
#ALL ARGUMENT DISPLAY  ARUN GOPI 25
#ALL ARGUMENT DISPLAY  ARUN GOPI 25
#COUNT 3
#PID 11085

#**********************************************************************************************************


#! /bin/bash

echo "First Argument" $0
echo "Second Argument" $1
echo "Third Argument" $2

echo "********************"

echo "ALL ARGUMENT DISPLAY " $@

echo "ALL ARGUMENT DISPLAY " $*

echo "COUNT" $#

echo "PID" $$


