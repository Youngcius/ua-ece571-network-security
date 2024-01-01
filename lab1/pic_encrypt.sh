openssl enc -aes-128-ecb -e -in pic_original.bmp -out pic_ecb.bmp -K 123456 -iv 123456
openssl enc -aes-128-cbc -e -in pic_original.bmp -out pic_cbc.bmp -K 123456 -iv 123456

head -c 54 pic_original.bmp > header
tail -c +55 pic_cbc.bmp > body_cbc
tail -c +55 pic_ecb.bmp > body_ecb
cat header body_cbc > pic_cbc_new.bmp
cat header body_ecb > pic_ecb_new.bmp


