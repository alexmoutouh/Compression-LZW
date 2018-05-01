Compression et décompression LWZ + Huffman : programmation en C++.

fichiers inclus :
Echantillons_Test/articles.txt 
Echantillons_Test/azAZ123.txt 
Echantillons_Test/bigLoremIpsum.txt 
Echantillons_Test/loremIpsum.txt 
Echantillons_Test/montsmots.txt 
Echantillons_Test/repetitions.txt 
Echantillons_Test/semiBigLorem.txt
Huffman/Dictionary.h 
Huffman/HuffmanAlgorithm.h 
Huffman/HuffmanLeaf.h 
Huffman/HuffmanNode.h 
Huffman/HuffmanObject.h
LZW.cxx 
lzw_Huffman_decode.cxx 
lzw_Huffman_encode.cxx 
makefile
README.md

--------
Makefile
--------

A/ Compiler : make
Cree 2 executables compression.run et decompression.run

B/ Effacer les executables : make clean

C/ Effacer les fichiers compresses et decompresses et dictionnaire : make encodedecodeclean
Efface les fichiers sous forme <nom_initial>_LZW... et <nom_initial>.dico. Conserve les fichiers texte initiaux.
/!\ La commande n'agit que dans le dossier Echantillons_Test.

------------------------------
Arguments de ligne de commande
------------------------------

A/ Compression
./compression.run <fichier_a_compresser>

B/ Decompression
./decompression.run <fichier_a_decompresser> <dictionnaire_genere_lors_de_la_compression>

--------------------------
Deroulement de l'execution
--------------------------

A/ Compression 
Genere un fichier <nom_initial>_LZW_ENCODED qui correspond au texte du fichier initial compresse avec LZW.
Genere également un fichier <nom_initial>_LZWHUFFMAN_ENCODED qui correspond au texte du fichier initial compresse 
avec LZW puis Huffman.
Genere un fichier <nom_initial>.dico qui correspond au dictionnaire de Huffman. A utiliser pour la decompression.

B/ Decompression 
Genere un fichier <nom_initial>_HUFFMAN_DECODED qui correspond au fichier compresse, decompresse uniquement avec Huffman. 
Il correspond donc au fichier initial compresse avec LZW.
Genere également un fichier <nom_initial>_HUFFMAN_DECODED_LZW_DECODED qui correspond au fichier decompresse.

C/ Exemple
./compression.run Echantillons_Test/loremIpsum.txt
[execution]
./decompression.run Echantillons_Test/loremIpsum.txt_LZWHUFFMAN_ENCODED loremIpsum.txt.dico
[execution]
ls Echantillons_Test/
articles.txt       loremIpsum.txt              loremIpsum.txt_LZWHUFFMAN_ENCODED                              montsmots.txt
azAZ123.txt        loremIpsum.txt.dico         loremIpsum.txt_LZWHUFFMAN_ENCODED_HUFFMAN_DECODED              repetitions.txt
bigLoremIpsum.txt  loremIpsum.txt_LZW_ENCODED  loremIpsum.txt_LZWHUFFMAN_ENCODED_HUFFMAN_DECODED_LZW_DECODED  semiBigLorem.txt

