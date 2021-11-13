#!/bin/bash
export CUDA_INSTALL_PATH=$1
cd ..
source setup_environment
make

CUDA_PATH=/usr/local/cuda; \
DATASET=../datasets; \
SPARSE=${DATASET}/sparse; \
BIN=../precompiled_bin; \
SCRIPTS=./scripts; \
RESULTS=./results; \
export CUDA_INSTALL_PATH=${CUDA_PATH}; \
cd ..; \
source setup_environment; \
make --silent; \
cd hb-config; \
mkdir -p ${RESULTS}/SpGEMM; \
touch ${RESULTS}/SpGEMM.out; \
i=../datasets/sparse/wiki-Vote.mtx; \
filename=$(basename -a -s .mtx $i); \
${SCRIPTS}/run_SpGEMM.sh ${BIN}/spgemm $i > ${RESULTS}/SpGEMM/$filename.out;

