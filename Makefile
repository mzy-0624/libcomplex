run:
	@g++ -o a.out main.cpp MathUtils.cpp Complex.cpp;
	@./a.out;
clean:
	@rm -rf *.out;
