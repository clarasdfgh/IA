# IA TEMA 1: Introducción a la inteligencia artificial

> OBJETIVOS
>
> - Conocer qué es la IA, sus fundamentos y su historia
> - Entender la IA como un conjunto de técnicas para el desarrollo de sistemas informáticos que exhiben comportamientos inteligentes
> - Conocer distintas aplicaciones reales de IA
> - Explorar y analizar soluciones actuales basadas en técnicas de IA

### 1. ¿Qué significa ser inteligente?

Según la RAE:

> 1. Capacidad de entender o comprender. 
> 2. Capacidad de resolver problemas. 
> 3. Conocimiento, comprensión, acto de entender. 
> 4. Sentido en que se puede tomar una sentencia, un dicho o una expresión. 
> 5. Habilidad, destreza y experiencia. 
> 6. Trato y correspondencia secreta de dos o más personas o naciones entre sí. 
> 7.  Sustancia puramente espiritual.

Según Gardner, de la Universidad de Harvard, la inteligencia es la capacidad de ordenar los pensamientos y coordinarlos con acciones. No es una sóla, sino que existen tipos distintos. Existe una diversidad de inteligencias que marcan las potencialidades y acentos significativos de cada individuo, trazados por las fortalezas y debilidades de una serie de escenarios de expansión de la inteligencia.

Inteligencia lingüística, lógico-matemática, corporal-cinética, visual-espacial, musical, interpersonal, intrapersonal, naturalista...

Aplicando a esta asignatura, la inteligencia artificial sólo suele necesitar un tipo de inteligencia para ser perfectamente funcional: *p.ej una lavadora inteligente tiene distinta inteligencia a la de un robot social*

### 2. Definición de IA

Nace a finales del siglo XX, con los primeros ordenadores para cálculos numéricos. Esto no quiere decir que en la antigüedad no se empezara a aplicar, pero no es lo que nos interesa. 

Poco a poco se ha ido ampliando el abanico de problemas que puede resolver el ordenador. 

*Cálculo numérico > juegos > reconocimiento de objetos > toma de decisiones complejas*

#### Definiciones de IA

Múltiples definiciones han surgido a lo largo de los años. Se crea una clasificación en cuadrante respecto a dos factores: **compararse con el ser humano vs. ser racional** y **actuar vs. pensar**

- Sistemas que actúan como humanos  
- Sistemas que piensan como humanos
- Sistemas que actúan racionalmente  
- Sistemas que piensan racionalmente

|              | ACTUACIÓN                         | PENSAMIENTO                        |
| ------------ | --------------------------------- | ---------------------------------- |
| **HUMANO**   | Sistemas que actúan como humanos  | Sistemas que piensan como humanos  |
| **RACIONAL** | Sistemas que actúan racionalmente | Sistemas que piensan racionalmente |

##### Sistemas que piensan como humanos

*Mente humana > Exp. psicológicos > Teoría de la mente > Ciencia cognitiva > Modelos cognitivos*

Más ligado a la psicología y las ciencias cognitivas, el modelo es el funcionamiento de la mente humana. 

Intentamos establecer una teoría sobre el funcionamiento de la mente mediante experimentación psicológica. A partir de esta teoría establecemos modelos computacionales

##### Sistemas que piensan racionalmente

Las leyes del pensamiento racional se fundamentan en lógica, que es la base formal de estos sistemas (logicismo).

Aunque puede llegar a ser más efectiva que el modelo humano, presenta dos obstáculos:

- Es muy difícil formalizar el conocimiento
- Hay un gran salto entre la capacidad teórica de la lógica y su realización práctica

##### Sistemas que actúan como humanos

###### DEFINICIÓN

Es una definición temporal, cambia según se van resolviendo nuevos problemas.

> “La Inteligencia Artificial es el estudio de cómo hacer que los ordenadores hagan cosas que por el momento son realizadas mejor por los seres humanos"
>
> (Rich y Knight) 

Antes las máquinas se desarrollaban para evitar tareas físicas, el ordenador y la IA pues se desarrolla para evitar tareas mentales. Las tareas mentales que no nos son innatas, aceptamos que el ordenador las desarrolla mejor:

- Cálculo numérico
- Almacenamiento de información
- Operaciones repetitivas

Si disponemos de un algoritmo que resuelve de forma exacta el problema, no entra en el campo de la IA. Por ejemplo, el reconocimiento de objetos es una habilidad innata al ser humano que no tiene un algoritmo exacto. Esto sí es parte del campo de estudio de la IA.

