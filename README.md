# Git

## GitHub

Este repositorio tiene configurado un _remote_ llamado `origin` que se puede ver con 
```
git remote -v
```

## Alias

El comando para crear un alias para el respositorio actual es:

```
git config alias.[alias] "comando"
```

Y si querríamos aplicar ese alias a cualquier repositorio de la máquina actual:

```
git config --global alias.[alias] "comando"
```

Algunos de los alias usados con git son:

### Globales

```
alias = ! git config --get-regexp ^alias\. | sed -e s/^alias\.// -e s/\ /\ =\ /
p = push
c = commit
ca = commit -a
```

### Locales

```
c = commit
ca = commit -a
p = push
```

## Bisect

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

## Hooks

Con respecto a los hooks, se han creado dos de ellos en la carpeta .git/hooks

### pre-commit

El hook _pre-commit_ se ejecuta antes de la lógica relacionada con `git commit`, por lo que se ejecuta siempre; aunque no se pueda realizar un commit en realidad.

Este hook se encarga de comprobar que exista el directorio test, el goal test en el makefile de la raíz del proyecto y de ejecutar los tests. Si algo falla, aborta el commit.

### post-commit

_post-commit_, por el contrario, solo se ejecuta si el commit se ha realizado con éxito (y después de que termine su ejecución, claro).

Este hook simplemente enseña al usuario el SHA-1 del commit que se acaba de confirmar.