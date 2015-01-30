Proyecto RAIDER: Robot Antropomórfico para la Investigación y Desarrollo en Entornos Reales.

En este proyecto se pueden encontrar todos los recursos que se están desarrollando para diseñar, construir y programar a RAIDER. 

El proyecto se ha distribuido en cuatro secciones:

- parts: Esta carpeta contiene todas las piezas imprimibles. Se ofrecen en formato scad (código), stl y step.
- shield: En esta carpeta pueden encontrarse todos los archivos necesarios para construir la placa electrónica de expansión. La placa ha sido diseñada en KiCAD y se incluyen tanto las fuentes como los gerbers.
- programming: Aquí puede encontrarse todo el código programado, desde el control de los controladores del robot, manejo de sensores y actuadores, algoritmos de visión, etc. A parte de las librerías existen aplicaciones completas para la teleoperación del robot y su presentación a las pruebas de CEABOT.

La documentación del proyecto puede encontrarse en el repositorio raider-doc

NOTA: Actualmente la programación en OpenCM no compila con versiones posteriores a v1.0.1 de OpenCM IDE. Sin embargo dado que las versiones actuales tienen bastantes bugs, no tengo pensado reescribir el código (de momento). 

Archivo FindZBar0.cmake: http://code.google.com/p/low-cost-vision-2012/

Clase serialib original: http://serialib.free.fr

Bibliotecas de control borroso Fuzzylite: http://www.fuzzylite.com/
