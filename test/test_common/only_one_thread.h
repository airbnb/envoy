#pragma once

#include "common/common/assert.h"
#include "common/common/thread.h"

namespace Envoy {
namespace Thread {

// Ensures that an operation is performed on only one thread. The first caller
// to OnlyOneThread::checkOneThread establishes the thread ID, and subsequent
// ones will assert-fail if they do not match.
class OnlyOneThread {
public:
  OnlyOneThread();

  /**
   * Ensures that one thread is used in a testcase to access some resource.
   */
  void checkOneThread();

private:
  ThreadFactory& thread_factory_;
  ThreadIdPtr thread_advancing_time_ GUARDED_BY(mutex_);
  mutable MutexBasicLockable mutex_;
};

} // namespace Thread
} // namespace Envoy
