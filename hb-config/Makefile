CUDA_PATH=/usr/local/cuda-11/
DATASET=../datasets
SPARSE=${DATASET}/sparse
BIN=../precompiled_bin
SCRIPTS=./scripts
RESULTS=./results
SHELL := /bin/bash
TS := $(shell /bin/date "+%Y-%m-%d_%H-%M-%S")
BENCHMARK_DIR := $(abspath ../../bsg-motif-gpu-benchmarks-src)

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
		${SCRIPTS}/run_SpGEMM.sh ${BIN}/spgemm ${SPARSE}/$${i}.mtx > ${RESULTS}/SpGEMM/$${i}_${TS}.out & \
	done
	
#	for i in $$(ls ${SPARSE}/*.mtx); do \
#		filename=$$(basename -a -s .mtx $$i); \
#		${SCRIPTS}/run_SpGEMM.sh ${BIN}/spgemm $$i > ${RESULTS}/SpGEMM/$$filename.out & \
#	done
	wait

SGEMM_SIZE ?= 512
SGEMM:
	export CUDA_INSTALL_PATH=${CUDA_PATH}; \
	cd ..; \
	source setup_environment; \
	$(MAKE) --silent; \
	cd hb-config; \
	mkdir -p ${RESULTS}/SGEMM; \
	$(BENCHMARK_DIR)/bin/sgemm ${SGEMM_SIZE} > ${RESULTS}/SGEMM/SGEMM_${SGEMM_SIZE}_${TS}.out

SGEMM_BATCHED:
	export CUDA_INSTALL_PATH=${CUDA_PATH}; \
	cd ..; \
	source setup_environment; \
	$(MAKE) --silent; \
	cd hb-config; \
	mkdir -p ${RESULTS}/SGEMM_BATCHED; \
	$(BENCHMARK_DIR)/bin/sgemm_batched > ${RESULTS}/SGEMM_BATCHED/SGEMM_BATCHED_512_${TS}.out
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



PR_INPUTS = wiki-Vote offshore roadNet-CA road_central road_usa soc-Pokec hollywood-2009 ljournal-2008
PR: sparse_data clean_folder 
	export CUDA_INSTALL_PATH=${CUDA_PATH}; \
	cd ..; \
	source setup_environment; \
	$(MAKE) --silent; \
	cd hb-config; \
	mkdir -p ${RESULTS}/PR; \
	for i in ${PR_INPUTS}; do \
		${SCRIPTS}/run_graphit.sh ${BIN}/pr ${SPARSE}/$${i}.mtx > ${RESULTS}/PR/$${i}_${TS}.out & \
	done; \
	wait
	
#	for i in $$(ls ${SPARSE}/*.mtx); do \
#		filename=$$(basename -a -s .mtx $$i); \
#		${SCRIPTS}/run_SpGEMM.sh ${BIN}/spgemm $$i > ${RESULTS}/SpGEMM/$$filename.out & \
#	done
	#${BIN}/pr ${SPARSE}/wiki-Vote.mtx
	#${BIN}/pr ${SPARSE}/soc-Pokec.mtx
	#${BIN}/pr ${SPARSE}/hollywood-2009.mtx
	#${BIN}/pr ${SPARSE}/ljournal-2008.mtx
	#${BIN}/pr ${SPARSE}/roadNet-CA.mtx
	#${BIN}/pr ${SPARSE}/road_central.mtx
	#${BIN}/pr ${SPARSE}/road_usa.mtx



