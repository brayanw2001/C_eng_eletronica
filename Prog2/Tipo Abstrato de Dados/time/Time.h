// Crie um TAD para representar horários (hora, minuto, segundo). Implemente funções para 
// somar dois horários, converter um horário em segundos e calcular a diferença entre dois horários.
#include <stdlib.h>
#include <stdio.h>

typedef struct Time Time;

Time SumTime(Time t1, Time t2);
Time TimeDiff (Time t1, Time t2);
int TimeToSeconds(Time t);