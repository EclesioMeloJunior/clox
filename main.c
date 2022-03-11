#include "common.h"
#include "chunk.h"

int main(int argc, const char* argv[]) {
	Chunk chunk;

	initChunk(&chunk);
	writeChuk(&chunk, OP_RETURN);
	freeChunk(&chunk);	
	return 0;
}
