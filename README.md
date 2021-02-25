# socketC

Este proyecto corresponde a la primera primera practica de la materia de sistemas distribuidos

Codifique cuatro programas usando sockets, en el enfoque cliente-servidor,
que permita el intercambio de mensajes de texto y de números enteros.

      -El programa Servidor ( debe ser codificado en java)
      -Mientras que el cliente ( debe ser codificado en C)
      -Otro programa Servidor ( debe ser codificado en C)
      -Mientras que el cliente ( debe ser codificado en Java)

Cuando se conecten entre su, el cliente enviará un entero indicando cuántos
caracteres van detrás (incluido un caracter nulo o vacío al final) y luego los
caracteres. Es decir, enviará, por ejemplo, un 5 y luego "Hola" y un caracter nulo (
que son los 5 caracteres). Cuando lo reciba, el servidor contestará con un 6 y
luego "Adiós" y un caracter nulo o vacio.

Muestre el funcionamiento de estos programas comunicando servidores y clientes ,
en el siguiente orden
      -Servidor ( en java) con cliente en C
      -Servidor ( en C) con cliente Java
      -Servidor y cliente en java
      -Servidor y cliente en C
La prueba y revisión de este ejercicio consiste en:
Ejecutar cualquiera de los dos servidores (el de C o el de java) con cualquiera de

los dos clientes (el de C o el de java) y deberán funcionar igual.