BFS_graphit: sparse_data clean_folder
	export CUDA_INSTALL_PATH=${CUDA_PATH}; \
	cd ..; \
	source setup_environment; \
	$(MAKE) --silent; \
	cd hb-config; \
	mkdir -p ${RESULTS}/bfs; \
	${BIN}/bfs_road ${SPARSE}/roadNet-CA.mtx 985640 > ${RESULTS}/bfs/roadNet-CA_${TS}.out  & \
	${BIN}/bfs_road ${SPARSE}/road_central.mtx 7040908 > ${RESULTS}/bfs/road_central_${TS}.out  & \
	${BIN}/bfs_road ${SPARSE}/road_usa.mtx 11973673 > ${RESULTS}/bfs/road_usa_${TS}.out  &
	wait
	#${BIN}/bfs_social ${SPARSE}/wiki-Vote.mtx 4668 0.01 > ${RESULTS}/bfs/wiki-Vote_${TS}.out;
	#${BIN}/bfs_social ${SPARSE}/soc-Pokec.mtx 816408 0.01 > ${RESULTS}/bfs/soc-Pokec_${TS}.out  & \
	#${BIN}/bfs_social ${SPARSE}/hollywood-2009.mtx 570170 0.026 > ${RESULTS}/bfs/hollywood-2009_${TS}.out;
	#${BIN}/bfs_social ${SPARSE}/ljournal-2008.mtx 2681669 0.006 > ${RESULTS}/bfs/ljournal-2008_${TS}.out  & \
	#${SCRIPTS}/run_bfs.sh ${BIN} ${SPARSE}/soc-Pokec.mtx  816408 >> ${RESULTS}/bfs.out; \
	#${SCRIPTS}/run_bfs.sh ${BIN} ${SPARSE}/hollywood-2009.mtx 570170 >> ${RESULTS}/bfs.out; \
	#${SCRIPTS}/run_bfs.sh ${BIN} ${SPARSE}/ljournal-2008.mtx 2681669 >> ${RESULTS}/bfs.out; \
	#${SCRIPTS}/run_bfs.sh ${BIN} ${SPARSE}/roadNet-CA.mtx 985640 >> ${RESULTS}/bfs.out; \
	#${SCRIPTS}/run_bfs.sh ${BIN} ${SPARSE}/road_central.mtx 7040908 >> ${RESULTS}/bfs.out; \
	#${SCRIPTS}/run_bfs.sh ${BIN} ${SPARSE}/road_usa.mtx 11973673 >> ${RESULTS}/bfs.out;

SSSP_graphit: sparse_data clean_folder
	export CUDA_INSTALL_PATH=${CUDA_PATH}; \
	cd ..; \
	source setup_environment; \
	$(MAKE) --silent; \
	cd hb-config; \
	mkdir -p ${RESULTS}/sssp; \
	${BIN}/ds_social ${SPARSE}/wiki-Vote.mtx 4668 15 > ${RESULTS}/sssp/wiki-Vote_${TS}.out & \
	${BIN}/ds_social ${SPARSE}/soc-Pokec.mtx 816408 120 > ${RESULTS}/sssp/soc-Pokec_${TS}.out  & \
	${BIN}/ds_social ${SPARSE}/hollywood-2009.mtx 570170 15 > ${RESULTS}/sssp/hollywood-2009_${TS}.out  & \
	${BIN}/ds_social ${SPARSE}/ljournal-2008.mtx 2681669 120 > ${RESULTS}/sssp/ljournal-2008_${TS}.out  & \
	${BIN}/ds_road ${SPARSE}/roadNet-CA.mtx 985640 20000 > ${RESULTS}/sssp/roadNet-CA_${TS}.out  & \
	${BIN}/ds_road ${SPARSE}/road_central.mtx 7040908 30000 > ${RESULTS}/sssp/road_central_${TS}.out  & \
	${BIN}/ds_road ${SPARSE}/road_usa.mtx 11973673 80000 > ${RESULTS}/sssp/road_usa_${TS}.out  & \
	wait

SSSP: sparse_data clean_folder
	${BIN}/sssp --graph-type market --src 4668 --graph-file ${SPARSE}/wiki-Vote.gr
	${BIN}/sssp --graph-type market --src 816408 --graph-file ${SPARSE}/soc-Pokec.gr
	${BIN}/sssp --graph-type market --src 570170 --graph-file ${SPARSE}/hollywood-2009.gr
	${BIN}/sssp --graph-type market --src 2681669 --graph-file ${SPARSE}/ljournal-2008.gr
	${BIN}/sssp --graph-type market --src 985640 --graph-file ${SPARSE}/roadNet-CA.gr
	${BIN}/sssp --graph-type market --src 7040908 --graph-file ${SPARSE}/road_central.gr
	${BIN}/sssp --graph-type market --src 11973673 --graph-file ${SPARSE}/road_usa.gr


