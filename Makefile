all:srv cli

cli:cli.c
	gcc $^ -o $@

srv:srv.c tpool.c	
	gcc  $^ -lpthread -o $@ 	

clean:
	rm -rf tpool.o srv.o cli.o

.PHONY: all clean

