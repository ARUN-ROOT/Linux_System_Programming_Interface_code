/************************************************************************************************************/
/* Name			: gcc1.c                  			                              */
/* Date			: 7/1/2023                                                                   */
/* Author			: Arun.V                                                                     */
/* Code link			:                                                                            */
/* Descrition			:  GCC compilation steps                                                     */
/*			          Here Explain all GCC Compilation step by step at each stage      		*/
/* o/p				:                                                                            */
/************************************************************************************************************/



#include <stdio.h>

void main()
{
printf("Hai\n");

}


// cpp file.c > file.i  (source file --> Preprocessor ---> file.i)
// gcc  -s  file.i      (file.i --> Compilation --> file.s)
// as file.s -o file.o  (file.s --> Assembler --> file.o)
// gcc file.o -o file   (file.o -->Linker --> ./file executable file)/

/*
						Preprocessor  gcc -E arun.c > arun.i
						    |
						    |.i
						Compilation   gcc -S arun.i //(file.i --> Compilation --> file.s)
						    |
						    |.s
						  Assembler   gcc -c arun.s //(file.s --> Assembler --> file.o)
						    |
						    |.o
						  Linker      gcc arun.o -o arun//(file.o -->Linker --> ./file executable file)
						    |
						    |
						 arun(exe) ./arun

 (NOTE: If you want directly obj file from source file before linker   gcc -c arun.c -o arun.o or gcc -c arun.c
        If you want directly exe file from source file after linker    gcc -o arun arun.c  or gcc arun.c -o arun)
        
        
        If you have more obj file then convert into single exe file
        gcc main.o add.o -o test
        
        ./test (loader file.exe)


 
        -c  Compile or assemble the source files, but do not link.  The linking stage simply is not done.  The ultimate output is in the
           form of an object file for each source file.

           By default, the object file name for a source file is made by replacing the suffix .c, .i, .s, etc., with .o.

           Unrecognized input files, not requiring compilation or assembly, are ignored.

       -S  Stop after the stage of compilation proper; do not assemble.  The output is in the form of an assembler code file for each non-
           assembler input file specified.

           By default, the assembler file name for a source file is made by replacing the suffix .c, .i, etc., with .s.

           Input files that don't require compilation are ignored.

       -E  Stop after the preprocessing stage; do not run the compiler proper.  The output is in the form of preprocessed source code,
           which is sent to the standard output.

           Input files that don't require preprocessing are ignored.

       -o file
           Place output in file file.  This applies to whatever sort of output is being produced, whether it be an executable file, an
           object file, an assembler file or preprocessed C code.

           If -o is not specified, the default is to put an executable file in a.out, the object file for source.suffix in source.o, its
           assembler file in source.s, a precompiled header file in source.suffix.gch, and all preprocessed C source on standard output.



*/
