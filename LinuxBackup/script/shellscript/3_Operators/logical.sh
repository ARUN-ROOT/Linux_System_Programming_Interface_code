#**********************************************************************************************************
# Name				: 01.Logical operators                                   
# Date				: 26/3/2023                                                                  
# Author			: Arun.V                                                                    
# Code link			: 									         
# Descrition			: 	
# output			:



#**********************************************************************************************************

#! /bin/bash/

echo "Enter Age"
read age

if [[ $age>=18  &&  $age<=28 ]]
then
  echo "Marriage eligible "
else
  echo  "Not Possible"
fi 

echo "enter Mark"
read mark

if [[ $mark>=90  &&  $mark<=100 ]]
then
 echo "Good"
else
 echo "Meduim"
fi
