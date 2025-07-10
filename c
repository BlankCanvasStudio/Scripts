#!/bin/bash
FILENAME=$1
FILETYPE="${FILENAME#*.}"
COMPILED=FALSE

# Compile and run c++ files
if [ "$FILETYPE" = "cpp" ]
then
    COMPILED=TRUE
    g++ "$FILENAME"
    ./a.out
    rm a.out
fi

if [ "$FILETYPE" = "c" ]
then
    COMPILED=TRUE
    gcc "$FILENAME"
    ./a.out
    rm a.out
fi

if [ "$FILETYPE" = "sv" ]
then
   COMPILED=TRUE
   verilator $1
fi
# Run python files. Assuming python 3. No beta shit here
if [ "$FILETYPE" = "py" ]
then 
    COMPILED=TRUE
    python3 "$FILENAME" "${@:2}"
fi

if [ COMPILED == FALSE ]
then
   echo "That file type cannot be compiled"
fi
