## ECE 571: Lab2

> Date: 2022-02-24<br>


See [description](Lab2-description.pdf) and [report](Lab2-report.pdf) for details.

### File description
- `find_key.sh`: high-level script for Task 2; dependent on `find_key.py`, `gene_keys.cpp`, `plain.bin`, etc.
- `plain.bin`: 16-base file whose content is the known plaintext `255044462d312e350a25d0d4c5d80a34` for Task 2
- `random.c`: modified program for Task1
- `urandom.c`: also a random number generation program, based on `/dev/urandom`, for Task 5

### Environment requirement
- gcc/g++, Python
- Linux programs: openssl, xxd
