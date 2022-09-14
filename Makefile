CXX = g++
OBJ = dataType/Int.o latex/latexOutput.o main.o latex/log.o

run: app
	./app

app: $(OBJ)
	$(CXX) $^ -I include/ -std=c++20 -o $@

%.o: %.cpp
	$(CXX) -c $< -I include/ -std=c++20 -o $@

dataType/Int.o: include/dataType.hpp
latex/latexOutput.o: include/latexOutput.hpp
latex/log.o: include/log.hpp
main.o: include/Matrix.hpp include/dataType.hpp include/latexOutput.hpp include/RREF.hpp RREF.cpp dataType/Matrix.cpp

clean:
	- rm $(OBJ)

clean-all: clean
	- rm app