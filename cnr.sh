#!/bin/bash

rm -r bin

if [ -e "bin" ]; then
    :
else
    mkdir bin
fi

cp -r ./assets ./bin
cp -r ./shaders ./bin

mapfile -t source_files < <(find src -type f \( -name "*.cpp" -o -name "*.c" \) | sort)

echo "Compiling these files:"
printf '%s\n' "${source_files[@]}"

g++ -o ./bin/exe -std=c++26 "${source_files[@]}" -I./include -lGL -lGLU -lglut -lglfw -ldl -lX11 -lpthread -lXrandr -lXi

status=$?
if [ $status -ne 0 ]; then
    echo "Compilation error!"
    exit 1
else
    echo "Compilation done!"
    if [ -z "$1" ]; then
        echo "Running Program!"
        ./bin/exe
    else
        echo "Don't provide any arg to run the binary as well!"
    fi
fi