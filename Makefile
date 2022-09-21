CXX = g++
OBJ = dataType/Int.o latex/latexOutput.o main.o latex/log.o ERROR.o
CXXFLAGS = -I include/ -std=c++20 -lunwind -lunwind-x86_64
run: app
	./app

app: $(OBJ)
	$(CXX) $^ $(CXXFLAGS) -o $@

%.o: %.cpp
	$(CXX) -c $< $(CXXFLAGS) -o $@

dataType/Int.o: include/dataType.hpp include/ERROR.hpp
latex/latexOutput.o: include/latexOutput.hpp
latex/log.o: include/log.hpp
main.o: include/Matrix.hpp include/dataType.hpp include/latexOutput.hpp include/RREF.hpp RREF.cpp dataType/Matrix.cpp include/ERROR.hpp
ERROR.o: include/ERROR.hpp

clean:
	- rm $(OBJ)

clean-all: clean
	- rm app