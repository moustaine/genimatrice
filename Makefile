OBJ=obj/main.o obj/menu.o obj/matrice.o obj/coordonnee.o

all : bin/genimatrice
	./$<

bin/genimatrice : $(OBJ)
	g++  $^ -o $@

obj/main.o : inc/matrice.h
obj/menu.o : inc/matrice.h inc/couleur.h
obj/matrice.o : inc/coordonnee.h inc/couleur.h
obj/coordonnee.o : inc/coordonnee.h

obj/%.o : src/%.cpp
	g++ -c $< -o $@

clean :
	rm -f obj/*.o

mrproper : clean
	rm -f bin/genimatrice
