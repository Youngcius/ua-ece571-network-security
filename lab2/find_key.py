import os


if __name__ == '__main__':
    plain_file = 'plain.bin'
    keys_file = 'keys.txt'
    iv_str = '09080706050403020100A2B2C2D2E2F2' # 没有头部0X的十六进制表示
    cipher_str = 'd06b f9d0 dab8 e8ef 8806 60d2 af65 aa82'
    cipher_file = 'cipher.bin'
    cipher_file_txt = 'cipher.txt'
    gene_prog = './gene_keys'

    #  start-time and end-time calculated based on the benchmark time, i.e., 2018-04-15 15:00:00 <--> 1523818800


    # time_start = 1523999329
    # time_end = 1524006529

    time_start, time_end = 1524013729, 1524020929


    os.system('{} {} {} {}'.format(gene_prog,keys_file, time_start, time_end))
    with open(keys_file, 'r') as f:
        keys = f.readlines()

    keys = [key[:-1] for key in keys] # remove '\n'
    

    if os.path.exists(cipher_file):
        os.remove(cipher_file)

    for i, key in enumerate(keys):
        os.system('openssl enc -aes-128-cbc -in {} -K {} -iv {} >> {}'.format(plain_file, key, iv_str, cipher_file))
    os.system('xxd {} > {}'.format(cipher_file, cipher_file_txt))

    with open(cipher_file_txt, 'r') as f:
        ciphers = f.readlines()
    
    ciphers = list(map(''.join, zip(ciphers[::2], ciphers[1::2])))
    for i, c_line in enumerate(ciphers):
        if cipher_str in c_line:
            print('correct key: {}'.format(keys[i]))
    

    # exact cipher should be : d06b f9d0 dab8 e8ef 8806 60d2 af65 aa82
    # 1524017695 是Key对应的随机数种子; 95fa2030e73ed3f8da761b4eb805dfd7