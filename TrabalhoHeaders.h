#include <iostream>
#include <stdbool.h>
#include <locale.h>
using namespace std;

struct Usuario
{
    int matricula; // id
    string nome;
};

struct Autor
{
    int matricula; // id
    string nome;
};

struct Editora
{
    int matricula; // id
    string nome;
};

struct Assunto
{
    int matricula; // id
    string genero;
};

struct Livro
{
    int matricula; // id
    string Titulo;
    Editora editora;
    string isbn;
    Assunto genero;
    string numeroPaginas;
    Autor autor;
    bool emprestado;
    Usuario u1;
};

struct Revista
{
    int matricula; // id
    string Titulo;
    Autor autores[999];
    int numAutoresR = 0;
    string numeroPaginas;
    Assunto genero;
};

#include "lue.hpp"

LUE<Livro> livros[TAM];
int numLivros = 0;
LUE<Revista> revistas[TAM];
int numRevistas = 0;
LUE<Autor> autores[TAM];
int numAutores = 0;
LUE<Usuario> usuarios[TAM];
int numUsuarios = 0;
LUE<Editora> editoras[TAM];
int numEditoras = 0;
LUE<Assunto> assuntos[TAM];
int numAssuntos = 0;

void imprimirLivrosDisponiveis()
{
    cout << endl;
    for (int i = 0; i < TAM; i++)
    {
        string frase = (i + 1) + "? posi??o: ";
        mostrarLueLivrosDisponiveis(livros[i], frase);
        cout << endl
             << endl;
    }
    cout << endl
         << endl;
}

void inicializarListas()
{
    for (int i = 0; i < TAM; i++)
    {
        inicializarLUE(livros[i]);
        inicializarLUE(revistas[i]);
        inicializarLUE(autores[i]);
        inicializarLUE(usuarios[i]);
    }
}

int funcaoHash(int matricula)
{
    return matricula % TAM;
}

void menuCadastroLivro()
{
    Livro novoLivro;

    cout << "Cadastro do " << numLivros + 1 << "? livro: ";
    cout << endl
         << endl
         << "\tInsira a matricula do livro:";
    cin >> novoLivro.matricula;
    cout << endl
         << "\tInsira o título do livro: ";
    cin >> novoLivro.Titulo;
    cout << endl
         << "\tInsira a editora do livro: ";
    cin >> novoLivro.editora.nome;
    cout << endl
         << "\tInsira o isbn do livro: ";
    cin >> novoLivro.isbn;
    cout << endl
         << "\tInsira o genero do livro: ";
    cin >> novoLivro.genero.genero;
    cout << endl
         << "\tInsira o numero de paginas do livro: ";
    cin >> novoLivro.numeroPaginas;

    inserirFinalLUE(livros[funcaoHash(novoLivro.matricula)], novoLivro);
    numLivros++;

    cout << endl
         << endl
         << "\tLivro cadastrado com sucesso! " << endl
         << endl;
    system("pause");
}

void menuCadastroAutor()
{
    Autor novoAutor;

    cout << "Cadastro do " << numAutores + 1 << "? autor: ";
    cout << endl
         << endl
         << "Insira a matricula do autor:";
    cin >> novoAutor.matricula;
    cout << endl
         << "Insira o nome do autor: ";
    cin >> novoAutor.nome;

    inserirFinalLUE(autores[funcaoHash(novoAutor.matricula)], novoAutor);
    numAutores++;

    cout << endl
         << endl
         << "Autor cadastrado com sucesso! " << endl
         << endl;
    system("pause");
}

void menuCadastroEditora()
{
    Editora novaEditora;

    cout << "Cadastro da " << numEditoras + 1 << "? editora: ";
    cout << endl
         << endl
         << "Insira a matricula da editora:";
    cin >> novaEditora.matricula;
    cout << endl
         << "Insira o nome da editora: ";
    cin >> novaEditora.nome;

    inserirFinalLUE(editoras[funcaoHash(novaEditora.matricula)], novaEditora);
    numEditoras++;

    cout << endl
         << endl
         << "Editora cadastrada com sucesso! " << endl
         << endl;
    system("pause");
}

