#!/bin/bash

##############
### Colors ###
##############

BLACK="\033[1;30m"
RED="\033[1;31m"
GREEN="\033[1;32m"
CYAN="\033[1;36m"
PURPLE="\033[1;35m"
WHITE="\033[1;37m"
EOC="\033[0;0m"
bold="\e[1m"
uline="\e[4m"
reset="\e[0m"


#--------------#
#   0. Setup   #
#--------------#

make re -j

#--------------#
#   1. Pipex   #
#--------------#
list_cmd=("file1 ls wc file2", "file1 ls ls file2")

echo "TESTING FD LEAKS:"
for cmd in "${list_cmd[@]}"
do
    valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes ./pipex ${cmd} 2>&1 | grep "indirectly lost:" | awk ' {if ($0==1) {print "[1]: \033[1;32m GOOD \033[0;0m"; exit}{print "[1]:\033[1;31m ERROR \033[0;0m"}}'
done