## FFT
FFT_RUNS = run.fft_16384_64 \
					 run.fft_16384_320 \
					 run.fft_65536_64 \
					 run.fft_65536_320

run_fft: $(FFT_RUNS)
run.fft_%:
	export CUDA_INSTALL_PATH=${CUDA_PATH}; \
	cd ..; \
	source setup_environment; \
	$(MAKE) --silent; \
	cd hb-config; \
	mkdir -p ${RESULTS}/fft; \
	$(BENCHMARK_DIR)/bin/fft_$* > ${RESULTS}/fft/fft_$*_${TS}.out

# 16 MB
AES_SIZE ?= 16777216
AES: clean_folder
	cd ${DATASET}; $(MAKE) aes_data AES_SIZE=${AES_SIZE};
	
	export CUDA_INSTALL_PATH=${CUDA_PATH}; \
	cd ..; \
	source setup_environment; \
	$(MAKE) --silent; \
	cd hb-config; \
	mkdir -p ${RESULTS}/AES; \
	$(BENCHMARK_DIR)/bin/aes e 128 ${DATASET}/aes_input_${AES_SIZE}.in ${DATASET}/aes_key.in > ${RESULTS}/AES/aes_${AES_SIZE}_${TS}.out

JACOBI_ITER ?= 1
Jacobi: clean_folder
	export CUDA_INSTALL_PATH=${CUDA_PATH}; \
	cd ..; \
	source setup_environment; \
	$(MAKE) --silent; \
	cd hb-config; \
	$(BENCHMARK_DIR)/bin/stencil 512 512 64 ${JACOBI_ITER} -i ${DATASET}/stencil/default/input/512x512x64x100.bin > ${RESULTS}/jacobi_512x512x64_${JACOBI_ITER}_iter_${TS}.out

BLK_INPUTS = in_10M.txt
#BLK_INPUTS = in_16K.txt
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
		$(BENCHMARK_DIR)/bin/bs ${DATASET}/BLK/$$i > ${RESULTS}/BS/$${i}_${TS}; \
	done
	
NFA: clean_folder
	export CUDA_INSTALL_PATH=${CUDA_PATH}; \
	cd ..; \
	source setup_environment; \
	$(MAKE) --silent; \
	cd hb-config; \
	mkdir -p ${RESULTS}/NFA; \
	${BIN}/nfa_engine -a ${DATASET}/Sample_NFA/Sample_NFA -i ${DATASET}/random_stream_1KB.input -T 1024 -g 1 -p 1 -N 3072 -O 1 > ${RESULTS}/NFA/nfa_${TS}.out
	
SW: clean_folder
	export CUDA_INSTALL_PATH=${CUDA_PATH}; \
	cd ..; \
	source setup_environment; \
	$(MAKE) --silent; \
	cd hb-config; \
	mkdir -p ${RESULTS}/SW; \
	$(BENCHMARK_DIR)/bin/sw -y local -p ${DATASET}/dna-reference.fasta ${DATASET}/dna-query.fasta > ${RESULTS}/SW/sw_${TS}.out
SW32: clean_folder
	export CUDA_INSTALL_PATH=${CUDA_PATH}; \
	cd ..; \
	source setup_environment; \
	$(MAKE) --silent; \
	cd hb-config; \
	mkdir -p ${RESULTS}/SW; \
	$(BENCHMARK_DIR)/bin/sw -y local -p ${DATASET}/dna-reference32.fasta ${DATASET}/dna-query32.fasta > ${RESULTS}/SW/sw32_${TS}.out

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
