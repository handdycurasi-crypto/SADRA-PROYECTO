#include <iostream> // Permite usar cout y cin para mostrar y recibir datos.
#include <fstream> // Permite trabajar con archivos de texto.
#include <string> // Permite usar variables de tipo string.
#include <vector> // Permite usar vectores para guardar varios anuncios.
using namespace std; // Permite usar cout, cin, string y vector sin escribir std::.

class ResultadoAnalisis { // Define la clase que guardará el resultado del análisis.
private: // Indica que los atributos solo se pueden usar dentro de la clase.
    string categoria; // Guarda la categoría detectada del anuncio.
    string intencion; // Guarda la intención detectada del anuncio.
    string riesgo; // Guarda el nivel de riesgo del anuncio.
    string recomendacion; // Guarda la recomendación preventiva.

public: // Indica que los métodos se pueden usar desde fuera de la clase.
    ResultadoAnalisis() { // Constructor vacío de la clase ResultadoAnalisis.
        categoria = "No analizado"; // Inicializa la categoría con un valor por defecto.
        intencion = "No analizado"; // Inicializa la intención con un valor por defecto.
        riesgo = "No analizado"; // Inicializa el riesgo con un valor por defecto.
        recomendacion = "No analizado"; // Inicializa la recomendación con un valor por defecto.
    } // Termina el constructor vacío.

    ResultadoAnalisis(string c, string i, string r, string rec) { // Constructor con parámetros.
        categoria = c; // Asigna el valor recibido a la categoría.
        intencion = i; // Asigna el valor recibido a la intención.
        riesgo = r; // Asigna el valor recibido al riesgo.
        recomendacion = rec; // Asigna el valor recibido a la recomendación.
    } // Termina el constructor con parámetros.

    string getCategoria() { // Método para obtener la categoría.
        return categoria; // Devuelve la categoría.
    } // Termina el método getCategoria.

    string getIntencion() { // Método para obtener la intención.
        return intencion; // Devuelve la intención.
    } // Termina el método getIntencion.

    string getRiesgo() { // Método para obtener el riesgo.
        return riesgo; // Devuelve el riesgo.
    } // Termina el método getRiesgo.

    string getRecomendacion() { // Método para obtener la recomendación.
        return recomendacion; // Devuelve la recomendación.
    } // Termina el método getRecomendacion.
}; // Termina la clase ResultadoAnalisis.

class Anuncio { // Define la clase Anuncio.
private: // Indica que los atributos son privados.
    int id; // Guarda el identificador del anuncio.
    string rutaImagen; // Guarda la ruta de la imagen del anuncio.
    string descripcion; // Guarda la descripción escrita del anuncio.
    ResultadoAnalisis resultado; // Guarda el resultado del análisis del anuncio.

public: // Indica que los métodos son públicos.
    Anuncio(int idAnuncio, string ruta, string desc) { // Constructor de la clase Anuncio.
        id = idAnuncio; // Asigna el id recibido al atributo id.
        rutaImagen = ruta; // Asigna la ruta recibida al atributo rutaImagen.
        descripcion = desc; // Asigna la descripción recibida al atributo descripcion.
    } // Termina el constructor.

    int getId() { // Método para obtener el id.
        return id; // Devuelve el id.
    } // Termina el método getId.

    string getRutaImagen() { // Método para obtener la ruta de la imagen.
        return rutaImagen; // Devuelve la ruta de la imagen.
    } // Termina el método getRutaImagen.

    string getDescripcion() { // Método para obtener la descripción.
        return descripcion; // Devuelve la descripción.
    } // Termina el método getDescripcion.

    void setResultado(ResultadoAnalisis r) { // Método para asignar el resultado del análisis.
        resultado = r; // Guarda el resultado recibido.
    } // Termina el método setResultado.

    ResultadoAnalisis getResultado() { // Método para obtener el resultado.
        return resultado; // Devuelve el resultado del análisis.
    } // Termina el método getResultado.

