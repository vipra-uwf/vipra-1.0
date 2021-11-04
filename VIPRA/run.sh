#!/bin/sh
Echo "Starting program compilation..."
make
make generated_main
Echo "Program compiled."
Echo "Running program..."
make run
Echo "Program complete."