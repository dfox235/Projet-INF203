all: newcow wildcow reading_cow tamagoshi_cow

newcow: newcow.o option.o 
		clang -o newcow newcow.o option.o 

wildcow: option.o wildcow.o
		clang -o wildcow option.o wildcow.o

reading_cow: reading_cow.o 
		clang -o reading_cow reading_cow.o 

tamagoshi_cow: tamagoshi_cow.o option.o options.h
		clang -o tamagoshi_cow tamagoshi_cow.o option.o

newcow.o: newcow.c options.h
		clang -Wall -Werror -Wno-unused -g -DDEBUG -c newcow.c

option.o: option.c options.h
		clang -Wall -Werror -Wno-unused -g -DDEBUG -c option.c

wildcow.o: wildcow.c options.h wildcow.h
		clang -Wall -Werror -Wno-unused -g -DDEBUG -c wildcow.c

reading_cow.o: reading_cow.c
		clang -Wall -Werror -Wno-unused -g -DDEBUG -c reading_cow.c

tamagoshi_cow.o: tamagoshi_cow.c options.h
		clang -Wall -Werror -Wno-unused -g -DDEBUG -c tamagoshi_cow.c

clean:
		rm *.o newcow wildcow reading_cow tamagoshi_cow
