
# Copyright (C) 2021 Seth Loh, Michael De Gans

# This build file may be modified and distributed under the terms
# of the MIT license.  See the LICENSE.mit file for details.

# setup the project's global options
project('jetsonbatt', ['cpp'],
  # we use the VERSION file as a source of truth for the semver
  version: run_command(
    'head', '-n', '1', files('VERSION'),
  ).stdout().strip(),
  meson_version: '>= 0.57.1',
  license: 'MIT',
  default_options: [
    'cpp_std=c++17',
    'warning_level=2',  # -Wall, -Wextra
    'werror=true',  # -Werror
  ],
)

# the c++ compiler object
cc = meson.get_compiler('cpp')

# split the project version
proj_ver = meson.project_version().split('.')
# version minus patch revision
proj_ver_short = proj_ver[0] + '.' + proj_ver[1]
proj_ver_major = proj_ver[0]
proj_ver_minor = proj_ver[1]
proj_ver_patch = proj_ver[2]
# git revision
git_cmd = run_command('git', 'rev-parse', '--short', 'HEAD')
if git_cmd.returncode() == 0
  proj_ver_git = git_cmd.stdout().strip()
else
  proj_ver_git = 'untracked'
endif
# all of this is used by configure_file on config.h.in
project_description = 'I2C interface library Battery Gauge for Jetson Nano'
binary_package = 'source'
origin = 'github'
# change this if you fork this
project_url = 'https://github.com/lackdaz/jetson-batt-gauge'

subdir('include')
subdir('src')
subdir('test')
# subdir('docs')

# executable('demo', 'main.cpp')
