# Tarea 6

## Ejecución

Se recomienda compilar el arhivo denominado **create.sql** dentro de la carpeta **src** en **MySQL Workbench 8.0 CE**

## Parte Teórica


1. ¿Qué es una base de datos relacional y cuáles son sus características fundamentales?


    > Una base de datos relacional es una base de datos que almacena y  permite acceder a datos que están relacionados entre sí. Este tipo de base de datos organiza la información en tablas, cada tabla posee filas, donde cada fila representa un registro único identificado por una clave, además posee columnas que poseen atributos de los datos, de esta manera se logra crear relaciones entre distintos datos en la base de datos. Entre sus principales características destacan gestión de datos de almacenamiento físico sin que influya en acceso de datos mediante estructuras lógicas, presencia de un modelo relacional que permite organizar la base de datos en tablas, vistas e índices y por último, su modelo relacional permite mantener uniformidad de los datos almacenados.


2. ¿Cuál es la diferencia entre una clave primaria y una clave candidata en una base de datos relacional?
   
    > Una clave primaria es una clave candidata, esto quiere decir que posee un conjunto de atributos que permite identificar de manera única cada fila. Por otro lado, una clave candidata es una combinación de atributos que también puede identificar de manera única cada fila en una tabla, pero no ha sido elegida como la clave primaria.


3. ¿Qué son las claves foráneas y cómo se utilizan para mantener la integridad referencial en una base de datos?


    > Una clave foránea es una o más columnas en una tabla cuyos valores son los valores de la clave primaria de otra tabla. Una llave foránea permite mantener la integridad referencial del código al permitir que únicamente se inserten, actualicen y eliminen valores correspondientes a la clave primaria, además permite realizar acciones en cascada que por ejemplo permite eliminar o actualizar una fila de la tabla principal eliminando consecutivamente la información en la tabla secundaria.


4. ¿Qué es una transacción en el contexto de bases de datos y cuáles son las propiedades ACID que debe cumplir?


    > Una transacción es un conjunto de propiedades denominadas como atomicidad, consistencia, aislamiento y durabilidad, cuyo acrónimo en inglés es ACID, permitiendo la integridad de los datos a nivel de transacciones en bases de datos. El término atomicidad garantiza que una operación dentro de una transacción se complete o no, la consistencia permite llevar la base de datos de un estado válido a otro estado válido, manteniendo las reglas de la base de datos. El aislamiento permite ocultar transacciones a otras transacciones, hasta que las transacciones hayan sido concluidas, por último la durabilidad permite que una vez que una transacción haya concluido , los cambios efectuados sean de carácter permanente.


5. ¿Qué son las vistas (views) en sql y cuáles son los beneficios y limitaciones de su uso?


    > Las **views** son tablas virtuales que contienen filas y columnas, pero no se almacenan en el disco como lo hace una tabla. Generalmente una view realiza una query que devuelve un conjunto de datos de una o más tablas. Entre sus beneficios destaca la comodidad para visualizar los datos, permiten reutilización y mantenimiento del código, por otro lado, entre sus limitaciones destacan que no todas las vistas son capaces de actualizar, las vistas dependen de otras tablas por lo que si una de estas se modifica, las vistas se tornará inválidas, por último, las vistas no permiten realizar ciertas operaciones en sql de manera directa.


6. ¿Qué es la normalización en bases de datos y cuáles son las diferentes formas normales (normal forms)?


    > La normalización es el proceso de estructurar los datos dentro de una base de datos. Esto implica crear tablas y establecer relaciones entre ellas, siguiendo reglas que protegen los datos y hacen que la base de datos sea más eficiente al eliminar redundancias y dependencias incoherentes. Los datos redundantes ocupan espacio innecesario en el disco y complican el mantenimiento. Cuando los datos se encuentran en múltiples lugares, cualquier cambio debe realizarse de manera uniforme en todas esas ubicaciones.
     > + Primera forma normal: Indica que se deben eliminar los  los grupos de datos repetidos en las tablas individuales, se debe crear una tabla separada para cada conjunto de datos relacionados, además se debe asignar una clave principal para identificar cada conjunto de datos relacionados, por último se debe evitar utilizar múltiples campos en la misma tabla para almacenar datos similares.
    > + Segunda forma normal: Indica que se deben crear tablas separadas para los conjuntos de valores que se aplican a varios registros, se debe vincular estas tablas mediante una clave externa, además se debe asegurar de que los registros dependan únicamente de la clave principal de la tabla.
    > + Tercera forma normal: Indica que se deben eliminar los campos que no dependen de una clave, esto quiere decir que los valores de un registro que no dependan de una clave no deben estar en una tabla y si un grupo de campos puede aplicarse a más de un registro, se debe considerar mover esos campos a una nueva tabla.


    > Finalmente la cuarta y quinta formas normales existen pero rara vez se consideran en el diseño, la cuarta forma normal elimina dependencias multivaluadas, mientras que la quinta forma normal indica que las tablas descompuestas pueden vincularse con otras tablas sin perder información.


