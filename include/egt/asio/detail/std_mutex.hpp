//
// detail/std_mutex.hpp
// ~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2018 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef EGT_ASIO_DETAIL_STD_MUTEX_HPP
#define EGT_ASIO_DETAIL_STD_MUTEX_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <egt/asio/detail/config.hpp>

#if defined(EGT_ASIO_HAS_STD_MUTEX_AND_CONDVAR)

#include <mutex>
#include <egt/asio/detail/noncopyable.hpp>
#include <egt/asio/detail/scoped_lock.hpp>

#include <egt/asio/detail/push_options.hpp>

namespace egt {
namespace asio {
namespace detail {

class std_event;

class std_mutex
  : private noncopyable
{
public:
  typedef egt::asio::detail::scoped_lock<std_mutex> scoped_lock;

  // Constructor.
  std_mutex()
  {
  }

  // Destructor.
  ~std_mutex()
  {
  }

  // Lock the mutex.
  void lock()
  {
    mutex_.lock();
  }

  // Unlock the mutex.
  void unlock()
  {
    mutex_.unlock();
  }

private:
  friend class std_event;
  std::mutex mutex_;
};

} // namespace detail
} // namespace asio
} // namespace egt

#include <egt/asio/detail/pop_options.hpp>

#endif // defined(EGT_ASIO_HAS_STD_MUTEX_AND_CONDVAR)

#endif // EGT_ASIO_DETAIL_STD_MUTEX_HPP
