# Copyright (C) 2021 Seth Loh
# This build file may be modified and distributed under the terms
# of the MIT license.  See the LICENSE.mit file for details.

jetsonbatt_config_hpp = configure_file(
  input: 'jetsonbatt.hpp.in',
  output: 'jetsonbatt.hpp',
  configuration: {
    'PROJECT_VERSION': meson.project_version(),
    'PROJECT_VERSION_MAJOR': proj_ver_major.to_int(),
    'PROJECT_VERSION_MINOR': proj_ver_minor.to_int(),
    'PROJECT_VERSION_PATCH': proj_ver_patch.to_int(),
    'PROJECT_VERSION_GIT': proj_ver_git,
  },
)

jetsonbatt_incdir = include_directories('.')

jetsonbatt_public_headers = [
  jetsonbatt_config_hpp
]

install_headers(
  jetsonbatt_public_headers,
  subdir: meson.project_name(),
) # what does this do?