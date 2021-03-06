KLIBC_UTILS_VARIANT ?= "shared"
KLIBC_UTILS_PKGNAME ?= "klibc-utils"

# modprobe and losetup go to ${base_sbindir}
# even though debian packages all in /usr/lib/klibc/bin

do_install_append() {

        install -d ${D}${base_bindir}
        install -d ${D}${base_sbindir}

        # those 2 are always static
        install -m 755 usr/dash/sh ${D}${base_bindir}/sh
        install -m 755 usr/kinit/kinit ${D}${base_bindir}/kinit

        install -m 755 usr/gzip/gzip ${D}${base_bindir}
        install -m 755 usr/kinit/fstype/${KLIBC_UTILS_VARIANT}/fstype ${D}${base_bindir}
        install -m 755 usr/kinit/ipconfig/${KLIBC_UTILS_VARIANT}/ipconfig ${D}${base_bindir}
        install -m 755 usr/kinit/nfsmount/${KLIBC_UTILS_VARIANT}/nfsmount ${D}${base_bindir}
        install -m 755 usr/kinit/resume/${KLIBC_UTILS_VARIANT}/resume ${D}${base_bindir}
        install -m 755 usr/kinit/run-init/${KLIBC_UTILS_VARIANT}/run-init ${D}${base_bindir}
        install -m 755 usr/utils/${KLIBC_UTILS_VARIANT}/cat ${D}${base_bindir}
        install -m 755 usr/utils/${KLIBC_UTILS_VARIANT}/chroot ${D}${base_bindir}
        install -m 755 usr/utils/${KLIBC_UTILS_VARIANT}/cpio ${D}${base_bindir}
        install -m 755 usr/utils/${KLIBC_UTILS_VARIANT}/dd ${D}${base_bindir}
        install -m 755 usr/utils/${KLIBC_UTILS_VARIANT}/dmesg ${D}${base_bindir}
        install -m 755 usr/utils/${KLIBC_UTILS_VARIANT}/false ${D}${base_bindir}
        install -m 755 usr/utils/${KLIBC_UTILS_VARIANT}/halt ${D}${base_bindir}
        install -m 755 usr/utils/${KLIBC_UTILS_VARIANT}/kill ${D}${base_bindir}
        install -m 755 usr/utils/${KLIBC_UTILS_VARIANT}/ln ${D}${base_bindir}
        install -m 755 usr/utils/${KLIBC_UTILS_VARIANT}/losetup ${D}${base_sbindir}
        install -m 755 usr/utils/${KLIBC_UTILS_VARIANT}/ls ${D}${base_bindir}
        install -m 755 usr/utils/${KLIBC_UTILS_VARIANT}/minips ${D}${base_bindir}
        install -m 755 usr/utils/${KLIBC_UTILS_VARIANT}/mkdir ${D}${base_bindir}
        install -m 755 usr/utils/${KLIBC_UTILS_VARIANT}/mkfifo ${D}${base_bindir}
        install -m 755 usr/utils/${KLIBC_UTILS_VARIANT}/mknod ${D}${base_bindir}
        install -m 755 usr/utils/${KLIBC_UTILS_VARIANT}/modprobe ${D}${base_sbindir}
        install -m 755 usr/utils/${KLIBC_UTILS_VARIANT}/mount ${D}${base_bindir}
        install -m 755 usr/utils/${KLIBC_UTILS_VARIANT}/mv ${D}${base_bindir}
        install -m 755 usr/utils/${KLIBC_UTILS_VARIANT}/nuke ${D}${base_bindir}
        install -m 755 usr/utils/${KLIBC_UTILS_VARIANT}/pivot_root ${D}${base_bindir}
        install -m 755 usr/utils/${KLIBC_UTILS_VARIANT}/poweroff ${D}${base_bindir}
        install -m 755 usr/utils/${KLIBC_UTILS_VARIANT}/readlink ${D}${base_bindir}
        install -m 755 usr/utils/${KLIBC_UTILS_VARIANT}/reboot ${D}${base_bindir}
        install -m 755 usr/utils/${KLIBC_UTILS_VARIANT}/sleep ${D}${base_bindir}
        install -m 755 usr/utils/${KLIBC_UTILS_VARIANT}/sync ${D}${base_bindir}
        install -m 755 usr/utils/${KLIBC_UTILS_VARIANT}/true ${D}${base_bindir}
        install -m 755 usr/utils/${KLIBC_UTILS_VARIANT}/umount ${D}${base_bindir}
        install -m 755 usr/utils/${KLIBC_UTILS_VARIANT}/uname ${D}${base_bindir}
        install -m 755 usr/utils/${KLIBC_UTILS_VARIANT}/wc ${D}${base_bindir}
        ln -s gzip ${D}${base_bindir}/gunzip
        ln -s gzip ${D}${base_bindir}/zcat
}

PACKAGES_DYNAMIC = "${KLIBC_UTILS_PKGNAME}-*"

python populate_packages_prepend () {

        base_bin_dir = bb.data.expand('${base_bindir}', d)
        do_split_packages(d, base_bin_dir, '(.*)', '${KLIBC_UTILS_PKGNAME}-%s', 'Klibc util for %s', allow_links=True, allow_dirs=True)

        base_sbin_dir = bb.data.expand('${base_sbindir}', d)
        do_split_packages(d, base_sbin_dir, '(.*)', '${KLIBC_UTILS_PKGNAME}-%s', 'Klibc util for %s', allow_dirs=True)
}
