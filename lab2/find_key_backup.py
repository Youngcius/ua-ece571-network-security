import datetime
import random

def gene_key_from_time(time:int=None)->int:
    
    
    key = []
    for _ in range(16):
        key.append(random.randrange(0,256))
    key = [hex(k)[2:].zfill(2) for k in key]
    key = ''.join(key)
    key = int(key, 16)
    return key


        

plain = 0x255044462d312e350a25d0d4c5d80a34
cipher = 0xd06bf9d0dab8e8ef880660d2af65aa82
iv = 0x09080706050403020100A2B2C2D2E2F2
key = [0]*16

if __name__ == '__main__':
    time_end = datetime.datetime(2018,4,17,23,8,49) #2018-04-17 23:08:49
    time_start = time_end-datetime.timedelta(hours=2)# 2018-04-17 21:08:49

    time_start = time_start - datetime.timedelta(hours=3) # calibrate time zone
    time_end = time_end - datetime.timedelta(hours=3)
    

    print(hex(gene_key_from_time()))



    # ===================================
    time_bench =  datetime.datetime(2018,4,15,15)
    int_bench = 1523818800

    time_end = datetime.datetime(2018,4,17,23,8,49) #2018-04-17 23:08:49
    delta = time_end - time_bench
    diff = delta.seconds
    
    print('end:\t', int_bench + diff)
    print('sta:\t',int_bench + diff - 3600*2)




    
    #  start-time and end-time calculated based on the benchmark time, i.e., 2018-04-15 15:00:00 <--> 1523818800
    time_end = 1523848129
    time_start = 1523840929

    