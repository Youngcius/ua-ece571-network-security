#!/user/bin/python
from scapy.all import *
import argparse


def print_pkt(pkt):
    pkt.show()


parser = argparse.ArgumentParser(
    description='designate packet types you would like to sniff')
parser.add_argument('-icmp', action='store_true')

parser.add_argument('-tcp', action='store_true')
parser.add_argument('-ip', type=str, default='192.168.1.1',
                    help='IP address the captured packets should come from')
parser.add_argument('-port', type=int, default=23,
                    help='destination port number for the anticipated captured packets')

parser.add_argument('-sub', action='store_true')
parser.add_argument('-subnet', type=str, default='10.0.2.15/24',
                    help='subnet address captured packets should come from or go to')


args = parser.parse_args()

if args.icmp:
    print('sniffing all ICMP packets ...')
    pkt = sniff(filter='icmp', prn=print_pkt)
elif args.tcp:
    print('sniffing all TCP packets from IP address {} and port {}'.format(
        args.ip, args.port))
    pkt = sniff(filter='tcp src host {} && dst port {}'.format(
        args.ip, args.port), prn=print_pkt)
elif args.sub:
    print('sniffing all packets in the subnet {}'.format(args.subnet))
    pkt = sniff(filter='net {}'.format(args.subnet), prn=print_pkt)
else:
    print('sniffing all packets ... (default)')
    pkt = sniff(prn=print_pkt)
