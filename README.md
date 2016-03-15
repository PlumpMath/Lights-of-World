# Lights-of-World
# Jogo Desenvolvido em C++ com GLFW, SDL e OpenGL.

# Devlog 28 - Criação do Projeto de Controle de Renderização;
Estava pensando na criação de um controlador de Render, pensei em usar o vector para esse trabalho, a ideia seria bem simples, na construção de um objeto eu diria qual cena eu estou utilizando, essa cena teria apenas os objetos que seriam desenhados, passando por todos os objetos eu executaria apenas a função de desenho de cada;

- Linha: std::vector<Draw> draws; // Passaria por todos os itens executando o draws[index].draw();

# Devlog 29 - Reconstrução (Declarações);
O Projeto estava sendo escrito com o puro windows.h, mas tinha problemas com o Cocoa do MacOSX,
então foi alternado para utilizar o GLFW, uma biblioteca bem famosa por sinal, ela me permite
escrever direto do Mac para o Windows e Compilar no proprio Mac, que é o meu programa operacional,
isso me gerou alguns problemas iniciais que já foram consertados:

- Criação da Janela Principal e seu devido Loop;
- Leitura de entradas do Mouse e do Teclado;
- Criação de um gerenciamento de desenhos;

As estruturas que não foram afetadas;

- Desenhos dos quadrados; Mas foi retirada a biblioteca SDL que fazia a importação de imagens;

As estruturas que foram melhoradas;

- Os Desenhos e Entradas de Handle por Objetos;
- Colisão com verificação de espaço;
- Desenho de Interseção de espaço em colisão;

# Devlog 30 - Reconstrução;
Tive que fazer uma coisa vergonhosa, tive que baixar um pacote para a leitura de imagens, pois minha preguiça
me impede de terminar minha biblioteca para leitura de imagens png, o que não deveria acontecer, pois ela 
estava pronta, mas acabei perdendo todos os meus arquivos e não havia mandado ela para o GitHub.

- Biblioteca :: lodepng ("http://lodev.org/lodepng/");
