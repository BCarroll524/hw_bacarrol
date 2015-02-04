## HW2
Blake Carroll
3001191388
bacarrol

This folder contains the provided code for hw2. 

Problem 3:
to compile first you need to make a .o file for llistdbl.cpp
to do this you need to execute "g++ -c llistdbl.cpp" on the command line, and it will create a .o file inside of the folder
then you need to execute another command that is "g++ -g -o main main.cpp llistdbl.o" which will compile the main.cpp as well as the llistdbl.o so it can be executed
lastly you need to call "./main" on the command line to run the program

Problem 4:
to compile first you need to make a .o file for alistint.cpp
to do this you need to execute "g++ -c alistint.cpp" on the command line, and it will create a .o file inside of the folder
then you need to execute another command that is "g++ -g -o alistmain alistmain.cpp alistint.o" which will compile the alistmain.cpp as well as the alistint.o so it can be executed
lastly you need to call "./alistmain" on the command line to run the program


Problem 7:
to compile first you need to make a .o file for stackdbl.cpp as well as llistdbl.cpp
to do this you need to execute "g++ -c stackdbl.cpp" on the command line and once that is done you with need to execute "g++ -c llistdbl.cpp" and it will create a .o file for both of the .cpp files inside of the folder
then you need to execute another command that is "g++ -g -o postfix postfix.cpp stackdbl.o llistdbl.o" which will compile the postfix.cpp as well as the stackdbl.o and llistdbl.o so it can be executed
lastly you need to call "./postfix postfix.in postfix.out" on the command line to run the program