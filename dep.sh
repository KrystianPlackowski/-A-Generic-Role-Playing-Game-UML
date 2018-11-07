#!/bin/bash

set -e

echo "Creating dependency file"
echo "## DEP" >dep.mk

for i in $(find -name "*.cpp" -or -name "*.h")
do
	P=$(dirname $i)
	dep=$(cat $i | sed -n -E 's|^[ \t]*#include[ \t]*"(.*.h)"|'$P'/\1|p' | paste -s -d " ")
	if ! test -z "$dep"
	then
		echo "$i : $dep" >>dep.mk
		echo -ne "\t@test -f \$@ && touch \$@\n" >>dep.mk
		echo -ne "\t@echo \$@ depends on \$^\n" >>dep.mk
	else
		echo "# $i - no dependencies" >>dep.mk
	fi
done

SOURCE=$(find -name "*.cpp" | paste -sd " ")

echo >>dep.mk
echo "SOURCE=$SOURCE" >>dep.mk
