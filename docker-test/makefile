CC = gcc
CFLAGS = -Wall -Wextra -std=c17 -O2
LDFLAGS =

.PHONY: all clean

all: response_resolver_test

response_resolver_test: response_resolver_test_impl.o ../solve/src/test/response_resolver_test.o ../solve/response_resolver.o ../solve/logger.o ../solve/safe_memory.o ../solve/string_buffer.o ../solve/buffered_reader.o ../solve/tcp_client.o
	$(CC) $(LDFLAGS) -o $@ $^

response_resolver_test_impl.o: src/test/c/response_resolver_test_impl.c src/test/c/interfaces/response_resolver_test.h
	$(CC) $(CFLAGS) -c $<