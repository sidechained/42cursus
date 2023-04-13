# TODO LIST
make some adjustments to broadcast message
- in Architecture, username should be displayed not hostname (really?)
- memory free should only mention MB once
- disk free first value should be in Gb, and Gb should only be mentioned once
- remove colours from LVM use

# GUIDES/TESTERS:
https://github.com/benmaia/42_Born2beRoot
https://github.com/Pixailz/Born2BeRootTester

# QUESTIONS/KNOWLEDGE:

Q: TODO do we need to port forward port 8080 to port 80 in VM? If so how?
Q: log file not found (made one, and made folders - does this fix it?)
Q: how to fix RETBLEED warning
Q: how to fix 'volume group gbooth42-vg not found' warning
Q: what exactly is root https://www.computerhope.com/jargon/a/admin.htm

## LVM

LVM stands for Logical Volume Management. It is a system of managing logical volumes, or filesystems, that is much more advanced and flexible than the traditional method of partitioning a disk into one or more segments and formatting that partition with a filesystem. 

most operations can be done on the fly, while the system is running. Most operations that you can do with gparted require that the partitions you are trying to manipulate are not in use at the time

A Volume Group is a named collection of physical and logical volumes. Typical systems only need one Volume Group to contain all of the physical and logical volumes on the system, and I like to name mine after the name of the machine. Physical Volumes correspond to disks; they are block devices that provide the space to store logical volumes.

old way was using gparted

## GOINFRE/SGOINFRE s
It's just a special 42 folder that doesn't have the limits of our home account

## LOGICAL VS PRIMARY PARTITIONS
Logical partitions are similar to primary partitions. However, while only four primary partitions can exist on a single disk, the number of logical partitions that can exist on a disk is unlimited. A logical partition can be formatted and assigned a drive letter.

## DIFFERENCE BETWEEN APT UPDATE AND APT UPGRADE
The update command only gets the information about the latest version of packages available for your system. It doesn’t download or install any package. It is the apt upgrade command that actually downloads and upgrades the package to the new version.

## DIFFERENCE BETWEEN APT AND APTITUDE
https://www.fosslinux.com/43884/apt-vs-aptitude.htm

APT (Advanced Packaging Tool) is a lower-level command-line only package manager, and Aptitude is a high-level package manager. This means that APT can be used in other higher-level package managers. Aptitude, has front-end and offers better functionality compared to apt-get. Aptitude comes with an interactive UI in addition to that of the text-only. Aptitude has more features and hence can be termed as a better package management tool compared to that of apt-get.

## WHAT IS SELINUX?
Security-Enhanced Linux (SELinux) is a security architecture for Linux® systems that allows administrators to have more control over who can access the system.
SELinux defines access controls for the applications, processes, and files on a system. It uses security policies, which are a set of rules that tell SELinux what can or can’t be accessed, to enforce the access allowed by a policy.

## WHAT IS APPARMOUR?
AppArmor is a Mandatory Access Control (MAC) system which is a kernel (LSM) enhancement to confine programs to a limited set of resources. AppArmor's security model is to bind access control attributes to programs rather than to users. AppArmor confinement is provided via profiles loaded into the kernel, typically on boot.

## WHAT IS BRIDGED APAPTER AND WHY MUST WE USE IT?
https://linuxhint.com/use-virtualbox-bridged-adapter/
https://www.howtogeek.com/122641/how-to-forward-ports-to-a-virtual-machine-and-use-it-as-a-server/

You can either use NAT and forward ports or used Bridged Adapter

### NAT
Note: While you don’t have to enter any IP details, leaving the Host IP box blank will make VirtualBox listen on 0.0.0.0—in other words, it will accept all traffic from the local network and forward it to your virtual machine. Enter 127.0.0.1 in the Host IP box and VirtualBox will only accept traffic originating on your computer—in other words, on the host operating system.

### BRIDGED
In the Bridged networking mode of VirtualBox, a device driver called ‘net filter’ is used on the Host machine. This driver filters the data from the physical adapter of the Host. By using this driver, VirtualBox takes data from the physical network and also inserts it into it. This also creates a new network interface in software. When we attach this software interface to a virtual machine, it appears to the Host machine as if the virtual machine is physically connected to the interface via a cable. Data can be sent from the Host to the virtual machine using this interface. In this way, a route or a bridged network has been set up between the virtual machine and the network to which the Host machine is connected.

All the machines connected to your LAN can communicate with your virtual machine as if it is another machine on the Lan. This VM can access all services on the network in the same way as any other machine on the Lan.

