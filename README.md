# Robots
simulation of random robot motion

I was asked by my university to create a c++ program that simulates the random motion of two robots on a matrix with a maximum size of 
40x40.The robots can go to 8 or 3 (corner) or 5 (boundary) adjacent positions,depending on their position on the matrix and of course one
can not go to the position of the other.The user enters the dimension of the matrix (Μ,Ν),the initial positions of the two robots (x1, y1)
and (x2, y2),the number T of the steps that the trace (the cells visited) of each robot remains active and the number K of the simulation
steps.The program returns the counter S that counts the times where a Robot can see the other Robot along a line, column or diagonal,the 
counter E that counts the times where a Robot passes through a cell where there is a trace of the other and the count C that counts the 
times a robot attempted to go to a place where the other one is already.