###### MODELO

El modelo es el hombre, el objetivo es construit un sistema que pase por humano. El test de Turing prueba *(siguiendo la definición anterior)* si el sistema es inteligente. A día de hoy no existe una máquina que cumpla el test de Turing totalmente (es decir, durante tiempo ilimitado sin identificarla como una máquina)

> ![](/home/clara/.config/Typora/typora-user-images/image-20200220114648291.png)
>
> **Conducta Inteligente:** la capacidad de lograr eficiencia a nivel humano en todas las actividades de tipo cognoscitivo, suficiente para engañar a un evaluador - *Turing, 1950, "Computer machinery and intelligence"*

Capacidades necesarias de un sistema que actúa como humano:

- Procesamiento de lenguaje natural
- Representación del conocimiento
- Razonamiento
- Aprendizaje

La interacción con personas hace que sea necesario que estos sistemas actúen como humanos

##### Sistemas que actúan racionalmente

El último paso de la IA: retirar al humano para conseguir sistemas que actúen de forma racional y potencialmente mejor. Actuar racionalmente significa conseguir unos objetivos dadas unas creencias.

El paradigma es el agente: un agente percibe y actúa, siempre según el entorno en el que esté situado. Un **agente racional** actúa de la manera correcta **según la información que posee.**

Las capacidades generales son las mismas que las del test de Turing, pero es una visión más general, no centrada en el modelo humano.

#### ¿Qué es la IA?

La Inteligencia Artificial es una rama de la Informática que estudia y resuelve problemas situados en la frontera de la misma. Si un problema no tiene solución mediante un algoritmo exacto, puede pertenecer al campo de la IA.

Se basa en dos ideas fundamentales: 

- Representación del conocimiento explícita y declarativa 
- Resolución de problemas (heurística)

#### ¿Es posible la IA?

La posibilidad de la inteligencia artificial plantea problemas filosóficos complejos:

- ¿Las maquinas pensantes poseen consciencia?
- ¿Es la inteligencia una propiedad emergente de los elementos biológicos que la producen?

No hay conclusión definitiva a este debate que existe desde el principio de la IA.

##### ELIZA

Agente conversacional que pasa el test de Turing en cierta medida. Muy reactivo y altamente convincente.

##### La habitación china

![image-20200220120647214](/home/clara/.config/Typora/typora-user-images/image-20200220120647214.png)

En una habitación cerrada, con un orificio de entrada y uno de salida, se coloca a un sujeto con un diccionario de chino. Cada vez que el sujeto recibe un documento en chino por la entrada, lo traduce y devuelve el documento resultante por la salida. 

Para el que no conozca el sistema, este en su conjunto “sabe chino”, pero… ¿realmente el sujeto sabe chino?

### 3. Bases de la IA

![image-20200220121206146](/home/clara/.config/Typora/typora-user-images/image-20200220121206146.png)

- **MATEMÁTICA:**
  - Lógica:
  - Complejidad:
  - Probabilidad:
- **Economía:**
  - ¿Cómo tomamos decisiones...
    - ...beneficiosas?
    - ...competitivas?
    - ...a largo plazo?
- **Neurociencia:**
  - ¿Cómo procesamos la información?
- **Psicología:**
  - ¿Cómo pensamos y actuamos?
- **Computación:**
  - Necesidad de un soporte físico y de desarrollo
- **Cibernética:**
  - Construcción de sistemas autónomos
- **Lingüística:**
  - Lingüística computacional, representación del conocimiento, gramática

### 4. Historia de la IA

- **Periodo de gestación (43-55)**
- **Nacimiento (56)**
- **Primeros pasos (52-69)**
- **Edad oscura (66-73)**
- **Sistemas basados en conocimiento (69-79)**
- **IA industrial (80-hoy)**
- **Nueva era de las redes neuronales artificiales (86-hoy)**
- **IA como ciencia (87-hoy)**
- **Fuerte avance de la IA (10-hoy)**

### 5. Áreas de trabajo de la IA

- Áreas Básicas
  - Representación del conocimiento 
  - Resolución de problemas, Búsqueda 
- Áreas Específicas 
  - Planificación de tareas 
  - Tratamiento del Lenguaje Natural 
  - Razonamiento Automático 
  - Sistemas Basados en el Conocimiento 
  - Percepción 
  - Aprendizaje Automático 
  - Agentes autónomos