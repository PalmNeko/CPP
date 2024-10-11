#!/bin/bash

if ! test -f '19920104_091532.log'; then
    echo 'you need log file: 19920104_091532.log'
    exit
fi

./account_test.out | sed -E 's/\[.{15}\]/\[19920104_091532\]/g' > log.txt
diff 'log.txt' '19920104_091532.log' && echo -e 'success! your outputs are same!\nbut you should check the timestamp format.'
rm log.txt
