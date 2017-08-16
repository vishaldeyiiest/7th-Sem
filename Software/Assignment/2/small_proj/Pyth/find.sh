#!/bin/bash
# This shell script finds source files of given extensions to cscope.files
# and then builds database
rm cscope*
echo -n "Enter source file extensions: "
read line
read -a ext <<< $line
for x in ${ext[@]}
do
echo "Type --> $x"
find . -maxdepth 1 -name "*.$x" -print >> cscope.files
done
echo "Building cscope database..."
cscope -q -k -b -i cscope.files
exit 0
