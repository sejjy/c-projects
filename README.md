## c-projects

_Programming Projects_ from _C Programming: A Modern Approach_, second edition,
by K. N. King

### Structure

```
.
├── 02
│   ├── 01.c
│   ├── 02.c
│   └── ...    # other project.c files or project directories
└── ...    # other chapters
```

### Compile and run

#### Single-file projects

Use `gcc` with the following options:

```bash
$ gcc -O -Wall -W -pedantic -ansi -std=c99 -o project project.c
$ ./project [args...]
```

Alternatively, use the [`car`](./car) script to <ins>c</ins>ompile
<ins>a</ins>nd <ins>r</ins>un single-file projects easily:

```bash
$ ./car chapter project [args...]
```

#### Multi-file projects

Use `make` inside the project directory:

```bash
$ make [target]
$ ./project [args...]
```