void menuCadastroAssunto()
{
    Assunto novoAssunto;

    cout << "Insira a matricula do assunto:";
    cin >> novoAssunto.matricula;
    cout << endl
         << "Insira o assunto: ";
    cin >> novoAssunto.genero;

    inserirFinalLUE(assuntos[funcaoHash(novoAssunto.matricula)], novoAssunto);
    numEditoras++;

    cout << endl
         << endl
         << "Assunto cadastrado com sucesso! " << endl
         << endl;
    system("pause");
}

void menuCadastroRevista()
{
    Revista novaRevista;

    cout << "Cadastro da " << numRevistas + 1 << "? revista: ";
    cout << endl
         << endl
         << "Insira a matricula da revista:";
    cin >> novaRevista.matricula;
    cout << endl
         << "Insira o t?tulo da Revista: ";
    cin >> novaRevista.Titulo;
    cout << endl
         << "Insira o numero de paginas da Revista: ";
    cin >> novaRevista.numeroPaginas;

    inserirFinalLUE(revistas[funcaoHash(novaRevista.matricula)], novaRevista);
    numRevistas++;

    cout << endl
         << endl
         << "revista cadastrada com sucesso! " << endl
         << endl;
    system("pause");
}

void menuCadastroUsuario()
{
    Usuario novousuario;

    cout << "Cadastro do " << numUsuarios + 1 << "? usuario: ";
    cout << endl
         << endl
         << "Insira a matricula do usuario:";
    cin >> novousuario.matricula;
    cout << endl
         << "Insira o nome do usuario: ";
    cin >> novousuario.nome;

    inserirFinalLUE(usuarios[funcaoHash(novousuario.matricula)], novousuario);
    numUsuarios++;

    cout << endl
         << endl
         << "usuario cadastrado com sucesso! " << endl
         << endl;
    system("pause");
}

void menuImprimirLivros()
{
    cout << "Livros: " << endl
         << endl;
    for (int i = 0; i < TAM; i++)
    {
        string frase = i + 1 + "? posi??o: ";
        mostrarLueLivros(livros[i], frase);
        cout << endl
             << endl;
    }
    cout << endl
         << endl;
}

void menuImprimirLivros(int matricula)
{
    int posicao = funcaoHash(matricula);
    mostrarLueLivros(livros[posicao], "livros da matr?cula selecionada: ");
    cout << endl
         << endl;
}

void menuImprimirAutores()
{
    cout << "Autores: " << endl
         << endl;
    for (int i = 0; i < TAM; i++)
    {
        string frase = i + 1 + "? posi??o: ";
        mostrarLueAutores(autores[i], frase);
        cout << endl
             << endl;
    }
    cout << endl
         << endl;
}

void menuImprimirAutores(int matricula)
{
    int posicao = funcaoHash(matricula);
    mostrarLueAutores(autores[posicao], "autores da matr?cula selecionada: ");
    cout << endl
         << endl;
}

void menuImprimirEditoras()
{
    cout << "Editoras: " << endl
         << endl;
    for (int i = 0; i < TAM; i++)
    {
        string frase = i + 1 + "? posi??o: ";
        mostrarLueEditora(editoras[i], frase);
        cout << endl
             << endl;
    }
    cout << endl
         << endl;
}

void menuImprimirEditoras(int matricula)
{
    int posicao = funcaoHash(matricula);
    mostrarLueEditora(editoras[posicao], "editoras da matr?cula selecionada: ");
    cout << endl
         << endl;
}

