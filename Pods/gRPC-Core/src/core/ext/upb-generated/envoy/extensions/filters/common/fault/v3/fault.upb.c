/* This file was generated by upbc (the upb compiler) from the input
 * file:
 *
 *     envoy/extensions/filters/common/fault/v3/fault.proto
 *
 * Do not edit -- your changes will be discarded when the file is
 * regenerated. */

#include <stddef.h>
#include "upb/msg_internal.h"
#include "envoy/extensions/filters/common/fault/v3/fault.upb.h"
#include "envoy/type/v3/percent.upb.h"
#include "google/protobuf/duration.upb.h"
#include "udpa/annotations/status.upb.h"
#include "udpa/annotations/versioning.upb.h"
#include "validate/validate.upb.h"

#include "upb/port_def.inc"

static const upb_msglayout_sub envoy_extensions_filters_common_fault_v3_FaultDelay_submsgs[3] = {
  {.submsg = &envoy_extensions_filters_common_fault_v3_FaultDelay_HeaderDelay_msginit},
  {.submsg = &envoy_type_v3_FractionalPercent_msginit},
  {.submsg = &google_protobuf_Duration_msginit},
};

static const upb_msglayout_field envoy_extensions_filters_common_fault_v3_FaultDelay__fields[3] = {
  {3, UPB_SIZE(8, 16), UPB_SIZE(-13, -25), 2, 11, _UPB_MODE_SCALAR | (_UPB_REP_PTR << _UPB_REP_SHIFT)},
  {4, UPB_SIZE(4, 8), 1, 1, 11, _UPB_MODE_SCALAR | (_UPB_REP_PTR << _UPB_REP_SHIFT)},
  {5, UPB_SIZE(8, 16), UPB_SIZE(-13, -25), 0, 11, _UPB_MODE_SCALAR | (_UPB_REP_PTR << _UPB_REP_SHIFT)},
};

const upb_msglayout envoy_extensions_filters_common_fault_v3_FaultDelay_msginit = {
  &envoy_extensions_filters_common_fault_v3_FaultDelay_submsgs[0],
  &envoy_extensions_filters_common_fault_v3_FaultDelay__fields[0],
  UPB_SIZE(16, 32), 3, _UPB_MSGEXT_NONE, 0, 255,
};

const upb_msglayout envoy_extensions_filters_common_fault_v3_FaultDelay_HeaderDelay_msginit = {
  NULL,
  NULL,
  UPB_SIZE(0, 0), 0, _UPB_MSGEXT_NONE, 0, 255,
};

static const upb_msglayout_sub envoy_extensions_filters_common_fault_v3_FaultRateLimit_submsgs[3] = {
  {.submsg = &envoy_extensions_filters_common_fault_v3_FaultRateLimit_FixedLimit_msginit},
  {.submsg = &envoy_extensions_filters_common_fault_v3_FaultRateLimit_HeaderLimit_msginit},
  {.submsg = &envoy_type_v3_FractionalPercent_msginit},
};

static const upb_msglayout_field envoy_extensions_filters_common_fault_v3_FaultRateLimit__fields[3] = {
  {1, UPB_SIZE(8, 16), UPB_SIZE(-13, -25), 0, 11, _UPB_MODE_SCALAR | (_UPB_REP_PTR << _UPB_REP_SHIFT)},
  {2, UPB_SIZE(4, 8), 1, 2, 11, _UPB_MODE_SCALAR | (_UPB_REP_PTR << _UPB_REP_SHIFT)},
  {3, UPB_SIZE(8, 16), UPB_SIZE(-13, -25), 1, 11, _UPB_MODE_SCALAR | (_UPB_REP_PTR << _UPB_REP_SHIFT)},
};

const upb_msglayout envoy_extensions_filters_common_fault_v3_FaultRateLimit_msginit = {
  &envoy_extensions_filters_common_fault_v3_FaultRateLimit_submsgs[0],
  &envoy_extensions_filters_common_fault_v3_FaultRateLimit__fields[0],
  UPB_SIZE(16, 32), 3, _UPB_MSGEXT_NONE, 3, 255,
};

static const upb_msglayout_field envoy_extensions_filters_common_fault_v3_FaultRateLimit_FixedLimit__fields[1] = {
  {1, UPB_SIZE(0, 0), 0, 0, 4, _UPB_MODE_SCALAR | (_UPB_REP_8BYTE << _UPB_REP_SHIFT)},
};

const upb_msglayout envoy_extensions_filters_common_fault_v3_FaultRateLimit_FixedLimit_msginit = {
  NULL,
  &envoy_extensions_filters_common_fault_v3_FaultRateLimit_FixedLimit__fields[0],
  UPB_SIZE(8, 8), 1, _UPB_MSGEXT_NONE, 1, 255,
};

const upb_msglayout envoy_extensions_filters_common_fault_v3_FaultRateLimit_HeaderLimit_msginit = {
  NULL,
  NULL,
  UPB_SIZE(0, 0), 0, _UPB_MSGEXT_NONE, 0, 255,
};

static const upb_msglayout *messages_layout[5] = {
  &envoy_extensions_filters_common_fault_v3_FaultDelay_msginit,
  &envoy_extensions_filters_common_fault_v3_FaultDelay_HeaderDelay_msginit,
  &envoy_extensions_filters_common_fault_v3_FaultRateLimit_msginit,
  &envoy_extensions_filters_common_fault_v3_FaultRateLimit_FixedLimit_msginit,
  &envoy_extensions_filters_common_fault_v3_FaultRateLimit_HeaderLimit_msginit,
};

const upb_msglayout_file envoy_extensions_filters_common_fault_v3_fault_proto_upb_file_layout = {
  messages_layout,
  NULL,
  5,
  0,
};

#include "upb/port_undef.inc"

