all: 
	gcc  ls.c -o ls
	gcc  rm.c -o rem
	gcc  mkdir.c -o mak 
	gcc  cat.c -o catto
	gcc  date.c -o dato
	gcc  shell.c
	./a.out
	

clean: 
	rm a.out
	rm ls
	rm rem
	rm mak
	rm catto
	rm dato