    void mostrar() { // Método para mostrar los datos del anuncio.
        cout << "\nANUNCIO ANALIZADO" << endl; // Muestra un título.
        cout << "ID: " << id << endl; // Muestra el id del anuncio.
        cout << "Ruta de imagen: " << rutaImagen << endl; // Muestra la ruta de la imagen.
        cout << "Descripcion: " << descripcion << endl; // Muestra la descripción del anuncio.
        cout << "Categoria: " << resultado.getCategoria() << endl; // Muestra la categoría.
        cout << "Intencion: " << resultado.getIntencion() << endl; // Muestra la intención.
        cout << "Riesgo: " << resultado.getRiesgo() << endl; // Muestra el riesgo.
        cout << "Recomendacion: " << resultado.getRecomendacion() << endl; // Muestra la recomendación.
    } // Termina el método mostrar.
}; // Termina la clase Anuncio.

class Clasificador { // Define una clase base abstracta.
public: // Indica que el método será público.
    virtual ResultadoAnalisis analizar(string texto) = 0; // Método virtual puro para aplicar polimorfismo.
}; // Termina la clase Clasificador.

class ClasificadorReglas : public Clasificador { // Define una clase derivada que hereda de Clasificador.
public: // Indica que los métodos son públicos.
    ResultadoAnalisis analizar(string texto) override { // Sobrescribe el método analizar.
        int puntos = 0; // Crea un contador de señales sospechosas.

        if (texto.find("gana dinero") != string::npos) puntos++; // Suma un punto si encuentra la frase gana dinero.
        if (texto.find("dinero rapido") != string::npos) puntos++; // Suma un punto si encuentra dinero rapido.
        if (texto.find("dinero rápido") != string::npos) puntos++; // Suma un punto si encuentra dinero rápido con tilde.
        if (texto.find("solo por hoy") != string::npos) puntos++; // Suma un punto si encuentra solo por hoy.
        if (texto.find("urgente") != string::npos) puntos++; // Suma un punto si encuentra urgente.
        if (texto.find("deposita") != string::npos) puntos++; // Suma un punto si encuentra deposita.
        if (texto.find("whatsapp") != string::npos) puntos++; // Suma un punto si encuentra whatsapp.
        if (texto.find("inversion") != string::npos) puntos++; // Suma un punto si encuentra inversion.
        if (texto.find("inversión") != string::npos) puntos++; // Suma un punto si encuentra inversión con tilde.
        if (texto.find("verifica tus datos") != string::npos) puntos++; // Suma un punto si encuentra verifica tus datos.
        if (texto.find("cuenta bloqueada") != string::npos) puntos++; // Suma un punto si encuentra cuenta bloqueada.

        if (puntos >= 4) { // Verifica si el anuncio tiene muchas señales sospechosas.
            return ResultadoAnalisis("Oferta o pago sospechoso", "Urgente / persuasiva", "Alto", "No realizar pagos ni ingresar enlaces sin verificar la fuente."); // Devuelve riesgo alto.
        } // Termina el if de riesgo alto.
        else if (puntos >= 2) { // Verifica si el anuncio tiene algunas señales sospechosas.
            return ResultadoAnalisis("Mensaje posiblemente sospechoso", "Persuasiva", "Medio", "Revisar la fuente del anuncio antes de interactuar."); // Devuelve riesgo medio.
        } // Termina el else if de riesgo medio.
        else { // Se ejecuta si hay pocas señales sospechosas.
            return ResultadoAnalisis("Sin señales fuertes", "Neutral", "Bajo", "No se detectaron señales fuertes, pero se recomienda verificar la información."); // Devuelve riesgo bajo.
        } // Termina el else de riesgo bajo.
    } // Termina el método analizar.
}; // Termina la clase ClasificadorReglas.

class GestorAnuncios { // Define la clase que administra los anuncios.
private: // Indica que los atributos son privados.
    vector<Anuncio> anuncios; // Guarda una lista de anuncios.
    Clasificador* clasificador; // Guarda un puntero a la clase base Clasificador.

public: // Indica que los métodos son públicos.
    GestorAnuncios(Clasificador* c) { // Constructor que recibe un clasificador.
        clasificador = c; // Guarda el clasificador recibido.
    } // Termina el constructor.

