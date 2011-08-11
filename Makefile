all: FindNumber FindMissingNumber

FindNumber: src/FindNumber.cpp
	g++ -o out/FindNumber src/FindNumber.cpp
FindMissingNumber: src/FindMissingNumber.cpp
	g++ -o out/FindMissingNumber src/FindMissingNumber.cpp

