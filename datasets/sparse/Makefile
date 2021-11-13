all: wiki-Vote.mtx soc-Pokec.mtx hollywood-2009.mtx ljournal-2008.mtx roadNet-CA.mtx road_central.mtx road_usa.mtx offshore.mtx #wiki-Vote.gr soc-Pokec.gr hollywood-2009.gr ljournal-2008.gr roadNet-CA.gr road_central.gr road_usa.gr offshore.gr
	
%.mtx: | %.tar.gz
	tar -xf $<
	cp $*/$*.mtx ./

%.gr: %.mtx
	./graph-convert --mtx2gr --edgeType=uint64 $*.mtx $*.gr

wiki-Vote.tar.gz:
	wget https://suitesparse-collection-website.herokuapp.com/MM/SNAP/wiki-Vote.tar.gz

soc-Pokec.tar.gz:
	wget https://suitesparse-collection-website.herokuapp.com/MM/SNAP/soc-Pokec.tar.gz

hollywood-2009.tar.gz:
	wget https://suitesparse-collection-website.herokuapp.com/MM/LAW/hollywood-2009.tar.gz
	
ljournal-2008.tar.gz:
	wget https://suitesparse-collection-website.herokuapp.com/MM/LAW/ljournal-2008.tar.gz
	
roadNet-CA.tar.gz:
	wget https://suitesparse-collection-website.herokuapp.com/MM/SNAP/roadNet-CA.tar.gz

road_central.tar.gz:
	wget https://suitesparse-collection-website.herokuapp.com/MM/DIMACS10/road_central.tar.gz

road_usa.tar.gz:
	wget https://suitesparse-collection-website.herokuapp.com/MM/DIMACS10/road_usa.tar.gz

offshore.tar.gz:	
	wget https://suitesparse-collection-website.herokuapp.com/MM/Um/offshore.tar.gz
