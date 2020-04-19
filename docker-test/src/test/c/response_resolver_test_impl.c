#include "interfaces/response_resolver_test.h"

#include <string.h>

void test_for_404_one_part_id_1();
void test_for_404_big_parts_id_2();
void test_for_404_small_parts_id_3();


void run_test(const char **response_parts, size_t number_of_response_parts,
  size_t response_part_size);

int main(int argc, char *argv[]) {
  int test_id = atoi(argv[1]);

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
    "Date: Sun, 18 Oct 2012 10:36:20 GMT\n"
    "Server: Apache/2.2.14 (Win32)\n"
    "Content-Length: 230\n"
    "Connection: Closed\n"
    "Content-Type: text/html; charset=iso-8859-1\n"
    "<!DOCTYPE HTML PUBLIC \"-//IETF//DTD HTML 2.0//EN\">\n"
    "<html>\n"
    "<head>\n"
    "   <title>404 Not Found</title>\n"
    "</head>\n"
    "<body>\n"
    "   <h1>Not Found</h1>\n"
    "   <p>The requested URL /t.html was not found on this server.</p>\n"
    "</body>\n"
    "</html>"
  };

  const size_t number_of_response_parts = 1;
  const size_t response_part_size = strlen(HTTP_RESPONSE_404_ONE_PART[0]);

  run_test(HTTP_RESPONSE_404_ONE_PART,
    number_of_response_parts, response_part_size);
}

void test_for_404_big_parts_id_2() {
  const char *HTTP_RESPONSE_404_BIG_PARTS[] = {
    "HTTP/1.1 404 Not Found\r\n"
    "Date: Tu, 18 Oct 2012 10:36:20 GMT\n"
    "Serve", "r: Apache/2.2.14 (Win32)\n"
    "Content-Length: 230\n"
    "Connection: Closed\n",
    "Content-Type: text/html; charset=iso-8859-1\n"
    "<!DOCTYPE HTML PUBLI", "C \"-//IETF//DTD HTML 2.0//EN\">\n"
    "<html>\n"
    "<head>\n"
    "   <title>404 Not F", "ound</title>\n"
    "</head>\n"
    "<body>\n"
    "   <h1>Not Found</h1>\n"
    "   <p>The requ", "ested URL /t.html was not found on this server.</p>\n"
    "</body>\n"
    "</ht", "ml>"
  };

  const size_t number_of_response_parts = 7;
  const size_t response_part_size = 64;

  run_test(HTTP_RESPONSE_404_BIG_PARTS,
    number_of_response_parts, response_part_size);
}

void test_for_404_small_parts_id_3() {
  const char *HTTP_RESPONSE_404_BIG_PARTS[] = {
    "HTTP/1.", "1 404 N", "ot Foun", "d\r\n"
    "Date", ": Tu, 1", "8 Oct 2", "012 10:", "36:20 G", "MT\n"
    "Serv", "er: Apa", "che/2.2", ".14 (Wi", "n32)\n"
    "Co", "ntent-L", "ength: ", "230\n"
    "Con", "nection", ": Close", "d\n"
    "Conte", "nt-Type", ": text/", "html; c", "harset=", "iso-885", "9-1\n"
    "<!D", "OCTYPE ", "HTML PU", "BLIC \"-", "//IETF/", "/DTD HT", "ML 2.0/", "/EN\">\n"
    "<\n", "html>"
    "<\n", "head>\n"
    " ", "  <titl", "e>404 N", "ot Foun", "d</titl", "e>\n"
    "</he", "ad>\n"
    "<bo", "dy>\n"
    "   ", "<h1>Not", " Found<", "/h1>\n"
    "  ", " <p>The", " reques", "ted URL", " /t.htm", "l was n", "ot foun", "d on th", "is serv", "er.</p>", "\n"
    "</body", ">\n"
    "</htm", "l>"
    };

  const size_t number_of_response_parts = 56;
  const size_t response_part_size = 7;

  run_test(HTTP_RESPONSE_404_BIG_PARTS,
    number_of_response_parts, response_part_size);
}

void run_test(const char **response_parts, size_t number_of_response_parts, size_t response_part_size) {
  report_for_response_test((char **) response_parts, number_of_response_parts, response_part_size);
}