void menuImprimirAssuntos()
{
    cout << "Assuntos: " << endl
         << endl;
    for (int i = 0; i < TAM; i++)
    {
        string frase = i + 1 + "? posi??o: ";
        mostrarLueAssunto(assuntos[i], frase);
        cout << endl
             << endl;
    }
    cout << endl
         << endl;
}

void menuImprimirAssuntos(int matricula)
{
    int posicao = funcaoHash(matricula);
    mostrarLueAssunto(assuntos[posicao], "assuntos da matr?cula selecionada: ");
    cout << endl
         << endl;
}

void menuImprimirRevistas()
{
    cout << "Revistas: " << endl
         << endl;
    for (int i = 0; i < TAM; i++)
    {
        string frase = i + 1 + "? posi??o: ";
        mostrarLueRevistas(revistas[i], frase);
        cout << endl
             << endl;
    }
    cout << endl
         << endl;
}

void menuImprimirRevistas(int matricula)
{
    int posicao = funcaoHash(matricula);
    mostrarLueRevistas(revistas[posicao], "revistas da matr?cula selecionada: ");
    cout << endl
         << endl;
}

void menuImprimirUsuarios(int matricula)
{
    int posicao = funcaoHash(matricula);
    mostrarLueUsuarios(usuarios[posicao], "usu?rios da matr?cula selecionada: ");
    cout << endl
         << endl;
}

void menuImprimirUsuarios()
{
    cout << "Usu?rios: " << endl
         << endl;
    for (int i = 0; i < TAM; i++)
    {
        string frase = i + 1 + "? posi??o: ";
        mostrarLueUsuarios(usuarios[i], frase);
        cout << endl
             << endl;
    }
    cout << endl
         << endl;
}

void menuImprimirTodos()
{
    menuImprimirLivros();
    menuImprimirAutores();
    menuImprimirRevistas();
    menuImprimirUsuarios();
    cout << endl
         << endl;
}

bool menuAlterarLivro()
{
    int matricula;
    cout << endl
         << endl
         << "Por favor informe a matr?cula do livro que deseja alterar: ";
    cin >> matricula;

    // lista vazia
    if (livros[funcaoHash(matricula)].comeco == NULL)
    {
        cout << "n?o h? livros cadastrados para esse matr?cula, por favor tente novamente com uma matr?cula v?lida" << endl
             << endl;
        system("pause");
        return false;
    }

    // s? tem um livro cadastrado nessa lista
    if (livros[funcaoHash(matricula)].comeco == livros[funcaoHash(matricula)].fim)
    {
        string opcao;
        cout << "S? h? um livro nessa lista, o livro de t?tulo '" << livros[funcaoHash(matricula)].comeco->info.Titulo << "' deseja edit?-lo? (y/n)";
        cin >> opcao;

        while (opcao != "y" || opcao != "n")
        {
            cout << endl
                 << "Informe um valor v?lido para continuar: ";
            cin >> opcao;
        }

        if (opcao == "n")
        {
            cout << "Nenhum livro foi alterado." << endl
                 << endl;
            system("pause");
            return false;
        }

        else
        {
            retirarLueLivro(livros[funcaoHash(matricula)], livros[funcaoHash(matricula)].comeco->info.Titulo);
            menuCadastroLivro();
            return true;
        }
    }

    // mais de um livro cadastrado na lista
    else
    {
        string tituloRetirar;
        menuImprimirLivros(matricula);
        cout << "Insira o t?tulo do livro que deseja alterar: ";
        cin >> tituloRetirar;

        retirarLueLivro(livros[funcaoHash(matricula)], tituloRetirar);
        menuCadastroLivro();
        return true;
    }
}

