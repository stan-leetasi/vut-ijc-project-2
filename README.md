## vut-ijc-project-2 

This program counts the words from the stdin input stream and displays the number of occurences of each unique word.
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

`make run <test.txt`br>

erat 	 1<br>
imperdiet 	 1<br>
sagittis 	 2<br>
fringilla, 	 1<br>
diam. 	 1<br>
eu, 	 1<br>
elit 	 1<br>
consectetur 	 1<br>
faucibus 	 1<br>
dapibus 	 1<br>
odio. 	 1<br>
Suspendisse 	 1<br>
vestibulum. 	 1<br>
eget, 	 1<br>
aliquam 	 1<br>
Lorem 	 1<br>
Duis 	 2<br>
amet 	 1<br>
velit 	 1<br>
at 	 1<br>
ipsum 	 1<br>
dolor 	 1<br>
magna 	 1<br>
ligula 	 1<br>
sit 	 2<br>
congue 	 1<br>
adipiscing 	 1<br>
amet, 	 1<br>
Integer 	 2<br>
elit. 	 1<br>
euismod 	 1<br>
eu 	 1<br>
bibendum 	 1<br>
efficitur 	 1<br>
nisi, 	 1<br>
nisi. 	 1<br>
ante 	 1<br>
eros, 	 1<br>
eros. 	 1<br>
leo 	 1<br>
at, 	 1<br>
vitae 	 2<br>
in 	 1<br>

Statistics: MAX: 1, MIN: 0, AVERAGE: 0.001835



