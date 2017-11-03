all: cli srv

srv: srv.c apue.h
	gcc $^ -o $@

cli:cli.c apue.h
	gcc $^ -o $@

clean:
	rm cli srv

.PHONY: all clean
	
