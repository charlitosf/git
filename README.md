# Sistemas de Control de Versiones

## Git

### Alias

El comando para crear un alias para el respositorio actual es:

```
git config alias.[alias] "comando"
```

Y si querríamos aplicar ese alias a cualquier repositorio de la máquina actual:

```
git config --global alias.[alias] "comando"
```

Algunos de los alias usados con git son:

#### Globales

```
alias = ! git config --get-regexp ^alias\. | sed -e s/^alias\.// -e s/\ /\ =\ /
p = push
c = commit
ca = commit -a
```

#### Locales

```
c = commit
ca = commit -a
p = push
```

### Bisect

Para probar bisect, he introducido un bug en el commit `77759de`, sabiendo que el código funcionaba en `e9de2bd` (puesto que ahí implemento make test).

Entonces, en el commit `2406155` comienzo la operación de bisect con:

```
git bisect start
git bisect bad
git bisect good e9de2bd
```
El último comando indica a git el último commit conocido en el que el código funcionaba.

Una vez hecho esto, git elige un commit intermedio y yo debo comprobar que funcione (con `make test`). Si funciona, ejecuto `git bisect good`. Si no, `git bisect bad`. En dos pasos, git me da el primer commit en el que el código falla (`77759de`) y deja HEAD apuntando a él. La solución aquí puede ser cambiar el código y hacer merge con la rama actual o, como yo lo he solucionado, volviendo al final de la rama y ejecutar:

```
git revert 77759de
```

Solucionamos el conflicto y comprobamos con `make test` que el código vuelve a funcionar.

Valdría también con:

```
git revert bisect/bad
```

Y acabamos con

```
git bisect reset
```