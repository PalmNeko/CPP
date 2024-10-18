#!/bin/bash

./a.out 2> /dev/null \
    | grep --color Failed -B 6 \
    || echo 'Success' | GREP_COLOR='1;32' grep --color Success
