#!/usr/bin/env bash

#Your script must always be able to display the following information:
#• The architecture of your operating system and its kernel version.
#• The number of physical processors.
#• The number of virtual processors.
#• The current available RAM on your server and its utilization rate as a percentage.
#• The current available storage on your server and its utilization rate as a percentage.
#• The current utilization rate of your processors as a percentage.
#• The date and time of the last reboot.
#• Whether LVM is active or not.
#• The number of active connections.
#• The number of users using the server.
#• The IPv4 address of your server and its MAC (Media Access Control) address.
#• The number of commands executed with the sudo program.

sys_info () {
INFO=$(uname -a)
echo "#Architecture: ${INFO}"
CPUs=$(grep "physical id" /proc/cpuinfo | sort -u | wc -l)
echo "#CPU physical: ${CPUs}"
VCPUs=$(nproc)
echo "#vCPU: ${VCPUs}"
RAM_TOTAL=$(free -m | awk '/^Mem:/ {print $2}')
RAM_USED=$(free -m | awk '/^Mem:/ {print $3}')
PERCENTAGE=$(awk "BEGIN {printf \"%.2f\", ($RAM_USED/$RAM_TOTAL)*100}")
echo "#Memory Usage: ${RAM_USED}/${RAM_TOTAL}MB (${PERCENTAGE}%)"
STORAGE_TOTAL=$(df -BM --output=size / | tail -n1 | tr -dc '0-9')
STORAGE_USED=$(df -BM --output=used / | tail -n1 | tr -dc '0-9')
PERCENTAGE=$((STORAGE_USED * 100 / STORAGE_TOTAL ))
echo "#Disk Usage: ${STORAGE_USED}Mb/${STORAGE_TOTAL}Gb (${PERCENTAGE}%)"
CPU_LOAD=$(top -bn1 | grep '^%Cpu' | awk '{print ""100-$8"%"}')
echo "#CPU load: ${CPU_LOAD}"
LAST_BOOT=$(who -b | awk '{print $3, $4}')
echo "#Last boot: ${LAST_BOOT}"

if ls /dev/mapper/*vg* 1>/dev/null 2>&1; then
    echo "#LVM use: yes "
else
    echo "#LVM use: no "
fi

CONNECTIONS=$(ss -tan state ESTABLISHED | tail -n +2 | wc -l)
echo "#Connections TCP: ${CONNECTIONS} ESTABLISHED"
USERS_LOGGED=$(who | sort -u | wc -l)
echo "#User log: ${USERS_LOGGED}"
MAC=$(ip a | awk '/ether/ {print $2}')
IP=$(ip -4 addr show scope global | awk '/inet/ {print $2}'| cut -d'/' -f1)
echo "#Network: IP ${IP} (${MAC})"
SUDO_CNT=$(grep sudo $HOME/.bash_history | wc -l)
echo "#Sudo : ${SUDO_CNT} cmd"
}

sys_info
