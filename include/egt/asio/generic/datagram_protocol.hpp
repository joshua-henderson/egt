//
// generic/datagram_protocol.hpp
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2018 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef EGT_ASIO_GENERIC_DATAGRAM_PROTOCOL_HPP
#define EGT_ASIO_GENERIC_DATAGRAM_PROTOCOL_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <egt/asio/detail/config.hpp>

#include <typeinfo>
#include <egt/asio/basic_datagram_socket.hpp>
#include <egt/asio/detail/socket_types.hpp>
#include <egt/asio/detail/throw_exception.hpp>
#include <egt/asio/generic/basic_endpoint.hpp>

#include <egt/asio/detail/push_options.hpp>

namespace egt {
namespace asio {
namespace generic {

/// Encapsulates the flags needed for a generic datagram-oriented socket.
/**
 * The egt::asio::generic::datagram_protocol class contains flags necessary
 * for datagram-oriented sockets of any address family and protocol.
 *
 * @par Examples
 * Constructing using a native address family and socket protocol:
 * @code datagram_protocol p(AF_INET, IPPROTO_UDP); @endcode
 * Constructing from a specific protocol type:
 * @code datagram_protocol p(egt::asio::ip::udp::v4()); @endcode
 *
 * @par Thread Safety
 * @e Distinct @e objects: Safe.@n
 * @e Shared @e objects: Safe.
 *
 * @par Concepts:
 * Protocol.
 */
class datagram_protocol
{
public:
  /// Construct a protocol object for a specific address family and protocol.
  datagram_protocol(int address_family, int socket_protocol)
    : family_(address_family),
      protocol_(socket_protocol)
  {
  }

  /// Construct a generic protocol object from a specific protocol.
  /**
   * @throws @c bad_cast Thrown if the source protocol is not datagram-oriented.
   */
  template <typename Protocol>
  datagram_protocol(const Protocol& source_protocol)
    : family_(source_protocol.family()),
      protocol_(source_protocol.protocol())
  {
    if (source_protocol.type() != type())
    {
      std::bad_cast ex;
      egt::asio::detail::throw_exception(ex);
    }
  }

  /// Obtain an identifier for the type of the protocol.
  int type() const
  {
    return EGT_ASIO_OS_DEF(SOCK_DGRAM);
  }

  /// Obtain an identifier for the protocol.
  int protocol() const
  {
    return protocol_;
  }

  /// Obtain an identifier for the protocol family.
  int family() const
  {
    return family_;
  }

  /// Compare two protocols for equality.
  friend bool operator==(const datagram_protocol& p1,
      const datagram_protocol& p2)
  {
    return p1.family_ == p2.family_ && p1.protocol_ == p2.protocol_;
  }

  /// Compare two protocols for inequality.
  friend bool operator!=(const datagram_protocol& p1,
      const datagram_protocol& p2)
  {
    return !(p1 == p2);
  }

  /// The type of an endpoint.
  typedef basic_endpoint<datagram_protocol> endpoint;

  /// The generic socket type.
  typedef basic_datagram_socket<datagram_protocol> socket;

private:
  int family_;
  int protocol_;
};

} // namespace generic
} // namespace asio
} // namespace egt

#include <egt/asio/detail/pop_options.hpp>

#endif // EGT_ASIO_GENERIC_DATAGRAM_PROTOCOL_HPP
