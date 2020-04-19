CC = gcc
CFLAGS = -Wall -Wextra -std=c17 -O2
LDFLAGS =

.PHONY: all clean

# tutaj pewnie trzeba dodac headera swojego modulu
response_resolver_test.o: c/response_resolver_test.c ../../../docker-test/src/test/c/interfaces/response_resolver_test.h ../main/c/response_resolver.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -r -f *.o