//
// impl/post.hpp
// ~~~~~~~~~~~~~
//
// Copyright (c) 2003-2018 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef EGT_ASIO_IMPL_POST_HPP
#define EGT_ASIO_IMPL_POST_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <egt/asio/detail/config.hpp>
#include <egt/asio/associated_allocator.hpp>
#include <egt/asio/associated_executor.hpp>
#include <egt/asio/detail/work_dispatcher.hpp>

#include <egt/asio/detail/push_options.hpp>

namespace egt {
namespace asio {

template <typename CompletionToken>
EGT_ASIO_INITFN_RESULT_TYPE(CompletionToken, void()) post(
    EGT_ASIO_MOVE_ARG(CompletionToken) token)
{
  typedef EGT_ASIO_HANDLER_TYPE(CompletionToken, void()) handler;

  async_completion<CompletionToken, void()> init(token);

  typename associated_executor<handler>::type ex(
      (get_associated_executor)(init.completion_handler));

  typename associated_allocator<handler>::type alloc(
      (get_associated_allocator)(init.completion_handler));

  ex.post(EGT_ASIO_MOVE_CAST(handler)(init.completion_handler), alloc);

  return init.result.get();
}

template <typename Executor, typename CompletionToken>
EGT_ASIO_INITFN_RESULT_TYPE(CompletionToken, void()) post(
    const Executor& ex, EGT_ASIO_MOVE_ARG(CompletionToken) token,
    typename enable_if<is_executor<Executor>::value>::type*)
{
  typedef EGT_ASIO_HANDLER_TYPE(CompletionToken, void()) handler;

  async_completion<CompletionToken, void()> init(token);

  typename associated_allocator<handler>::type alloc(
      (get_associated_allocator)(init.completion_handler));

  ex.post(detail::work_dispatcher<handler>(init.completion_handler), alloc);

  return init.result.get();
}

template <typename ExecutionContext, typename CompletionToken>
inline EGT_ASIO_INITFN_RESULT_TYPE(CompletionToken, void()) post(
    ExecutionContext& ctx, EGT_ASIO_MOVE_ARG(CompletionToken) token,
    typename enable_if<is_convertible<
      ExecutionContext&, execution_context&>::value>::type*)
{
  return (post)(ctx.get_executor(),
      EGT_ASIO_MOVE_CAST(CompletionToken)(token));
}

} // namespace asio
} // namespace egt

#include <egt/asio/detail/pop_options.hpp>

#endif // EGT_ASIO_IMPL_POST_HPP
