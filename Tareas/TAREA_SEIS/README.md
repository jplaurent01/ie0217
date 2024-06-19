# Tarea 6




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
    El código anterior muestra la estructura de la tabla **Cursos** 

