src = src
inc = include
lib = lib
bin = bin
app = app
out = $(bin)/$(app) 
libs = -ltermDisplay -lpthread
flags = -std=c++17 -O3

make: build run

build:
	g++ $(src)/*.cpp -o $(out) -I$(inc) -L$(lib) $(libs) $(flags)

run:
	cd $(bin); \
	./$(app);
	