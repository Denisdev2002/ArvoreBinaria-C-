#ifndef ARVOREBINARIA_H
#define ARVOREBINARIA_H

struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* criarArvore();
void inserirNode(Node*& node, int value);
Node* deletarNode(Node* node, int valorDeletar);
void imprimirArvoreVisual(Node* node);
Node* buscarNode(Node* node, int value);
void reverterArvore(Node*& node);
void opcoesArvore(Node* node); // Função para exibir opções de manipulação da árvore
int alturaArvore(Node* node);
void imprimirNivel(Node* node, int nivel, int espaco);
void inserirNodeFilho(Node*& node, int value, char lado);

#endif