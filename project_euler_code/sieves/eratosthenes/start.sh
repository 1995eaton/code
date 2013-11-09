#!/bin/bash

echo -e "1. 1-million\n2. 10-million\n3. 100-million\n4. 1-billion"
read amount

if (("$amount" == '1')); then
	amount=1000000
elif (("$amount" == '2')); then
	amount=10000000
elif (("$amount" == '3')); then
	amount=100000000
elif (("$amount" == '4')); then
	amount=1000000000
else
	echo "Invalid selection\n"
fi

./eratosthenes $amount primelist.txt
tail --lines=1 ./primelist.txt
#cat ./primelist.txt
#rm ./primelist.txt
