PROJECT_NAME=PR7 FN Chomsky
DIRPATH=$(shell realpath .)
DIRNAME=$(shell basename $(DIRPATH))

cmake:
	cmake -S . -B build

build: cmake
	cd build; make

clean:
	rm -rf build

tar:
	cd ..; tar cvfz $(DIRNAME)/p07-PortilloGarcia-JoseAngel.tar.gz --exclude-from=./$(DIRNAME)/.gitignore $(DIRNAME)
