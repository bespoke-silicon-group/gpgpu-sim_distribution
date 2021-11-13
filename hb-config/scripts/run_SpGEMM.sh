BIN=$1
FILE=$2
echo "Running SpGEMM with graph ${FILE}..."
${BIN} -cuda -spgemm ${FILE}
echo "Finished SpGEMM with graph ${FILE}."
