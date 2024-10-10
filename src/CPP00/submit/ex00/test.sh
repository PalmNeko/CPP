#!/bin/bash

test -f ./megaphone || echo 'you need program `megaphone`'

echo 'test: ./megaphone "shhhhh... I think the students are asleep..." > outfile'
./megaphone "shhhhh... I think the students are asleep..." > outfile
diff <(echo "SHHHHH... I THINK THE STUDENTS ARE ASLEEP...") outfile

echo 'test: ./megaphone Damnit " ! " "Sorry students, I thought this thing was off." > outfile'
./megaphone Damnit " ! " "Sorry students, I thought this thing was off." > outfile
diff <(echo "DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.") outfile

echo 'test: ./megaphone > outfile'
./megaphone > outfile
diff <(echo "* LOUD AND UNBEARABLE FEEDBACK NOISE *") outfile

rm outfile
