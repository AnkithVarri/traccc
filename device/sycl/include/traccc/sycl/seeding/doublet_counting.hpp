/** TRACCC library, part of the ACTS project (R&D line)
 *
 * (c) 2021-2022 CERN for the benefit of the ACTS project
 *
 * Mozilla Public License Version 2.0
 */

#pragma once

// SYCL include(s).
#include <CL/sycl.hpp>

// Project include(s).
#include "traccc/edm/internal_spacepoint.hpp"
#include "traccc/seeding/detail/doublet.hpp"
#include "traccc/seeding/detail/seeding_config.hpp"
#include "traccc/seeding/detail/spacepoint_grid.hpp"
#include "traccc/seeding/doublet_finding_helper.hpp"
#include "traccc/sycl/seeding/detail/doublet_counter.hpp"
#include "traccc/sycl/seeding/detail/sycl_helper.hpp"

namespace traccc {
namespace sycl {
/// Forward declaration of doublet counting function
/// The number of mid-bot and mid-top doublets are counted for all spacepoints
/// and recorded into doublet counter container if the number of doublets are
/// larger than zero.
///
/// @param config seed finder config
/// @param internal_sp_container vecmem container for internal spacepoint
/// @param doublet_counter_container vecmem container for doublet_counter
/// @param resource vecmem memory resource
/// @param q sycl queue for kernel scheduling
void doublet_counting(const seedfinder_config& config, sp_grid& internal_sp,
                      host_doublet_counter_container& doublet_counter_container,
                      vecmem::memory_resource& resource, ::sycl::queue* q);

}  // namespace sycl
}  // namespace traccc