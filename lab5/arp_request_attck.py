sendp(Ether(dst='ff:ff:ff:ff:ff:ff') / ARP(hwsrc = '00:0c:29:72:b2:b5', psrc = '192.168.2.1', hwdst = 'ff:ff:ff:ff:ff:ff', pdst = '192.168.2.11') / 'abc', iface='ens33')

from scapy.all import *


E = Ether()
A = ARP()
pkt = E/A
sendp(pkt)



Ether