BIN=$1
FILE=$2
SRC_NODE=$3
echo "Running BFS with graph ${FILE} and source node ${SRC_NODE}..."
${BIN}/bfs --graph-type market --direction-optimized=1 --graph-file ${FILE} --src ${SRC_NODE}
echo "Finished BFS with graph ${FILE} and source node ${SRC_NODE}."