bool menuAlterarAutor()
{
    int matricula;
    cout << endl
         << endl
         << "Por favor informe a matr?cula do autor que deseja alterar: ";
    cin >> matricula;

    // lista vazia
    if (autores[funcaoHash(matricula)].comeco == NULL)
    {
        cout << "n?o h? autores cadastrados para esse matr?cula, por favor tente novamente com uma matr?cula v?lida" << endl
             << endl;
        system("pause");
        return false;
    }

    // s? tem um autor cadastrado nessa lista
    if (autores[funcaoHash(matricula)].comeco == autores[funcaoHash(matricula)].fim)
    {
        string opcao;
        cout << "S? h? um autor nessa lista, o autor de nome '" << autores[funcaoHash(matricula)].comeco->info.nome << "' deseja edit?-lo? (y/n)";
        cin >> opcao;

        while (opcao != "y" || opcao != "n")
        {
            cout << endl
                 << "Informe um valor v?lido para continuar: ";
            cin >> opcao;
        }

        if (opcao == "n")
        {
            cout << "Nenhum autor foi alterado." << endl
                 << endl;
            system("pause");
            return false;
        }

        else
        {
            retirarLueAutor(autores[funcaoHash(matricula)], autores[funcaoHash(matricula)].comeco->info.nome);
            menuCadastroAutor();
            return true;
        }
    }

    // mais de um autor cadastrado na lista
    else
    {
        string autorRetirar;
        menuImprimirAutores(matricula);
        cout << "Insira o nome do autor que deseja alterar: ";
        cin >> autorRetirar;

        retirarLueAutor(autores[funcaoHash(matricula)], autorRetirar);
        menuCadastroAutor();
        return true;
    }
}

bool menuAlterarEditora()
{
    int matricula;
    cout << endl
         << endl
         << "Por favor informe a matr?cula da editora que deseja alterar: ";
    cin >> matricula;

    // lista vazia
    if (editoras[funcaoHash(matricula)].comeco == NULL)
    {
        cout << "n?o h? editoras cadastradas para esse matr?cula, por favor tente novamente com uma matr?cula v?lida" << endl
             << endl;
        system("pause");
        return false;
    }

    // s? tem uma editora cadastrada nessa lista
    if (editoras[funcaoHash(matricula)].comeco == editoras[funcaoHash(matricula)].fim)
    {
        string opcao;
        cout << "S? h? uma editora nessa lista, a editora " << editoras[funcaoHash(matricula)].comeco->info.nome << "' deseja edit?-la? (y/n)";
        cin >> opcao;

        while (opcao != "y" || opcao != "n")
        {
            cout << endl
                 << "Informe um valor v?lido para continuar: ";
            cin >> opcao;
        }

        if (opcao == "n")
        {
            cout << "Nenhuma editora foi alterada." << endl
                 << endl;
            system("pause");
            return false;
        }

        else
        {
            retirarLueEditora(editoras[funcaoHash(matricula)], editoras[funcaoHash(matricula)].comeco->info.nome);
            menuCadastroEditora();
            return true;
        }
    }

    // mais de uma editora cadastrada na lista
    else
    {
        string editoraRetirar;
        menuImprimirEditoras(matricula);
        cout << "Insira o nome da editora que deseja alterar: ";
        cin >> editoraRetirar;

        retirarLueEditora(editoras[funcaoHash(matricula)], editoraRetirar);
        menuCadastroEditora();
        return true;
    }
}

