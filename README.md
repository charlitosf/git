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