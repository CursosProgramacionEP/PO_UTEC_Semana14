# PO_UTEC – Semana 14 (Archivos)

Laboratorio de **Programación II (CS6003)**, Unidad 9: *Archivos*. Resumen de la teoría de la sesión 14A (**flujos de entrada y salida, modos de apertura, lectura y escritura, y sobrecarga del operador de inserción**), más los ejercicios de **templates** de la misma sesión, y de dónde se usa cada concepto en los ejercicios.

## Ejercicios del laboratorio

| Carpeta | Ejercicio | Concepto que usa |
|---------|-----------|------------------|
| `A1_ContadorVocales` | Cuenta las vocales de un archivo y genera `vocales.txt` | `ifstream` + `ofstream` en el mismo programa; lectura carácter por carácter |
| `A2_RegistroPersonas` | Graba n personas con fecha y hora de registro | escritura con formato; `getline` para textos con espacios |
| `A3_ListaOrdenada` | Lee una lista cuya primera línea es la cantidad, la ordena y busca | lectura con `>>`; cabecera de tamaño; búsqueda secuencial |
| `A4_CAleatorio` | Clase que carga, ordena por dos algoritmos, graba y busca | archivos dentro de una clase; InsertSort, QuickSort y búsqueda binaria |
| `A5_ContadorPalabras` | Clase `contador_palabras_t` que lee con `contador << "origen.txt"` | sobrecarga de `operator<<` como método |
| `B1_OrdenarGenerico` | Ordenar enteros y reales con herencia y con `template` | comparación entre polimorfismo de inclusión y paramétrico |
| `B2_InputGenerico` | Función genérica `input` al estilo Python | plantilla de función + especialización |
| `B3_RangoGenerico` | Clase genérica `rango` con `operator++` | plantilla de clase + sobrecarga de operadores |

Ejercicios adicionales: [EJERCICIOS_PROPUESTOS.md](EJERCICIOS_PROPUESTOS.md)

---

## 1. Qué es un archivo para el programa

Hasta ahora todo lo que leía un programa venía de `cin` y todo lo que escribía iba a `cout`. Un archivo es lo mismo con **otro extremo**: en vez del teclado y la pantalla, el disco.

```cpp
cin  >> dato;        // viene del teclado
archivo >> dato;     // viene del disco
```

La sintaxis es idéntica porque la idea es la misma: un **flujo**, una secuencia de datos que entra o sale. Por eso lo que ya saben de `cin` y `cout` sirve tal cual.

La diferencia es que un archivo hay que **abrirlo** antes y **cerrarlo** después, y que puede fallar al abrirse.

---

## 2. Las tres clases de `<fstream>`

| Clase | Dirección | Qué hace si el archivo no existe |
|---|---|---|
| `std::ifstream` | solo lectura | falla al abrir |
| `std::ofstream` | solo escritura | **lo crea** |
| `std::fstream` | lectura y escritura | depende del modo que se le indique |

```cpp
std::ifstream entrada("datos.txt");    // abre para leer
std::ofstream salida("salida.txt");    // crea o vacia, y abre para escribir
std::fstream  archivo("datos.txt", std::ios::in | std::ios::out);
```

`ifstream` y `ofstream` ya traen decidida su dirección; `fstream` no, por eso con `fstream` hay que indicar el modo.

**Cuidado con `ofstream`:** si el archivo ya existía, lo deja en cero. Para no perder lo que había, hay que abrirlo en modo `app`.

---

## 3. Los modos de apertura

Se pasan como segundo argumento y se combinan con `|`:

| Modo | Qué hace |
|---|---|
| `std::ios::in` | abrir para leer |
| `std::ios::out` | abrir para escribir |
| `std::ios::app` | escribir **siempre al final**, conservando lo que había |
| `std::ios::ate` | abrir y situarse al final, pero se puede escribir en cualquier parte |
| `std::ios::trunc` | vaciar el archivo al abrirlo |
| `std::ios::binary` | tratar el contenido como bytes y no como texto |

```cpp
std::ofstream bitacora("log.txt", std::ios::app);   // agrega, no reemplaza
```

Cada clase tiene su modo por defecto: `ifstream` abre con `in`, `ofstream` con `out | trunc`.

---

## 4. Abrir, comprobar y cerrar

```cpp
std::ifstream entrada(nombre);
if (!entrada) {
    std::cout << "No se pudo abrir " << nombre << std::endl;
    return;
}
...
entrada.close();
```

**La comprobación no es opcional.** Un archivo que no existe, un nombre mal escrito o un permiso faltante dan un flujo que no sirve, y seguir usándolo no produce ningún error visible: simplemente no se lee nada.

