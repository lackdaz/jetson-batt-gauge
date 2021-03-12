# Copyright (C) 2021 Seth Loh, Michael de Gans

# This build file may be modified and distributed under the terms
# of the MIT license.  See the LICENSE.mit file for details.

jetsonbatt_config_hpp = configure_file(
  input: 'jetsonbatt_config.hpp.in',
  output: 'jetsonbatt_config.hpp',
  configuration: {
    'PROJECT_VERSION': meson.project_version(),
    'PROJECT_VERSION_MAJOR': proj_ver_major.to_int(),
    'PROJECT_VERSION_MINOR': proj_ver_minor.to_int(),
    'PROJECT_VERSION_PATCH': proj_ver_patch.to_int(),
    'PROJECT_VERSION_GIT': proj_ver_git,
  },
)

# this variable points to this directory, but can be used anywhere
jetsonbatt_incdir = include_directories('.')

# headers you want available publicly go here
jetsonbatt_public_headers = [
  jetsonbatt_config_hpp
  # you probably want more here
]

# this installs the public headers to $PREFIX/include/$PROJECT_NAME
install_headers(
  jetsonbatt_public_headers,
  subdir: meson.project_name(),
)