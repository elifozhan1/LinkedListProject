kural: derle calistir

derle:
	g++ -I ./include/ -o ./lib/basamak.o -c ./src/basamak.cpp
	g++ -I ./include/ -o ./lib/sayi.o -c ./src/sayi.cpp
	g++ -I ./include/ -o ./lib/dugum.o -c ./src/dugum.cpp
	g++ -I ./include/ -o ./lib/sayilarlistesi.o -c ./src/sayilarlistesi.cpp
	g++ -I ./include/ -o ./bin/main ./lib/basamak.o ./lib/sayi.o ./lib/dugum.o ./lib/sayilarlistesi.o ./src/main.cpp
calistir:
	./bin/main.exe