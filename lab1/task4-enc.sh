# construct a file with 1000+ bytes (herein we use the plain.txt file)

# encryption commands
openssl enc -aes-128-cbc -e -in plain.txt -out cipher_cbc.bin -K 123456 -iv 123456
openssl enc -aes-128-ecb -e -in plain.txt -out cipher_ecb.bin -K 123456 -iv 123456
openssl enc -aes-128-cfb -e -in plain.txt -out cipher_cfb.bin -K 123456 -iv 123456
openssl enc -aes-128-ofb -e -in plain.txt -out cipher_ofb.bin -K 123456 -iv 123456


# ...... modifying the 55th byte content of ciphers using visulization editor


# decryption commands
openssl enc -aes-128-cbc -d -in cipher_cbc.bin -out dec_cbc.txt -K 123456 -iv 123456
openssl enc -aes-128-ecb -d -in cipher_ecb.bin -out dec_ecb.txt -K 123456 -iv 123456
openssl enc -aes-128-cfb -d -in cipher_cfb.bin -out dec_cfb.txt -K 123456 -iv 123456
openssl enc -aes-128-ofb -d -in cipher_ofb.bin -out dec_ofb.txt -K 123456 -iv 123456