7. ¿Cómo funcionan los ́índices en sql y cuál es su impacto en el rendimiento de las consultas?


    > Los índices son estructuras de datos que permiten crear una tabla en una base de datos, ellos permiten mejorar la velocidad de consultas en la tabla, así como recuperar datos de una manera más veloz, todo esto permite incrementar el rendimiento en operaciones de consulta al reducir el tiempo.


8. ¿Qué es sql Injection y cuáles son las mejores prácticas para prevenir este tipo de ataque?


    > Es un ataque que permite ejecutar expresiones maliciosas de sql. Para proteger una base de datos de un ataque sql Injection se recomienda que el usuario no tenga acceso directo a las expresiones de consulta, para ello se deben usar parámetros en sql, que son similares a variables que se ejecutan en el query de una manera controlada.
    ```sql
    txtUserId = getRequestString("UserId");
    txtsql = "SELECT * FROM Users WHERE UserId = @0";
    db.Execute(txtsql,txtUserId);
    ```
    En el caso de que el usuario agregue:
    ```sql
    SELECT * FROM Users WHERE UserId = 105 OR 1=1;
    ```
    El usuario tendrá acceso al todo el contenido de la tabla **User**.


9. ¿Qué son los procedimientos almacenados (stored procedures) en sql y cómo pueden mejorar la eficiencia y seguridad de las operaciones de base de datos?


    > Los procedimientos almacenados en sql, es un código en sql que permite ser guardado, de esta manera el código puede ser reutilizado una y otra vez. Es decir si se tiene un query, este se puede guardar y luego se puede llamar para ejecutar, de manera adicional los procedimientos almacenados permiten parámetros. En fin mejoran la eficiencia ya que no hay que estar escribiendo código una y otra vez para ejecutar un query, esto permite reducir redundancias.


10. ¿Cómo se implementan las relaciones uno a uno, uno a muchos y muchos a muchos en una base de datos relacional y qué consideraciones se deben tener en cuenta en cada caso?


> Una relación uno a uno, es un vínculo entre la información de dos tablas,donde cada registro en cada tabla aparece únicamente una vez. Este tipo de relación ocurre cuando se tiene una tabla que contiene una lista de elementos, pero la información específica que se quiere almacenar sobre de ellos varía según el tipo. Para su implementación se debe utilizar una clave primaria compartida, es decir ambas tablas deben contar con una clave primaria y al menos una de ellas debe tener una clave foránea que se encuentra enlazada con la clave primaria de la otra tabla.


> Las relaciones uno a muchos se tiene un registro de una tabla se vincula a múltiples registros de otras tablas. Para su implementación se debe establecer una clave foránea en las múltiples tablas cuyos registros se vinculan a la clave primaria de la tabla principal.


>  Las relaciones uno a muchos ocurre cuando un registro de una tabla se asocia a varios registros de otra tabla. Para su implementación se puede hacer uso de una tabla intermedia que contiene las claves foráneas que contienen las referencias de las claves primarias de ambas tablas.


## Parte Práctica


Dentro de la carpeta **src** se encuentra el archivo **create.sql** que se analizará a continuación.


### Esquema de la Base de Datos


#### Tabla Cursos


```sql
-- Creo la tabla Cursos
CREATE TABLE IF NOT EXISTS Cursos (
    -- Identificador unico
    CursoID INT AUTO_INCREMENT PRIMARY KEY,
    -- Debe ser unico
    Sigla VARCHAR(10) UNIQUE,
    Nombre VARCHAR(100) NOT NULL,
    Semestre VARCHAR(100) NOT NULL,
    Creditos INT NOT NULL
);
```


 El código anterior muestra la estructura de la tabla **Cursos**, en ella se aprecia que
 **CursoID** es un identificador int único del curso que se autoincrementa (Clave primaria), **Sigla** posee código del curso único mediante una variable char (Clave candidata), **Nombre**  es una columna tipo char que alberga el nombre del curso (Clave candidata), **Semestre** es una columna tipo char que almacena el semestre en el cual se imparte el curso y por último **Creditos** es una columna de tipo int con el número de créditos del curso.


 #### Tabla Requisitos
 ```sql
 -- Creo la tabla Requisitos
CREATE TABLE IF NOT EXISTS Requisitos (
    -- Identificador unico
    RequisitoID INT AUTO_INCREMENT PRIMARY KEY,
    CursoID INT ,
    RequisitoCursoID INT ,
    FOREIGN KEY (CursoID) REFERENCES Cursos(CursoID) ON DELETE CASCADE,
    FOREIGN KEY (RequisitoCursoID) REFERENCES Cursos(CursoID) ON DELETE CASCADE
);
```
El código anterior muestra la estructura de la tabla **Requisitos**, en ella se tiene que **RequisitoID** es un identificador int único de la relación de requisito (Clave primaria), además **CursoID** es un identificador int del curso que tiene el requisito (Clave foránea, referencia a
Cursos) y por último **RequisitoCursoID** es un identificador int del curso que es el requisito del curso principal (Clave foránea, referencia a Cursos). Cabe destacar que la expresión **ON DELETE CASCADE** permite eliminar un curso y esto eliminará a su vez los requisitos asociados que tenia este curso.




