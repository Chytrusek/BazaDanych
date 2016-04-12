all:
	g++ *.cpp -o elo -std=c++11 `wx-config --cxxflags --libs`

clean:
	$(RM) elo