## WHAT IS PHP?
PHP (recursive acronym for PHP: Hypertext Preprocessor) is a widely-used open source general-purpose scripting language that is especially suited for web development and can be embedded into HTML. 

Instead of lots of commands to output HTML (as seen in C or Perl), PHP pages contain HTML with embedded code that does "something" (in this case, output "Hi, I'm a PHP script!"). The PHP code is enclosed in special start and end processing instructions <?php and ?> that allow you to jump into and out of "PHP mode." 

## WHAT IS LIGHTPD?
lighttpd (pronounced "lighty")[2] is an open-source web server optimized for speed-critical environments while remaining standards-compliant, secure and flexible.[citation needed] It was originally written by Jan Kneschke as a proof-of-concept of the c10k problem – how to handle 10,000 connections in parallel on one server,[3] but has gained worldwide popularity.[4] Its name is a portmanteau of "light" and "httpd". 

## WHAT IS MARIADB?
MariaDB is a community-developed, commercially supported fork of the MySQL relational database management system (RDBMS), intended to remain free and open-source software under the GNU General Public License

# THE BASICS: 
- use VirtualBox to create a Virtual Machine running Debian as it's OS
- submit signature.txt file at root (signature of your machine’s virtual disk)

## REQUIREMENTS:
- create at least 2 encrypted partitions using LVM
- SSH service on port 4242 only (not connectable as root)
- use of SSH will be tested during the defense by setting up a new account
- firewall must be active when launching virtual machine
- hostname must be 'gbooth42'
- install and config sudo following strict rules
- users: root, gbooth (belongs to 'user42' and 'sudo' groups)

# DEBIAN IMAGE:
Get debian image from here:
https://www.debian.org/download
This is Debian 11, codenamed bullseye, netinst, for 64-bit PC (amd64) debian-11.6.0-amd64-netinst.iso.

# VIRTUALBOX SETUP:
Open Oracle VirtualBox:
- install path is: /nfs/homes/gbooth/VirtualBox VMs
- hard disk file type is: VDI
- storage is dynamically allocated
- file location should be /sgoinfre/gbooth/Born2beRoot/
- in Settings -> Storage -> Controller -> Empty, click magifying glass, "Choose a disk file", navigate to debian image

# INSTALLING DEBIAN:
- click Install
- Language (defaults) English - English, United States, American English
hostname 'gbooth42', domain name blank, username 'gbooth'
time zone: central
Partitioning method: Guided - use entire disk and set up encrypted LVM
SCSI3(0,0,0)
Paritioning scheme: Separate /home partition
Write changes to disks and configure LVM?: Yes
Passphrase
Amount of volume group to use for guided partitioning?: max
Finish partitioning and write changes to disk
Write changes to disks?: Yes
Scan extra installation media?: No
Scan extra installation media?: No
Debian archive mirror country: United States
Debian archive mirror: deb.debian.org
HTTP proxy: leave blank
Participate in usage survey: No
Choose software to install: Debian Desktop Environment
Install GRUB boot loader to master boot record?: Yes
Device for bootloader installation: /dev/sda (or whatever is suggested)
Installation complete

# PARTITIONING:
- above specifies 12GB, but I should use 8GB (or 30.8GB for bonuses)
- bonus guide: https://github.com/mcombeau/Born2beroot/blob/main/guide/bonus_debian.md

# CONFIGURATION:
- when initiallly booting debian, we are asked for encryption pass
- then we are logged in as normal user 'gbooth'

## CHECK PARTITIONING
$ lsblk
$ cat /etc/os-release
## LOGIN AS SUPERUSER
- to do some basic setup we need to log in as superuser using 'su'
$ apt update
$ apt upgrade
## INSTALL SUDO
$ apt install sudo
## ADD USER TO SUDO GROUP
$ sudo usermod -aG sudo gbooth
append sudo to the list of groups the user belongs to
## CHECK IF USER IS IN SUDO GROUP
$ getent group sudo
## LEAVE ROOT TO YOUR USER
$ su - gbooth
## ADD GROUP 'user42'
$ sudo groupadd user42
## ADD OUR USER TO THAT GROUP
$ sudo usermod -aG user42 gbooth
## INSTALL VIM
$ sudo apt install vim