#### Tabla Descripciones


```sql
-- Creo la tabla Descripciones
CREATE TABLE IF NOT EXISTS Descripciones (
    DescripcionID INT AUTO_INCREMENT PRIMARY KEY,
    CursoID INT NOT NULL,
    Descripcion TEXT NOT NULL,
    Dificultad ENUM('Facil', 'Media', 'Dificil') NOT NULL,
    FOREIGN KEY (CursoID) REFERENCES Cursos(CursoID) ON DELETE CASCADE
);
```
El código anterior muestra la estructura de la tabla **Descripciones**, en ella se aprecia que **DescripcionID** es un identificador int único de la descripción (Clave primaria),  **CursoID** es un identificador int del curso al que corresponde la descripción (Clave foránea, referencia a Cursos), además **Descripcion** es una string con la descripción detallada del curso y finalmente **Dificultad** es un enum que contiene los strings de nivel de dificultad del curso (Fácil, Media, Difícil). Cabe señalar que la expresión **ON DELETE CASCADE** permite eliminar un curso y su descripción asociada de manera simultánea.


De manera adicional, el campo **CursoID** en la tabla **Requisitos**  asegura la existencia de un valor en el campo **CursoID** de la tabla **Cursos**. Esto asegura que el curso al que se refiere **CursoID** en la tabla
**Requisitos** realmente existe. De manera análoga, el campo **RequisitoCursoID** en la tabla **Requisitos** debe coincidir con un valor existente en el campo **CursoID** de la tabla **Cursos**, esto permite que el curso al que se refiere **RequisitoCursoID** en la tabla Requisitos también exista.


### Tareas Específicas


#### 1. Creación de la base de datos y tablas:


```sql
-- 1. Creacion de la base de datos
-- Se crea base de datos en caso de no existir
CREATE DATABASE IF NOT EXISTS LicenciaturaDataBase;
-- Seleciono base de datos "LicenciaturaDataBase" para crear tablas.
USE LicenciaturaDataBase;


-- Creo la tabla Cursos
CREATE TABLE IF NOT EXISTS Cursos (
    -- Identificador unico
    CursoID INT AUTO_INCREMENT PRIMARY KEY,
    -- Debe ser unico
    Sigla VARCHAR(10) UNIQUE,
    Nombre VARCHAR(100) NOT NULL,
    Semestre VARCHAR(100) NOT NULL,
    Creditos INT NOT NULL
);


-- Creo la tabla Requisitos
CREATE TABLE IF NOT EXISTS Requisitos (
    -- Identificador unico
    RequisitoID INT AUTO_INCREMENT PRIMARY KEY,
    CursoID INT ,
    RequisitoCursoID INT ,
    FOREIGN KEY (CursoID) REFERENCES Cursos(CursoID) ON DELETE CASCADE,
    FOREIGN KEY (RequisitoCursoID) REFERENCES Cursos(CursoID) ON DELETE CASCADE
);


-- Creo la tabla Descripciones
CREATE TABLE IF NOT EXISTS Descripciones (
    DescripcionID INT AUTO_INCREMENT PRIMARY KEY,
    CursoID INT NOT NULL,
    Descripcion TEXT NOT NULL,
    Dificultad ENUM('Facil', 'Media', 'Dificil') NOT NULL,
    FOREIGN KEY (CursoID) REFERENCES Cursos(CursoID) ON DELETE CASCADE
);
```
Del código anterior se crea la base de datos **LicenciaturaDataBase** en ella se crean 3 tablas con los nombres de Cursos, Requisitos y Descripciones, cada una de ellas se definen las claves primarias para CursoID, RequisitoID y DescripcionID, además Sigla y Nombre en la tabla Cursos son únicos y por último se implementan claves foráneas en las tablas Requisitos y Descripciones, cabe destacar que el código detecta si la base de datos y sus tablas ya existen mediante la expresión **IF NOT EXISTS** para crear únicamente una instancia de esos elementos.


##### Evidencia
En al imagen de la Figura 1 evidencia la creación de la base de datos **LicenciaturaDataBase** con sus respectivas tablas, cabe destacar que estas tablas se encuentran vacías debido a que no se han insertado datos.


<div style="text-align: center;">
    <img src=".\images\creacionDB.PNG" alt="creacionDB" />
    <p><b>Figura 1:</b> Creación de la base de datos.</p>
</div>


#### 2. Inserción de datos (Create)


