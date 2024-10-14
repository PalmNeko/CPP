#!/bin/bash

echo "create infile!"
echo "I'm HUMAN!!" > infile
echo "replace infile strings HUMAN to Vampire"
./replace.out infile "HUMAN" "Vampire"
echo "check file is created"
test -f infile.replace && echo " > found infile.replace so OK!" || echo " > NOT found infile.replace so BAD!!"
echo "check file is expects"
echo "I'm Vampire!!" > expect
diff infile.replace expect && echo " > your output is right" || echo " > did unexpected result"