# SSH:
## Install OpenSSH:
$ sudo apt install openssh-server
## Verify ssh service:
$ sudo systemctl status ssh
## Add port 4242 (uncomment the line!!!!!:
$ cd /etc/ssh
$ sudo vim sshd_config
(edit the #Port22 to Port 4242)
## Install, Activate and Check Activation Status of UFW Firewall:
$ sudo apt install ufw
$ sudo ufw enable
$ sudo ufw status
## Go to VirtualBox -> Choose the VM -> Select "Settings" -> Choose "Network"
Adapter should be set to NAT. In advanced settings, Port Forwarding, add new rule with protocol TCP to forward 4242 Host Port to 4242 Guest Port
## Reboot the machine:
$ sudo reboot
## Allow the port 4242 on the Firewall:
$ sudo ufw allow 4242/tcp
## Get the ip address:
ip a
## Now outside your VM, in your pc (42 Linux, in your own terminal) run:
$ ssh -p 4242 username@your_ip in my case
$ ssh -p 4242 gbooth@10.15.249.247

# STRONG PASSWORD POLICY (ALL ACCOUNTS i.e. root and user)
## Use pwquality.conf to enforce password complexity
$ sudo apt install libpam-pwquality
## Go to /etc and run
$ sudo vim login.defs
Search for:
PASS_MAX_DAYS  9999
PASS_MIN_DAYS   0
PASS_WARN_AGE   7
and change to
PASS_MAX_DAYS  30
(SATISFIES expires every 30 days)
PASS_MIN_DAYS   2
(SATISFIES 2 days must elapse before password can be changed)
PASS_WARN_AGE   7
(SATISFIES user must receive warning message 7 days before password expiry)
## Go to /etc/pam.d, run
$ sudo vim common-password
and find
password        requisite                       pam_pwquality.so retry=3
To set at least one upper-case letter in the pw add  ucredit=-1
To set at least one lower-case letter in the pw add  lcredit=-1
To set at least one digit in the pw add  dcredit=-1
(SATISFIES password must be min 10 chars with an UC letter, LC letter and a number)
To set the minimum length in the pw add  minlen=10
To set at max consecutive identical chars in the pw add  maxrepeat=3
(SATISFIES password must not contain more than 3 consecutive identical chars)
To check if the password contains the username in some form add  usercheck=0
(SATISFIES password must not include the name of the user 'gbooth')
To set a minimum number of chars that must be different from the old pw add  difok=7
(SATISFIES must have 7 chars that are not part of the former password)
(TODO: doesn't apply to root password)
To the root pw comply to this policy add  enforce_for_root
## Reboot your VM
$ sudo reboot

TODO Q: how to check?!?!

# STRONG CONFIG FOR SUDO GROUP
## Go to /etc/sudoers.d
$ sudo visudo
## Find the Defaults section and add:
To enable TTY
Defaults        requiretty
(TTY must be enabled)
To select the right folder for your log files
Defaults        logfile="/var/log/sudo/sudo.log"
To archive your log inputs and outputs
Defaults        log_input, log_output
(- input/output actions must be archived (in /var/log/sudo/)
To set your password retries (It usually comes 3 times as default, but still...)  Defaults        passwd_tries=3
(- authentication limited to three wrong password attempts)
Defaults        badpass_message="Your message"
(- display custom message if wrong password given)
Defaults        secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
(- paths must be restricted to:....)

TODO Q: how to check?!?

# CREATE monitoring.sh BASH SCRIPT:
display following info on all terminals every 10 minutes
(see wall)
The architecture of your operating system and its kernel version.
• The number of physical processors.
• The number of virtual processors.
• The current available RAM on your server and its utilization rate as a percentage.
• The current available memory on your server and its utilization rate as a percentage.
• The current utilization rate of your processors as a percentage.
• The date and time of the last reboot.
• Whether LVM is active or not.
• The number of active connections.
• The number of users using the server.
• The IPv4 address of your server and its MAC (Media Access Control) address.
• The number of commands executed with the sudo program

## REVERSE ENGINEERING THE COMMANDS AND MAKING SOME TWEAKS

```
arch=$(uname -a)
- uname prints the name, version and other details about the current machine and the operating system running on it. 

phyproc=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)
- count number of unique lines that match "physical_id"

virtproc=$(grep "^processor" /proc/cpuinfo | wc -l)
- count lines start with "processor"

ram_free=$(free -m | grep Mem | awk '{print $4}')
- take only the 4th column of the Mem line from 'free' (amount of memory free)

ram_total=$(free -m | grep Mem | awk '{print $2}')
- take only the 2nd column of the Mem line from 'free' (total amount of memory)

ram_usage_percent=$(free -m | grep Mem | awk '{printf("%.2f"), $3/$2*100}')
- divide free by used, * 100, print to 2 decimal places

free_disk=$(df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{fdisk += $4} END {print fdisk}')
- add up all the 'free' columns minus the boot volume

total_disk=$(df -Bg | grep '^/dev/' | grep -v '/boot$' | awk '{tdisk += $2} END {print tdisk}')
- add up all the 'available' columns minus the boot volume

disk_usage_percent=$(df -Bm | grep '^/dev/' | grep -v '/boot$' | awk '{fdisk += $3} {tdisk += $2} END {printf("%.2f"), fdisk/tdisk*100}')

proc_usage_percent=$(top -bn1 | grep '^%Cpu' | awk '{printf("%.1f%%"), $2}')
last_boot=$(who -b | awk '{print $3 " " $4}')

lvm_active=$(lsblk | grep 'lvm' | awk '{if ($1) {printf "Yes";exit} else {printf "No";exit;}}')

n_active_connect=$(ss -t | grep ESTAB | wc -l)

n_users_server=$(who | cut -d " " -f 1 | sort -u | wc -l)

ipv4=$(hostname -I)

mac=$(ip link show | grep ether | awk '{print $2}')

n_commands_sudo=$(journalctl _COMM=sudo | grep COMMAND | wc -l)
```


### WALL

```
wall "  #Architecture: $arch
        #CPU physical: $phyproc
        #vCPU: $virtproc
        #Memory Free: ${ram_free}MB/${ram_total}MB ($ram_usage_percent%)
        #Disk Free: ${free_disk}MB/${total_disk}GB ($disk_usage_percent%)
        #CPU load: $proc_usage_percent
        #Last boot: $last_boot
        #LVM use: $lvm_active
        #Connections TCP: $n_active_connect ESTABLISHED
        #User log: $n_users_server
        #Network: IP $ipv4 ($mac)
        #Sudo: $n_commands_sudo cmd"
```

## DESIRED OUTPUT:
Broadcast message from root@wil (tty1) (Sun Apr 25 15:45:00 2021):
-Architecture: Linux wil 4.19.0-16-amd64 #1 SMP Debian 4.19.181-1 (2021-03-19) x86_64 GNU/Linux
-CPU physical : 1
-vCPU : 1
-Memory Usage: 74/987MB (7.50%)
-Disk Usage: 1009/2Gb (39%)
-CPU load: 6.7%
-Last boot: 2021-04-25 14:45
-LVM use: yes
-Connections TCP : 1 ESTABLISHED
-User log: 1
-Network: IP 10.0.2.15 (08:00:27:51:9b:a5)
-Sudo : 42 cmd

## CREATE SCRIPT LOCALLY AND COPY USING SSH TO VM
$ scp -P 4242 /path/to/file username@a:/path/to/destination
$ scp -P 4242 monitoring.sh gbooth@10.15.249.247:/home/gbooth
## ON VM MOVE TO CORRECT PLACE
$ sudo mv /home/gbooth/monitoring.sh /usr/local/bin/
## SET PERMISSIONS TO RUN
chmod 777 monitoring.sh
## ADD RULE TO EXEC SCRIPT WITH SUDO PERMISSIONS WITHOUT SUDO PASSWORD
$ sudo visudo
in the "Allow members of group sudo to execute any command"
add bmiguel- ALL=(ALL) NOPASSWD: /usr/local/bin/monitoring.sh 
## SETUP CRON TO MAKE SCRIPT RUN EVERY 10 MINS
sudo crontab -e
- at the end of the file put */10 * * * * /usr/local/bin/monitoring.sh
- to make it running after reboot add
@reboot /usr/local/bin/monitoring.sh under the 10 min macro.
- I'm adding the sleep macro, because when you boot your machine the script will run but you ain't logged in so you won't even see it sleep 10 so the end code is 
@reboot sleep 10; sh /usr/local/bin/monitoring.sh

# INSTALL OWN SERVICE

$ sudo apt update
$ sudo apt install git
$ git clone https://github.com/slwulf/baba-is-you
$ sudo apt install npm
$ cd baba-is-you
$ npm install
$ sudo ufw allow 1234/tcp
$ npm start
http://localhost:1234
# 

# COMMANDS TO CHECK REQUIREMENTS:
## Checking OS that has been installed:
$ head -n 2 /etc/os-release
## App Armor status
$ sudo /usr/sbin/aa-status
- 3 profiles are in enforce mode - is this the expected result?!
$ ss -tunip
- TODO: doesn't show any output at all beyond header line (see PDF for expected output)
$ sudo /usr/sbin/ufw status
- show if firewall is up and which ports are being forwarded/let through
Wordpress Check
$ http://127.0.0.1:8080
Baba is You Check
$ http://localhost:1234



The hostname must be your_intra_login42, but the hostname must be changed during the Born2beroot evaluation. The following commands might help:

$ sudo hostnamectl set-hostname <new_hostname>
$ hostnamectl status