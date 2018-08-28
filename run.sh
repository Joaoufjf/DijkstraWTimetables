#!/bin/bash

#echo Criando executável

make clean > garbage.txt
make > garbage.txt

rm garbage.txt

#echo Executando

./bin/Program < in.txt


