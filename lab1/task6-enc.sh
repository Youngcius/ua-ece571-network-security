openssl enc -aes-128-cbc -e -in plain.txt -out cipher_iv_1-1.bin -K 00112233445566778889aabbccddeeff -iv 123456
openssl enc -aes-128-cbc -e -in plain.txt -out cipher_iv_1-2.bin -K 00112233445566778889aabbccddeeff -iv 123456
openssl enc -aes-128-cbc -e -in plain.txt -out cipher_iv_2.bin -K 00112233445566778889aabbccddeeff -iv 654321