bool menuAlterarAssunto()
{
    int matricula;
    cout << endl
         << endl
         << "Por favor informe a matr?cula do assunto que deseja alterar: ";
    cin >> matricula;

    // lista vazia
    if (assuntos[funcaoHash(matricula)].comeco == NULL)
    {
        cout << "n?o h? assuntos cadastradas para esse matr?cula, por favor tente novamente com uma matr?cula v?lida" << endl
             << endl;
        system("pause");
        return false;
    }

    // s? tem um assunto cadastrada nessa lista
    if (assuntos[funcaoHash(matricula)].comeco == assuntos[funcaoHash(matricula)].fim)
    {
        string opcao;
        cout << "S? h? um assunto nessa lista, o assunto " << assuntos[funcaoHash(matricula)].comeco->info.genero << "' deseja edit?-la? (y/n)";
        cin >> opcao;

        while (opcao != "y" || opcao != "n")
        {
            cout << endl
                 << "Informe um valor v?lido para continuar: ";
            cin >> opcao;
        }

        if (opcao == "n")
        {
            cout << "Nenhum assunto foi alterado." << endl
                 << endl;
            system("pause");
            return false;
        }

        else
        {
            retirarLueAssunto(assuntos[funcaoHash(matricula)], assuntos[funcaoHash(matricula)].comeco->info.genero);
            menuCadastroAssunto();
            return true;
        }
    }

    // mais de uma editora cadastrada na lista
    else
    {
        string assuntoRetirar;
        menuImprimirAssuntos(matricula);
        cout << "Insira o nome do assunto que deseja alterar: ";
        cin >> assuntoRetirar;

        retirarLueAssunto(assuntos[funcaoHash(matricula)], assuntoRetirar);
        menuCadastroAssunto();
        return true;
    }
}

bool menuAlterarRevista()
{
    int matricula;
    cout << endl
         << endl
         << "Por favor informe a matr?cula da revista que deseja alterar: ";
    cin >> matricula;

    // lista vazia
    if (revistas[funcaoHash(matricula)].comeco == NULL)
    {
        cout << "n?o h? revistas cadastradas para esse matr?cula, por favor tente novamente com uma matr?cula v?lida" << endl
             << endl;
        system("pause");
        return false;
    }

    // s? tem um revista cadastrada nessa lista
    if (revistas[funcaoHash(matricula)].comeco == revistas[funcaoHash(matricula)].fim)
    {
        string opcao;
        cout << "S? h? um revista nessa lista, o revista de t?tulo '" << revistas[funcaoHash(matricula)].comeco->info.Titulo << "' deseja edit?-la? (y/n)";
        cin >> opcao;

        while (opcao != "y" || opcao != "n")
        {
            cout << endl
                 << "Informe um valor v?lida para continuar: ";
            cin >> opcao;
        }

        if (opcao == "n")
        {
            cout << "Nenhum revista foi alterada." << endl
                 << endl;
            system("pause");
            return false;
        }

        else
        {
            retirarLueRevista(revistas[funcaoHash(matricula)], revistas[funcaoHash(matricula)].comeco->info.Titulo);
            menuCadastroRevista();
            return true;
        }
    }

    // mais de um revista cadastrada na lista
    else
    {
        string tituloRetirar;
        menuImprimirRevistas(matricula);
        cout << "Insira o t?tulo da revista que deseja alterar: ";
        cin >> tituloRetirar;

        retirarLueRevista(revistas[funcaoHash(matricula)], tituloRetirar);
        menuCadastroRevista();
        return true;
    }
}

bool menuAlterarUsuario()
{
    int matricula;
    cout << endl
         << endl
         << "Por favor informe a matr?cula do usu?rio que deseja alterar: ";
    cin >> matricula;

    // lista vazia
    if (usuarios[funcaoHash(matricula)].comeco == NULL)
    {
        cout << "n?o h? usu?rios cadastrados para esse matr?cula, por favor tente novamente com uma matr?cula v?lida" << endl
             << endl;
        system("pause");
        return false;
    }

    // s? tem um usuario cadastrado nessa lista
    if (usuarios[funcaoHash(matricula)].comeco == usuarios[funcaoHash(matricula)].fim)
    {
        string opcao;
        cout << "S? h? um usu?rio nessa lista, o usuario '" << usuarios[funcaoHash(matricula)].comeco->info.nome << "' deseja edit?-lo? (y/n)";
        cin >> opcao;

        while (opcao != "y" || opcao != "n")
        {
            cout << endl
                 << "Informe um valor v?lido para continuar: ";
            cin >> opcao;
        }

        if (opcao == "n")
        {
            cout << "Nenhum usu?rio foi alterado." << endl
                 << endl;
            system("pause");
            return false;
        }

        else
        {
            retirarLueUsuario(usuarios[funcaoHash(matricula)], usuarios[funcaoHash(matricula)].comeco->info.nome);
            menuCadastroUsuario();
            return true;
        }
    }

    // mais de um usuario cadastrado na lista
    else
    {
        string usuarioRetirar;
        menuImprimirUsuarios(matricula);
        cout << "Insira o nome do usuario que deseja alterar: ";
        cin >> usuarioRetirar;

        retirarLueUsuario(usuarios[funcaoHash(matricula)], usuarioRetirar);
        menuCadastroUsuario();
        return true;
    }
}