```sql
-- Crear (Create)
-- 2. Insercion de datos:
-- Inserte la información básica de los cursos y sus requisitos según el plan de estudios
-- proporcionado


INSERT INTO Cursos (Sigla, Nombre, Semestre, Creditos) VALUES
('IE-0579', 'Administración de sistemas', 'IX', 4),
('IE-0613', 'Electrónica industrial', 'IX', 4),
('IE-0599', 'Anteproyecto de TFG', 'IX', 4),
('IE-0679', 'Ciencia de datos para la est. y pron. de eventos', 'X', 4),
('IE-0541', 'Seguridad ocupacional', 'X', 4),
('TFG', 'Trabajo final de graduación', 'X', 4),
('IE-0117', 'Programación bajo plataformas abiertas', 'II', 3),
('IE-0217', 'Estructuras abstractas de datos y algoritmos para ingeniería', 'III', 3),
('IE-0321', 'Estructuras de computadores digitales I', 'III', 3),
('IE-0407', 'Electromagnetismo II', 'IV', 3),
('IE-0414', 'Control y simulación de convertidores electrónicos de potencia', 'V', 3),
('IE-0417', 'Diseño de software para ingeniería', 'V', 3),
('IE-0424', 'Laboratorio de circuitos digitales', 'V', 2),
('IE-0425', 'Redes de computadores', 'V', 3),
('IE-0435', 'Inteligencia artificial aplicada a la ingeniería eléctrica', 'V', 3),
('IE-0437', 'Fotónica', 'V', 3),
('IE-0439', 'Optoelectrónica', 'V', 3),
('IE-0445', 'Metrología en la ingeniería eléctrica', 'V', 3),
('IE-0447', 'Procesamiento digital de señales I', 'VI', 3),
('IE-0449', 'Visión por computador', 'VI', 3),
('IE-0505', 'Técnicas de optimización', 'VII', 3),
('IE-0509', 'Sistemas no lineales', 'VII', 3),
('IE-0514', 'Electrónica de potencia y control de máquinas', 'VIII', 3),
('IE-0521', 'Estructuras de computadoras digitales II', 'VII', 3),
('IE-0523', 'Circuitos digitales II', 'VII', 3),
('IE-0527', 'Ingeniería de comunicaciones', 'VIII', 3),
('IE-0528', 'Laboratorio de transmisión de datos', 'VIII', 2),
('IE-0529', 'Sistemas móviles en comunicaciones', 'VIII', 3),
('IE-0530', 'Laboratorio de telecomunicaciones', 'VIII', 2),
('IE-0537', 'Radiometría y fotometría', 'VIII', 3),
('IE-0539', 'Comunicaciones por fibra óptica', 'VIII', 3),
('IE-0545', 'Mediciones ópticas', 'VIII', 3),
('IE-0573', 'Diseño de sistemas de señales en edificaciones', 'VIII', 3),
('IE-0621', 'Verificación funcional del diseño de circuitos integrados', 'VIII', 3),
('IE-0623', 'Microprocesadores', 'VIII', 3),
('IE-0624', 'Laboratorio de microcontroladores', 'VIII', 2),
('IE-0627', 'Conmutación telefónica', 'VIII', 3),
('IE-0628', 'Laboratorio de microondas', 'VIII', 2),
('IE-0629', 'Sistemas de comunicación', 'VIII', 3),
('IE-0639', 'Circuitos integrados fotónicos', 'VIII', 3),
('IE-0724', 'Laboratorio de programación y microcomputadores', 'VIII', 2),
('IE-0727', 'Ingeniería de radio', 'VIII', 3),
('IE-0729', 'Redes telefónicas', 'VIII', 3),
('IE-0731', 'Sistemas en tiempo discreto', 'VII', 3),
('IE-0739', 'Redes ópticas en telecomunicaciones', 'VIII', 3),
('IE-0827', 'Sistemas de transmisión en telecomunicaciones', 'VIII', 3),
('IE-0829', 'Teoría de tráfico', 'VIII', 3),
('IE-1103', 'Temas especiales II en ingeniería', 'VIII', 3),
('IE-1115', 'Temas especiales II en telecomunicaciones', 'VIII', 3),
('IE-1116', 'Temas especiales II en electrónica', 'VIII', 3),
('IE-1119', 'Temas especiales II en sistemas digitales', 'VIII', 3),
-- Agrege dos cursos nuevos (que le gustar´ıa que impartieran en la carrera) y
-- complete la informaci´on requerida (sigla, nombre, semestre, cr´editos, descripcion y
-- dificultad).
('IE-1201', 'Robótica avanzada', 'VII', 3),
('IE-1202', 'Ciencia de datos aplicada', 'VII', 3),
('IE-1114', 'Temas especiales II en control', 'II', 3),
('IE-1118', 'Temas especiales II en control', 'II', 3),
('IE-1169', 'Temas especiales II en control', 'II', 3),
('CI-0202', 'PRINCIPIOS DE INFORMATICA', 'II', 3),
('IE-0323', 'CIRCUITOS DIGITALES I', 'II', 3),
('IE-0413', 'ELECTRONICA II', 'II', 3),
('IE-0281', 'TERMOFLUIDOS', 'III', 3),
('IE-0408', 'LABORATORIO ELÉCTRICO II ', 'III', 3),
('IE-0405', 'MODELOS PROBABILÍSTICOS DE SENALES Y SISTEMAS', 'III', 3),
('IE-0431', 'SISTEMAS DE CONTROL', 'IV', 3),
('IE-0615', 'MAQUINAS ELÉCTRICAS II', 'IV', 3),
('IE-0616', 'LABORATORIO DE MAQUINAS ELECTRICAS II', 'IV', 3),
('IE-0469', 'SISTEMAS DE POTENCIA I', 'IV', 3),
('IE-0471', 'DISENO ELÉCTRICO INDUSTRIAL I', 'IV', 3),
('IE-0499', 'PROYECTO ELECTRICO', 'IV', 3),
('IE-0479', 'INGENIERÍA ECONÓMICA', 'IV', 3),
('IE-0307', 'ELECTROMAGNETISMO I', 'IV', 3),
('IE-0513', 'ELECTRÓNICA III', 'IV', 3),
('IE-0315', 'MÁQUINAS ELÉCTRICAS I', 'IV', 3),
('IE-0501', 'RESPONSABILIDADES EN EL EJERCICIO PROFESION', 'IV', 3),
('IE-0432', 'Laboratorio de control automatico', 'IV', 3),
('IE-0433', 'Instrumentación industrial', 'IV', 3),
('IE-0308', 'LABORATORIO ELÉCTRICO I', 'IV', 3),
('IE-0457', 'CONSERVACION DE ENERGIA ELECTRICA', 'IV', 3),
('IE-0461', 'CENTRALES Y SUBESTACIONES', 'IV', 3),
('IE-0465', 'REDES DE DISTRIBUCIÓN Y TRANSMISIÓN', 'IV', 3),
('IE-0365', 'TRANSMISION DE POTENCIA', 'IV', 3),
('IE-0467', 'DISTRIBUCION ELECTRICA SUBTERRANEA', 'IV', 3),
('IE-0559', 'ENERGIA SOLAR FOTOVOLTAICA', 'IV', 3),
('IE-0563', 'DISENO DE SISTEMAS DE ILUMINACION', 'IV', 3),
('IE-0565', 'INGENIERIA DE ALTA TENSION', 'IV', 3),
('IE-0569', 'SISTEMAS DE POTENCIA II', 'IV', 3),
('IE-0619', 'CONTROL ELECTRICO INDUSTRIAL', 'IV', 3),
('IE-0633', 'AUTOMATIZACIÓN INDUSTRIAL', 'IV', 3),
('IE-0715', 'MAQUINAS ELECTRICAS III', 'IV', 3),
('IE-0571', 'DISENO ELECTRICO INDUSTRIAL II ', 'IV', 3),
('IE-0733', 'CONTROL DISTRIBUIDO', 'IV', 3),
('IE-0769', 'PROTECCIÓN DEL SISTEMA DE POTENCIA', 'IV', 3),
('IE-0869', 'SUBESTACIONES', 'IV', 3),
('IE-1117', 'TEMAS ESPECIALES II EN MAQUINAS ELECTRICAS', 'IV', 3),
('IE-0316', 'LABORATORIO DE MAQUINAS ELECTRICAS I', 'IV', 3);




-- Agregar los requisitos de los cursos
INSERT INTO Requisitos (CursoID, RequisitoCursoID) VALUES
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0579'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0479')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0613'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0315')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0613'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0413')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0679'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0405')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0679'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0579')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0541'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0501')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0117'), (SELECT CursoID FROM Cursos WHERE Sigla = 'CI-0202')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0217'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0117')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0414'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0431')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0417'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0217')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0432'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0431')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0433'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0431')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0435'), (SELECT CursoID FROM Cursos WHERE Sigla = 'CI-0202')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0445'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0307')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0445'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0308')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0447'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0413')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0447'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0413')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0457'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0315')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0457'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0316')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0461'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0615')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0461'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0616')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0465'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0365')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0467'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0307')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0467'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0315')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0467'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0316')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0469'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0365')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0469'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0615')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0469'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0616')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0471'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0315')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0471'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0316')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0509'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0431')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0514'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0413')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0514'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0315')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0514'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0316')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0545'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0308')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0545'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0307')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0559'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0315')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0559'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0316')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0563'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0471')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0565'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0469')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0569'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0469')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0571'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0471')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0573'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0471')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0619'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0323')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0619'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0323')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0621'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0523')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0633'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0323')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0715'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0615')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0731'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0431')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0733'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0431')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0769'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0365')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0869'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0365')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-1103'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0499')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-1114'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0431')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-1114'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0431')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-1117'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0615')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-1118'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0365')),
 ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-1169'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0365'));


-- Agregar los descripcion cursos de los cursos
INSERT INTO Descripciones (CursoID, Descripcion, Dificultad) VALUES
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0579'), 'Curso sobre administración de sistemas informáticos y de redes.', 'Media'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0613'), 'Estudio de electrónica aplicada a entornos industriales.', 'Dificil'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0599'), 'Preparación del anteproyecto de Trabajo Final de Graduación.', 'Facil'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0679'), 'Aplicación de la ciencia de datos para la estimación y pronóstico de eventos.', 'Dificil'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0541'), 'Curso sobre prácticas y normas de seguridad ocupacional.', 'Media'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'TFG'), 'Trabajo Final de Graduación requerido para la obtención del título.', 'Dificil'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0117'), 'Introducción a la programación en plataformas abiertas.', 'Facil'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0217'), 'Estructuras abstractas de datos y algoritmos para ingeniería.', 'Media'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0321'), 'Primer curso de estructuras de computadores digitales.', 'Media'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0407'), 'Curso avanzado de electromagnetismo.', 'Dificil'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0414'), 'Control y simulación de convertidores electrónicos de potencia.', 'Dificil'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0417'), 'Diseño de software especializado para ingeniería.', 'Media'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0424'), 'Laboratorio práctico sobre circuitos digitales.', 'Facil'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0425'), 'Fundamentos y técnicas de redes de computadores.', 'Media'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0435'), 'Aplicación de inteligencia artificial en la ingeniería eléctrica.', 'Dificil'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0437'), 'Curso sobre tecnologías fotónicas.', 'Dificil'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0439'), 'Estudio de la optoelectrónica y sus aplicaciones.', 'Media'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0445'), 'Introducción a la metrología en ingeniería eléctrica.', 'Media'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0447'), 'Curso básico sobre procesamiento digital de señales.', 'Media'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0449'), 'Técnicas y aplicaciones de visión por computador.', 'Dificil'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0505'), 'Curso sobre técnicas avanzadas de optimización.', 'Media'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0509'), 'Estudio de sistemas no lineales en ingeniería.', 'Dificil'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0514'), 'Electrónica de potencia y control de máquinas eléctricas.', 'Dificil'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0521'), 'Segundo curso de estructuras de computadores digitales.', 'Media'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0523'), 'Curso avanzado sobre circuitos digitales.', 'Media'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0527'), 'Introducción a la ingeniería de comunicaciones.', 'Media'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0528'), 'Laboratorio práctico sobre transmisión de datos.', 'Facil'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0529'), 'Estudio de sistemas de comunicaciones móviles.', 'Media'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0530'), 'Laboratorio avanzado sobre telecomunicaciones.', 'Facil'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0537'), 'Curso sobre radiometría y fotometría.', 'Media'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0539'), 'Comunicaciones por fibra óptica y sus aplicaciones.', 'Dificil'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0545'), 'Técnicas de mediciones ópticas.', 'Media'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0573'), 'Diseño de sistemas de señales para edificaciones.', 'Media'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0621'), 'Verificación funcional de diseño de circuitos integrados.', 'Dificil'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0623'), 'Introducción a los microprocesadores.', 'Media'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0624'), 'Laboratorio práctico sobre microcontroladores.', 'Facil'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0627'), 'Estudio de la conmutación telefónica.', 'Media'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0628'), 'Laboratorio sobre tecnologías de microondas.', 'Facil'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0629'), 'Sistemas de comunicación avanzados.', 'Dificil'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0639'), 'Circuitos integrados fotónicos y sus aplicaciones.', 'Dificil'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0724'), 'Laboratorio sobre programación y microcomputadores.', 'Facil'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0727'), 'Estudio avanzado de ingeniería de radio.', 'Dificil'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0729'), 'Redes telefónicas y sus aplicaciones.', 'Media'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0731'), 'Sistemas en tiempo discreto y su análisis.', 'Media'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0739'), 'Redes ópticas para telecomunicaciones.', 'Dificil'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0827'), 'Sistemas de transmisión en telecomunicaciones.', 'Media'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0829'), 'Teoría de tráfico y su aplicación en telecomunicaciones.', 'Media'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-1103'), 'Temas especiales en ingeniería avanzada.', 'Dificil'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-1115'), 'Temas especiales en telecomunicaciones avanzadas.', 'Dificil'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-1116'), 'Temas especiales en electrónica avanzada.', 'Dificil'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-1119'), 'Temas especiales en sistemas digitales avanzados.', 'Dificil'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-1201'), 'Curso avanzado sobre robótica.', 'Dificil'),
((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-1202'), 'Aplicación de la ciencia de datos en ingeniería.', 'Media');
```
Del código anterior se inserta la información de los cursos, sus requisitos  y descripciones según el plan de estudios proporcionado, además se agregan dos cursos nuevos  y su información requerida estos dos cursos tiene el nombre de **'Robótica avanzada** y **Ciencia de datos aplicada**.


