CC = g++
CFLAGS = -Wall -g
 
lab1: main.cpp Controller.h Process.h Common.h
	$(CC) $(CFLAGS) -o lab1 main.cpp
 