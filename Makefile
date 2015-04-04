OBJ=obj/main.o obj/matrice.o obj/coordonnee.o

all : bin/genimatrice
	./$<

bin/genimatrice : $(OBJ)
	g++  $^ -o $@

obj/main.o : inc/matrice.h
obj/matrice.o : inc/coordonnee.h
obj/coordonnee.o : inc/coordonnee.h

obj/%.o : src/%.cpp
	g++ -c $< -o $@

clean :
	rm -f obj/*.o

mrproper : clean
	rm -f bin/genimatrice
