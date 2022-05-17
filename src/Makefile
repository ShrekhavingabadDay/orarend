test:
	g++ -o tests/test *.cpp tests/$(TEST).cpp
	./tests/test tests/$(TEST).tsv | tee $(TEST).output
	rm tests/test

clear_output:
	rm *.output
