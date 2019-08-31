
Debian
====================
This directory contains files used to package leisurecoind/leisurecoin-qt
for Debian-based Linux systems. If you compile leisurecoind/leisurecoin-qt yourself, there are some useful files here.

## leisurecoin: URI support ##


leisurecoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install leisurecoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your leisurecoinqt binary to `/usr/bin`
and the `../../share/pixmaps/leisurecoin128.png` to `/usr/share/pixmaps`

leisurecoin-qt.protocol (KDE)

