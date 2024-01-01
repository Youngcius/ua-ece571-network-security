openssl enc -cast-cbc -in pic_original.bmp -out pic_encrypted.bmp -K 00112233445566778889aabbccddeeff -iv 0102030405060708
head -c 54 pic_original.bmp > header
head -c +55 pic_encrypted.bmp > body
cat header body > pic_new.bmp

