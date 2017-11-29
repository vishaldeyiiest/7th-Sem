#!/bin/sh
./lex_parser code.txt output 
g++ -oparser parser.cpp
./parser output
