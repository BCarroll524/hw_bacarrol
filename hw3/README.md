Blake Carroll
3001191388
bacarrol@usc.edu

Each problem is in their own directory with a name corresponding to there problem number.
I do not have makefiles so I am going to provide command line operations. 

prob 2:

g++ -c llistint.cpp
g++ -g -o llisttest llisttest.cpp llistint.cpp

prob 3:

g++ -c setint.cpp
g++ -g -o test3 test3.cpp setint.o ../prob2/llistint.o
./test3

prob 4:

g++ -g -o main main.cpp ../prob2/llistint.cpp
./main pages.txt output.txt The fox onion 104