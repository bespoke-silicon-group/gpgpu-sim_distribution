.PHONY: BLK sparse_data aes_data

sparse_data:
	cd sparse; $(MAKE)
	
AES_SIZE ?= 1048576

aes_data: aes_input_${AES_SIZE}.in aes_key.in

aes_key.in:
	echo "" > aes_key.in
	for i in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16; do \
		val=$$(openssl rand -hex 1);\
		echo $$val >> aes_key.in;\
	done
 
aes_input_${AES_SIZE}.in:
	dd if=/dev/urandom of=./aes_input_${AES_SIZE}.in count=${AES_SIZE} bs=1

BLK:
	cd BLK; $(MAKE)
