.DEFAULT_GOAL := build

all: build

build:
	@echo "Build Started"
	echo "Q Q q Q Q"
	g++ -o sampleapp ./src/main.cpp ./src/sample_function.cpp -Iinclude
	echo "\033[0;32mBuild Complete\033[0m"
	@echo "Build Complete"
	./sampleapp

clean:
	@echo "Cleaning up"
	rm *.o
