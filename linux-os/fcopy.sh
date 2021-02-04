#!/bin/bash

NMODULE=$1

cp -rf module-pattern ${NMODULE}
cd ./${NMODULE}
make clean
mv module-pattern.c ${NMODULE}".c"
sed -i s/module-pattern/"${NMODULE}"/ Makefile

echo -e "#!/bin/bash\n" >>debug.sh
echo -e "modname=${NMODULE}.ko\n">>debug.sh
echo 'insmod ${modname}'>>debug.sh
echo 'rmmod ${modname}'>>debug.sh
echo -e "dmesg -c">>debug.sh
chmod +x debug.sh
