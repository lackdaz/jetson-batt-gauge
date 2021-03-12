# Copyright (C) 2021 Seth Loh, Michael de Gans

# This build file may be modified and distributed under the terms
# of the MIT license.  See the LICENSE.mit file for details.

# this meson.build is for gst-check tests (mostly integration tests)

# a list of dicts describing tests
tests = [
  {
    'description': 'test test',
    'filename': 'testy_test',
    'sources': ['test.cpp'],
    'suites': ['unit'],
  },
]

cmake = import('cmake')

# Configure the CMake project

# libi2c dependency (serial control library)
# first, try to get a locally installed version
libi2c_dep = dependency('libi2c-0.1',
  version: '>=0.1.1',
  required: false,
)
# if it's not found, get it from subproject
if not libi2c_dep.found()
	# sub_proj = cmake.subproject('libi2c')
  libi2c_proj = subproject('libi2c')
  libi2c_dep = libi2c_proj.get_variable('libi2c_dep')
endif


# build and run tests (on ninja test)
foreach t: tests
  exe = executable(t['filename'], t['sources'],
    link_with: libjetsonbatt,
    dependencies: jetsonbatt_deps,
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