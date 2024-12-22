#**********************************************************************************************************
# Name				: 01.Relational operators                                   
# Date				: 26/3/2023                                                                  
# Author			: Arun.V                                                                    
# Code link			: 									         
# Descrition			: 	
# output			:



#**********************************************************************************************************

#! /bin/bash

echo "welcome to Voter Eligibilty"
echo "Enter your name "
read name
echo "enter age"
read age

echo "check your details $name and $age "
echo "Type 1 for Yes or 2 for ss No "
read correct 
if [ $correct -eq 1 ]
then 
  echo "Welcomes"
fi
