# vut-ijc-project-2 

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

`make run <test.txt`

1        enim<br>
4        a<br>
2        sollicitudin<br>
2        Cras<br>
3        risus<br>
2        ultricies<br>
2        tellus<br>
2        lectus<br>
3        erat<br>
2        vestibulum<br>
2        auctor<br>
2        imperdiet<br>
2        Vestibulum<br>
1        accumsan<br>
1        odio<br>
1        sagittis<br>
1        semper<br>
2        feugiat<br>
2        potenti<br>
1        mi<br>
1        malesuada<br>
1        Morbi<br>
3        quis<br>
2        vehicula<br>
1        Fusce<br>
3        dignissim<br>
2        eros<br>
1        luctus<br>
2        interdum<br>
7        eget<br>
2        elit<br>
2        nunc<br>
2        consectetur<br>
1        dapibus<br>
4        nibh<br>
1        convallis<br>
1        tortor<br>
2        felis<br>
1        laoreet<br>
2        finibus<br>
3        orci<br>
3        pretium<br>
2        In<br>
2        pellentesque<br>
3        volutpat<br>
3        Suspendisse<br>
1        nulla<br>
1        lacinia<br>
3        porta<br>
2        Vivamus<br>
3        fringilla<br>
2        facilisis<br>
1        aliquam<br>
2        tempus<br>
1        sed<br>
1        sem<br>
1        mattis<br>
6        tincidunt<br>
1        eleifend<br>
1        rutrum<br>
1        fermentum<br>
8        amet<br>
6        vel<br>
5        ut<br>
3        ac<br>
2        at<br>
1        rhoncus<br>
2        est<br>
2        ipsum<br>
4        dolor<br>
1        pulvinar<br>
2        magna<br>
1        lacus<br>
1        ligula<br>
3        non<br>
2        Mauris<br>
2        tempor<br>
2        suscipit<br>
1        Nullam<br>
8        sit<br>
1        Curabitur<br>
1        congue<br>
1        condimentum<br>
1        tristique<br>
1        adipiscing<br>
2        Phasellus<br>
1        lobortis<br>
2        commodo<br>
2        viverra<br>
3        mauris<br>
3        mollis<br>
2        scelerisque<br>
1        arcu<br>
4        et<br>
5        eu<br>
3        ex<br>
1        bibendum<br>
1        efficitur<br>
3        libero<br>
1        justo<br>
2        sodales<br>
1        quam<br>
2        metus<br>
1        diam<br>
1        dui<br>
1        venenatis<br>
1        aecenas<br>
1        Nam<br>
1        vulputate<br>
4        Sed<br>
2        neque<br>
2        iaculis<br>
1        maximus<br>
3        consequat<br>
1        varius<br>
2        Etiam<br>
2        Donec<br>
5        ante<br>
2        sapien<br>
2        nisi<br>
4        nisl<br>
2        Aliquam<br>
4        leo<br>
2        turpis<br>
1        Pellentesque<br>
1        ultrices<br>
4        vitae<br>
1        estibulum<br>
1        dictum<br>
3        massa<br>
1        id<br>
5        in<br>
1        orem<br>
1        Ut<br>
1        ornare<br>
1        Nulla<br>
1        augue<br>
4        urna<br>
Statistics: MAX: 1, MIN: 0, AVERAGE: 0.005890, TABLE SIZE: 138, BUCKET COUNT: 23431