void alugarLivro()
{
    int matricula, matriculaUsuario;
    string titulo;
    cout << "\nTodos os livros disponíveis serão listados a seguir:";
    imprimirLivrosDisponiveis();
    cout << "Insira a matricula do livro que deseja emprestar:";
    cin >> matricula;
    if (livros[funcaoHash(matricula)].comeco == NULL)
    {
        cout << "n?o h? livros cadastrados para esse matr?cula, por favor tente novamente com uma matr?cula v?lida" << endl
             << endl;
        system("pause");
    }

    // s? tem um livro cadastrado nessa lista
    if (livros[funcaoHash(matricula)].comeco == livros[funcaoHash(matricula)].fim)
    {
        char opcao;
        cout << "S? h? um livro nessa lista, o livro de t?tulo '" << livros[funcaoHash(matricula)].comeco->info.Titulo << "' deseja empresta-lo? (y/n)";
        cin >> opcao;

        switch (opcao)
        {
        case 'n':
            cout << "Nenhum livro foi emprestado." << endl
                 << endl;
            system("pause");
            break;
        case 'y':
            cout << "\nInforme a matricula do usuario que ira emprestar o livro: ";
            cin >> matriculaUsuario;
            if (usuarios[funcaoHash(matriculaUsuario)].comeco != NULL)
            {
                livros[funcaoHash(matricula)].comeco->info.emprestado = true;
                cout << "\nLivro emprestado com sucesso";
                system("pause");
            }
            else
            {
                cout << "Usuario inválido!";
                system("pause");
            }
            break;

        default:
            break;
        }
    }

    else
    {
        mostrarLueLivrosDisponiveis(livros[funcaoHash(matricula)], "Essa matrícula possui mais de um livro cadastrado: ");
        cout << "\nInforme a matricula do usuario que ira emprestar o livro: ";
        cin >> matriculaUsuario;
        cout << "\nInforme o titulo do livro que deseja emprestar: ";
        cin >> titulo;
        if (usuarios[funcaoHash(matriculaUsuario)].comeco != NULL)
        {
            alugarLivroLue(livros[funcaoHash(matricula)], titulo);
            cout << "\nLivro emprestado com sucesso";
        }
    }
}

void menuAlterar()
{
    system("cls");
    char opcao = ' ';
    string opcaoTexto;
    cout << "menu Alterar" << endl
         << endl
         << "Por favor insira o comando desejado: ";
    cout << endl
         << "1- Alterar Livro";
    cout << endl
         << "2- Alterar Autor";
    cout << endl
         << "3- Alterar Revista";
    cout << endl
         << "4- Alterar Usu?rio";
    cout << endl
         << "5- Alterar Editora";
    cout << endl
         << "6- Alterar Assunto";
    cout << endl
         << "Digite qualquer outra tecla para voltar ao menu principal";
    cin >> opcaoTexto;
    opcao = opcaoTexto.at(0);

    switch (opcao)
    {
    case '1':
        menuAlterarLivro();
        system("cls");
        break;
    case '2':
        menuAlterarAutor();
        system("cls");
        break;
    case '3':
        menuAlterarRevista();
        system("cls");
        break;
    case '4':
        menuAlterarUsuario();
        system("cls");
        break;
    case '5':
        menuAlterarEditora();
        system("cls");
        break;
    case '6':
        menuAlterarAssunto();
        system("cls");
        break;
    default:
        break;
    }
}

