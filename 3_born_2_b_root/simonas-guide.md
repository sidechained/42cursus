DOWNLOAD DEBIAN
https://www.debian.org/
THEN GO TO YOUTUBE AND FOLLOW THIS
https://www.youtube.com/watch?v=OQEdjt38ZJA
MY FAV (ALSO FOR BONUS PART)
https://github.com/mcombeau/Born2beroot/blob/main/guide/bonus_debian.md
THIS ONE IS VERY DETAILED but some mistakes on cron and bonus
https://github.com/caroldaniel/42sp-cursus-born2beroot/blob/master/guides/Debian-en.md
THIS IS GOOD TOO
https://github.com/hanshazairi/42-born2beroot#installation
THIS IS ESSENTIAL FOR THE EVAL
https://github.com/PublioElio/School-42-Born2beroot#apparmor-application-armor
Some helpful commands
    sudo systemctl stop cron.service (stop cron without deleting script)
    php -v (this checks php status by telling u what version is installed)
    getent group groupname (this checks who is in a group)
    sudo adduser username (creates user)
    sudo adduser username group (adds to group)
    hostname (tells u the hostname)
    sudo nano /etc/security/pwquality.conf (shows one file with passwords configurations during eval)
    sudo nano /etc/login.defs (shows the other file with passwd configurations during eval)
    sudo -V (shows that sudo is active)
    sudo nano /var/log/sudo/sudo.log (shows the list of logs)
    lsb_release -a (shows the operating system)
    sudo systemctl status ssh.service (shows that ssh is active...for eval)
    groups username (shows what groups the user is in)
    sudo systemctl status fail2ban (IF you install fail2ban for bonus, it shows it is active in eval)
    $ sudo hostnamectl set-hostname <new_hostname> (creates new hostname no need to reboot)
    $ sudo nano /etc/hostname (modify hostname in the file active if you reboot first)
    $ lsblk (shows partitions)
    $ sudo nano /var/log/sudo/sudo.log (shows sudo files log)
    su username (su stands for switch user)
    sudo ufw allow 8080 (allows access to port 8080)
    sudo ufw status numbered
    sudo ufw delete 5 (deletes rule number 5)
    $ crontab -e (shows the cron command line)
    ip addr show        (shows your ip address)
    ip a                (same thing as above)
    # sudo nano /etc/ssh/sshd_config (check/modify sssh configuration)
    $ sudo fail2ban-client status sshd (command to check fail2ban status re sshd)
    $ sudo tail -f /var/log/fail2ban.log (command to check log of fail2ban)
    
VIDEO ON HOW TO CONFIGURE WORDPRESS WEBSITE (IF U WANNA MAKE IT PRETTY)
https://cdn.intra.42.fr/video/video/82/low_d_WordPress-1.mp4