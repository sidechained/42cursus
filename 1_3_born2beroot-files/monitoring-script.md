Run: sudo vim /usr/local/bin/monitoring.sh

#!/bin/bash

wall is a command-line utility that displays a message on the terminals of all logged-in users. The messages can be either typed on the terminal or the contents of a file.

##Architecture
$ uname -a
##Physical CPU
$ grep "physical id" /proc/cpuinfo | sort | uniq | wc -l
##Virtual CPU
$ grep "^processor" /proc/cpuinfo | wc -l
##Free RAM and usage %
$ free -m
(-m flag makes the output in MB as we want).
$ free -m | grep Mem | awk '{print $4}'
$ free -m | grep Mem | awk '{print $2}'
$ free -m | grep Mem | awk '{printf("%.2f"), $3/$2*100}'
##Free server space and usage %
df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{fdisk += $4} END {print fdisk}'
##
To get the total disk space lets do the same but change the variable name to tdisk, the -m for -Bg and the column $4 to $2 so df -Bg | grep '^/dev/' | grep -v '/boot$' | awk '{tdisk += $2} END {print tdisk}'

For the usage percent of the server is putting together what we did in the RAM but with the disk commands we did earlier, so df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{fdisk += $3} {tdisk += $2} END {printf("%.2f"), fdisk/tdisk*100}'

##CPU usage %
$ top -bn1 | grep '^%Cpu' | awk '{printf("%.1f%%"), $2}'
##Last reboot
$ who -b | awk '{print $3 " " $4}'
##LVM active
$ lsblk | grep 'lvm' | awk '{if ($1) {printf "\033[0;32mYes\033[0m";exit} else {print "\033[0;031mNo\033[0m";exit;}}'
##Number of connections
$ ss -t | grep ESTAB | wc -l
##Number of users
$ who | cut -d " " -f 1 | sort -u | wc -l
##IPv4 Adress & MAC (Media Access Control)
$ ip link show | grep ether | awk '{print $2}'
##Numbers of sudo commands
$ sudo apt install net-tools
(for journalct;)
$ journalctl _COMM=sudo | grep COMMAND | wc -l


