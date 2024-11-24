#include <stdio.h>
#include "work.h"

Job get_job(int job_id) {
  Job job;
  switch (job_id) {
    case EVIL_LAB_ASSISTANT:
      job.job_id = EVIL_LAB_ASSISTANT;
      job.salary = EVIL_LAB_ASSISTANT_SALARY;
      job.duration = EVIL_LAB_ASSISTANT_DURATION;
      break;
    case OWCA_HIRING_MANAGER:
      job.job_id = OWCA_HIRING_MANAGER;
      job.salary = OWCA_HIRING_MANAGER_SALARY;
      job.duration = OWCA_HIRING_MANAGER_DURATION;
      break;
    case CIKAPUNDUNGINATOR_CARETAKER:
      job.job_id = CIKAPUNDUNGINATOR_CARETAKER;
      job.salary = CIKAPUNDUNGINATOR_CARETAKER_SALARY;
      job.duration = CIKAPUNDUNGINATOR_CARETAKER_DURATION;
      break;
    case MEWING_SPECIALIST:
      job.job_id = MEWING_SPECIALIST;
      job.salary = MEWING_SPECIALIST_SALARY;
      job.duration = MEWING_SPECIALIST_DURATION;
      break;
    case INATOR_CONNOISSEUR:
      job.job_id = INATOR_CONNOISSEUR;
      job.salary = INATOR_CONNOISSEUR_SALARY;
      job.duration = INATOR_CONNOISSEUR_DURATION;
      break;
    default:
      job.job_id = 0;
      job.salary = 0;
      job.duration = 0;
      break;
  }
  return job;
}

void delay(int sec){
  int milisec = 1000 * sec;
  clock_t start = clock();
  while(clock() < start + milisec ){
    ;
  }
}

void start_job(int duration, int salary){
  int i;
  printf("Anda sedang bekerja harap tunggu.");
  for(i = 0; i < duration; i++;){
    delay(1);
  }
  printf("Pekerjaan selesai, +%d rupiah telah ditambahkan ke akun Anda.", salary);
}