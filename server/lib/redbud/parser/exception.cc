// ============================================================================
// Copyright (c) 2017 Alinshans. All rights reserved.
// Licensed under the MIT License. See LICENSE for details.
// 
// Source File : redbud/exception.cc 
//
// This file contains the implementation of Exception class.
// ============================================================================

#include <redbud/exception.h>

#include <cstdio>
#include <cstdlib>

namespace redbud
{

// ----------------------------------------------------------------------------
// Outputs the exception messages and quits.

Exception::Exception(const std::string& cond,
                     const std::string& msg,
                     const char* file,
                     size_t line)
{
  fprintf(stderr, "Exception : [ %s ], %s : %zu\n"
          "     Note : %s\n",
          cond.c_str(), file, line, msg.c_str());
}

ParseException::ParseException(const std::string& cond,
                               const std::string& exp,
                               const std::string& act,
                               size_t pos,
                               const char* file,
                               size_t line)
{
  fprintf(stderr, "Exception : [ %s ], %s : %zu\n"
          "   Expect : %s, Actual : %s at postion %zu.\n",
          cond.c_str(), file, line, exp.c_str(), act.c_str(), pos);
}

} // namespace redbud

