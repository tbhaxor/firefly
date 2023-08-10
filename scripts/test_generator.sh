#!/bin/bash

git_dir=$(git rev-parse --show-toplevel)

: "${SRC_DIR_BASE:=src}"
: "${TESTS_DIR_BASE:=tests}"

src_dir="$git_dir/$SRC_DIR_BASE"
unimplemented_tests='false'

# shellcheck disable=SC2044
for src_file in $(find "$src_dir" -type f -name "*.cpp" | sort); do
    test_file="${src_file//$SRC_DIR_BASE/$TESTS_DIR_BASE}"
    test_name=$(basename "$test_file" | awk -F'.' '{print $1}')
    test_suite_name=$(basename "$(dirname "$test_file")")
    if [[ "$test_name" == "$test_suite_name" ]]; then 
        ext_name=$(basename "$test_file" | awk -F'.' '{print $2}')
        test_file="${test_file//"${test_name}.${ext_name}"/"constructor.${ext_name}"}"
        test_name='constructor'
    fi
    test_suite_name="$(tr '[:lower:]' '[:upper:]' <<< "${test_suite_name:0:1}")${test_suite_name:1}"
    if [[ ! -f "$test_file" ]]; then
        mkdir -p "$(dirname "$test_file")"
        if [[ -n "$CI" ]]; then
            unimplemented_tests='true'
            continue
        fi

        cat <<EOF > "$test_file"
#include <stdexcept>

#include "firefly/vector.hpp"
#include "gtest/gtest.h"

TEST($test_suite_name, ${test_name}__example) {
    ASSERT_TRUE(true);
}
EOF
    echo "Created test TEST($test_suite_name, ${test_name}__example) in '$test_file'"
    fi
done

if $unimplemented_tests; then
    echo "[x] Some tests are not implemented. Run this script on your local environment to generate it/"
    exit 1
fi