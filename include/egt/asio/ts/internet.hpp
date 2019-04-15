//
// ts/internet.hpp
// ~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2018 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef EGT_ASIO_TS_INTERNET_HPP
#define EGT_ASIO_TS_INTERNET_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include <egt/asio/ip/address.hpp>
#include <egt/asio/ip/address_v4.hpp>
#include <egt/asio/ip/address_v4_iterator.hpp>
#include <egt/asio/ip/address_v4_range.hpp>
#include <egt/asio/ip/address_v6.hpp>
#include <egt/asio/ip/address_v6_iterator.hpp>
#include <egt/asio/ip/address_v6_range.hpp>
#include <egt/asio/ip/bad_address_cast.hpp>
#include <egt/asio/ip/basic_endpoint.hpp>
#include <egt/asio/ip/basic_resolver_query.hpp>
#include <egt/asio/ip/basic_resolver_entry.hpp>
#include <egt/asio/ip/basic_resolver_iterator.hpp>
#include <egt/asio/ip/basic_resolver.hpp>
#include <egt/asio/ip/host_name.hpp>
#include <egt/asio/ip/network_v4.hpp>
#include <egt/asio/ip/network_v6.hpp>
#include <egt/asio/ip/tcp.hpp>
#include <egt/asio/ip/udp.hpp>
#include <egt/asio/ip/v6_only.hpp>
#include <egt/asio/ip/unicast.hpp>
#include <egt/asio/ip/multicast.hpp>

#endif // EGT_ASIO_TS_INTERNET_HPP