El `close()` lo hace también el destructor cuando el objeto sale de alcance. Se escribe igual, por claridad y para liberar el archivo antes si el programa sigue haciendo otras cosas.

---

## 5. Las tres formas de leer

| Forma | Hasta dónde lee | Cuándo usarla |
|---|---|---|
| `archivo >> dato` | hasta el primer espacio en blanco | números, códigos, palabras sueltas |
| `std::getline(archivo, linea)` | hasta el salto de línea | textos con espacios, líneas completas |
| `archivo.get(c)` | un solo carácter | análisis carácter por carácter |

Las tres devuelven **el propio flujo**, y un flujo usado como condición vale `false` cuando la operación no se pudo hacer. De ahí el patrón que se repite en todos los ejercicios:

```cpp
while (archivo >> valor) { ... }          // A3, A4, A5
while (std::getline(archivo, linea)) { ... }
while (archivo.get(c)) { ... }            // A1
```

Al llegar al final del archivo la lectura falla, la condición vale falso y el bucle termina **solo**. No hace falta preguntar por `eof()`; de hecho, preguntar por `eof()` antes de leer procesa un dato de más.

```cpp
while (!archivo.eof()) {      // <- el ultimo dato se procesa dos veces
    archivo >> valor;
}
```

### Qué devuelve `archivo >> texto` al final del archivo

Devuelve **el mismo flujo**, ya en estado de fallo. No devuelve un valor leído ni una cadena vacía: devuelve el objeto, y ese objeto, convertido a `bool`, vale `false`. Por eso puede ir directamente en la condición de un `while`.

---

## 6. Escribir

Igual que a pantalla, cambiando el destino:

```cpp
salida << "Vocal y frecuencia en el texto:" << std::endl;
salida << vocal << ": " << frecuencia << std::endl;
```

Para que el archivo quede legible se usa `<iomanip>`, como en [A2](A2_RegistroPersonas):

| Manipulador | Qué hace |
|---|---|
| `setw(n)` | ancho de la **siguiente** salida; se pierde después de usarse |
| `left` / `right` | alineación; se mantienen hasta cambiarlas |
| `fixed` + `setprecision(n)` | cantidad fija de decimales |

---

## 7. El error más común: dónde busca el archivo

`leer_lista("datos/numeros.txt")` a veces funciona y a veces no, en el mismo proyecto. El programa **no busca junto al código fuente**, sino en el **directorio de trabajo** con el que arrancó el ejecutable, y ese directorio depende del entorno y de la versión del IDE.

La solución que usan los ejercicios de este repositorio es dejar los datos disponibles en los dos sitios: la carpeta `datos/` vive junto al código y el `CMakeLists.txt` la copia al directorio de compilación en cada build.

```cmake
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/datos DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/datos DESTINATION ${CMAKE_BINARY_DIR})
```

Si aparece "No se pudo abrir el archivo", lo primero es comprobar desde **dónde** se está ejecutando, no si el archivo existe.

---

## 8. Leer un archivo con un operador propio

En [A5](A5_ContadorPalabras) la lectura no se pide con un método sino con un operador:

```cpp
contador_palabras_t contador;
contador << "origen.txt";
```

El objeto de la clase está a la **izquierda**, así que el operador se escribe como **método**:

```cpp
contador_palabras_t& contador_palabras_t::operator<<(const std::string& nombre_archivo);
```

Devolver `contador_palabras_t&` (una referencia al propio objeto, `return *this;`) permite encadenar varios archivos.

Es el caso contrario a `cout << objeto`: ahí el de la izquierda es el `ostream`, que no es de nuestra clase, y por eso ese operador tiene que ir como **función libre**.

| | `objeto << "archivo.txt"` | `cout << objeto` |
|---|---|---|
| Quién está a la izquierda | el objeto de la clase | un `ostream` |
| Dónde se escribe el operador | método de la clase | función libre |
| Qué devuelve para encadenar | referencia al objeto | referencia al `ostream` |

---

## 9. Templates: el repaso de los ejercicios B

Los tres ejercicios B usan **polimorfismo paramétrico**: escribir el código una vez y que sirva para cualquier tipo.

### Qué tipos de plantillas existen

| Tipo | Qué se parametriza | Dónde está |
|---|---|---|
| Plantilla de **función** | una función | `ordenar` en B1, `input` en B2 |
| Plantilla de **clase** | una clase completa | `rango` en B3 |

