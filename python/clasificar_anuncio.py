import sys  # Importa sys para poder recibir datos enviados desde la consola o desde C++.

def convertir_a_minusculas(texto):  # Define una función para convertir el texto a minúsculas.
    return texto.lower()  # Devuelve el texto convertido a minúsculas.

def contar_palabras_sospechosas(texto):  # Define una función para contar palabras o frases sospechosas.
    palabras_sospechosas = [  # Crea una lista con palabras o frases relacionadas con riesgo.
        "gana dinero",  # Frase sospechosa relacionada con promesas económicas.
        "dinero rapido",  # Frase sospechosa por prometer dinero fácil.
        "dinero rápido",  # Frase sospechosa con tilde.
        "solo hoy",  # Frase que genera urgencia.
        "urgente",  # Palabra que indica presión.
        "cupos limitados",  # Frase usada para presionar al usuario.
        "deposita",  # Palabra relñacionada con pagos previos.
        "deposito",  # Palabra relacionada con pagos.
        "depósito",  # Palabra relacionada con pagos con tilde.
        "whatsapp",  # Canal informal usado en muchos anuncios sospechosos.
        "inversion",  # Palabra relacionada con entrega de dinero.
        "inversión",  # Palabra relacionada con entrega de dinero con tilde.
        "sin experiencia",  # Frase común en ofertas sospechosas.
        "link",  # Palabra relacionada con enlaces.
        "premio",  # Palabra usada en engaños o promociones falsas.
        "verifica tus datos",  # Frase relacionada con phishing.
        "cuenta bloqueada",  # Frase relacionada con suplantación o phishing.
        "oferta unica",  # Frase que busca presionar al usuario.
        "oferta única",  # Frase con tilde.
        "paga ahora"  # Frase relacionada con presión para pagar.
    ]  # Termina la lista de palabras sospechosas.

    contador = 0  # Inicializa el contador de coincidencias sospechosas en cero.

    for palabra in palabras_sospechosas:  # Recorre cada palabra o frase sospechosa.
        if palabra in texto:  # Verifica si la palabra sospechosa está dentro del texto.
            contador = contador + 1  # Aumenta el contador si encuentra una coincidencia.

    return contador  # Devuelve la cantidad de coincidencias encontradas.

def clasificar_riesgo(cantidad):  # Define una función para clasificar el riesgo según la cantidad de coincidencias.
    if cantidad >= 4:  # Verifica si existen muchas señales sospechosas.
        return "Alto"  # Devuelve riesgo alto.
    elif cantidad >= 2:  # Verifica si existen algunas señales sospechosas.
        return "Medio"  # Devuelve riesgo medio.
    else:  # Se ejecuta cuando hay pocas o ninguna señal sospechosa.
        return "Bajo"  # Devuelve riesgo bajo.

def obtener_categoria(texto):  # Define una función para determinar la categoría del posible riesgo.
    if "cuenta bloqueada" in texto or "verifica tus datos" in texto:  # Verifica señales relacionadas con robo de datos.
        return "Posible phishing o suplantación"  # Devuelve categoría de phishing.
    elif "deposita" in texto or "deposito" in texto or "depósito" in texto or "paga ahora" in texto:  # Verifica señales de pago previo.
        return "Solicitud de pago sospechosa"  # Devuelve categoría de pago sospechoso.
    elif "gana dinero" in texto or "dinero rapido" in texto or "dinero rápido" in texto:  # Verifica promesas económicas exageradas.
        return "Oferta económica sospechosa"  # Devuelve categoría de oferta sospechosa.
    elif "solo hoy" in texto or "urgente" in texto or "cupos limitados" in texto:  # Verifica señales de presión o urgencia.
        return "Mensaje de urgencia o presión"  # Devuelve categoría de urgencia.
    else:  # Se ejecuta cuando no se identifica una categoría clara.
        return "Sin categoría sospechosa clara"  # Devuelve una categoría general.

def obtener_intencion(texto):  # Define una función para identificar la intención del anuncio.
    if "urgente" in texto or "solo hoy" in texto or "cupos limitados" in texto:  # Verifica palabras de urgencia.
        return "Urgente / persuasiva"  # Devuelve intención urgente.
    elif "gana dinero" in texto or "sin experiencia" in texto:  # Verifica frases de promesa económica.
        return "Persuasiva / económica"  # Devuelve intención persuasiva.
    elif "verifica tus datos" in texto or "cuenta bloqueada" in texto:  # Verifica frases de alarma.
        return "Alarmante / engañosa"  # Devuelve intención alarmante.
    else:  # Se ejecuta cuando no hay intención clara.
        return "Neutral o poco sospechosa"  # Devuelve intención neutral.

def obtener_recomendacion(riesgo):  # Define una función para generar una recomendación según el riesgo.
    if riesgo == "Alto":  # Verifica si el riesgo es alto.
        return "No realizar pagos ni ingresar enlaces sin verificar la fuente."  # Devuelve recomendación fuerte.
    elif riesgo == "Medio":  # Verifica si el riesgo es medio.
        return "Revisar la fuente del anuncio antes de interactuar."  # Devuelve recomendación moderada.
    else:  # Se ejecuta cuando el riesgo es bajo.
        return "No se detectaron señales fuertes, pero se recomienda verificar la información."  # Devuelve recomendación básica.

def analizar_anuncio(descripcion):  # Define la función principal de análisis del anuncio.
    texto = convertir_a_minusculas(descripcion)  # Convierte la descripción a minúsculas.
    cantidad = contar_palabras_sospechosas(texto)  # Cuenta las palabras sospechosas encontradas.
    riesgo = clasificar_riesgo(cantidad)  # Clasifica el nivel de riesgo.
    categoria = obtener_categoria(texto)  # Obtiene la categoría del posible riesgo.
    intencion = obtener_intencion(texto)  # Obtiene la intención del anuncio.
    recomendacion = obtener_recomendacion(riesgo)  # Obtiene la recomendación preventiva.
    return categoria, intencion, riesgo, recomendacion  # Devuelve los resultados del análisis.

if __name__ == "__main__":  # Verifica si el archivo se está ejecutando directamente.
    if len(sys.argv) < 2:  # Verifica si no se recibió una descripción.
        print("Error|Error|Error|No se recibió texto para analizar.")  # Muestra un error en formato separado por barras.
    else:  # Se ejecuta cuando sí se recibió texto.
        descripcion = sys.argv[1]  # Guarda la descripción recibida desde la consola.
        categoria, intencion, riesgo, recomendacion = analizar_anuncio(descripcion)  # Analiza el anuncio y guarda los resultados.
        print(categoria + "|" + intencion + "|" + riesgo + "|" + recomendacion)  # Imprime los resultados separados por barras.