BIN = merge_common_prefix
all:$(BIN) 

$(BIN): merge_common_prefix.o trie.o
	gcc -o merge_common_prefix merge_common_prefix.o trie.o
merge_common_prefix.o: merge_common_prefix.c
	gcc -c -o merge_common_prefix.o merge_common_prefix.c
trie.o: trie.c 
	gcc -c -o trie.o trie.c


clean:
	rm *.o
	rm $(BIN)



