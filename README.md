<<<<<<< HEAD
# labs3142
The main branch for the labs CISC 3142

Author: Olga Chsherbakova
=======
# labs3142_lab_3
This is a programming assignment exposed to the OOP paradigm, as well as practice with refactoring code to make it more maintainable.
This program include:
Folders: data, include, obj, output, src and test.
		"include" consists of .h files which include the structure and declared methods with private and public fields.
		"controller" consists of declaring the functions which can control data.
		"structure" include the enum with grades and structure of data
		"utils" include the regular functions which do the manipulations in different classes. Can be applied to any method in the classes.
		"write_read" declare the methods for write and read files

Every header file has a .cpp file, where all logic is present.
	"calculation.cpp"  includes all methods for calculating the data. The methods are very similar to each other and use the same data structure.
	"controller.cpp" was created to control enrollment (add students to the data), update student's grade and search all information about the student.
	Controller has the different purpose from the calculation because it's control and upgrade the data file, but calculation.cpp only use the data 		file to give us the information.
	"utils.cpp" includes standard methods such as: "split"-separate the data, assign and add to the vector, "dataGrade"- assign grades to enum.
	"isPass" - which grade is associated with pass or fail which, "printData"-this method can work for any vector passed. Utils help to keep the main code logic cleaner.
	"write_read" include the methods for working with data such as read and write. It includes as standard methods which can be used in any other program, as a special method only for these data files.

The “Main” includes a while-switch loop for 8 cases and exit from the program. In the loop the methods for each case are called. Also the main method includes the Chrono system clock, so we can control when the output file is updated.

The main purpose of this program was to make a structured program with Makefile and Test.
Makefile does all actions with the program such as, compile is, makes .cpp files, object .o files, and runs the test file. At the end, Makefile cleans all files which were created during its run. 
All the tests have been done on GitHub and were done successfully.
A well-structured file makes it easy to navigate the program, find errors, and some classes can be used standalone without being tied to the rest of the program. 
Makefile and test allows you to make sure that everything works and there are no errors:  syntactic, compilation and logical 
>>>>>>> lab_3
