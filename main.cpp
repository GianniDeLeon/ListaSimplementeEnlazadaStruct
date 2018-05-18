#include <iostream>

using namespace std;

typedef struct nodo
{
    int id;
    struct nodo *siguiente;
    nodo(int id) {
        this->id =id;
        siguiente = NULL;
    }
}nodo;

typedef struct lista
{
    int cantidad;
    nodo *inicio,*final;
    bool listaVacia();
    void agregar(int id);
    nodo *buscar(int id);
    void recorrer();
    bool eliminar(int id);
    lista() {
        cantidad = 0;
        inicio = final = NULL;
    }
}lista;

void eliminarDeLista(lista *list,int id);
void cantidadEnLista(lista *list);
int main()
{
    lista *list = new lista();
    cantidadEnLista(list);
    list->agregar(8);
    list->agregar(81);
    list->agregar(18);
    cantidadEnLista(list);
    eliminarDeLista(list,8);
    cantidadEnLista(list);
    list->agregar(90);
    list->agregar(99);
    eliminarDeLista(list,8);
    cantidadEnLista(list);
    list->recorrer();
    return 0;
}

void eliminarDeLista(lista *list,int id){
    if(list->eliminar(id)){
        cout<<"eliminacion exitosa"<<endl;
    }else{
        cout<<"eliminacion fallida"<<endl;
    }
}

void cantidadEnLista(lista *list){
    cout<<"Cantidad de objetos actual en la lista es de: "<<list->cantidad<<endl;
}

bool lista::listaVacia()
{
    return inicio == NULL;
}

void lista::agregar(int id)
{
    nodo *nuevo = new nodo(id);
    if(inicio){
        final->siguiente = nuevo;
        final = nuevo;
    }else{
        inicio = final = nuevo;
    }
    cantidad ++;
}

nodo *lista::buscar(int id)
{
    nodo *aux = inicio;
    while (aux) {
        if(aux->id == id){
            return aux;
        }
        aux = aux->siguiente;
    }
    return NULL;
}

void lista::recorrer()
{
    cout<<"##########INICIO DE LA LISTA##########"<<endl;
    nodo *aux = inicio;
    while (aux) {
        cout<<"id: "<<aux->id<<endl;
        aux = aux->siguiente;
    }
    cout<<"#########FIN DE LA LISTA##########"<<endl;
}

bool lista::eliminar(int id)
{
    nodo *aux = inicio;
    if(aux->id == id){
        inicio = aux->siguiente;
        delete(aux);
        cantidad--;
        return true;
    }else {
        while(aux){
            if(aux->siguiente){
                if(aux->siguiente->id == id){
                    aux->siguiente = aux->siguiente->siguiente;
                    cantidad--;
                    return true;
                }
            }
            aux = aux->siguiente;
        }
    }
    return false;
}