    void registrarAnuncio() { // Método para registrar y analizar un anuncio.
        string ruta; // Variable para guardar la ruta de la imagen.
        string descripcion; // Variable para guardar la descripción.
        int id = anuncios.size() + 1; // Genera un id según la cantidad de anuncios registrados.

        cin.ignore(); // Limpia el salto de línea pendiente en la entrada.
        cout << "Ingrese la ruta de la imagen: "; // Pide la ruta de la imagen.
        getline(cin, ruta); // Lee la ruta de la imagen.
        cout << "Ingrese la descripcion del anuncio: "; // Pide la descripción.
        getline(cin, descripcion); // Lee la descripción completa.

        Anuncio anuncio(id, ruta, descripcion); // Crea un objeto Anuncio.
        ResultadoAnalisis resultado = clasificador->analizar(descripcion); // Analiza la descripción usando polimorfismo.
        anuncio.setResultado(resultado); // Asigna el resultado al anuncio.
        anuncios.push_back(anuncio); // Guarda el anuncio en el vector.
        guardarHistorial(anuncio); // Guarda el anuncio en el historial.
        anuncio.mostrar(); // Muestra el resultado del análisis.
    } // Termina el método registrarAnuncio.

    void mostrarHistorial() { // Método para mostrar todos los anuncios guardados en memoria.
        if (anuncios.empty()) { // Verifica si no hay anuncios registrados.
            cout << "No hay anuncios registrados." << endl; // Muestra un mensaje si no hay anuncios.
        } // Termina el if.
        else { // Se ejecuta si sí hay anuncios.
            for (int i = 0; i < anuncios.size(); i++) { // Recorre todos los anuncios registrados.
                anuncios[i].mostrar(); // Muestra cada anuncio.
            } // Termina el for.
        } // Termina el else.
    } // Termina el método mostrarHistorial.

    void guardarHistorial(Anuncio anuncio) { // Método para guardar un anuncio en un archivo.
        ofstream archivo("../resultados/historial_anuncios.txt", ios::app); // Abre el archivo historial en modo agregar.
        archivo << "ID: " << anuncio.getId() << endl; // Guarda el id.
        archivo << "Ruta de imagen: " << anuncio.getRutaImagen() << endl; // Guarda la ruta.
        archivo << "Descripcion: " << anuncio.getDescripcion() << endl; // Guarda la descripción.
        archivo << "Categoria: " << anuncio.getResultado().getCategoria() << endl; // Guarda la categoría.
        archivo << "Intencion: " << anuncio.getResultado().getIntencion() << endl; // Guarda la intención.
        archivo << "Riesgo: " << anuncio.getResultado().getRiesgo() << endl; // Guarda el riesgo.
        archivo << "Recomendacion: " << anuncio.getResultado().getRecomendacion() << endl; // Guarda la recomendación.
        archivo << "----------------------------------------" << endl; // Guarda una separación.
        archivo.close(); // Cierra el archivo.
    } // Termina el método guardarHistorial.
}; // Termina la clase GestorAnuncios.

int main() { // Función principal del programa.
    ClasificadorReglas clasificadorReglas; // Crea un clasificador por reglas.
    GestorAnuncios gestor(&clasificadorReglas); // Crea un gestor y le pasa el clasificador.
    int opcion; // Variable para guardar la opción del menú.

    do { // Inicia un ciclo para mostrar el menú varias veces.
        cout << "\nSADRA - Sistema de Analisis de Anuncios Digitales" << endl; // Muestra el nombre del sistema.
        cout << "1. Registrar y analizar anuncio" << endl; // Muestra la opción 1.
        cout << "2. Mostrar historial" << endl; // Muestra la opción 2.
        cout << "3. Salir" << endl; // Muestra la opción 3.
        cout << "Seleccione una opcion: "; // Pide una opción.
        cin >> opcion; // Lee la opción.

        if (opcion == 1) { // Verifica si el usuario eligió registrar anuncio.
            gestor.registrarAnuncio(); // Llama al método para registrar y analizar.
        } // Termina el if de opción 1.
        else if (opcion == 2) { // Verifica si el usuario eligió mostrar historial.
            gestor.mostrarHistorial(); // Muestra el historial.
        } // Termina el else if de opción 2.
        else if (opcion == 3) { // Verifica si el usuario eligió salir.
            cout << "Saliendo del sistema..." << endl; // Muestra mensaje de salida.
        } // Termina el else if de opción 3.
        else { // Se ejecuta si la opción no es válida.
            cout << "Opcion no valida." << endl; // Muestra mensaje de error.
        } // Termina el else.
    } while (opcion != 3); // Repite el menú mientras la opción sea diferente de 3.

    return 0; // Finaliza el programa correctamente.
} // Termina la función principal.
