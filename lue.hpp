
#include <iostream>
using namespace std;

template <typename T>
struct No
{
    T info;
    No *elo;
};

template <typename T>
struct LUE
{
    No<T> *comeco, *fim;
};

template <typename T>
void inicializarLUE(LUE<T> &lista)
{
    lista.comeco = NULL;
    lista.fim = NULL;
}

template <typename T>
void mostrarLUE(LUE<T> lista, string frase)
{
    cout << frase << ": ";
    if (lista.comeco == NULL)
        cout << " vazia";

    No<T> *aux = lista.comeco;
    while (aux != NULL)
    {
        cout << aux->info << "\n";
        aux = aux->elo;
    }
}

template <typename T>
void mostrarLueLivros(LUE<T> lista, string frase)
{
    cout << frase << ": ";
    if (lista.comeco == NULL)
        cout << " vazia";

    No<Livro> *aux = lista.comeco;
    while (aux != NULL)
    {
        cout << "matr�cula: " << aux->info.matricula << "\n";
        cout << "t�tulo: " << aux->info.Titulo << "\n";
        cout << "editora: " << aux->info.editora.nome << "\n";
        cout << "isbn: " << aux->info.isbn << "\n";
        cout << "g�nero: " << aux->info.genero.genero << "\n";
        cout << "n�mero de p�ginas: " << aux->info.numeroPaginas << "\n";
        aux = aux->elo;
    }
}

template <typename T>
void mostrarLueLivrosDisponiveis(LUE<T> lista, string frase)
{
    cout << frase << ": ";
    if (lista.comeco == NULL){
        cout << " vazia";
    }
    else{
    No<Livro> *aux = lista.comeco;
    while (aux != NULL)
    {
        if (aux->info.emprestado = false){
            cout << "t�tulo: " << aux->info.Titulo << "\n";
            aux = aux->elo;
        }
        
        else
        {
            aux = aux->elo;
        }
    }
    }
}

template <typename T>
void alugarLivroLue(LUE<T> lista, string titulo)
{

    if (lista.comeco == NULL)
        cout << "Lista vazia";

    No<Livro> *aux = lista.comeco;
    while (aux != NULL)
    {
        if (aux->info.Titulo == titulo)
        {
            aux->info.emprestado = true;
        }
        else
        {
            aux = aux->elo;
        }
    }
}

template <typename T>
void mostrarLueAutores(LUE<T> lista, string frase)
{
    cout << frase << ": ";
    if (lista.comeco == NULL)
        cout << " vazia";

    No<Autor> *aux = lista.comeco;
    while (aux != NULL)
    {
        cout << "matr�cula: " << aux->info.matricula << "\n";
        cout << "nome: " << aux->info.nome << "\n";
        aux = aux->elo;
    }
}

template <typename T>
void mostrarLueEditora(LUE<T> lista, string frase)
{
    cout << frase << ": ";
    if (lista.comeco == NULL)
        cout << " vazia";

    No<Editora> *aux = lista.comeco;
    while (aux != NULL)
    {
        cout << "matr�cula: " << aux->info.matricula << "\n";
        cout << "nome: " << aux->info.nome << "\n";
        aux = aux->elo;
    }
}

template <typename T>
void mostrarLueAssunto(LUE<T> lista, string frase)
{
    cout << frase << ": ";
    if (lista.comeco == NULL)
        cout << " vazia";

    No<Assunto> *aux = lista.comeco;
    while (aux != NULL)
    {
        cout << "matr�cula: " << aux->info.matricula << "\n";
        cout << "Genero: " << aux->info.genero << "\n";
        aux = aux->elo;
    }
}

template <typename T>
void mostrarLueUsuarios(LUE<T> lista, string frase)
{
    cout << frase << ": ";
    if (lista.comeco == NULL)
        cout << " vazia";

    No<Usuario> *aux = lista.comeco;
    while (aux != NULL)
    {
        cout << "matr�cula: " << aux->info.matricula << "\n";
        cout << "nome: " << aux->info.nome << "\n";
        aux = aux->elo;
    }
}

template <typename T>
void mostrarLueRevistas(LUE<T> lista, string frase)
{
    cout << frase << ": ";
    if (lista.comeco == NULL)
        cout << " vazia";

    No<Revista> *aux = lista.comeco;
    while (aux != NULL)
    {
        cout << "matr�cula: " << aux->info.matricula << "\n";
        cout << "t�tulo: " << aux->info.Titulo << "\n";
        cout << "n�mero de p�ginas: " << aux->info.numeroPaginas << "\n";
        aux = aux->elo;
    }
}

template <typename T>
bool inserirLUE(LUE<T> &lista, T valor)
{
    No<T> *novo = new No<T>;

    if (novo == NULL)
        return false;
    novo->info = valor;
    novo->elo = NULL;

    // Inserir em lista vazia
    if (lista.comeco == NULL)
    {
        lista.comeco = novo;
        lista.fim = novo;
        return true;
    }

    // Inserir no inicio da lista
    if (valor < lista.comeco->info)
    {
        novo->elo = lista.comeco;
        lista.comeco = novo;
        return true;
    }

    // Inserir no final da lista
    if (valor > lista.fim->info)
    {
        lista.fim->elo = novo;
        lista.fim = novo;
        return true;
    }

    // Inserir no meio da lista
    No<T> *aux = lista.comeco;
    while (aux->info < valor && aux->elo->info < valor)
        aux = aux->elo;
    novo->elo = aux->elo;
    aux->elo = novo;
    return true;
}

