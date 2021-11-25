run: compile  
	./a.out > ./FilesData/result.txt

compile:
	g++ main.cpp ./MatrixClass/MatrixClass.cpp
	
