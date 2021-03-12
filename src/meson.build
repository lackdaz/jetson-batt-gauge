# Copyright (C) 2021 Seth Loh

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

jetsonbatt_src = [
]

libjetsonbatt_libname = meson.project_name() + '-' + proj_ver_short
libjetsonbatt = library(libjetsonbatt_libname, jetsonbatt_src,
  dependencies: jetsonbatt_deps,
  cpp_args: [
    '-fno-exceptions',
    '-DBOOST_LOG_DYN_LINK=1',
  ],
  include_directories: jetsonbatt_incdir,
)

# # use this variable in superprojects
# nvcvcam_dep = declare_dependency(
#   link_with: libnvcvcam,
#   include_directories: nvcvcam_incdir,
#   dependencies: nvcvcam_deps,
# )

pkg = import('pkgconfig')
jetsonbatt_pc = pkg.generate(libjetsonbatt,
  description: project_description,
  libraries: jetsonbatt_deps,
  url: project_url,
  install_dir: get_option('datadir') / 'pkgconfig', # what is this sorcery?
)
