CUDA_PATH=/usr/local/cuda-11/
DATASET=../datasets
SPARSE=${DATASET}/sparse
BIN=../precompiled_bin
SCRIPTS=./scripts
RESULTS=./results
SHELL := /bin/bash
TS := $(shell /bin/date "+%Y-%m-%d_%H-%M-%S")

.PHONY: sparse_data SpGEMM BFS clean_folder

SpGEMM_INPUTS = wiki-Vote offshore roadNet-CA road_central road_usa #soc-Pokec hollywood-2009 ljournal-2008
SpGEMM: sparse_data ${BIN}/spgemm clean_folder
	export CUDA_INSTALL_PATH=${CUDA_PATH}; \
	cd ..; \
	source setup_environment; \
	$(MAKE) --silent; \
	cd hb-config; \
	mkdir -p ${RESULTS}/SpGEMM; \
	for i in ${SpGEMM_INPUTS}; do \
		${SCRIPTS}/run_SpGEMM.sh ${BIN}/spgemm ${SPARSE}/$$i.mtx > ${RESULTS}/SpGEMM/$$i_${TS}.out & \
	done
	
#	for i in $$(ls ${SPARSE}/*.mtx); do \
#		filename=$$(basename -a -s .mtx $$i); \
#		${SCRIPTS}/run_SpGEMM.sh ${BIN}/spgemm $$i > ${RESULTS}/SpGEMM/$$filename.out & \
#	done
	wait

SGEMM_SIZE ?= 2048
SGEMM:
	export CUDA_INSTALL_PATH=${CUDA_PATH}; \
	cd ..; \
	source setup_environment; \
	$(MAKE) --silent; \
	cd hb-config; \
	mkdir -p ${RESULTS}/SGEMM; \
	${BIN}/sgemm ${SGEMM_SIZE} > ${RESULTS}/SGEMM/SGEMM_${SGEMM_SIZE}_${TS}.out

BFS: sparse_data clean_folder
	export CUDA_INSTALL_PATH=${CUDA_PATH}; \
	cd ..; \
	source setup_environment; \
	$(MAKE) --silent; \
	cd hb-config; \
	mkdir -p ${RESULTS}/bfs; \
	${SCRIPTS}/run_bfs.sh ${BIN} ${SPARSE}/wiki-Vote.mtx 4668; #\
	#${SCRIPTS}/run_bfs.sh ${BIN} ${SPARSE}/soc-Pokec.mtx  816408 >> ${RESULTS}/bfs.out; \
	#${SCRIPTS}/run_bfs.sh ${BIN} ${SPARSE}/hollywood-2009.mtx 570170 >> ${RESULTS}/bfs.out; \
	#${SCRIPTS}/run_bfs.sh ${BIN} ${SPARSE}/ljournal-2008.mtx 2681669 >> ${RESULTS}/bfs.out; \
	#${SCRIPTS}/run_bfs.sh ${BIN} ${SPARSE}/roadNet-CA.mtx 985640 >> ${RESULTS}/bfs.out; \
	#${SCRIPTS}/run_bfs.sh ${BIN} ${SPARSE}/road_central.mtx 7040908 >> ${RESULTS}/bfs.out; \
	#${SCRIPTS}/run_bfs.sh ${BIN} ${SPARSE}/road_usa.mtx 11973673 >> ${RESULTS}/bfs.out;

SSSP: sparse_data clean_folder
	${BIN}/sssp --graph-type market --src 4668 --graph-file ${SPARSE}/wiki-Vote.gr
	${BIN}/sssp --graph-type market --src 816408 --graph-file ${SPARSE}/soc-Pokec.gr
	${BIN}/sssp --graph-type market --src 570170 --graph-file ${SPARSE}/hollywood-2009.gr
	${BIN}/sssp --graph-type market --src 2681669 --graph-file ${SPARSE}/ljournal-2008.gr
	${BIN}/sssp --graph-type market --src 985640 --graph-file ${SPARSE}/roadNet-CA.gr
	${BIN}/sssp --graph-type market --src 7040908 --graph-file ${SPARSE}/road_central.gr
	${BIN}/sssp --graph-type market --src 11973673 --graph-file ${SPARSE}/road_usa.gr

