 
## Complejidad de tiempo

| Función | Complejidad de tiempo Big O |
| ---- | --- |
|Búsqueda lineal | O(n)|
|Búsqueda binaria| O(log n)|
|Búsqueda trinaria | O(log(n)|


## Resultados experimentales

| Elementos (`n`) | Búsqueda lineal (ms) | Búsqueda binaria (ms) | Búsqueda trinaria (ms) |
| --------------: | -------------------: | --------------------: | ---------------------: |
|         100,000 |             0.109796 |              0.000295 |               0.000269 |
|       1,000,000 |             0.944221 |              0.000453 |               0.000432 |
|      10,000,000 |               10.053 |              0.001013 |               0.001225 |
|     100,000,000 |              99.0356 |              0.003355 |               0.001430 |


# La pregunta: ¿Cuál es más rápido?

Aunque tanto la busqueda binaria como la trinaria tienen una complejidad de O(log n) en notación asíntótica, hay que notar el hecho de que la cantidad de instrucciones realizadas no es la misma, si bien la busqueda trinaria realiza mas operaciones por iteración, tambien reduce el parametro de control una mayor cantidad, por lo que llega un punto en el cual las mayores instrucciónes por iteración generan menos tardanza que la menor división del parametro de control. Los datos experimentales sugieren que a partir de un valor de n muy alto la busqueda trinaria se vuelve mas eficaz. Pero ninguna de las dós es más rápida en todos los casos.

![Es verdad](https://media.tenor.com/YRbAqeoblnkAAAAe/robert-downey-jr-explaining.png)
La comparación de la eficiencia de los metodos es fuertemente influenciada por las circumstancias bajo las cuales se evaluan.