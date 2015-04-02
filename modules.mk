mod_rootme.la: mod_rootme.slo
	$(SH_LINK) -rpath $(libexecdir) -module -avoid-version  mod_rootme.lo
DISTCLEAN_TARGETS = modules.mk
shared =  mod_rootme.la