void menuCadastro()
{
    system("cls");
    char opcao = ' ';
    string opcaoTexto;
    cout << "menu Cadastro" << endl
         << endl
         << "Por favor insira o comando desejado: ";
    cout << endl
         << "1- Cadastrar Livro";
    cout << endl
         << "2- Cadastrar Autor";
    cout << endl
         << "3- Cadastrar Revista";
    cout << endl
         << "4- Cadastrar Usu?rio";
    cout << endl
         << "5- Cadastrar Editora";
    cout << endl
         << "6- Cadastrar Assunto";
    cout << endl
         << "Digite qualquer outra tecla para voltar ao menu principal";
    cin >> opcaoTexto;
    opcao = opcaoTexto.at(0);

    switch (opcao)
    {
    case '1':
        menuCadastroLivro();
        system("cls");
        break;
    case '2':
        menuCadastroAutor();
        system("cls");
        break;
    case '3':
        menuCadastroRevista();
        system("cls");
        break;
    case '4':
        menuCadastroUsuario();
        system("cls");
        break;
    case '5':
        menuCadastroEditora();
        system("cls");
        break;
    case '6':
        menuCadastroAssunto();
        system("cls");
        break;
    default:
        break;
    }
}

void menuImprimir()
{
    system("cls");
    char opcao = ' ';
    string opcaoTexto;
    cout << "menu Imprimir" << endl
         << endl
         << "Por favor insira o comando desejado: ";
    cout << endl
         << "1- Imprimir Livros";
    cout << endl
         << "2- Imprimir Autores";
    cout << endl
         << "3- Imprimir Revistas";
    cout << endl
         << "4- Imprimir Usu?rios";
    cout << endl
         << "5- Imprimir Editoras";
    cout << endl
         << "6- Imprimir Assuntos";
    cout << endl
         << "7- Imprimir Tudo";
    cout << endl
         << "Digite qualquer outra tecla para voltar ao menu principal";
    cin >> opcaoTexto;
    opcao = opcaoTexto.at(0);

    switch (opcao)
    {
    case '1':
        menuImprimirLivros();
        system("pause");
        system("cls");
        break;
    case '2':
        menuImprimirAutores();
        system("pause");
        system("cls");
        break;
    case '3':
        menuImprimirRevistas();
        system("pause");
        system("cls");
        break;
    case '4':
        menuImprimirUsuarios();
        system("pause");
        system("cls");
        break;
    case '5':
        menuImprimirEditoras();
        system("pause");
        system("cls");
        break;
    case '6':
        menuImprimirAssuntos();
        system("pause");
        system("cls");
        break;
    case '7':
        menuImprimirTodos();
        system("pause");
        system("cls");
        break;
    default:
        break;
    }
}

void menu()
{
    char opcao = ' ';
    string opcaoTexto;
    while (opcao != 's')
    {
        cout << "menu principal" << endl
             << endl
             << "Por favor insira o comando desejado: ";
        cout << endl
             << "1- Cadastrar";
        cout << endl
             << "2- Alterar";
        cout << endl
             << "3- Buscar";
        cout << endl
             << "4- Imprimir";
        cout << endl
             << "5- Emprestar Livro";
        cout << endl
             << "Digite qualquer outra tecla para encerrar o programa: ";
        cin >> opcaoTexto;
        opcao = opcaoTexto.at(0);

        switch (opcao)
        {
        case '1':
            menuCadastro();
            system("cls");
            break;
        case '2':
            menuAlterar();
            system("cls");
            break;
        case '3':
            // code
            break;
        case '4':
            menuImprimir();
            system("cls");
            break;
        case '5':
            alugarLivro();
            system("cls");
            break;
        default:
            opcao = 's';
            break;
        }
    }
}
