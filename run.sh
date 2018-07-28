#!/bin/bash

echo Criando executável

make clean
make

echo Executando

./bin/Program < in.txt


