escolhas atuais ficam:

Campo	Tipo	Situação
PID	int	definido
Nome	char[101]	definido
Prioridade	int	definido
Estado	EstadoProcesso	definido
Tempo CPU total	double	definido
Tempo CPU utilizado	double	definido
Memória	double	a decidir
Recursos associados	int	definido
Arquivos abertos	int	definido


um núcleo de cpu - 250 processos simultâneos
cada posição possui uma marcação de ocupação

| Posição | Ocupação | Processo | Estado     |
| ------- | -------- | -------- | ---------- |
| 0       | Livre    | —        | —          |
| 1       | Ocupada  | PID 1    | PRONTO     |
| 2       | Ocupada  | PID 2    | EXECUTANDO |
| 3       | Ocupada  | PID 3    | BLOQUEADO  |
| 4       | Livre    | —        | —          |

ocupado/livre → controla a utilização da posição na tabela.

estado do processo → controla o ciclo de vida do processo.

Então temos:

Estado do processo:
NOVO, PRONTO, EXECUTANDO, BLOQUEADO, TERMINADO

Ocupação da posição:
true ou false retorna a situação da posição do processo

true = ocupado
false = livre posição

representar com bool