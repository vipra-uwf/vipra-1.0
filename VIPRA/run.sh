#!/bin/sh
echo "COMPILING PROGRAM...\n"
sudo make cc
sudo make
echo "COMPILATION COMPLETE.\n\nRUNNING PROGRAM..."
./generated_main
echo "PROGRAM COMPLETE."
