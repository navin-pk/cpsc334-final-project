all: compile run clean

compile:
	@echo "Executing Compilation Command: " 
	g++ -std=c++11 bst.cpp main.cpp -o tree
	@echo ""

compile_test:
	@echo "Executing Test Compilation Command:"
	g++ -std=c++11 bst.cpp test_bst.cpp -o test_tree
	chmod +x test_tree
	@echo ""

run: 
	@echo "Executing Program:"
	@echo ""
	@./tree

run_test: 
	@echo "Executing Test Program:"
	@./test_tree
	@echo ""

clean: 
	@echo "Cleaning .deb build artifacts..."
	rm -f tree test_tree
	rm -f bst-project_1.0.deb
	rm -f debbuild/usr/local/bin/test_tree

build-deb:
	@echo "Building .deb package..."
	make compile_test
	mkdir -p debbuild/usr/local/bin
	cp test_tree debbuild/usr/local/bin/test_tree
	chmod 755 debbuild/usr/local/bin/test_tree
	dpkg-deb --build debbuild bst-project_1.0.deb