##### Evidencia


En la imagen de la Figura 2 se muestra un extracto de los cursos agregados al plan de estudios de licenciatura en ellos se ingresan los cursos propiamente de licenciatura cuyo semestre es **IX** Y **X** y los cursos optativos denominados por semestres menores a **IX**, en total se insertan 94 cursos.


<div style="text-align: center;">
    <img src=".\images\xxx.PNG" alt="xxx" />
    <p><b>Figura 2:</b> Extracto contenido tabla cursos.</p>
</div>


En la imagen de la Figura 3 se muestra un extracto de las descripciones de los cursos.


<div style="text-align: center;">
    <img src=".\images\insert_descripciones.PNG" alt="insert_descripciones" />
    <p><b>Figura 3:</b> Extracto contenido tabla descripciones.</p>
</div>


En la imagen de la Figura 4 se muestra un extracto de los requisitos de los cursos de los cursos.


<div style="text-align: center;">
    <img src=".\images\insert_requisitos.PNG" alt="insert_requisitos" />
    <p><b>Figura 4:</b> Extracto contenido tabla requisitos.</p>
</div>


Finalmente se agregan 2 cursos inventados, tal y como se muestra en la imagen de la Figura 5 y sus descripciones en la Figura 6 ver los índice 52 y 53.
<div style="text-align: center;">
    <img src=".\images\inventado1.PNG" alt="inventado1" />
    <p><b>Figura 5:</b> Cursos inventados Robótica avanzada y Ciencia de datos aplicada.</p>
