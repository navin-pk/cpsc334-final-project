all: compile run clean

compile:
	@echo "Executing Compilation Command: " 
	g++ -std=c++11 bst.cpp main.cpp -o tree
	@echo ""

compile_test:
	@echo "Executing Test Compilation Command:"
	g++ -std=c++11 bst.cpp test_bst.cpp -o test_tree
	@echo ""

run: 
	@echo "Executing Program:"
	@echo ""
	@./tree

run_test: 
	@echo "Executing Test Program:"
	@echo ""
	@./test_tree

clean: 
	@rm -f tree test_tree