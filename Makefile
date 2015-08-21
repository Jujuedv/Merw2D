SRC=main.cpp Vec2D.cpp Isorenderer.cpp
HDR=ext_include.h Isorenderer.h Vec2D.h
BIN=engine
OBJ=$(SRC:%cpp=%o)
CXX=/usr/bin/clang++
CXXFLAGS=-std=c++11 -O2 -g -Wall
LDFLAGS=-lSDL2 -lSDL2_image -lpthread

all: .depend $(BIN)

clean:
	rm -rf $(BIN) .depend *.o

.depend: $(HDR) $(SRC)
	$(CXX) -MM $(CXXFLAGS) $(SRC) > .depend

engine: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(BIN) $(OBJ) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

-include .depend
