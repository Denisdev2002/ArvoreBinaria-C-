#include <iostream>
#include "ArvoreBinaria.h"

using namespace std;

int main() {
	Node* raiz = criarArvore();
	
	if (raiz != nullptr) {
		opcoesArvore(raiz);
	}
	else {
		cout << "Erro ao criar a arvore." << endl;
	}

	return 0;
}
