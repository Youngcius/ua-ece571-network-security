## ECE 571: Lab3

> Date: 2022-03-14

See [description](Lab3-description.pdf) and [report](Lab3-report.pdf) for details.

### File description
- `run_tasks.sh`: Bash script integrating necessary commands for Task 1, Task 2 and Task 3 of this lab
- `prefix-56.txt`: 56-byte prefix text file 
- `prefix-64.txt`: 64-byte prefix text file 
- `out1.bin`, `out2.bin`: generated with "md5collgen" based on the prefix file `prefix-56.txt`
- `out1-64.bin`, `out2-64.bin`: generated with "md5collgen" based on the prefix file `prefix-64.txt`
- `xyz_arr.c`, `xyz_arr`: C language source file and generated executable file for Task 3
- `prefix-xyz`: prefix of `xyz_arr`, its length is multiple of 64 bytes
- `suffix-xyz`: suffix of `xyz_arr`, there is a 128-byte block between `prefix-xyz` and `suffix-xyz`

### Environment requirement
- gcc/g++
- Linux programs: md5collgen, md5sum

