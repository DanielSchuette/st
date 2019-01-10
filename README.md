st - simple terminal
--------------------
st is a simple terminal emulator for X which sucks less.


Requirements
------------
In order to build st you need the Xlib header files.


Installation
------------
Edit config.mk to match your local setup (st is installed into
the /usr/local namespace by default).

Afterwards enter the following command to build and install st (if
necessary as root):

    make clean install


Running st
----------
If you did not install st with make clean install, you must compile
the st terminfo entry with the following command:

    tic -sx st.info

See the man page for additional details.

Patches
-------
Based upon this source code, I changed things in `config.h` to get some non-default behavior:

1. Color scheme (see dotfiles repository in `termcolors/simpleterm.h`)
2. I use tmux to have a scroll back buffer, so no patches needed for that
3. more to come!

Credits
-------
Based on Aurélien APTEL <aurelien dot aptel at gmail dot com> bt source code.

