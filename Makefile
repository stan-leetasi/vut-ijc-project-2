CC=gcc
CFLAGS= -g -Wextra -Wall -pedantic -std=c11 -O2
OBJS=htab_bucket_count.o htab_clear.o htab_erase.o htab_find.o htab_hash_function.o htab_init.o htab_lookup_add.o htab_size.o htab_free.o htab_for_each.o htab_statistics.o htab_print.o
OBJSD=htab_bucket_count_d.o htab_clear_d.o htab_erase_d.o htab_find_d.o htab_hash_function_d.o htab_init_d.o htab_lookup_add_d.o htab_size_d.o htab_free_d.o htab_for_each_d.o htab_statistics_d.o htab_print_d.o

default: libhtab.a wordcount libhtab.so wordcount-dynamic


#Staticka kniznica
libhtab.a: $(OBJS)
	ar rcs libhtab.a $(OBJS)
		
wordcount: wordcount.o
	$(CC) $(CFLAGS) -o wordcount wordcount.o -L. -lhtab

wordcount.o: wordcount.c htab.h 
	$(CC) $(CFLAGS) -c wordcount.c

#Dynamicka kniznica
libhtab.so: $(OBJSD)
	$(CC) -shared -o libhtab.so $(OBJSD)

wordcount-dynamic: wordcount.o libhtab.so
	$(CC) $(CFLAGS) -o wordcount-dynamic wordcount.o -L. -lhtab


htab_bucket_count.o: htab_bucket_count.c htab.h _htab_private.h
	$(CC) $(CFLAGS) -c htab_bucket_count.c

htab_clear.o: htab_clear.c htab.h _htab_private.h
	$(CC) $(CFLAGS) -c htab_clear.c
		
htab_erase.o: htab_erase.c htab.h _htab_private.h
	$(CC) $(CFLAGS) -c htab_erase.c

htab_find.o: htab_find.c htab.h _htab_private.h
	$(CC) $(CFLAGS) -c htab_find.c

htab_hash_function.o: htab_hash_function.c htab.h _htab_private.h
	$(CC) $(CFLAGS) -c htab_hash_function.c

htab_init.o: htab_init.c htab.h _htab_private.h
	$(CC) $(CFLAGS) -c htab_init.c

htab_lookup_add.o: htab_lookup_add.c htab.h _htab_private.h
	$(CC) $(CFLAGS) -c htab_lookup_add.c

htab_size.o: htab_size.c htab.h _htab_private.h
	$(CC) $(CFLAGS) -c htab_size.c

htab_free.o: htab_free.c htab.h _htab_private.h
	$(CC) $(CFLAGS) -c htab_free.c

htab_for_each.o: htab_for_each.c htab.h _htab_private.h
	$(CC) $(CFLAGS) -c htab_for_each.c

htab_statistics.o: htab_statistics.c htab.h _htab_private.h
	$(CC) $(CFLAGS) -c htab_statistics.c

htab_print.o: htab_print.c htab.h _htab_private.h
	$(CC) $(CFLAGS) -c htab_print.c


htab_bucket_count_d.o: htab_bucket_count.c htab.h _htab_private.h
	$(CC) -fPIC $(CFLAGS) -c htab_bucket_count.c -o htab_bucket_count_d.o

htab_clear_d.o: htab_clear.c htab.h _htab_private.h
	$(CC) -fPIC $(CFLAGS) -c htab_clear.c -o htab_clear_d.o
		
htab_erase_d.o: htab_erase.c htab.h _htab_private.h
	$(CC) -fPIC $(CFLAGS) -c htab_erase.c -o htab_erase_d.o

htab_find_d.o: htab_find.c htab.h _htab_private.h
	$(CC) -fPIC $(CFLAGS) -c htab_find.c -o htab_find_d.o

htab_hash_function_d.o: htab_hash_function.c htab.h _htab_private.h
	$(CC) -fPIC $(CFLAGS) -c htab_hash_function.c -o htab_hash_function_d.o

htab_init_d.o: htab_init.c htab.h _htab_private.h
	$(CC) -fPIC $(CFLAGS) -c htab_init.c -o htab_init_d.o

htab_lookup_add_d.o: htab_lookup_add.c htab.h _htab_private.h
	$(CC) -fPIC $(CFLAGS) -c htab_lookup_add.c -o htab_lookup_add_d.o

htab_size_d.o: htab_size.c htab.h _htab_private.h
	$(CC) -fPIC $(CFLAGS) -c htab_size.c -o htab_size_d.o

htab_free_d.o: htab_free.c htab.h _htab_private.h
	$(CC) -fPIC $(CFLAGS) -c htab_free.c -o htab_free_d.o

htab_for_each_d.o: htab_for_each.c htab.h _htab_private.h
	$(CC) -fPIC $(CFLAGS) -c htab_for_each.c -o htab_for_each_d.o

htab_statistics_d.o: htab_statistics.c htab.h _htab_private.h
	$(CC) -fPIC $(CFLAGS) -c htab_statistics.c -o htab_statistics_d.o

htab_print_d.o: htab_print.c htab.h _htab_private.h
	$(CC) -fPIC $(CFLAGS) -c htab_print.c -o htab_print_d.o

clear:
	rm -f *.o *.a

clean:
	rm -f *.o *.a *.so wordcount wordcount-dynamic

run: libhtab.a wordcount
	./wordcount

run-d: libhtab.so wordcount-dynamic
	export LD_LIBRARY_PATH="."; ./wordcount-dynamic
		