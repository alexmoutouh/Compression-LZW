# Compression et décompression LWZ + Huffman 
Projet de Compression de 4A (Polytech Marseille) en C.

Il s'agit d'un outil montrant le fonctionnement des compressions et décompression LWZ ainsi que du codage Huffman.

--------
Makefile
--------

A/ Compiler : make
Créé 2 exécutables compression.run et décompression.run

B/ Effacer les exécutables : make clean

C/ Effacer les fichiers compressés et décompressés + dictionnaire : make encodedecodeclean
Efface les fichiers sous forme <nom_initial>_LZW... et <nom_initial>.dico. Conserve les fichiers texte initiaux.
/!\ La commande n'agit que dans le dossier Echantillons_Test.

------------------------------
Arguments de ligne de commande
------------------------------

A/ Compression
./compression.run <fichier_a_compresser>

B/ Décompression
./decompression.run <fichier_a_decompresser> <dictionnaire_genere_lors_de_la_compression>

--------------------------
Déroulement de l'exécution
--------------------------

A/ Compression 
Génère un fichier <nom_initial>_LZW_ENCODED qui correspond au texte du fichier initial compressé avec LZW.
Génère également un fichier <nom_initial>_LZWHUFFMAN_ENCODED qui correspond au texte du fichier initial compressé 
avec LZW puis Huffman.
Génère un fichier <nom_initial>.dico qui correspond au dictionnaire de Huffman. A utiliser pour la décompression.

B/ Décompression 
Génère un fichier <nom_initial>_HUFFMAN_DECODED qui correspond au fichier décompressé uniquement avec Huffman. 
Il correspond donc au fichier initial compresse avec LZW.
Génère également un fichier <nom_initial>_HUFFMAN_DECODED_LZW_DECODED qui correspond au fichier décompressé.

C/ Exemple
./compression.run Echantillons_Test/loremIpsum.txt
[execution]
./decompression.run Echantillons_Test/loremIpsum.txt_LZWHUFFMAN_ENCODED loremIpsum.txt.dico
[execution]
ls Echantillons_Test/
articles.txt       loremIpsum.txt              loremIpsum.txt_LZWHUFFMAN_ENCODED                              montsmots.txt
azAZ123.txt        loremIpsum.txt.dico         loremIpsum.txt_LZWHUFFMAN_ENCODED_HUFFMAN_DECODED              repetitions.txt
bigLoremIpsum.txt  loremIpsum.txt_LZW_ENCODED  loremIpsum.txt_LZWHUFFMAN_ENCODED_HUFFMAN_DECODED_LZW_DECODED  semiBigLorem.txt

