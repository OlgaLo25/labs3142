<<<<<<< HEAD
# labs3142
The main branch for the labs CISC 3142

Author: Olga Chsherbakova
=======
# labs3142_lab_2
The program is a simple calculator (not scientific) created with all program’s structure requirements. This program include:

Structure.  Include the enum {ADD, SUBSTRACT, MULTIPLY, DIVIDE, SQRT, POW, OPEN_BRACKET, NUMBER} op;
This structure gives the opotunity easier to manipulate with giving cheraters

Utils. The functions which do the manipulations in different classes. Can be applied to any method in the classes.

Postfix. I chose the postfix method to create the calculator. This class transforms any expression to postfix using “stacks”. 

Calculator. The class takes postfix expressions and calculates them.

All these classes have the “header” files with the constructor and “cpp” files for actions and manipulations (all logic is in cpp files) . 

The “Main” is for input files, which can be done from the keyboard, file, or any other method. On this program the input was done as an expression in the method itself for tests, but it can easily change. Also calling “Postfix.h” and “Calculator.h” are done from the “main''.

The main purpose of this program was to make a structured program with Makefile and Test.
Makefile does all actions with the program such as, compile is, makes .cpp files, object .o files, and runs the test file. At the end, Makefile cleans all files which were created during its run. 
All the tests have been done on GitHub and were done successfully.
A well-structured file makes it easy to navigate the program, find errors, and some classes can be used standalone without being tied to the rest of the program. 
Makefile and test allows you to make sure that everything works and there are no errors:  syntactic, compilation and logical 
>>>>>>> lab_2
