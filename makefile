CXX=g++

CXXFLAGS= -g -Wall
CXXFLAGS+= `pkg-config --cflags gtkmm-3.0`
LXXFLAGS= `pkg-config --libs sdl2 SDL2_mixer gtkmm-3.0 glibmm-2.4`

SOURCES=$(wildcard src/*.cpp)
OBJECTS=$(patsubst %.cpp, %.o, $(SOURCES))

EXECUTABLE = MewZik.out
DEBUG = -rdynamic

all: $(OBJECTS)
	$(CXX) -o $(EXECUTABLE) $(OBJECTS) $(CXXFLAGS) $(LXXFLAGS)

$(OBJECTS): src/%.o: src/%.cpp
	$(CXX) -c -o $@ $< $(DEBUG) $(CXXFLAGS) $(LXXFLAGS)

clean:
	rm -r $(EXECUTABLE) $(OBJECTS)

run:
	./$(EXECUTABLE)