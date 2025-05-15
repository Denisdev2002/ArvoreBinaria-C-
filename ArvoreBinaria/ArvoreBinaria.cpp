#include "ArvoreBinaria.h"
#include <iostream>

using namespace std;
// Função para exibir funções de manipulação da árvore
void opcoesArvore(Node* node) {
	cout << "Escolha uma opcao:" << endl;
	cout << "1. Inserir no" << endl;
	cout << "2. Deletar no" << endl;
	cout << "3. Buscar no" << endl;
	cout << "4. Inverter arvore" << endl;
	cout << "5. Imprimir arvore" << endl;
	cout << "6. Adicionar um filho a um no especifico" << endl;
	cout << "7. Sair" << endl;
	int opcao;
	cin >> opcao;
	switch (opcao) {
	case 1:
		int valor;
		cout << "Digite o valor do no a ser inserido: ";
		cin >> valor;
		inserirNode(node, valor);
		break;
	case 2:
		int valorDeletar;
		cout << "Digite o valor do no a ser deletado: ";
		cin >> valorDeletar;
		deletarNode(node, valorDeletar);
		break;
	case 3:
		int valorBuscar;
		cout << "Digite o valor do no a ser buscado: ";
		cin >> valorBuscar;
		buscarNode(node, valorBuscar);
		break;
	case 4:
		inverterArvore(node);
		cout << "Arvore revertida!" << endl;
		break;
	case 5:
		imprimirArvoreVisual(node);
		break;
	case 6: {
		int valorFilho;
		char lado;
		int valorPai;
		Node* paiEncontrado = nullptr;

		cout << "Digite o valor do no filho a ser inserido: ";
		cin >> valorFilho;
		cout << "Digite o lado (E para esquerda, D para direita): ";
		cin >> lado;
		cout << "Digite o valor do no pai: ";
		cin >> valorPai;

		paiEncontrado = buscarNode(node, valorPai);
		if (paiEncontrado != nullptr) {
			inserirNodeFilho(paiEncontrado, valorFilho, lado);
		}
		else {
			cout << "No pai nao encontrado na arvore!" << endl;
		}
		break;
	}
	case 7:
		exit(0);
	default:
		cout << "Opcao invalida!" << endl;
	}
	cout << endl;
	opcoesArvore(node);
}

// Função para criar uma árvore binária
Node* criarArvore() {
	int valor;
	cout << "Digite o valor do no raiz: ";
	cin >> valor;
	Node* root = new Node(valor);
	cout << "Arvore criada com o no raiz: " << root->data << endl;
	return root;
}

// Função auxiliar para calcular a altura da árvore
int alturaArvore(Node* node) {
	if (node == nullptr) {
		return 0;
	}
	return 1 + max(alturaArvore(node->left), alturaArvore(node->right));
}

// Função auxiliar para imprimir nós com espaçamento
void imprimirNivel(Node* node, int nivel, int espaco) {
	if (node == nullptr) {
		return;
	}

	imprimirNivel(node->right, nivel + 1, espaco); // imprima a direita primeiro

	for (int i = 0; i < espaco * nivel; i++) {
		cout << " ";
	}
	cout << node->data << endl;

	imprimirNivel(node->left, nivel + 1, espaco); // depois a esquerda
}

// Função principal para imprimir arvore de forma visual
void imprimirArvoreVisual(Node* node) {
	int altura = alturaArvore(node);
	int espaco = 4;
	imprimirNivel(node, 0, espaco);
}

//Função para imprimir a árvore binária
void imprimirArvore(Node* node) {
	if (node == nullptr) {
		return;
	}
	imprimirArvore(node->left);
	cout << node->data << " ";
	imprimirArvore(node->right);
}

// Função para deletar um nó e seus nós filhos
Node* deletarNode(Node* node, int valorDeletar) {
	if (node == nullptr) {
		cout << "No nao encontrado!" << endl;
		return node;
	}
	if (valorDeletar < node->data) {
		node->left = deletarNode(node->left, valorDeletar);
	}
	else if (valorDeletar > node->data) {
		node->right = deletarNode(node->right, valorDeletar);
	}
	else {
		if (node->left == nullptr && node->right == nullptr) {
			delete node;
			node = nullptr;
			cout << "No deletado!" << endl;
		}
		else if (node->left == nullptr) {
			Node* temp = node->right;
			delete node;
			node = temp;
			cout << "No deletado!" << endl;
		}
		else if (node->right == nullptr) {
			Node* temp = node->left;
			delete node;
			node = temp;
			cout << "No deletado!" << endl;
		}
		else {
			Node* temp = node->right;
			while (temp->left != nullptr) {
				temp = temp->left;
			}
			node->data = temp->data;
			node->right = deletarNode(node->right, temp->data);
			cout << "No deletado!" << endl;
		}
	}
}

// Função para inserir um nó na árvore
void inserirNode(Node*& node, int value) {
	if (node == nullptr) {
		node = new Node(value);
		cout << "No inserido: " << value << endl;
	}
	else if (value < node->data) {
		inserirNode(node->left, value);
	}
	else if (value > node->data) {
		inserirNode(node->right, value);
	}
	else {
		cout << "Valor ja existe na arvore!" << endl;
	}
}

// Função para inserir um nó filho na árvore
void inserirNodeFilho(Node*& pai, int value, char lado) {
	if (pai == nullptr) {
		cout << "No pai invalido!" << endl;
		return;
	}

	Node* novoNode = new Node(value);

	if (lado == 'E' || lado == 'e') {
		if (pai->left == nullptr) {
			pai->left = novoNode;
			cout << "No filho inserido a esquerda: " << value << endl;
		}
		else {
			cout << "Ja existe um no a esquerda!" << endl;
		}
	}
	else if (lado == 'D' || lado == 'd') {
		if (pai->right == nullptr) {
			pai->right = novoNode;
			cout << "No filho inserido a direita: " << value << endl;
		}
		else {
			cout << "Ja existe um no a direita!" << endl;
		}
	}
	else {
		cout << "Lado invalido! Use 'E' para esquerda ou 'D' para direita." << endl;
		delete novoNode;
	}
}

// Função para buscar um nó na árvore
Node* buscarNode(Node* node, int value) {
	if (node == nullptr) {
		cout << "No nao encontrado!" << endl;
		return nullptr;
	}
	if (value < node->data) {
		return buscarNode(node->left, value);
	}
	else if (value > node->data) {
		return buscarNode(node->right, value);
	}
	else {
		cout << "No encontrado: " << node->data << endl;
		return node;
	}
}

// Função para inverter a árvore
void inverterArvore(Node*& node) {
	if (node == nullptr) {
		return;
	}
	swap(node->left, node->right);
	inverterArvore(node->left);
	inverterArvore(node->right);
}