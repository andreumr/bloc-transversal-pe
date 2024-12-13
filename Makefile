all: clean kruskal prim graf

kruskal: Kruskal.cc
	g++ -o kruskal Kruskal.cc

prim: Prim.cc
	g++ -o prim Prim.cc

graf: creador_graphs.cc
	g++ -o graf creador_graphs.cc

executar: graf kruskal prim
	./graf > input.txt
	./kruskal < input.txt >> output.txt
	./prim < input.txt >> output.txt

clean:
	rm -f kruskal prim graf input.txt *.o
	echo Kruskal,Prim,nodes,arestes > output.txt
