#!/bin/bash

## --- FUNCITONS --- ##
function yes_or_no {
    while true; do
        read -p "$* [y/n]: " yn
        case $yn in
            [Yy]*) return 0  ;;  
            [Nn]*) echo "Aborted" ; return  1 ;;
        esac
    done
}

## --- BUILD --- ##

SRC_PATH="./src"
BIN_PATH="./bin/MAIN.a"

# Get all the cpp files in the source directory
SRC_FILES="$(ls $SRC_PATH/*.cpp | tr '\n' ' ')"

# Print starting message
echo -e "Started build...\n"

# Run the clang command with the src files, outputting to the bin directory
clang++ $SRC_FILES -o $BIN_PATH -I/usr/local/include -L/usr/local/lib -lSDL3 -Wl,-rpath=/usr/local/lib
SUCCESS=$?

## --- RUN --- ##
# Check that clang compiled successfully
if [ $SUCCESS == '0' ]; then
    echo "----- BUILD SUCCESS -----"
    echo -e "Running application...\n"
    clear
    # Success!, run the newly built file
    exec "$BIN_PATH"
else
    echo "----- BUILD FAILURE -----"
    # Build failed. Ask the user if they want to run the last build anyway
    yes_or_no "Do you want to run last build anyway?" && (echo -e "\n"; exec "$BIN_PATH")
fi
