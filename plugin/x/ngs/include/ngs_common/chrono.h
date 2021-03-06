/*
 * Copyright (c) 2015, 2018, Oracle and/or its affiliates. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License, version 2.0,
 * as published by the Free Software Foundation.
 *
 * This program is also distributed with certain software (including
 * but not limited to OpenSSL) that is licensed under separate terms,
 * as designated in a particular file or component or in included license
 * documentation.  The authors of MySQL hereby grant you an additional
 * permission to link the program and your derivative works with the
 * separately licensed software that they have included with MySQL.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License, version 2.0, for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA
 */

#ifndef PLUGIN_X_NGS_INCLUDE_NGS_COMMON_CHRONO_H_
#define PLUGIN_X_NGS_INCLUDE_NGS_COMMON_CHRONO_H_

#include <chrono>  // NOLINT(build/c++11)

namespace ngs {
namespace chrono {

using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::system_clock;
using clock = std::chrono::steady_clock;
using time_point = clock::time_point;
using duration = clock::duration;

inline time_point now() { return clock::now(); }

inline milliseconds::rep to_milliseconds(const duration &d) {
  return std::chrono::duration_cast<milliseconds>(d).count();
}

inline seconds::rep to_seconds(const duration &d) {
  return std::chrono::duration_cast<seconds>(d).count();
}

inline bool is_valid(const time_point &p) {
  return p.time_since_epoch().count() > 0;
}

}  // namespace chrono
}  // namespace ngs

#endif  // PLUGIN_X_NGS_INCLUDE_NGS_COMMON_CHRONO_H_
