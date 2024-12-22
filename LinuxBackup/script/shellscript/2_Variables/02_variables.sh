#**********************************************************************************************************
# Name				: 02.Variables                                    
# Date				: 27/1/2023                                                                  
# Author			: Arun.V                                                                    
# Code link			: 									         
# Descrition			: Read from user input into Variables	
# output			:
#arun@arun:~/practise$ ./script.sh
#what is your name ? 
#ARUN
#Hi ARUN , Welcome



#**********************************************************************************************************


#! /bin/bash

#variablename=value
#Note that there must be no spaces around the "=" sign: VAR=value works; VAR = value doesn't work.
#The shell does not care about types of variables; they may store strings, integers, real numbers - anything you like.

echo "what is your name ? "

read name

echo "Hi $name , Welcome"



