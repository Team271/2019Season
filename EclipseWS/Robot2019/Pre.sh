#/bin/bash

cd "/home/lvuser"
sed -i -e 's/^StartupDLLs/;StartupDLLs/' /etc/natinst/share/ni-rt.ini
cd "/usr/local/frc/third-party/lib"
chmod -R 777 "/usr/local/frc/third-party/lib" || true; chown -R lvuser:ni "/usr/local/frc/third-party/lib"
ldconfig
cd "/home/lvuser"
. /etc/profile.d/natinst-path.sh; /usr/local/frc/bin/frcKillRobot.sh -t 2> /dev/null
#rm -f "/home/lvuser/frcUserProgram"