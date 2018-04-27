/**
 * This file is part of the CernVM File System.
 */

#include "gtest/gtest.h"

#include "cvmfs_suid_util.h"

using namespace std;  // NOLINT

namespace cvmfs_suid {

TEST(T_SuidUtil, EscapeSystemdUnit) {
  EXPECT_DEATH(EscapeSystemdUnit(""), ".*");

  EXPECT_EQ("-.mount", EscapeSystemdUnit("/"));
  EXPECT_EQ("-.mount", EscapeSystemdUnit("//"));
  EXPECT_EQ("-.mount", EscapeSystemdUnit("///"));
  EXPECT_EQ("-.mount", EscapeSystemdUnit("////"));

  EXPECT_EQ("a-b-c.mount", EscapeSystemdUnit("/a/b/c"));
  EXPECT_EQ("a-b-c.mount", EscapeSystemdUnit("/a/b//c"));

  EXPECT_EQ("a-b-c.mount", EscapeSystemdUnit("/a/b/c/"));
  EXPECT_EQ("\\x2ea_-.b-c\\x40.mount", EscapeSystemdUnit(".a_/.b/c@"));
}

}  // namespace cvmfs_suid
