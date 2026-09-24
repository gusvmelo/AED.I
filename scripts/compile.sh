#!/usr/bin/env bash

# usa o find pra achar os arquivos finalizados em .c de forma recursiva dentro do diretorio raiz
arquivos_c="$(find . -type f -name "*.c" -print)"

# define o diretorio de build
build_dir="./build/"

select file in $arquivos_c
do
    arquivo="${file##*/}"           # tira o caminho e deixa apenas o nome.c
    executable="$build_dir${arquivo%.c}.out"            # substitui o .c por .out e adciona o caminho do diretorio de build

    gcc "$file" -o "$executable"            # compila
    
    echo ""
    
    "$executable"       # executa
    
    break
done