C++ moderno agrega plantillas de **alias** (`template <typename T> using lista = std::vector<T>;`) y de **variable**, menos frecuentes en el curso.

### `class` o `typename`

```cpp
template <typename T> ...
template <class T>    ...
```

En la lista de parámetros de una plantilla son **equivalentes**: no hay ninguna diferencia de comportamiento. `typename` se prefiere porque `T` puede ser cualquier tipo, también `int` o `double`, que no son clases. (`typename` sí tiene un segundo uso distinto, para indicar que un nombre dependiente es un tipo, pero eso es otra historia.)

### Ventajas y desventajas

| Ventajas | Desventajas |
|---|---|
| El algoritmo se escribe una sola vez | Los errores aparecen dentro de la plantilla, con mensajes largos |
| Sirve para tipos que no se habían previsto | Todo el código va en el `.h`: compilaciones más lentas |
| Se resuelve en compilación: no cuesta nada en ejecución | El binario crece, una copia por cada tipo usado |
| El compilador verifica los tipos | Los objetos de distinto tipo **no** se pueden guardar juntos en un vector |

Las plantillas van **completas en el `.h`**: el compilador necesita el cuerpo para generar cada versión.

---

## 10. Errores frecuentes

- No comprobar si el archivo se abrió. El programa sigue y no lee nada.
- Usar `while (!archivo.eof())`: el último dato se procesa dos veces.
- Abrir con `ofstream` un archivo que se quería conservar: queda vacío.
- Leer un nombre con espacios usando `>>`: se queda con la primera palabra.
- Usar `getline` justo después de un `>>` sin `cin.ignore()`: devuelve una cadena vacía.
- Buscar el archivo en la carpeta del código fuente en vez del directorio de trabajo.
- Hacer búsqueda binaria sobre un vector sin ordenar: responde mal, no da error.
- Separar una plantilla en `.h` y `.cpp`: errores de símbolos indefinidos al enlazar.
- Olvidar `static_cast<T>` al sumar en una plantilla con `char`.
- Confiar en la cabecera de tamaño de un archivo sin comprobar que los datos existen.

---

## 11. Miscelánea: preguntas frecuentes

| Pregunta | Respuesta corta |
|---|---|
| ¿Diferencia entre `ofstream` y `ifstream`? | Uno solo escribe, el otro solo lee |
| ¿Diferencia entre `ofstream` y `fstream`? | `fstream` puede las dos cosas, pero hay que indicarle el modo |
| ¿Cuáles son las formas de abrir un archivo? | `in`, `out`, `app`, `ate`, `trunc`, `binary`, combinables con `|` |
| ¿Qué devuelve `archivo >> texto` al final del archivo? | El flujo mismo, en estado de fallo: en una condición vale `false` |
| ¿Hay que llamar a `close()`? | El destructor lo hace, pero conviene escribirlo |
| ¿Se puede leer y escribir el mismo archivo a la vez? | Con `fstream` y los dos modos, pero conviene evitarlo en el curso |
| ¿Cómo agrego al final sin borrar? | Abriendo con `std::ios::app` |
| ¿Qué tipos de templates existen? | De función y de clase (además de alias y variable) |
| ¿`class` o `typename` en una plantilla? | Equivalentes; `typename` es más claro |
| ¿Por qué las plantillas van enteras en el `.h`? | El compilador necesita el cuerpo para generar cada versión |

---

## Compilación

Cada ejercicio tiene su propio `main.cpp` y sigue siendo un proyecto CMake independiente. También puede abrir el repositorio completo en CLion: el `CMakeLists.txt` de la raíz registra cada ejercicio como un ejecutable separado, sin combinar sus `main`.

Para configurar todo el repositorio y compilar solo un ejercicio:

```bash
cmake -S . -B build
cmake --build build --target A1_ContadorVocales
./build/A1_ContadorVocales
```

Reemplace `A1_ContadorVocales` por el target que quiera ejecutar: `A2_RegistroPersonas`, `A3_ListaOrdenada`, `A4_CAleatorio`, `A5_ContadorPalabras`, `B1_OrdenarGenerico`, `B2_InputGenerico` o `B3_RangoGenerico`. En CLion, seleccione ese target en la lista de configuraciones de ejecución antes de presionar ▶. No ejecute `main.cpp` directamente: eso compila solo ese archivo y produce errores de símbolos indefinidos porque no enlaza los demás `.cpp` del ejercicio.

Los ejercicios que leen archivos traen su carpeta `datos/`, que el build copia junto al ejecutable. Si al correr aparece "No se pudo abrir el archivo", vuelva a cargar el proyecto CMake para que la copia se rehaga.
