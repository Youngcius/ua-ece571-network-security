g++ -o gene_keys gene_keys.cpp
python find_key.py
# xxd cipher.bin | grep "d06b f9d0 dab8 e8ef 8806 60d2 af65 aa82"

# dependent file: find_python.py, gene_keys.cpp, plain.bin
# output file: cipher.bin, keys.txt


# if no output on terminal, no correct key was searched in the time window