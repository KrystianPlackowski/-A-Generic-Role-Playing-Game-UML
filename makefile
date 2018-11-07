all: main

include dep.mk

dep.mk : dep.sh Entities/* *.cpp
	@./dep.sh

main : $(SOURCE:.cpp=.o)
	$(CXX) -o $@ $^

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<


