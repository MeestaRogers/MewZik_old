# MewZik
An application to manage your music library and jam your favorite hits. Will be cross-platform.

Mewzik is intended to be an open source alternative to other media players.
This includes music, movies, streaming services, and other modern media
capabilities.

GTK3/Glade (gtkmm) and SDL will be the primary libraries to support application development.
Linux is the initial target. Following Linux will be OSX and Windows.
Applying a similiar cross platform approach as gimp is the direction moving forward,
but things may change as time progresses.

# Environment Setup

# Linux
Use your package manager to install <code>gtkmm-3.0 | SDL-2.0.5 | SDL2_mixer-2.0.1</code>

# Windows
To build the project on windows install msys2. Once installed use pacman to install <br><code>gcc-6.3.0.1 | gtkmm-3.0 | SDL-2.0.5 | SDL2_mixer-2.0.1 | GNU make</code>
Make sure all packages you install are prepended with msys64/mingw64_x64_x86-{package_name}

# OS X
Simply install Homebrew then install <code>gcc-6.3.0.1 | gtkmm-3.0 | SDL-2.0.5 | SDL2_mixer-2.0.1 | GNU make</code>
