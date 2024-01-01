# M="A top secret!"
msg=$(/home/rose/miniconda3/bin/python -c 'print("A top secret!".encode("utf-8").hex())')
# /home/rose/miniconda3/bin/python -c 'A top secret!'.encode('utf-8').hex()

echo $msg

C=

python -c 'import binascii; print(binascii.a2b_hex("4120746f702073656372657421").decode())'
