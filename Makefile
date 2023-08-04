help:	
	@echo "======================="	
	@echo "		AJUDA          "
	@echo "======================="
	@echo "help  | ajuda"
	@echo "ola   | executa mensagem de teste"
	@echo "clean | apaga codigos compilados"
ola: clean 
	@echo "======================="
	@echo  "PROGRAMA OLA"
	@echo "======================="
	@echo "Compilando o programa Ola mundo"
	gcc ponteiro_duplo.c -o ola 
	@echo "Tornando o programa ola mundo executavel"
	chmod +x ola
	@echo "executando o programa olamundo"
	./ola
	@echo "======================="
clean:
	@echo "======================="
	@echo "Removendo os progamas compilados"
	@echo "======================="
	@echo "Removendo o programa olamundo"
	rm -f ola
	@echo "======================="