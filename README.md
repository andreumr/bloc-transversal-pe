# Temps d’execució dels algorismes Prim i Kruskal

En aquest repositori es troben les implementacions del programes fets servir en el nostre estudi estadistic, en llenguatge C++.
També hi ha el fitxer Makefile que hem utilitzat per facilitar la compilació i les execucións.

## Fitxers

### creador_grafs.cc

Aquest fitxer conté el codi que genera grafs ponderats connexos aleatoriament.

### Kruskal.cc

Aquest fitxer conté la implementació de l'algorisme de Kruskal.

### Prim.cc

Aquest fitxer conté la implementació de l'algorisme de Prim.

### Makefile

Aquest fitxer compila els codis i els executa per generar una dada amb la comanda *make*.

## Ús

### make

Executar aquesta comanda a la terminal generarà una dada i l'afegirà al fitxer **output.txt**.
Els programes es compilen autimaticament.

Atenció: si s'executa el programa **creador_grafs.cc** varies vegades en intervals de temps molt petits s'acabaran generant els mateixos grafs.

### make clean

Executant aquesta comanda es borrarant els executables i l'**output.txt**.

### output.txt

En aquest fitxer de text es guardaran les dades generades en el següent format: *temps de Kruskal*,*temps de prim*,*nodes*,*arestes*
