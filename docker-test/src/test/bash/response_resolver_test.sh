#!/bin/bash

PASSED_TESTS=0
ALL_TESTS=0
RESOURCES_PATH=src/test/resources/response_resolver_test

function update_counters() {
  if diff ${RESOURCES_PATH}/out ${RESOURCES_PATH}/id_$1.out -Z >/dev/null 2>&1
  then
    echo -e -n "OK"
    echo -e "\tfor test: $2"
    ((PASSED_TESTS++))
  else
    echo -e -n "WA"
    echo -e "\tfor test: $2"
    echo -e "Got:"
    cat ${RESOURCES_PATH}/out
    echo -e "\nExpected:"
    cat ${RESOURCES_PATH}/id_$1.out
  fi
  ((ALL_TESTS++))
}

echo -e "=================================="
echo -e "CREATING REPORT FOR RESPONSE TESTS"
echo -e "=================================="

./response_resolver_test 1 > ${RESOURCES_PATH}/out
update_counters 1 "one part response (id: 1)"

./response_resolver_test 2 > ${RESOURCES_PATH}/out
update_counters 2 "big parts response (id: 2)"

./response_resolver_test 3 > ${RESOURCES_PATH}/out
update_counters 3 "small parts response (id: 3)"

echo -e "Passed: ${PASSED_TESTS} / ${ALL_TESTS}"
echo -e "==================================\n"

if [[ ${ALL_TESTS} -eq ${PASSED_TESTS} ]]
  then
    exit 0
  fi
  exit 1