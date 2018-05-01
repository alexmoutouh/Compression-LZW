COMPILER = g++
CFLAGS = -std=c++11

all : compression.run decompression.run

compression.run : lzw_Huffman_encode.cxx
	$(COMPILER) $(CFLAGS) lzw_Huffman_encode.cxx -o compression.run

decompression.run : lzw_Huffman_decode.cxx
	$(COMPILER) $(CFLAGS) lzw_Huffman_decode.cxx -o decompression.run

clean : 
	clear; rm -rf *.o; rm *.run;

encodedecodeclean : 
	clear; rm -rf Echantillons_Test/*CODE*; rm -rf Echantillons_Test/*.dico;

