####################################
# Taks 1
echo "This is a prefix text file demo, its length is 56 bytes" > prefix-56.txt
echo "This is a prefix text demo file, its length is exactly 64 bytes" > prefix-64.txt

md5collgen -p prefix-56.txt -o out1.bin out2.bin # MD5 collision generation 
md5collgen -p prefix-64.txt -o out1-64.bin out2-64.bin

xxd out1.bin out1.txt # binary file --> text file
xxd out2.bin out2.txt
xxd out1-64.bin out1-64.txt
xxd out2-64.bin out2-64.txt

echo "Taks 1 difference comparision -- with 56-byte prefix file"
diff out1.txt out2.txt
echo "Taks 1 difference comparision -- with 64-byte prefix file"
diff out1-64.txt out2-64.txt

####################################
# Task 2
# MD5 values of out1.bin and out2.bin generated in Task 1 are the same, which can be verified by "md5sum" command
echo "a suffix text file" > suffix.txt
cat out1.bin suffix.txt > modified1
cat out2.bin suffix.txt > modified2
echo "observing MD5 value of files with the same initial MD5 values after appended with the same suffix file"
md5sum modified1
md5sum modified2


####################################
# Task 3
gcc -o xyz_arr xyz_arr.c
# .... find the splitting offset of "xyz_arr"
head -c 12352 xyz_arr > prefix-xyz
tail -c +12480 xyz_arr > suffix-xyz
md5collgen -p prefix-xyz -o file1 file2
cat file1 suffix-xyz > exe1
cat file2 suffix-xyz > exe2
chmod +x exe1
chmod +x exe2
./exe1 # different output of "./exe2"
./exe2
md5sum exe1 # same value with "exe2"
md5sum exe2



####################################
# Task 4
# gcc -o beni_mali beni_mali.c

# head -c 12352 beni_mali > prefix-beni_mali
# tail -c +12480  beni_mali > suffix-beni_mali




