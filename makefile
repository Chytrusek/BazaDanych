all:
	g++ *.cpp -o BazaDanych -std=c++11 `wx-config --cxxflags --libs`

clean:
	$(RM) BazaDanych
