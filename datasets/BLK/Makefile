INPUTS = in_4.txt in_16.txt in_4K.txt in_16K.txt in_64K.txt in_10M.txt

all: ${INPUTS}

in_%.txt: | parsec-3.0
	cp parsec-3.0/pkgs/apps/blackscholes/inputs/* ./
	for i in $$(ls in*); do \
		tar -xvf $$i; \
	done	

parsec-3.0: parsec-3.0.tar.gz
	tar -xf parsec-3.0.tar.gz

parsec-3.0.tar.gz: 
	wget http://parsec.cs.princeton.edu/download/3.0/parsec-3.0.tar.gz
