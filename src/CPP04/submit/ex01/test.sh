#!/bin/bash

if ! test -f ./a.out ; then
    echo '          Error!: 0'
fi
./a.out &> result.txt
diff expected.txt result.txt || echo 'Error!: 1'

echo "DONE"
