#include <stdio.h>
#include "tests/threads/tests.h"
#include "threads/malloc.h"
#include "threads/synch.h"
#include "threads/thread.h"
#include "devices/timer.h"

#define THREAD_CNT 20

struct wake_test
  {
    int64_t target;
    int64_t wakeups[THREAD_CNT];
    int count;
    struct lock lock;
  };

static void sleeper (void *aux);

void
test_alarm_many_simultaneous (void)
{
  struct wake_test test;
  int i;

  ASSERT (!thread_mlfqs);

  msg ("Creating %d threads to sleep until the same tick.", THREAD_CNT);

  test.target = timer_ticks () + 100;
  test.count = 0;
  lock_init (&test.lock);

  for (i = 0; i < THREAD_CNT; i++)
    {
      char name[16];
      snprintf (name, sizeof name, "thread %d", i);
      thread_create (name, PRI_DEFAULT, sleeper, &test);
    }

  timer_sleep (200);

  if (test.count != THREAD_CNT)
    fail ("only %d of %d threads woke up", test.count, THREAD_CNT);

  for (i = 0; i < THREAD_CNT; i++)
    if (test.wakeups[i] != test.target)
      fail ("thread %d woke up at the wrong tick", i);

  msg ("All %d threads woke up at the same tick, as expected.", THREAD_CNT);
  pass ();
}

static void
sleeper (void *test_)
{
  struct wake_test *test = test_;

  timer_sleep (test->target - timer_ticks ());

  lock_acquire (&test->lock);
  test->wakeups[test->count++] = timer_ticks ();
  lock_release (&test->lock);
}
