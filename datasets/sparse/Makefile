all: wiki-Vote.mtx soc-Pokec.mtx hollywood-2009.mtx road_usa.parboil.gr wiki-Vote.parboil.gr soc-Pokec.parboil.gr hollywood-2009.parboil.gr ljournal-2008.mtx roadNet-CA.mtx road_central.mtx road_usa.mtx offshore.mtx ljournal-2008.parboil.gr roadNet-CA.parboil.gr road_central.parboil.gr road_usa.parboil.gr offshore.parboil.gr
	
%.mtx: %.tar.gz
	tar -xf $<
	cp $*/$*.mtx ./

convert_to_parboil.exe: mtx_to_parboil.cpp
	g++ -std=c++11 $^ -o $@

wiki-Vote.parboil.gr: wiki-Vote.mtx convert_to_parboil.exe
	./convert_to_parboil.exe wiki-Vote.mtx 4668

soc-Pokec.parboil.gr: soc-Pokec.mtx convert_to_parboil.exe
	./convert_to_parboil.exe soc-Pokec.mtx 816408

hollywood-2009.parboil.gr: hollywood-2009.mtx convert_to_parboil.exe
	./convert_to_parboil.exe hollywood-2009.mtx 570170

ljournal-2008.parboil.gr: ljournal-2008.mtx convert_to_parboil.exe
	./convert_to_parboil.exe ljournal-2008.mtx 2681669

roadNet-CA.parboil.gr: roadNet-CA.mtx convert_to_parboil.exe
	./convert_to_parboil.exe roadNet-CA.mtx 985640

road_central.parboil.gr: road_central.mtx convert_to_parboil.exe
	./convert_to_parboil.exe road_central.mtx 7040908

road_usa.parboil.gr: road_usa.mtx convert_to_parboil.exe
	./convert_to_parboil.exe road_usa.mtx 11973673

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
