#!/bin/bash

PASSED_TESTS=0
ALL_TESTS=0

function update_counters() {
  if [[ $? == $1 ]]
  then
    echo -e -n "OK"
    ((PASSED_TESTS++))
  else
    echo -e -n "WA"
  fi
  echo -e "\tfor test: $2"
  ((ALL_TESTS++))
}

echo -e "=================================="
echo -e "PROGRAM ARGUMENTS VALIDATION TESTS"
echo -e "=================================="

# 0 args
./$1 >/dev/null 2>&1
update_counters 1 "./testhttp_raw"

# 1 arg
./$1 www.mimuw.edu.pl:80 >/dev/null 2>&1
update_counters 1 "./testhttp_raw www.mimuw.edu.pl:80"

# 2 arg
./$1 www.mimuw.edu.pl:80 ciasteczka.txt >/dev/null 2>&1
update_counters 1 "./testhttp_raw www.mimuw.edu.pl:80 ciasteczka.txt"

# 3 arg - OK
./$1 www.mimuw.edu.pl:80 ciasteczka.txt http://www.mimuw.edu.pl/ >/dev/null 2>&1
update_counters 0 "./testhttp_raw www.mimuw.edu.pl:80 ciasteczka.txt http://www.mimuw.edu.pl/"

# 4 arg
./$1 www.mimuw.edu.pl:80 ciasteczka.txt http://www.mimuw.edu.pl/ mimuw >/dev/null 2>&1
update_counters 1 "./testhttp_raw www.mimuw.edu.pl:80 ciasteczka.txt http://www.mimuw.edu.pl/ mimuw"

echo -e "Passed: ${PASSED_TESTS} / ${ALL_TESTS}"
echo -e "==================================\n"

if [[ ${ALL_TESTS} -eq ${PASSED_TESTS} ]]
  then
    exit 0
  fi
  exit 1