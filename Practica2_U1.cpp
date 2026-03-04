
/************************
Instituto Tecnologico de Durango
Departamento Metal-Mecanica

Programacion Avanzada 7U
Fabian Quiñones Escarzaga 23040871
Ing. Mario Gerardo Hernandez Marines
2026-03-03
Practica 2 U1 Clase que utilize un Objeto que contenga argumentos
************************/

#include <iostream>
#include <cstring>
#include <math.h>
#include <vector>

using namespace std;
//Precio en centavos
class item {
    friend class order;
 protected:
    int m_precio = 0;
    char * m_name;
 public:
    item(int precio, const char* name) : m_precio(precio)  {
        m_name = new char[strlen(name)+1];
        strcpy(m_name,name);
    };
    const char * getName(){ return(m_name);};
    float  getPrice(){ return(m_precio/100.00f);};
};

class client{
  protected:
    char * m_name;
    char * m_addr;
  public:
    client(const char * name, const char * addr){
        m_name = new char[strlen(name)+1];
        strcpy(m_name, name);
        m_addr = new char[strlen(addr)+1];
        strcpy(m_addr, addr);
    };
};

class order : public client{
 private:
    std::vector<item*> m_items;
    int m_nettotal=0;
 public:
    order(const char * name, const char * addr) : client(name,addr){ };
    
    float addItem(item* newItem){
        m_items.push_back(newItem);
        m_nettotal += newItem->m_precio;
        return(m_nettotal/100.00f);
    };
    
    float removeItem(unsigned int idx){
        m_nettotal -= m_items[idx]->m_precio;
        m_items.erase(m_items.begin()+idx);
        return(m_nettotal/100.00f);
    };
    
    void printLabel(const char * trackingNumb){
        cout << trackingNumb << endl;
        cout << "Destinatario: \n \t" << m_name << endl << m_addr << endl;
        cout << "Manifiesto de Articulos:\n";
        for(item * articulo : m_items){
            cout << "\t" << articulo->m_name << " $"<< articulo-> m_precio/100.00f<< endl;
        };
        cout << "----------------------------------------\n" << "Total: $"<<m_nettotal;
    };
};

void print_items(vector<item*>* itemList){
    cout << "#ID | Nombre del Articulo | Precio"<<endl;
    for(int i=0; i<itemList->size(); i++){
        item* art = itemList->at(i);
      cout<< "\t "<< i << "| "<<art->getName() << " |$"<< art->getPrice()<< endl;
    };
}

int main(){
    vector<item*> availableItems = {
        new item(10000, "Calculadora CASIO fx-ms10"),
        new item(2000, "Libreta Cuadrícula Grande"),
        new item(100, "Borrador Pelikan"),
        new item(10000, "Pluma Pilot Blanca"),
        new item(5000, "Sacapuntas Hexagonal")
    };
    cout << "PORTAL DE ORDENES DE USUARIO: \n IDENTIFIQUESE:\n\tNombre Completo: ";
    char name[256];
    cin >> name;
    cout << "\n\tDireccion: ";
    char addr[256];
    cin >> addr;
    cout << "\x1b[2J\x1b[1;1H";//Limpia la Consola
    cout << "Articulos disponibles:\n";
    print_items(&availableItems);
    cout << "PORTAL DE USUARIO\n ORDEN #1 \n Cantidad de articulos desea agregar: ";
    order newOrder(name,addr);
    unsigned int qty=0;
    cin >> qty;
    for(int i = 0; i< qty; i++){
        print_items(&availableItems);
        cout << "Seleccione Producto: ";
        
        int choosedIdx =-1;
        cin >> choosedIdx;
        if(choosedIdx<0 || choosedIdx >= availableItems.size()){cout << "OPCION INVALIDA!!\n"; cin >> choosedIdx;}
        else{
            cout << "\x1b[2J\x1b[1;1H";//Limpia la Consola
            cout << "Total acomulado (SIN IVA) $0.2f: "<< newOrder.addItem(availableItems[choosedIdx])<<endl<<endl<<"----------------------------------------"<<endl;
        };
    };
    
        cout << endl;
        newOrder.printLabel("0xDEADBEEF");
}
