# Laboratorio 8

## Bases de datos SQL

Room 5, Integrantes: Jose Pablo Laurent, Ismael Jimenez, Andrés Bonilla.

En el presente documento se analizan dos bases de datos SQL **hospital.db**, que contiene tablas de relacionadas con información sobre los pacientes, doctores, admición y nombres de las provincias. Por otro la base de datos **northwind.db** contiene infromación relacionada sobre productos,categorias,detalles de una orden, ordenes, clientes, entre otros más.

### Hospital.db

1. Show the patience id and the total number of admissions for patient_id 597

```SQL
-- Selecciona el ID del paciente y el conteo de veces que el ID del paciente es igual a 579
-- Selecciona el ID del paciente
-- Cuenta las filas donde el ID del paciente es igual a 579
SELECT patient_id, count (patient_id = 579)
-- De la tabla 'admissions'
FROM admissions
-- Filtra las filas donde el ID del paciente es igual a 579
where patient_id is 579;
```

2. Based on the cities that our patients live in, show unique cities that are in province _id "NS"?

```SQL
-- Selecciona las ciudades únicas de los pacientes que pertenecen a la provincia con ID 'NS'
-- Selecciona ciudades únicas y les asigna el alias 'unique_cities'
SELECT DISTINCT(city) AS unique_cities
-- De la tabla 'patients'
FROM patients
  -- Filtra las filas donde el ID de la provincia es 'NS'
where province_id = 'NS';
```

3. Show unique birth years from patients and order them ascending

```SQL
-- Selecciona los años únicos de nacimiento de los pacientes y los ordena de forma ascendente
SELECT DISTINCT YEAR(birth_date) AS birth_year
-- De la tabla 'patients'
FROM patients
-- Ordena los años de nacimiento de forma ascendente
ORDER BY birth_year ASC;
```

4. Show unique first names from the patients table which only ocurrs once in the list.

```SQL
-- Selecciona los primeros nombres de los pacientes que aparecen solo una vez en la tabla
SELECT first_name
-- De la tabla 'patients'
FROM patients
-- Agrupa los resultados por los primeros nombres de los pacientes
GROUP BY first_name
-- Filtra los grupos para incluir solo aquellos con un conteo de nombres igual a 1
HAVING COUNT(first_name) = 1;
```

5. Sort the province names in ascendign order in such a way that the province "Ontario" is always on top.

```SQL
-- Selecciona la columna 'province_name' de la tabla 'province_names'
select province_name
from province_names
-- Ordena los resultados según los siguientes criterios:
order by
  -- Primer criterio de ordenamiento: Si 'province_name' es 'Ontario', asigna 0, de lo contrario, asigna 1.
  -- Esto asegura que 'Ontario' siempre aparezca primero en la lista.
  (case when province_name = 'Ontario' then 0 else 1 end),
  -- Segundo criterio de ordenamiento: Ordena alfabéticamente los nombres de las provincias.
  province_name;
```

6. We need a breakdown for the total amount of admissions each doctor has started each year. Show the doctor_id, doctor_full_name, specialty, year, total_admissions for that year.

```SQL
-- Selecciona el ID del doctor, concatenación del nombre y apellido, especialidad,
-- año de la fecha de admisión y el total de admisiones
SELECT
  d.doctor_id as doctor_id,  -- Selecciona y asigna un alias 'doctor_id' para el ID del doctor
  CONCAT(d.first_name,' ', d.last_name) as doctor_name,  -- Concatena el nombre y apellido del doctor y asigna un alias 'doctor_name'
  d.specialty,  -- Selecciona la especialidad del doctor
  YEAR(a.admission_date) as selected_year,  -- Extrae el año de la fecha de admisión y asigna un alias 'selected_year'
  COUNT(*) as total_admissions  -- Cuenta el número total de admisiones y asigna un alias 'total_admissions'
FROM doctors as d
  LEFT JOIN admissions as a ON d.doctor_id = a.attending_doctor_id  -- Realiza un LEFT JOIN entre la tabla 'doctors' y 'admissions' usando 'doctor_id'
GROUP BY
  doctor_name,  -- Agrupa los resultados por el nombre del doctor
  selected_year  -- Agrupa los resultados por el año seleccionado
ORDER BY doctor_id, selected_year;  -- Ordena los resultados por el ID del doctor y el año seleccionado
```

