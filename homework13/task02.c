/* В данном задании рассматривается использования блокирующей функции sygwait 
 * для обработки приходящих сигналов. Ввиду того, что используется          
 * блокирующая функция, то ожидаемым результатом является отсутствие
 * утилизации процессорного времен процессорного времени.
 * Результат нагрузки на CPU приложен в файле task02.txt */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
    /* инициализируем структуры сигналов */
    sigset_t sig1, sig2;
    /* очищаем их */
    sigemptyset(&sig1);
    /* добавляем сигнал SIGUSR1 в переменную */
    sigaddset(&sig1, SIGUSR1);
    /* изменяем блокируемый сигнал по маске */
    sigprocmask(SIG_BLOCK, &sig1, &sig2);
    int event;
    /* Вызов блокирующей функции sigwait. 
     * Вызов сигнала для прерывания производится из терминала с помощью 
     * команды kill -10 *pid*, где:
     * - 10 - номер сигнала SIGUSR1;
     * - *pid* - идентификатор процесса, взятый из вывода ps -u */
    sigwait(&sig1, &event);
    printf("test\n");
}
