# Copyright (C) 2021 Seth Loh, Michael de Gans

# This build file may be modified and distributed under the terms
# of the MIT license.  See the LICENSE.mit file for details.

# For googletests

# a list of dicts describing tests
tests = [
#   {
#     'description': 'math test for i2c conversions',
#     'filename': 'test_math',
#     'sources': ['test_math.cpp'],
#     'suites': ['unit'],
#   },
  {
    'description': 'unit test for bitwise operations',
    'filename': 'test_bitwise',
    'sources': ['test_bitwise.cpp'],
    'suites': ['unit'],
  }
]

i2c_proj = subproject('libi2c')
i2c_dep = i2c_proj.get_variable('i2c_dep')

gtest_proj = subproject('gtest')
gtest_dep = gtest_proj.get_variable('gtest_dep')

# build and run tests (on ninja test)
foreach t: tests
  exe = executable(t['filename'], t['sources'],
    link_with: libjetsonbatt,
		dependencies: [i2c_dep, gtest_dep, jetsonbatt_deps],
    # this defines LOGFILE and TESTNAME so you can use those in your tests.
    # (eg. for logging. See nvcvcam. for more.)
    cpp_args: [
      '-DLOGFILE="' + t['filename'] + '.txt"',
      '-DTESTNAME="' + t['filename'] + '"',
      # this says we want to dynamically link boost log rather than using
      # the header only version.
      '-DBOOST_LOG_DYN_LINK=1',
    ],
    include_directories: jetsonbatt_incdir,
  )
  # skip running test if it's an interactive one
  if 'interactive' in t['suites']
    continue
  endif
  # run the rest of the tests in parallel
  test(t['description'], exe,
    protocol: 'exitcode',
    is_parallel: 'integration' not in t['suites'],
    suite: t['suites'],
  )

endforeach