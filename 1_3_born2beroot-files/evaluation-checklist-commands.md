TODO:
- review AppArmour
$ sudo /usr/sbin/aa-status
what is?
- usercheck
- difok
- enforce_for_root


- review LMV

check UFW stated
$ sudo ufw status

check SSH started
$ sudo systemctl status ssh

check OS
$ cat /etc/os-release

check user has been added
- obvious from logging in

check user belongs to sudo and user42 groups
$ groups gbooth

add new user
$ sudo adduser testuser

remove user
$ sudo deluser --remove-home testuser

password files located here
$ sudo vim /etc/login.defs
$ sudo vim /etc/pam.d/common-password

create new group
$ sudo groupadd evaluating
add user to group
$ sudo usermod -aG evaluating testuser
check user was added
$ groups testuser
remove group
$ sudo groupdel evaluating

modify hostname
$ sudo hostnamectl set-hostname boothg4242
$ sudo nano /etc/hosts

view partitions
$ lsblk

Assign user to sudo group
$ sudo usermod -aG sudo testuser

Check sudo logs
$ sudo vim /var/log/sudo/sudo.log

Delete ufw rule
$ sudo ufw allow 8080/tcp
$ sudo ufw status numbered
$ sudo ufw delete 3

Check SSH installed
$ sudo systemctl status ssh
$ exit
$ ssh -p 4242 testuser@10.15.248.248
(or another IP)

Tested ssh-ing as root, permission denied
$ ssh -p 4242 root@10.15.248.248

To do this, you can use a
key or a simple password. It will depend on the student being evaluated. Of course, you have to make sure that you cannot
use SSH with the "root" user as stated in the subject.

Check the script
$ sudo crontab -e
Change to 1 minute intervals

Finally, the student being evaluated should make the script stop running when the server has started up, but without modifying the script itself. To check this point,
you will have to restart the server one last time. At startup, it will be necessary to check that the script still exists in the same place, that its rights have remained unchanged, and that it has not been modified.