#!/bin/sh
echo "COMPILING PROGRAM...\n"
sudo make cc
sudo make 
echo "COMPILATION COMPLETE.\n\nRUNNING PROGRAM..."
sudo sh -c './generated_main input_data/sim_options.json > output.txt 2>&1'
echo "PROGRAM COMPLETE."