7. Show  the provinces that has more patiences  identified as "M" tha "F". Must only show full province_name

```SQL
-- Selecciona el nombre de la provincia
SELECT pr.province_name
FROM patients AS pa  -- De la tabla 'patients' con el alias 'pa'
  JOIN province_names AS pr ON pa.province_id = pr.province_id  -- Realiza un JOIN entre 'patients' y 'province_names' usando 'province_id'
GROUP BY pr.province_name  -- Agrupa los resultados por el nombre de la provincia
HAVING
  -- Filtra los grupos para incluir solo aquellos donde la cuenta de pacientes masculinos es mayor que la de pacientes femeninos
  COUNT(CASE WHEN gender = 'M' THEN 1 END) > COUNT(CASE WHEN gender = 'F' THEN 1 END);
  -- La cláusula HAVING compara el número de pacientes masculinos (M) con el número de pacientes femeninos (F) por provincia
```

8. For each day display the total amount of admissions on that day. Display the amount changed from the previous date.

```SQL
-- Selecciona la fecha de admisión, el total de admisiones por día y el cambio en el conteo de admisiones respecto al día anterior
SELECT
  admission_date,  -- Selecciona la fecha de admisión
  count(admission_date) as admission_day,  -- Cuenta las admisiones por fecha y asigna un alias 'admission_day'
  -- Calcula el cambio en el número de admisiones comparado con el día anterior
  count(admission_date) - LAG(count(admission_date)) OVER(ORDER BY admission_date) AS admission_count_change
FROM admissions  -- De la tabla 'admissions'
GROUP BY admission_date;  -- Agrupa los resultados por la fecha de admisión

```

### northwind.db

1. Write a query to find the first_name, last name and birth date of patients who has height greater than 160 and weight greater than 70

```SQL
-- Selecciona el primer nombre, apellido y fecha de nacimiento de los pacientes que tienen una altura mayor a 160 y un peso mayor a 70
SELECT first_name,last_name, birth_date
-- De la tabla 'patients'
FROM patients
-- Filtra las filas donde la altura es mayor a 160 y el peso es mayor a 70
WHERE (height > 160 and weight > 70)
```

2. Write a query to find list of patients first_name, last_name, and allergies where allergies are not null and are from the city of 'Hamilton'

```SQL
-- Selecciona el primer nombre, apellido y alergias de los pacientes que tienen alergias y viven en la ciudad de Hamilton
SELECT first_name,last_name, allergies
-- De la tabla 'patients'
FROM patients
-- Filtra las filas donde las alergias no son nulas y la ciudad es Hamilton
WHERE allergies IS NOT NULL and city = 'Hamilton';
```

3. Show unique birth years from patients and order them by ascending.

```SQL
-- Selecciona los años únicos de nacimiento de los pacientes y los ordena de forma ascendente
-- De la tabla 'patients'
SELECT DISTINCT YEAR (birth_date) FROM patients
-- Ordena los años de nacimiento de forma ascendente
ORDER BY YEAR (birth_date) ASC;
```

4. Show unique first names from the patients table which only occurs once in the list.

```SQL
-- Selecciona los primeros nombres de los pacientes que aparecen solo una vez en la tabla
SELECT first_name
 -- De la tabla 'patients'
FROM patients
-- Agrupa los resultados por los primeros nombres de los pacientes
GROUP BY first_name
-- Filtra los grupos para incluir solo aquellos con un conteo de nombres igual a 1
HAVING COUNT(*) = 1
```
