#!/bin/bash

_extdir="/usr/lib/modules/extramodules-"$(uname -r | grep -Eo "^[0-9]{,}\.[0-9]{,}")"-ARCH"

if [[ ! -f "patches/linux-recent.patch" ]]; then
	read "Patches for compilation were not found. Continue anyway? (y/n) " cont
	if [[ $cont == 'n' ]]; then exit; fi
fi

if [[ ! $1 ]]; then
	echo "Please append the valid gzip file to the end of the command."
	exit
else
	if [[ -d 'a' || -d 'b' ]]; then
		read -p "About to remove previous source directories. Continue? (y/n) " owrite
		if [[ $owrite == 'y' ]]; then
			rm -r a b
		else exit
		fi
	fi
	mkdir a && cd a
	tar xzfv "../"$1
	cd .. && cp -r a b
fi

if [[ $cont != 'y' ]]; then
	patch -p0 < patches/linux-recent.patch
	if [[ $(ls -R | grep -E "\.rej") != '' ]]; then
		read -p "Patch was unsuccessful. Continue? (y/n) " cont2
		if [[ $cont2 != 'y' ]]; then
			exit
		fi
	fi
fi

cd a && make && cd ..
sudo install -D -m 644 a/wl.ko $_extdir"/wl.ko"
echo -e "blacklist b43\nblacklist ssb\nblacklist bcma\nblacklist brcmsmac\nblacklist brcmfmac" | sudo tee -a /etc/modprobe.d/broadcom-wl.conf
sudo modprobe wl
