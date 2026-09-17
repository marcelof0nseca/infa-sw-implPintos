#include <stdio.h>
#include "tests/threads/tests.h"
#include "devices/timer.h"

void
test_alarm_boundary (void)
{
  static const int durations[] = {1, 2, 7};
  int i;

  for (i = 0; i < 3; i++)
    {
      int64_t align_start = timer_ticks ();
      int64_t start;

      while (timer_elapsed (align_start) == 0)
        continue;

      start = timer_ticks ();
      timer_sleep (durations[i]);
      msg ("slept %d ticks, requested %d",
           (int) timer_elapsed (start), durations[i]);
    }

  pass ();
}