</div>
<div style="text-align: center;">
    <img src=".\images\inventado1.PNG" alt="inventado1" />
    <p><b>Figura 6:</b> Cursos inventados descripciones.</p>
</div>


#### 3. Consultas (Read):


A continuación se muestra el código para listar todos los cursos con su sigla, nombre, semestre,
créditos, descripción y dificultad:


```sql
-- Realiza consultas para listar todos los cursos con su sigla, nombre, semestre,
-- creditos, descripcion y dificultad
SELECT
    c.Sigla,
    c.Nombre,
    c.Semestre,
    c.Creditos,
    d.Descripcion,
    d.Dificultad
FROM
    Cursos c
INNER JOIN
    Descripciones d ON c.CursoID = d.CursoID;
```
El código anterior accede a las tablas de Cursos y Descripciones mediante un álias de **c** para cursos y **d** para descripción, luego el mando **INNER JOIN** une las dos tablas mediante una condición de igualdad que es el número de identificación del curso **CursoID**.


<div style="text-align: center;">
    <img src=".\images\lectura_1.PNG" alt="lectura_1" />
    <p><b>Figura 7:</b> Extracto contenido de la  consulta para listar todos los cursos con su sigla, nombre, semestre, créditos, descripción y dificultad.</p>
</div>


En la imagen de la Figura 7 se observa un extracto del contenido de la consulta, en ella se logra apreciar las siglas, nombres, semestres, cantidad de créditos, descripciones y dificultad de cada curso.


