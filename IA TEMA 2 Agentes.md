# IA TEMA 2: Agentes

> OBJETIVOS
>
> - Comprender que el desarrollo de sistemas inteligentes pasa por el desarrollo de agentes capaces de representar conocimiento para resolver problemas
>   - El agente puede orientarse hacia la construcción de sistemas autónomos o interactivos con los humanos
> - Conocer el concepto de agente inteligente y el ciclo "Percepción-Decisión-Actuación"
> - Adquirir las habilidades básicas para construir sistemas capaces de resolver problemas mediante técnicas de IA

### 1.Agentes inteligentes

La inteligencia artificial es el subcampo de la informática dedicado a la construcción de **agentes** que exhiben aspectos de comportamiento inteligente. Los agentes permiten dar una nueva forma a mostrar la IA.

![image-20200617131149118](/home/clara/.config/Typora/typora-user-images/image-20200617131149118.png)

> Un agente inteligente es un sistema de ordenador **situado** en algún *entorno* que es capaz de realizar acciones de forma **autónoma** y que es **flexible** para lograr los objetivos planteados

- **Situación: **el agente recibe entradas sensoriales de un entorno donde está situado y realiza acciones que cambian dicho entorno
- **Autonomía:** el sistema es capaz de actuar sin la intervención directa de un humano y tiene control sobre sus propias acciones y estado interno
- **Flexibilidad**
  - Reactivo: el agente debe percibir el entorno y responder de una forma temporal a los cambios que ocurren en dicho entorno
  - Pro-activo: los agentes no deben simplemente actuar en respuesta a su entorno, sino que deben ser capaces de exhibir comportamientos dirigidos a lograr objetivos que sean oportunos y tomar la iniciativa cuando sea apropiado
  - Social: los agentes deben ser capaces de interactuar, cuando sea apropiado, con otros agentes o con humanos para completar su propio proceso de resolución del problema y ayudar a otros con sus actividades

Un sistema basado en agentes será un sistema en el que la abstracción clave utilizada es, precisamente, un agente. 

#### Sistemas multi-agente

Los sistemas **multi-agente** son implementados para que varios agentes interactúen entre sí. Son una opción interesante para representar problemas que tienen múltiples formas de resolverse, múltiples perspectivas o múltiples entidades. La **interacción entre agentes** se da para...

- Cooperación, trabajar juntos para resolver algo
- Coordinación, organizar una actividad para evitar las intercacciones perjudiciales y explotar las beneficiosas
- Negociación, llegar a un acuerdo que sea aceptable por todas las partes implicadas

Los **sistemas multi-agente** (SMA) son una IA distribuída. Un SMA es una red más o menos unida de resolutores de problemas que trabajan conjuntamente para resolver problemas que están más allá de las capacidades individuales o del conocimiento de cada resolutor individual del problema. Un resolutor es lo mismo que un agente autónomo de naturaleza heterogénea.

Las características de los SMA son:

- Cada agente tiene información incompleta o no cuenta con las capacidades para resolver el problema, es decir, tiene un punto de vista limitado
- No hay un sistema de control global
- Los datos no están centralizados
- La computación es síncrona

### 2.Arquitecturas de agentes

##### Arquitectura deliberativa

- **Sistema de símbolos físicos:** un conjunto de entidades físicas (símbolos) que pueden combinarse para formar estructuras, y que es capaz de ejecutar procesos que operan con dichos símbolos de acuerdo a conjuntos de instrucciones codificadas simbólicamente
  - La hipótesis de sistema de símbolos físicos dice que tales sistemas son capaces de generar acciones inteligentes
- **Agente deliberativo:** aquel que contiene un modelo simbólico del mundo explícitamente representado y cuyas decisiones se realizan a través de un razonamiento lógico basado en emparejamientos de patrones y manipulaciones simbólicas
- Problemas:
  - Trasladar en un tiempo razonable para que sea útil el mundo real en una descripción simbólica precisa y adecuada
  - Representar simbólicamente la información acerca de entidades y procesos complejos del mundo real, y como conseguir que los agentes razonen con esta información para que los resultados sean útiles

##### Arquitectura reactiva

Una arquitectura reactiva es aquella que no incluye ninguna clase de modelo centralizado de representación simbólica del mundo, y no hace uso de razonamiento complejo

- El comportamiento inteligente puede ser generado sin una representación explícita ni un razonamiento abstracto explícito de la clase que la IA simbólica propone
- La inteligencia es una propiedad emergente de ciertos sistemas complejos
  - El comportamiento inteligente surge como resultado de la interacción del agente con su entorno

##### Arquitectura híbrida

Siguen una estructura vertical

![image-20200617131128055](/home/clara/.config/Typora/typora-user-images/image-20200617131128055.png)

### 3.Agentes reactivos

Representaciones del mundo: modelos icónicos o basados en características

#### Diseño de un agente reactivo

##### Percepción y acción

- El agente reactivo percibe su entorno a través de sensores
- Procesa la información recibida y hace una representación interna de sí misma
- Escoge una acción, entre las posibles, considerando la información percibida
- Transforma la acción en señales para los actuadores y la realiza

###### Ejemplo

Supongamos un robot en un mundo dividido en cuadrículas. El robot puede percibir si las 8 casillas vecinas están libres o no, con un sensor Si por cada casilla i. 

El objetivo del robot es ir a una pared y seguir su perímetro indefinidamente. Tiene 4 posibles movimientos (todos de una casilla): N, S, E, O. No se permite que el entorno contenga pasillos estrechos (casillas rodeadas por 2 o más obstáculos a ambos lados)

![image-20200617181619421](/home/clara/.config/Typora/typora-user-images/image-20200617181619421.png)

Podemos usar un vector de 8 componentes: el componente i vale 0 si el sensor Si no detecta obstáculo. Por ejemplo, la posición A={0,0,0,0,1,0,0,0}

![image-20200617181645549](/home/clara/.config/Typora/typora-user-images/image-20200617181645549.png)

#### Arquitecturas de agentes reactivos



#### Características de agentes reactivos