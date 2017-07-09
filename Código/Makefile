all: main

ordenacao.o: ordenacao.c
	gcc -c -o ordenacao.o ordenacao.c -std=c99
	

main.o: main.c 
	gcc -c -o main.o main.c -std=c99

# Tool invocations
main: main.o ordenacao.o
	@echo 'Building target: $@'
	@echo 'Invoking: GCC Linker'
	gcc -I. -o main main.o ordenacao.o 
	@echo ' '

# Other Targets
clean:
	rm -rf main.o ordenacao.o main 2>/dev/null
	-@echo ' '

.PHONY: all clean
