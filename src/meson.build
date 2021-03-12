# Copyright (C) 2021 Seth Loh, Michael de Gans

# This build file may be modified and distributed under the terms
# of the MIT license.  See the LICENSE.mit file for details.

# dependencies
jetsonbatt_deps = [
  # FIXME(mdegans): find a way to check for cuda components
  dependency('boost',
    # unlike CMake, 'thread' and 'system' are not implicit, apparently
    modules: ['log', 'log_setup', 'thread', 'system'],
  ), 
]

# source files go here
jetsonbatt_src = [
  'battery.cpp'
]

# the library target
libjetsonbatt = library(meson.project_name(), jetsonbatt_src,
  dependencies: jetsonbatt_deps,
  cpp_args: [
    '-fno-exceptions',
    '-DBOOST_LOG_DYN_LINK=1',
  ],
  # this generates semver symlinks from the project version to this target
  # (foo.so, foo.so.0, foo.so.0.0) and so on.
  version: meson.project_version(),
  include_directories: jetsonbatt_incdir,
)

# use this variable in superprojects
libjetsonbatt_dep = declare_dependency(
  link_with: libjetsonbatt,
  include_directories: jetsonbatt_incdir,
  dependencies: jetsonbatt_deps,
)

# this installs a `.pc` pkg-config file, allowing other libraries and apps to
# find the installed package. In Cmake you must generally make a template and
# `configure_file` it. Here, there is no need. The `pkgconfig` modules does it
# for you and generates most of the annoying bits from the first arguement
# (usually a library target).
pkg = import('pkgconfig')
jetsonbatt_pc = pkg.generate(libjetsonbatt,
  description: project_description,
  libraries: jetsonbatt_deps,
  url: project_url,
  # 'datadir' built-in meson option usually evaluates to $PREFIX/share
  # while the default is $PREFIX/lib
  # Either works for pkgconfig with most configurations. $PREFIX/share/pkgconfig
  # is mostly just personal preference.
  install_dir: get_option('datadir') / 'pkgconfig',
)
