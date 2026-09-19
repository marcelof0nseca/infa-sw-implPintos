# infa-sw-implPintos

Implementacao do exercicio "Alarm Clock" (Pint-OS), disciplina Infraestrutura de Software -- CESAR School.

Arquivos alterados/criados na arvore original do Pintos (fork `jhu-cs318/pintos`):
- `devices/timer.c`
- `threads/thread.h`
- `tests/threads/alarm-boundary.c` + `.ck`
- `tests/threads/alarm-many-simultaneous.c` + `.ck`
- `tests/threads/tests.c`, `tests.h`, `Make.tests`
- `Makefile.kernel`, `threads/Makefile` (stock, necessarios para compilar/limpar)

## Compilar

Copie estes arquivos por cima de um checkout limpo do mesmo Pintos (`jhu-cs318/pintos`), respeitando os caminhos relativos, depois:

    cd src/threads
    make

## Rodar os testes do alarm clock

    cd src/threads/build
    make tests/threads/alarm-single.result tests/threads/alarm-multiple.result \
         tests/threads/alarm-simultaneous.result tests/threads/alarm-priority.result \
         tests/threads/alarm-zero.result tests/threads/alarm-negative.result \
         tests/threads/alarm-boundary.result tests/threads/alarm-many-simultaneous.result
    cat tests/threads/alarm-*.result

`alarm-priority` falha por design: exige escalonamento por prioridade, fora do escopo deste exercicio (ver relatorio).
