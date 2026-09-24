#!/usr/bin/env bash

files=$(find -type f -name "*.out" -print)          # soluçao externa

for file in $files
do
    echo "Deletando: $file"
    rm $file
done
