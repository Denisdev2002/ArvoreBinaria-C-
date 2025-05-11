#include "ArvoreBinaria.h"
#include <iostream>

using namespace std;
// Função para exibir funções de manipulação da árvore
void opcoesArvore(Node* node) {
	cout << "Escolha uma opção:" << endl;
	cout << "1. Inserir nó" << endl;
	cout << "2. Deletar nó" << endl;
	cout << "3. Buscar nó" << endl;
	cout << "4. Reverter árvore" << endl;
	cout << "5. Imprimir árvore" << endl;
	cout << "6. Adicionar um filho a um nó especifico" << endl;
	cout << "7. Sair" << endl;
	int opcao;
	cin >> opcao;
	switch (opcao) {
	case 1:
		int valor;
		cout << "Digite o valor do nó a ser inserido: ";
		cin >> valor;
		inserirNode(node, valor);
		break;
	case 2:
		int valorDeletar;
		cout << "Digite o valor do nó a ser deletado: ";
		cin >> valorDeletar;
		deletarNode(node, valorDeletar);
		break;
	case 3:
		int valorBuscar;
		cout << "Digite o valor do nó a ser buscado: ";
		cin >> valorBuscar;
		buscarNode(node, valorBuscar);
		break;
	case 4:
		reverterArvore(node);
		break;
	case 5:
		imprimirArvoreVisual(node);
		break;
	case 6:
		int valorFilho;
		char lado;
		cout << "Digite o valor do nó filho a ser inserido: ";
		cin >> valorFilho;
		cout << "Digite o lado (E para esquerda, D para direita): ";
		cin >> lado;
		inserirNodeFilho(node, valorFilho, lado);
		break;
	case 7:
		exit(0);
	default:
		cout << "Opção inválida!" << endl;
	}
	cout << endl;
	opcoesArvore(node);
}

// Função para criar uma árvore binária
Node* criarArvore() {
	int valor;
	cout << "Digite o valor do nó raiz: ";
	cin >> valor;
	Node* root = new Node(valor);
	cout << "Árvore criada com o nó raiz: " << root->data << endl;
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

	imprimirNivel(node->left, nivel + 1, espaco);

	for (int i = 0; i < espaco * nivel; i++) {
		cout << " ";
	}
	cout << node->data << endl;

	imprimirNivel(node->right, nivel + 1, espaco);
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
		cout << "Nó não encontrado!" << endl;
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
			cout << "Nó deletado!" << endl;
		}
		else if (node->left == nullptr) {
			Node* temp = node->right;
			delete node;
			node = temp;
			cout << "Nó deletado!" << endl;
		}
		else if (node->right == nullptr) {
			Node* temp = node->left;
			delete node;
			node = temp;
			cout << "Nó deletado!" << endl;
		}
		else {
			Node* temp = node->right;
			while (temp->left != nullptr) {
				temp = temp->left;
			}
			node->data = temp->data;
			node->right = deletarNode(node->right, temp->data);
			cout << "Nó deletado!" << endl;
		}
	}
}

// Função para inserir um nó na árvore
void inserirNode(Node*& node, int value) {
	if (node == nullptr) {
		node = new Node(value);
		cout << "Nó inserido: " << value << endl;
	}
	else if (value < node->data) {
		inserirNode(node->left, value);
	}
	else if (value > node->data) {
		inserirNode(node->right, value);
	}
	else {
		cout << "Valor já existe na árvore!" << endl;
	}
}

// Função para inserir um nó filho na árvore
void inserirNodeFilho(Node*& pai, int value, char lado) {
	if (pai == nullptr) {
		cout << "Nó pai invalido!" << endl;
		return;
	}

	Node* novoNode = new Node(value);

	if (lado == 'E' || lado == 'e') {
		if (pai->left == nullptr) {
			pai->left = novoNode;
			cout << "Nó filho inserido à esquerda: " << value << endl;
		}
		else {
			cout << "Já existe um nó à esquerda!" << endl;
		}
	}
	else if (lado == 'D' || lado == 'd') {
		if (pai->right == nullptr) {
			pai->right = novoNode;
			cout << "Nó filho inserido à direita: " << value << endl;
		}
		else {
			cout << "Já existe um nó à direita!" << endl;
		}
	}
	else {
		cout << "Lado inválido! Use 'E' para esquerda ou 'D' para direita." << endl;
		delete novoNode;
	}
}

// Função para buscar um nó na árvore
Node* buscarNode(Node* node, int value) {
	if (node == nullptr) {
		cout << "Nó não encontrado!" << endl;
		return nullptr;
	}
	if (value < node->data) {
		return buscarNode(node->left, value);
	}
	else if (value > node->data) {
		return buscarNode(node->right, value);
	}
	else {
		cout << "Nó encontrado: " << node->data << endl;
		return node;
	}
}

// Função para reverter a árvore
void reverterArvore(Node*& node) {
	if (node == nullptr) {
		return;
	}
	swap(node->left, node->right);
	reverterArvore(node->left);
	reverterArvore(node->right);
	cout << "Árvore revertida!" << endl;
}