PR: sparse_data clean_folder 
	${BIN}/pr --graph-type market --pull=true --graph-file ${SPARSE}/wiki-Vote.mtx
	${BIN}/pr --graph-type market --pull=true --graph-file ${SPARSE}/soc-Pokec.mtx
	${BIN}/pr --graph-type market --pull=true --graph-file ${SPARSE}/hollywood-2009.mtx
	${BIN}/pr --graph-type market --pull=true --graph-file ${SPARSE}/ljournal-2008.mtx
	${BIN}/pr --graph-type market --pull=true --graph-file ${SPARSE}/roadNet-CA.mtx
	${BIN}/pr --graph-type market --pull=true --graph-file ${SPARSE}/road_central.mtx
	${BIN}/pr --graph-type market --pull=true --graph-file ${SPARSE}/road_usa.mtx
	
FFT: clean_folder
	${BIN}/fft 32768 1
	${BIN}/fft 65536 1
	${BIN}/fft 524288 1
	${BIN}/fft 1048576 1
	${BIN}/fft 32768 0
	${BIN}/fft 65536 0
	${BIN}/fft 524288 0
	${BIN}/fft 1048576 0

# 1 MB
AES_SIZE ?= 524288#1048576
AES: clean_folder
	cd ${DATASET}; $(MAKE) aes_data AES_SIZE=${AES_SIZE};
	
	export CUDA_INSTALL_PATH=${CUDA_PATH}; \
	cd ..; \
	source setup_environment; \
	$(MAKE) --silent; \
	cd hb-config; \
	mkdir -p ${RESULTS}/AES; \
	${BIN}/aes e 128 ${DATASET}/aes_input_${AES_SIZE}.in ${DATASET}/aes_key.in > ${RESULTS}/AES/aes_${AES_SIZE}_${TS}.out

JACOBI_ITER ?= 1
Jacobi: clean_folder
	export CUDA_INSTALL_PATH=${CUDA_PATH}; \
	cd ..; \
	source setup_environment; \
	$(MAKE) --silent; \
	cd hb-config; \
	${BIN}/stencil 512 512 64 ${JACOBI_ITER} -i ${DATASET}/stencil/default/input/512x512x64x100.bin > ${RESULTS}/jacobi_512x512x64_${JACOBI_ITER}_iter_${TS}.out

BLK_INPUTS = in_4.txt in_16.txt in_4K.txt in_16K.txt in_64K.txt in_10M.txt
BS: clean_folder
	cd ${DATASET}; $(MAKE) BLK
	export CUDA_INSTALL_PATH=${CUDA_PATH}; \
	cd ..; \
	source setup_environment; \
	$(MAKE) --silent; \
	cd hb-config; \
	mkdir -p ${RESULTS}/BS; \
	touch ${RESULTS}/BS.out; \
	for i in ${BLK_INPUTS}; do \
		echo BLK/$$i; \
		${BIN}/bs ${DATASET}/BLK/$$i > ${RESULTS}/BS/$$i_${TS}; \
	done
	
SW: clean_folder
	export CUDA_INSTALL_PATH=${CUDA_PATH}; \
	cd ..; \
	source setup_environment; \
	$(MAKE) --silent; \
	cd hb-config; \
	mkdir -p ${RESULTS}/SW; \
	${BIN}/sw dna ${DATASET}/dna-reference.fasta ${DATASET}/dna-query.fasta output > ${RESULTS}/SW/sw_${TS}.out

${CUDA_PATH}/include/cusp: cusp/
	sudo cp -r ./cusp ${CUDA_PATH}/include/
	
sparse_data: 
	cd ${DATASET}; make sparse_data

clean_folder:
	rm -f _app_cuda*
	rm -f _cuobjdump*

/usr/local/cuda:
	wget https://developer.download.nvidia.com/compute/cuda/repos/ubuntu2004/x86_64/cuda-ubuntu2004.pin
	sudo mv cuda-ubuntu2004.pin /etc/apt/preferences.d/cuda-repository-pin-600
	wget https://developer.download.nvidia.com/compute/cuda/11.5.0/local_installers/cuda-repo-ubuntu2004-11-5-local_11.5.0-495.29.05-1_amd64.deb
	sudo dpkg -i cuda-repo-ubuntu2004-11-5-local_11.5.0-495.29.05-1_amd64.deb
	sudo apt-key add /var/cuda-repo-ubuntu2004-11-5-local/7fa2af80.pub
	sudo apt-get update
	sudo apt-get -y install cuda