template <typename T>
bool inserirFinalLUE(LUE<T> &lista, T valor)
{
    No<T> *novo = new No<T>;

    if (novo == NULL)
        return false;
    novo->info = valor;
    novo->elo = NULL;

    // Inserir em lista vazia
    if (lista.comeco == NULL)
    {
        lista.comeco = novo;
        lista.fim = novo;
    }
    else
    {
        lista.fim->elo = novo;
        lista.fim = novo;
    }
    return true;
}

template <typename T>
No<T> *buscarLUE(LUE<T> lista, T valor)
{
    No<T> *aux = lista.comeco;
    while (aux != NULL)
    {
        if (aux->info == valor)
            return aux;
        aux = aux->elo;
    }
    return NULL;
}

template <typename T>
bool retirarLUE(LUE<T> &lista, string valor)
{
    No<T> *ant = NULL, *pos;

    pos = lista.comeco;
    while (pos != NULL && pos->info != valor)
    {
        ant = pos;
        pos = pos->elo;
    }
    if (pos == NULL)
        return false; // Lista vazia ou valor n�o encontrado

    // Retirada no inicio da lista
    if (pos == lista.comeco)
    {
        lista.comeco = lista.comeco->elo;
        if (pos == lista.fim)
            lista.fim = NULL;
    }
    else
    {
        ant->elo = pos->elo;
        if (pos == lista.fim)
            lista.fim = ant;
    }
    delete (pos);
    return true;
}

template <typename T>
bool retirarLueLivro(LUE<T> &lista, string valor)
{
    No<Livro> *ant = NULL, *pos;

    pos = lista.comeco;
    while (pos != NULL && pos->info.Titulo != valor)
    {
        ant = pos;
        pos = pos->elo;
    }
    if (pos == NULL)
        return false; // Lista vazia ou valor n�o encontrado

    // Retirada no inicio da lista
    if (pos == lista.comeco)
    {
        lista.comeco = lista.comeco->elo;
        if (pos == lista.fim)
            lista.fim = NULL;
    }
    else
    {
        ant->elo = pos->elo;
        if (pos == lista.fim)
            lista.fim = ant;
    }
    delete (pos);
    return true;
}

template <typename T>
bool retirarLueAutor(LUE<T> &lista, string valor)
{
    No<Autor> *ant = NULL, *pos;

    pos = lista.comeco;
    while (pos != NULL && pos->info.nome != valor)
    {
        ant = pos;
        pos = pos->elo;
    }
    if (pos == NULL)
        return false; // Lista vazia ou valor não encontrado

    // Retirada no inicio da lista
    if (pos == lista.comeco)
    {
        lista.comeco = lista.comeco->elo;
        if (pos == lista.fim)
            lista.fim = NULL;
    }
    else
    {
        ant->elo = pos->elo;
        if (pos == lista.fim)
            lista.fim = ant;
    }
    delete (pos);
    return true;
}

template <typename T>
bool retirarLueEditora(LUE<T> &lista, string valor)
{
    No<Editora> *ant = NULL, *pos;

    pos = lista.comeco;
    while (pos != NULL && pos->info.nome != valor)
    {
        ant = pos;
        pos = pos->elo;
    }
    if (pos == NULL)
        return false; // Lista vazia ou valor não encontrado

    // Retirada no inicio da lista
    if (pos == lista.comeco)
    {
        lista.comeco = lista.comeco->elo;
        if (pos == lista.fim)
            lista.fim = NULL;
    }
    else
    {
        ant->elo = pos->elo;
        if (pos == lista.fim)
            lista.fim = ant;
    }
    delete (pos);
    return true;
}

template <typename T>
bool retirarLueAssunto(LUE<T> &lista, string valor)
{
    No<Assunto> *ant = NULL, *pos;

    pos = lista.comeco;
    while (pos != NULL && pos->info.genero != valor)
    {
        ant = pos;
        pos = pos->elo;
    }
    if (pos == NULL)
        return false; // Lista vazia ou valor não encontrado

    // Retirada no inicio da lista
    if (pos == lista.comeco)
    {
        lista.comeco = lista.comeco->elo;
        if (pos == lista.fim)
            lista.fim = NULL;
    }
    else
    {
        ant->elo = pos->elo;
        if (pos == lista.fim)
            lista.fim = ant;
    }
    delete (pos);
    return true;
}

template <typename T>
bool retirarLueRevista(LUE<T> &lista, string valor)
{
    No<Revista> *ant = NULL, *pos;

    pos = lista.comeco;
    while (pos != NULL && pos->info.Titulo != valor)
    {
        ant = pos;
        pos = pos->elo;
    }
    if (pos == NULL)
        return false; // Lista vazia ou valor n�o encontrado

    // Retirada no inicio da lista
    if (pos == lista.comeco)
    {
        lista.comeco = lista.comeco->elo;
        if (pos == lista.fim)
            lista.fim = NULL;
    }
    else
    {
        ant->elo = pos->elo;
        if (pos == lista.fim)
            lista.fim = ant;
    }
    delete (pos);
    return true;
}

template <typename T>
bool retirarLueUsuario(LUE<T> &lista, string valor)
{
    No<Usuario> *ant = NULL, *pos;

    pos = lista.comeco;
    while (pos != NULL && pos->info.nome != valor)
    {
        ant = pos;
        pos = pos->elo;
    }
    if (pos == NULL)
        return false; // Lista vazia ou valor n�o encontrado

    // Retirada no inicio da lista
    if (pos == lista.comeco)
    {
        lista.comeco = lista.comeco->elo;
        if (pos == lista.fim)
            lista.fim = NULL;
    }
    else
    {
        ant->elo = pos->elo;
        if (pos == lista.fim)
            lista.fim = ant;
    }
    delete (pos);
    return true;
}
