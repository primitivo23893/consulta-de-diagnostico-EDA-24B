#include <iostream>
#include <string>

using namespace std;

class QuimicaSanguinea{
private:
    static int nextFolio;
    int folio;
    string nombre;
    string fecha;
    string elemento;
    float cantidad;
    string* elementosRegistrados;
    float* cantidadesRegistradas;
    int numElementos;
public:
    QuimicaSanguinea() : folio(nextFolio++), elementosRegistrados(nullptr), cantidadesRegistradas(nullptr), numElementos(0) {}

    ~QuimicaSanguinea(){
        delete[] elementosRegistrados;
        delete[] cantidadesRegistradas;
    }

    void setNombre(){
        string nombreQS;
        cout << "Ingrese su nombre completo: ";
        getline(cin, nombreQS);
        nombre = nombreQS;
    }

    void setFecha(){
        string fechaQS;
        cout << "Ingrese la fecha del analisis (DD/MM/AAAA): ";
        getline(cin, fechaQS);
        fecha = fechaQS;
    }

    void setElemento(){
        string elementoQS;
        cout << "Ingrese el elemento: ";
        getline(cin, elementoQS);
        elemento = elementoQS;
    }

    void setCantidad(){
        float cantidadQS;
        cout << "Ingrese la cantidad del elemento: ";
        cin >> cantidadQS;
        cin.ignore();
        cantidad = cantidadQS;
    }

    void registrarElemento(){
        string* nuevosElementos = new string[numElementos + 1];
        float* nuevasCantidades = new float[numElementos + 1];

        for(int i = 0; i < numElementos; i++){
            nuevosElementos[i] = elementosRegistrados[i];
            nuevasCantidades[i] = cantidadesRegistradas[i];
        }

        nuevosElementos[numElementos] = elemento;
        nuevasCantidades[numElementos] = cantidad;

        delete[] elementosRegistrados;
        delete[] cantidadesRegistradas;

        elementosRegistrados = nuevosElementos;
        cantidadesRegistradas = nuevasCantidades;
        ++numElementos;
    }

    int getFolio() const{ return folio; }
    string getNombre() const{ return nombre; }
    string getFecha() const{ return fecha; }
    string getElemento() const{ return elemento; }
    float getCantidad() const{ return cantidad; }

    void mostrarElementosRegistrados() const {
        for (int i = 0; i < numElementos; ++i) {
            cout << "- Elemento: " << elementosRegistrados[i] << ", Cantidad: " << cantidadesRegistradas[i] << "." << endl;
        }
    }

    void guardarCancelar(){
        char opcionQS;
        cout << "Desea guardar el registro? (S/N): ";
        cin >> opcionQS;
        cin.ignore();
        if (opcionQS == 'S' || opcionQS == 's') {
            cout << "El registro se ha guardado exitosamente." << endl;
        } else if (opcionQS == 'N' || opcionQS == 'n') {
            cout << "Registro cancelado." << endl;
        } else {
            cout << "Opción invalida. El registro ha sido cancelado." << endl;
        }
    }
};

int QuimicaSanguinea::nextFolio = 1;

int main(){
    QuimicaSanguinea analisis;

    analisis.setNombre();
    analisis.setFecha();

    char continuarQS;
    do {
        analisis.setElemento();
        analisis.setCantidad();
        analisis.registrarElemento();

        cout << "Desea agregar otro elemento? (S/N): ";
        cin >> continuarQS;
        cin.ignore();
    } while (continuarQS == 'S' || continuarQS == 's');

    cout << endl;

    cout << "Datos del registro: " << endl;
    cout << "Folio: " << analisis.getFolio() << "." << endl;
    cout << "Nombre: " << analisis.getNombre() << "." << endl;
    cout << "Fecha: " << analisis.getFecha() << "." << endl;
    cout << "Elementos registrados: " << endl;
    analisis.mostrarElementosRegistrados();

    analisis.guardarCancelar();

    return 0;
}
