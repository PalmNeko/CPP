#!/bin/bash

if ! test -f ./a.out ; then
    echo '          Error!: 0'
fi
./a.out &> result.txt
diff expected.txt result.txt || echo 'Error!: 1'

TMP="$(expr "$(tput cols)" \- 4)"
if test "$TMP" -gt 70; then
    TMP=70
fi
TMP="$(expr "$TMP" / 2)"
echo ' /                       \                    /                       \'
echo '/                         \                  /                         \'
printf "%s%s%-s\n" '{ | ( l H : + = = = - - -      -: ' 'DONE' ' :-      - - - = = = + : H l ) | }'
echo '\                         /                  \                         /'
echo ' \                       /                    \                       /'
