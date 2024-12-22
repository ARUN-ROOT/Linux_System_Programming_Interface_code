#**********************************************************************************************************
# Name				: 01.Variables                                    
# Date				: 27/1/2023                                                                  
# Author			: Arun.V                                                                    
# Code link			: 									         
# Descrition			: 	
# output			:
#arun@arun:~/practise/shellscript/Variables$ ./01_Variables.sh 
#Arun
#25
#your name is : Arun
#your age is : 25
#****************************************
#your name is : GOPI
#your age is : 30
#****************************************
#Arun GOPI 25 30


#**********************************************************************************************************


#! /bin/bash

#variablename=value
#Note that there must be no spaces around the "=" sign: VAR=value works; VAR = value doesn't work.
#The shell does not care about types of variables; they may store strings, integers, real numbers - anything you like.
name=Arun

echo $name

age=25

echo $age

echo "your name is :" $name
echo "your age is :"  $age

echo "****************************************"
name1="GOPI"
age1="30"

echo "your name is :" $name1
echo "your age is :"  $age1

echo "****************************************"

echo "$name $name1 $age $age1" #inside Double Quotation also get variable


