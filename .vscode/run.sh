#!/bin/sh

compiler=gcc
extension=c

clear
rm -rf ./bin/$1
mkdir ./bin/$1

echo "HELLLPO"

if $compiler ./kod/$1.$extension -o ./bin/$1/$1
then
  echo "lol xD"
else
  echo -n "Press any key to continue..."
  read -n1 -s
fi

if [ -f ./bin/$1/$1 ] 
then
  clear

  echo $1.$extension:
  echo

  ./bin/$1/$1
  echo
fi