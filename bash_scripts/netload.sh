#!/bin/bash

_wldev="$(iw dev | grep -Eo "face .*" | cut --bytes=6-)"

if [ ! -d "/etc/netctl" || ! `compgen -c | grep -E "^iw$"` ]; then
	echo "Are you sure you have netctl and/or iw installed?"
	exit
fi

_pfiles=`ls /etc/netctl | grep $_wldev)`
c=1
echo

for i in $(ls /etc/netctl | grep $_wldev); do
	echo $c $i
	_parray[c]=$i
	c="$(expr $c + 1)"
done

echo
read -p "Choose a network profile: " ans

if [[ $(echo $ans | grep -E "^[0-9]{,}$") -eq "" ]]; then
	exit
fi

if [[ $ans -lt c ]]; then
	sudo ip link set $_wldev down
	sudo netctl stop-all
	sudo netctl start ${_parray[$(echo $ans | bc)]}
fi
