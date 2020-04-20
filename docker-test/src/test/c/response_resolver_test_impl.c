#include "interfaces/response_resolver_test.h"

#include <string.h>

void test_for_404_one_part_id_1();
void test_for_404_big_parts_id_2();
void test_for_404_small_parts_id_3();


void run_test(const char **response_parts, size_t number_of_response_parts,
  size_t response_part_size);

int main(int argc, char *argv[]) {
  int test_id = argc > 1 ? atoi(argv[1]) : 0;

  switch (test_id) {
    case 1:
      test_for_404_one_part_id_1();
      break;
    case 2:
      test_for_404_big_parts_id_2();
      break;
    case 3:
      test_for_404_small_parts_id_3();
      break;
    default:
      break;
  }

  return 0;
}

void test_for_404_one_part_id_1() {
  const char *HTTP_RESPONSE_404_ONE_PART[] = {
    "HTTP/1.1 404 Not Found\r\n"
    "Date: Sun, 18 Oct 2012 10:36:20 GMT\r\n"
    "Server: Apache/2.2.14 (Win32)\r\n"
    "Content-Length: 0\r\n"
    "Connection: Closed\r\n"
    "\r\n"
  };

  const size_t number_of_response_parts = 1;
  const size_t response_part_size = strlen(HTTP_RESPONSE_404_ONE_PART[0]);

  run_test(HTTP_RESPONSE_404_ONE_PART,
    number_of_response_parts, response_part_size);
}

void test_for_404_big_parts_id_2() {
  const char *HTTP_RESPONSE_404_BIG_PARTS[] = {
    "HTTP/1.1 404 Not Found\r\n"
    "Date: Sun, 18 Oct 2012 10:36:20 GMT\r\n"
    "Ser", "ver: Apache/2.2.14 (Win32)\r\n"
    "Content-Length: 0\r\n"
    "Connection: Close", "d\r\n"
    "\r\n"
  };

  const size_t number_of_response_parts = 3;
  const size_t response_part_size = 64;

  run_test(HTTP_RESPONSE_404_BIG_PARTS,
    number_of_response_parts, response_part_size);
}

void test_for_404_small_parts_id_3() {
  const char *HTTP_RESPONSE_404_BIG_PARTS[] = {
    "HTTP/1.", "1 404 N", "ot Foun", "d\r\n"
    "Date", ": Sun, ", "18 Oct ", "2012 10", ":36:20 ", "GMT\r\n"
    "Se", "rver: A", "pache/2", ".2.14 (", "Win32)\r","\n"
    "Conten", "t-Lengt", "h: 0\r\n"
    "C", "onnecti", "on: Clo", "sed\r\n"
    "\r\n"
  };

  const size_t number_of_response_parts = 19;
  const size_t response_part_size = 7;

  run_test(HTTP_RESPONSE_404_BIG_PARTS,
    number_of_response_parts, response_part_size);
}

void run_test(const char **response_parts, size_t number_of_response_parts, size_t response_part_size) {
  report_for_response_test((char **) response_parts, number_of_response_parts, response_part_size);
}


