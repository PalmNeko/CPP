#!/bin/bash

function snakeToPascal() {
    echo "$1" | awk -F '_' '{ for(i=1; i<=NF; i++) {printf toupper(substr($i,1,1)) substr($i,2)}} END {print ""}'
}

function snakeToCaml() {
    echo "$1" | awk -F '_' '{ printf $1; for(i=2; i<=NF; i++) {printf toupper(substr($i,1,1)) substr($i,2)}} END {print ""}'
}

function main()
{
    printf "please input class name (sep. space) : "
    read NAME
    NAME="$(echo $NAME)"
    if test -z "$NAME" ; then
        echo "please input class name separated with space"
        exit 0
    fi
    SNAKE_CASE="${NAME/ /_}"
    LOWER_SNAKE_CASE="${SNAKE_CASE,,}"
    PASCAL="$(snakeToPascal "$LOWER_SNAKE_CASE")"
    make_header "$NAME" > "${PASCAL}.hpp"
    make_source "$NAME" > "${PASCAL}.cpp"
    echo "done!"
}

function make_header() {
    NAME="$1"
    SNAKE_CASE="${NAME/ /_}"
    LOWER_SNAKE_CASE="${SNAKE_CASE,,}"
    UPPER_SNAKE_CASE="${SNAKE_CASE^^}"
    PASCAL="$(snakeToPascal "$LOWER_SNAKE_CASE")"
    CAML="$(snakeToCaml "$LOWER_SNAKE_CASE")"
    echo \
"#ifndef ${UPPER_SNAKE_CASE}_HPP
# define ${UPPER_SNAKE_CASE}_HPP

class ${PASCAL}
{
    // variables
    public:
    private:
    // functions
    public:
        // special member functions
        ${PASCAL}(void); // default constructor
        ${PASCAL}(const ${PASCAL}& ${CAML}); // copy constructor
        ~${PASCAL}(void); // destructor
        // operators
        ${PASCAL}& operator=(const ${PASCAL}& ${CAML}); // operator=
        // others
    private:
};

#endif"
}

function make_source() {
    NAME="$1"
    SNAKE_CASE="${NAME/ /_}"
    LOWER_SNAKE_CASE="${SNAKE_CASE,,}"
    UPPER_SNAKE_CASE="${SNAKE_CASE^^}"
    PASCAL="$(snakeToPascal "$LOWER_SNAKE_CASE")"
    CAML="$(snakeToCaml "$LOWER_SNAKE_CASE")"
    echo \
"#include \"${PASCAL}.hpp\"

/*
 * special member functions
 */
${PASCAL}::${PASCAL}(void)
{}

${PASCAL}::${PASCAL}(const ${PASCAL}& ${CAML})
{}

${PASCAL}::~${PASCAL}(void)
{}

/*
 * operators
 */
${PASCAL}& ${PASCAL}::operator=(const ${PASCAL}& ${CAML})
{
    if (this != &${CAML})
    {
    }
    return *this;
}

/*
 * others: public
 */

/*
 * others: private
 */
"
}

main
