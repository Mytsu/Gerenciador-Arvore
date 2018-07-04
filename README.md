# Gerenciador-Arvore

    Instituto Federal de Minas Gerais Campus Formiga
    Jonathan Arantes Pinto

Este trabalho tem como base a implementação de uma estrutura de dados de Árvore Binária de Busca AVL, e um gerenciador para a árvore com a intenção de ler um arquivo com um padrão de entrada de comandos para operar a árvore.

## Implementação

A árvore segue uma implementação básica de ABB com a adição da propriedade `int height` que guarda a altura atual do node, desta forma as múltiplas chamadas da função `height()` são limitadas apenas à checar esta variável ao invés de calcular a altura da árvore repetidas vezes desnecessariamente.

A árvore utiliza funções simples de rotação única (somente à esquerda e somente à direita) para fazer o balanceamento, uma dupla rotação da árvore exige duas chamadas de rotação das funções, isso torna o código mais enxuto e fácil de ler.

A função de inserção faz uma simples inserção binária seguida do teste de rebalanceamento, usando o nível de balanceamento com base na escolha de qual rotação é necessária.

A função de remoção segue o mesmo padrão da ABB, que realiza a busca binária pelo elemento e em seguida checa a necessidade de tratar o movimento do node até uma folha para ser removido, em seguida é checado a necessidade de realizar o rebalanceamento.

Funções de pré-ordem, in-ordem e pós-ordem utilizando recursão para atender às necessidades do gerenciador.

Função para destruir a árvore `void destroyTree(Node * arv)` feita para liberar a memória alocada ao encerrar a aplicação.

## Conclusão

A implementação da árvore foi uma tarefa relativamente simples uma vez entendida a lógica do processo de rebalanceamento da AVL. A implementação do gerenciador mostrou diversos problemas no tratamento de strings utilizando funções não mais recomendadas pela versão atual dos compiladores (_Clang e GCC_).

## Bibliografia

[InfoGeek - https://www.geeksforgeeks.org/avl-tree-set-1-insertion/](https://www.geeksforgeeks.org/avl-tree-set-1-insertion/)