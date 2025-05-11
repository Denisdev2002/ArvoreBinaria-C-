<img width="50" height="50" src="https://cdn.jsdelivr.net/gh/devicons/devicon@latest/icons/cplusplus/cplusplus-original.svg" /> #Projeto Árvore Binária em C++ para Estudo

Este repositório contém um projeto pessoal de estudo em C++ focado na implementação e manipulação de árvores binárias. O objetivo principal é aprofundar o conhecimento em C++, especialmente no que diz respeito a ponteiros e gerenciamento de memória, ao mesmo tempo em que revisito os conceitos de árvores binárias aprendidos anteriormente em Python.

## 📌Propósito do Projeto

* **Aprendizado de C++:** Praticar a sintaxe, o uso de ponteiros, a alocação e desalocação de memória (`new` e `delete`) e as estruturas de dados em C++.
* **Revisão de Árvores Binárias:** Relembrar os conceitos fundamentais de árvores binárias estudados na faculdade, agora aplicando-os na linguagem C++.
* **Entendimento de Ponteiros:** Utilizar ponteiros para implementar as relações entre os nós da árvore e compreender seu papel na manipulação dinâmica de memória.
* **Implementação de Inversão de Árvore Binária:** Desenvolver a lógica e a implementação para inverter uma árvore binária, um problema comum em entrevistas técnicas.

## Funcionalidades Implementadas

O projeto atualmente oferece as seguintes funcionalidades interativas através de um menu de console:

* **Criação de Árvore Binária:** Permite criar uma raiz para a árvore, definindo seu valor.
* **Inserção de Nó (BST):** Implementa a inserção de novos nós seguindo a lógica de uma Árvore de Busca Binária (BST), onde valores menores são inseridos à esquerda e valores maiores à direita.
* **Inserção Controlada de Nó:** Permite adicionar um novo nó como filho esquerdo ou direito de um nó específico existente na árvore.
* **Deleção de Nó:** Implementa a remoção de um nó específico da árvore, mantendo a sua estrutura (para Árvores de Busca Binária).
* **Busca de Nó:** Permite buscar um nó na árvore por seu valor.
* **Reversão de Árvore:** Implementa a inversão da estrutura da árvore binária, trocando os filhos esquerdo e direito de cada nó.
* **Impressão da Árvore:** Exibe a estrutura da árvore no console de forma visual, com indentação para representar os níveis.

## Como Usar (Visual Studio 2022)

1.  **Clonar o Repositório:**
    Abra o Visual Studio 2022. No menu principal, vá em **Arquivo** -> **Clone um Repositório...**. Cole a URL do seu repositório do GitHub na caixa de diálogo e escolha um local para salvar o projeto em sua máquina. Clique em **Clonar**.

2.  **Abrir o Projeto:**
    Após a clonagem, na janela do Team Explorer (geralmente visível no lado direito ou acessível pelo menu **Exibir** -> **Team Explorer**), clique duas vezes no nome do repositório clonado. O Visual Studio pode perguntar se você deseja abrir a pasta clonada como um projeto do CMake ou criar um projeto a partir do código.

    * **Se você já tem um arquivo de projeto do Visual Studio (`.vcxproj`):** Clique duas vezes nesse arquivo no Solution Explorer (geralmente visível no lado direito ou acessível pelo menu **Exibir** -> **Solution Explorer**) para abrir a solução.

    * **Se você não tem um arquivo de projeto (`.vcxproj`) ainda:**
        * Vá em **Arquivo** -> **Abrir** -> **Pasta...** e selecione a pasta onde você clonou o repositório. O Visual Studio deverá reconhecer os arquivos `.cpp` e você poderá criar um projeto.
        * Para criar um projeto C++: Vá em **Arquivo** -> **Novo** -> **Projeto...**. Na janela "Criar um novo projeto", procure por "Aplicativo de Console (C++)" e clique em **Avançar**.
        * Configure o nome do projeto e o local (você pode escolher a pasta onde clonou o repositório). Clique em **Criar**.
        * No Solution Explorer, clique com o botão direito em "Arquivos de Origem" e selecione **Adicionar** -> **Item Existente...**. Navegue até a pasta onde seus arquivos `Main.cpp` e `ArvoreBinaria.cpp` estão e adicione-os ao projeto. Faça o mesmo para os arquivos de cabeçalho (`.h`).

3.  **Compilar o Projeto:**
    No Solution Explorer, clique com o botão direito no nome do seu projeto e selecione **Compilar**. O Visual Studio compilará o código. Você poderá ver o progresso na janela de Saída (geralmente na parte inferior).

4.  **Executar o Programa:**
    Após a compilação bem-sucedida, vá em **Depurar** -> **Iniciar Sem Depuração** (ou pressione `Ctrl + F5`). Uma janela de console será aberta, exibindo o menu interativo do seu programa de árvore binária.

## Aprendizados e Próximos Passos

Durante o desenvolvimento deste projeto, foram explorados e reforçados os seguintes conceitos:

* **Alocação e desalocação dinâmica de memória com `new` e `delete`.**
* **Utilização de ponteiros para criar a estrutura da árvore e navegar entre os nós.**
* **Implementação de algoritmos recursivos para travessia e manipulação da árvore.**
* **Conceitos básicos de Árvores Binárias e Árvores de Busca Binária.**
* **A lógica para inverter uma árvore binária.**
* **Organização do código em arquivos de cabeçalho (`.h`) e implementação (`.cpp`).**

Os próximos passos para este projeto podem incluir:

* Implementar outras operações comuns em árvores binárias (e.g., encontrar mínimo/máximo, calcular altura, verificar se é balanceada).
* Explorar diferentes métodos de travessia da árvore (pré-ordem, pós-ordem).
* Adicionar tratamento de erros mais robusto.
* Considerar a implementação de uma classe `ArvoreBinaria` para encapsular a estrutura e as operações.
* Experimentar com diferentes formas de visualização da árvore no console.

## Observações

Este é um projeto de estudo pessoal, e o código pode não seguir todas as melhores práticas de desenvolvimento em todos os aspectos. O foco principal é o aprendizado e a experimentação com os conceitos de C++ e árvores binárias.

Sinta-se à vontade para explorar o código e fornecer sugestões ou comentários!