A continuación se realiza la consulta para listar todos los requisitos de un curso específico, el curso selecciona es **electrónica industrial**.


```sql
-- Realiza consultas para listar todos los requisitos de un curso especifico.
-- Consultar todos los requisitos de un curso
SELECT CursoID, RequisitoCursoID FROM Requisitos WHERE CursoID = (SELECT CursoID FROM Cursos WHERE Nombre = 'Electrónica industrial');
```


El resultado de la consulta anterior da como resultado:


<div style="text-align: center;">
    <img src=".\images\lectura_2.PNG" alt="lectura_2" />
    <p><b>Figura 8:</b> Contenido de la  consulta para listar todos los requisitos de un curso específico.</p>
</div>


En la imagen de la Figura 8, se muestran los requisitos del curso **Electrónica industrial**, donde se obtiene que son los cursos cuyos números de identificación son 72 y 59, cuyos nombres son **MÁQUINAS ELÉCTRICAS I** y **ELECTRONICA II** de manera respectiva.


Posteriormente se realiza la consulta para listar los cursos que no son optativos, a la hora de elaborar el plan se establece que estos cursos son todos aquellos que se imparte en los semestres **IX** y **X**.


```sql
SELECT * FROM Cursos WHERE Semestre = 'IX' OR  Semestre = 'X';
```
Del código anterior se selecciona toda la información de la tabla cursos que cumple que su semestre sea  **IX** o **X**, dando como resultado la imagen de la Figura 9.


<div style="text-align: center;">
    <img src=".\images\lectura_3.PNG" alt="lectura_3" />
    <p><b>Figura 9:</b>  Consulta para listar los cursos que no son optativos.</p>
</div>


A continuación se realiza la consulta de todos los cursos pertenecientes al semestre X.


```sql
SELECT * FROM Cursos WHERE Semestre = 'X';
```
Del código anterior se seleccionan todas las columnas de la tabla Cursos cuyo semestre es igual a **X**, dando como resultado la imagen de la Figura 10.


<div style="text-align: center;">
    <img src=".\images\lectura_4.PNG" alt="lectura_4" />
    <p><b>Figura 10:</b>  Consulta los cursos que pertenecen al semestre X.</p>
</div>


#### 4. Actualizaciones (Update):


Se pide actualizar el nombre y créditos de 3 de los cursos optativos, para ello se eligen los cursos cuyo número de identificación es 7,8 y 9, es decir los cursos **Programación bajo plataformas abiertas**, **Estructuras abstractas de datos y algoritmos para ingeniería** y **Estructuras de computadores digitales I**, para ello se implementa el siguiente código:


