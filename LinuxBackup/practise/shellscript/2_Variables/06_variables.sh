#**********************************************************************************************************
# Name				: 06.Variables                                    
# Date				: 27/1/2023                                                                  
# Author			: Arun.V                                                                    
# Code link			: 									         
# Descrition			: Backtick symbol in Variable
#				 The backtick allows you to assign the output of a shell command to a variable. While this doesn’t seem like #much, it is a major building block in script programming. You must surround the entire command line command with backtick characters:
# output			:



#**********************************************************************************************************


#! /bin/bash
echo "Date command used in Script"
date

echo "**********"
echo "Backtick used date command assigned to Variable value"
value=`date`
echo $value

echo "****backtick replace dollar(command)*********"
value1=$(date)
echo $value1



