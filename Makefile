o_path = object_files
MYDIR = .


run: $(opath)/*
	gcc -g -o neural_net $(opath)/$^
	./neural_net
	rm neural_net

debug: $(opath)/*
	gcc -g -o neural_net $(opath)/$^
	gdb ./neural_net
	rm neural_net

compile all: $(MYDIR)/*.c
	for file in $^; do \
		echo "Hello" $${file} ; \
		gcc -c -o $${opath}/$${file}.o $${file}; \
		done

	
