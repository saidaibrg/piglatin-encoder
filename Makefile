pig: pig.c
	gccx -o pig pig.c
clean: pig 
	rm -rf pig