```sql
UPDATE Cursos SET Nombre = 'Nombre curso editado', Creditos= 1 WHERE CursoID = 7;
UPDATE Cursos SET Nombre = 'Nombre curso editado', Creditos= 1 WHERE CursoID = 8;
UPDATE Cursos SET Nombre = 'Nombre curso editado', Creditos= 1 WHERE CursoID = 9;
```


Adicionalmente se pide actualizar la descripción y dificultad de 3 cursos, para ello se escogen los mismo 3 cursos mencionados con anterioridad, para ello se utiliza el siguiente código:


```sql
UPDATE Descripciones SET Descripcion = "Descripcion curso editada", Dificultad = "Dificil"  WHERE CursoID = 7;
UPDATE Descripciones SET Descripcion = "Descripcion curso editada", Dificultad = "Dificil"  WHERE CursoID = 8;
UPDATE Descripciones SET Descripcion = "Descripcion curso editada", Dificultad = "Dificil"  WHERE CursoID = 9;
```


Finalmente se imprime el resultado mediante el siguiente comando:
```sql
SELECT
    c.CursoID,
    c.Sigla,
    c.Nombre,
    c.Semestre,
    c.Creditos,
    d.Descripcion,
    d.Dificultad
FROM
    Cursos c
INNER JOIN
    Descripciones d ON c.CursoID = d.CursoID;
```
Del comando anterior se obtiene el resultado visto en la imagen de la Figura 11.


<div style="text-align: center;">
    <img src=".\images\update.PNG" alt="update" />
    <p><b>Figura 11:</b>  Actualización del nombre y créditos de 3 de los cursos optativos y a la descripción y dificultad</p>
</div>


De la imagen de la Figura 11 se observa que se han actualizado los cursos cuyos id son 7,8 y 9, en la imagen de la Figura 2 se observa su contenido anterior.


#### 5. Eliminaciones  (Delete):


Se pide eliminar un curso inventado y 2 cursos del plan y asegurando eliminar también sus descripciones asociadas, para ello se seleccionan los cursos IE-1201 **Robótica avanzada**, IE-0579 **Administración de sistemas** y IE-0613 **Electrónica industrial**, para ello se utiliza el código que se muestra a continuación:


```sql
-- Eliminar un curso inventado y 2 cursos del plan y sus descripciones asociadas.
DELETE FROM Cursos WHERE Sigla IN ('IE-1201', 'IE-0579', 'IE-0613');
SELECT Sigla, Nombre FROM Cursos WHERE Sigla IN ('IE-1201', 'IE-0579', 'IE-0613');
SELECT * FROM Descripciones WHERE CursoID IN ((SELECT CursoID FROM Cursos WHERE Sigla = 'IE-1201'), (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0579'),   (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0613'));
```
El código anterior se encarga de eliminar los cursos mencionados así como sus requisitos y descripciones, ya que dentro de las estructuras de las tablas requisitos y descripciones se estableció un **ON DELETE CASCADE** para las llaves foráneas, luego al ejecutar los dos SELECT se obtendrán los siguientes resultado:


<div style="text-align: center;">
    <img src=".\images\delete1.PNG" alt="delete1" />
    <p><b>Figura 12:</b>  Eliminación de un curso inventado y 2 cursos del plan.</p>
</div>


<div style="text-align: center;">
    <img src=".\images\delete2.PNG" alt="delete2" />
    <p><b>Figura 13:</b>  Eliminación descripciones.</p>
</div>


En las imágenes de las Figuras 12 y 13, se observa el resultado de las eliminaciones planteadas.
Finalmente se solicita eliminar los requisitos específicos de 2 cursos existentes, para ello se selecciona el curso Anteproyecto de TFG y el curso IE-0217 cuyo nombre fue actualizado a **Nombre curso editado**.


```sql
-- Eliminar requisitos de 2 cursos especificos.
-- VERIFICAR
SET @curso_id_Anteproyecto = (SELECT CursoID FROM Cursos WHERE Nombre = 'Anteproyecto de TFG');
SET @curso_id_CursoEditado  = (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0217');


DELETE FROM Requisitos WHERE CursoID = @curso_id_administracion;
DELETE FROM Requisitos WHERE CursoID =  @curso_id_CursoEditado;


SELECT * FROM Requisitos WHERE CursoID IN (@curso_id_Anteproyecto, @curso_id_CursoEditado);
```
El código anterior mediante los comandos SET crea dos variables que almacenan el número de identificación a partir del nombre y siglas de los cursos, luego el comando delete se encarga de eliminar los requisitos de los cursos a través de su id, finalmente se imprime el contenido de la tabla requisitos para los números de identificación  de los cursos.


<div style="text-align: center;">
    <img src=".\images\delete3.PNG" alt="delete3" />
    <p><b>Figura 14:</b>  Eliminación requisitos.</p>
</div>


En la imagen de la Figura 14 se observa que la eliminación ha sido correctamente efectuada.



