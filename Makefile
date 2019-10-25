CC=gcc # compilador
CFLAGS=-Wall -Wextra # compiler flags, troque o que quiser, exceto bibliotecas externas
EXEC=./somamax # nome do executavel que sera gerado, nao troque

run: $(EXEC)
	$(EXEC)

$(EXEC): somamax.c somamax.o
	$(CC) $(CFLAGS) somamax.c -o $(EXEC)

somamax.o: somamax.c
	$(CC) $(CFLAGS) -c somamax.c -o somamax.o

clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf somamax.o

# Para mais informacoes sobre o Makefile, procure os monitores ou consulte
# outras referencias disponiveis na internet como:
# https://opensource.com/article/18/8/what-how-makefile
