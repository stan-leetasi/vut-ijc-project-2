## vut-ijc-project-2 

This program counts the words from the stdin input stream and displays the number of occurences of each unique word.<br> 
It utilizes a hash table, implemented as a dynamically allocated array of linked lists, to store and count the frequency of words.

## Program Functionality

The program reads words from the input, separated by whitespace, and increments their count in the hash table. Once all the words are read, it prints each word along with its frequency. On the last line it prints out the hash table statistics - lenghts of linked lists.

## Build Structure

The hash table is built in the form of a static library used by wordcount, and a dynamic library used by wordcount-dynamic. Each htab_*.c file contains an individual function used by the hash table. The library interface only includes an incomplete declaration of the structure, while the definition is hidden from library users (in _htab_private.h).

## Usage

1. Compile the program with the provided Makefile:

`make wordcount-dynamic`	Builds only the wordcount-dynamic executable and libhtab.so library file

`make wordcount`		Builds only the wordcount executable and libhtab.a library file

`make`				Builds both

2. To run the program:

`make run "input text"`		Uses the static hash table library

`make run-d "input text"`	Uses the dynamic hash table library

3. Teardown:

`make clear`	Deletes intermediate and static library files

`make clean`	Deletes all intermediate, library and executable files

## Example input and output

`make run <test.txt`

erat 	 1
imperdiet 	 1
sagittis 	 2
fringilla, 	 1
diam. 	 1
eu, 	 1
elit 	 1
consectetur 	 1
faucibus 	 1
dapibus 	 1
odio. 	 1
Suspendisse 	 1
vestibulum. 	 1
eget, 	 1
aliquam 	 1
Lorem 	 1
Duis 	 2
amet 	 1
velit 	 1
at 	 1
ipsum 	 1
dolor 	 1
magna 	 1
ligula 	 1
sit 	 2
congue 	 1
adipiscing 	 1
amet, 	 1
Integer 	 2
elit. 	 1
euismod 	 1
eu 	 1
bibendum 	 1
efficitur 	 1
nisi, 	 1
nisi. 	 1
ante 	 1
eros, 	 1
eros. 	 1
leo 	 1
at, 	 1
vitae 	 2
in 	 1

Statistics: MAX: 1, MIN: 0, AVERAGE: 0.001835



