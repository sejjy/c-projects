## c-projects

Solutions to _Programming Projects_ from _C Programming: A Modern Approach_ (2nd
edition) by K. N. King

### Structure

```
.
├── chap_02
│   ├── 01.c
│   ├── 02.c
│   └── ...    # other projects
└── ...    # other chapters
```

### Compile and run

The book recommends using `gcc` with the following options:

```bash
gcc -O -Wall -W -pedantic -ansi -std=c99 -o project project.c && ./project
```

Makefiles are introduced in Chapter 15.4, which I haven't reached yet. Use the
[car](./car) script to <ins>c</ins>ompile <ins>a</ins>nd <ins>r</ins>un projects
easily:

```bash
> ./car chapter project
```
