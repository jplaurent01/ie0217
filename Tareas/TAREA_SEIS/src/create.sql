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


/*
-- Leer (Read)
-- 3. Consultas:
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

-- Realiza consultas para listar todos los requisitos de un curso especifico.
-- Consultar todos los requisitos de un curso
SELECT CursoID, RequisitoCursoID FROM Requisitos WHERE CursoID = (SELECT CursoID FROM Cursos WHERE Sigla = 'IE-0613');
-- Realizar consulta para listar los cursos que no son optativos.
-- PUEDO CONSULTAR POR LOS CURSOS CON SEMESTRE iguales A IX O X
SELECT * FROM Cursos WHERE Semestre = 'IX' OR  Semestre = 'X';
-- Listar los cursos que pertenecen al semestre X.
SELECT * FROM Cursos WHERE Semestre = 'X';
-- Actualizar (Update)
-- 4. Actualizaciones:
-- Actualiza el nombre y creditos de 3 de los cursos optativos (puedes agregar cursos
-- del plan de estudios de bachillerato para tomarlo como optativa).
UPDATE Cursos SET Nombre = 'Nombre curso editado', Creditos= 1 WHERE CursoID = 7;
UPDATE Cursos SET Nombre = 'Nombre curso editado', Creditos= 1 WHERE CursoID = 8;
UPDATE Cursos SET Nombre = 'Nombre curso editado', Creditos= 1 WHERE CursoID = 9;
UPDATE Descripciones SET Descripcion = "Descripcion curso editada", Dificultad = "Dificil"  WHERE CursoID = 7;
UPDATE Descripciones SET Descripcion = "Descripcion curso editada", Dificultad = "Dificil"  WHERE CursoID = 8;
UPDATE Descripciones SET Descripcion = "Descripcion curso editada", Dificultad = "Dificil"  WHERE CursoID = 9;

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
    
-- Eliminar (Delete)
-- 5. Eliminaciones:
-- Elimina un curso inventado y 2 cursos del plan y asegurate de que tambien se
-- eliminen sus descripciones asociadas.

-- Eliminar un curso inventado y 2 cursos del plan y sus descripciones asociadas.
DELETE FROM Cursos WHERE Sigla IN ('IE-1201', 'IE-0579', 'IE-0613');

-- Eliminar requisitos de 2 cursos especificos.
-- VERIFICAR
SET @curso_id_Anteproyecto = (SELECT CursoID FROM Cursos WHERE Nombre = 'Anteproyecto de TFG');
SET @curso_id_CursoEditado  = (SELECT CursoID FROM Cursos WHERE Nombre = 'IE-0217');

DELETE FROM Requisitos WHERE CursoID = @curso_id_administracion;
DELETE FROM Requisitos WHERE CursoID =  @curso_id_administracion;

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
    
SELECT 
    c.Sigla, 
    c.Nombre, 
    d.RequisitoCursoID
FROM 
    Cursos c
INNER JOIN 
    Requisitos d ON c.CursoID = d.CursoID;




