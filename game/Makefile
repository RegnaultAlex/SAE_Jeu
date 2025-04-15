# Compilation manuelle avec dépendances explicites

main.exe : main.o enemies.o game.o getLanguage.o inventory.o location.o playerCharacts.o progress.o readFile.o
	gcc -o main.exe main.o enemies.o game.o getLanguage.o inventory.o location.o playerCharacts.o progress.o readFile.o

main.o : main.c header/enemies.h header/game.h header/getLanguage.h header/inventory.h header/location.h header/playerCharacts.h header/progress.h header/readFile.h
	gcc -c main.c -Wall -Iheader

enemies.o : cFiles/enemies.c header/enemies.h
	gcc -c cFiles/enemies.c -Wall -Iheader

game.o : cFiles/game.c header/game.h
	gcc -c cFiles/game.c -Wall -Iheader

getLanguage.o : cFiles/getLanguage.c header/getLanguage.h
	gcc -c cFiles/getLanguage.c -Wall -Iheader

inventory.o : cFiles/inventory.c header/inventory.h
	gcc -c cFiles/inventory.c -Wall -Iheader

location.o : cFiles/location.c header/location.h
	gcc -c cFiles/location.c -Wall -Iheader

playerCharacts.o : cFiles/playerCharacts.c header/playerCharacts.h
	gcc -c cFiles/playerCharacts.c -Wall -Iheader

progress.o : cFiles/progress.c header/progress.h
	gcc -c cFiles/progress.c -Wall -Iheader

readFile.o : cFiles/readFile.c header/readFile.h
	gcc -c cFiles/readFile.c -Wall -Iheader

clean :
	rm -r *.exe *.o
